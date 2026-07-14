import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from ultralytics import YOLO

from edgevision_msgs.msg import Detection
from edgevision_msgs.msg import DetectionArray

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

        self.image_publisher = self.create_publisher(
            Image,
            "/camera/detections/image",
            10
        )

        self.detection_publisher = self.create_publisher(
            DetectionArray,
            "/detections",
            10
        )

        self.get_logger().info("Detector Node Started")

    def image_callback(self, msg):

        frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        results = self.model(frame)

        annotated_frame = results[0].plot()

        annotated_msg = self.bridge.cv2_to_imgmsg(
            annotated_frame,
            encoding="bgr8"
        )

        self.image_publisher.publish(annotated_msg)

        detection_array = DetectionArray()
        detection_array.header = msg.header

        for box in results[0].boxes:

            detection = Detection()

            cls = int(box.cls[0])
            detection.class_name = self.model.names[cls]

            detection.confidence = float(box.conf[0])

            x1, y1, x2, y2 = box.xyxy[0].tolist()

            detection.x1 = int(x1)
            detection.y1 = int(y1)
            detection.x2 = int(x2)
            detection.y2 = int(y2)

            detection_array.detections.append(detection)

        self.detection_publisher.publish(detection_array)

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