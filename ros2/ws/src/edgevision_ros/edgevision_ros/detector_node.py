import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from ultralytics import YOLO

import cv2


class DetectorNode(Node):

    def __init__(self):
        super().__init__("detector_node")

        self.bridge = CvBridge()

        self.model = YOLO("yolov8n.pt")

        self.subscription = self.create_subscription(
            Image,
            "/camera/image",
            self.image_callback,
            10
        )

        self.publisher = self.create_publisher(
            Image,
            "/camera/detections/image",
            10
        )

        self.get_logger().info("Detector Node Started")

    def image_callback(self, msg):

        # Convert ROS Image to OpenCV image
        frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        # Run YOLO inference
        results = self.model(frame)

        # Draw detections
        annotated_frame = results[0].plot()

        # Publish annotated image
        annotated_msg = self.bridge.cv2_to_imgmsg(
            annotated_frame,
            encoding="bgr8"
        )

        self.publisher.publish(annotated_msg)

        # Display image
        cv2.imshow("EdgeVision Detection", annotated_frame)
        cv2.waitKey(1)


def main(args=None):

    rclpy.init(args=args)

    node = DetectorNode()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    cv2.destroyAllWindows()

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()