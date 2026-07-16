import rclpy
from rclpy.node import Node
import sys
print("=" * 60)
print("PYTHON EXECUTABLE:", sys.executable)
print("=" * 60)

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from insightface.app import FaceAnalysis
import numpy as np

from ultralytics import YOLO

from edgevision_msgs.msg import (
    Detection,
    DetectionArray,
    TrackedDetection,
    TrackedDetectionArray,
)

import cv2


class PerceptionNode(Node):

    def __init__(self):
        super().__init__("perception_node")

        self.bridge = CvBridge()

        # YOLO model
        self.model = YOLO("yolov8n.pt")

        # -----------------------------
        # InsightFace Initialization
        # -----------------------------
        self.face_app = FaceAnalysis(
            providers=["CPUExecutionProvider"]
        )

        self.face_app.prepare(
            ctx_id=0,
            det_size=(640, 640)
        )

        self.get_logger().info("InsightFace Loaded")
        # -----------------------------

        # Camera subscriber
        self.subscription = self.create_subscription(
            Image,
            "/camera/image",
            self.image_callback,
            10
        )

        # Annotated image publisher
        self.image_publisher = self.create_publisher(
            Image,
            "/camera/detections/image",
            10
        )

        # Detection publisher
        self.detection_publisher = self.create_publisher(
            DetectionArray,
            "/detections",
            10
        )

        # Tracking publisher
        self.tracked_publisher = self.create_publisher(
            TrackedDetectionArray,
            "/tracked_objects",
            10
        )

        self.get_logger().info("Perception Node Started")


    def image_callback(self, msg):

        # ROS Image -> OpenCV
        frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        # YOLO + ByteTrack
        results = self.model.track(
            frame,
            persist=True,
            tracker="bytetrack.yaml"
        )

        # Annotated frame
        annotated_frame = results[0].plot()

        # Publish annotated image
        annotated_msg = self.bridge.cv2_to_imgmsg(
            annotated_frame,
            encoding="bgr8"
        )

        annotated_msg.header = msg.header

        self.image_publisher.publish(annotated_msg)

        # Detection messages
        detection_array = DetectionArray()
        detection_array.header = msg.header

        # Tracking messages
        tracked_array = TrackedDetectionArray()
        tracked_array.header = msg.header
        for box in results[0].boxes:

            # -----------------------------
            # Normal Detection
            # -----------------------------
            detection = Detection()

            cls = int(box.cls[0])

            detection.class_name = self.model.names[cls]
            detection.confidence = float(box.conf[0])

            x1, y1, x2, y2 = box.xyxy[0].tolist()

            detection.x1 = int(x1)
            detection.y1 = int(y1)
            detection.x2 = int(x2)
            detection.y2 = int(y2)

            detection_array.detections.append(
                detection
            )

            # -----------------------------
            # Tracked Detection
            # -----------------------------
            tracked = TrackedDetection()

            if box.id is not None:
                tracked.track_id = int(box.id[0])
            else:
                tracked.track_id = -1

            tracked.class_name = detection.class_name
            tracked.confidence = detection.confidence

            tracked.x1 = detection.x1
            tracked.y1 = detection.y1
            tracked.x2 = detection.x2
            tracked.y2 = detection.y2

            tracked_array.detections.append(
                tracked
            )

            # -----------------------------
            # Face Detection
            # -----------------------------
            if detection.class_name != "person":
                continue

            h, w = frame.shape[:2]

            x1c = max(0, detection.x1)
            y1c = max(0, detection.y1)
            x2c = min(w, detection.x2)
            y2c = min(h, detection.y2)

            if x2c <= x1c or y2c <= y1c:
                continue

            person_roi = frame[y1c:y2c, x1c:x2c]

            if person_roi.size == 0:
                continue

            faces = self.face_app.get(person_roi)

            for face in faces:

                fx1, fy1, fx2, fy2 = map(int, face.bbox)

                cv2.rectangle(
                    annotated_frame,
                    (x1c + fx1, y1c + fy1),
                    (x1c + fx2, y1c + fy2),
                    (0, 255, 0),
                    2,
                )

        # Publish detections
        self.detection_publisher.publish(
            detection_array
        )

        # Publish tracked objects
        self.tracked_publisher.publish(
            tracked_array
        )

        # Display
        cv2.imshow(
            "EdgeVision Detection",
            annotated_frame
        )

        cv2.waitKey(1)


def main(args=None):

    rclpy.init(args=args)

    node = PerceptionNode()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    finally:
        cv2.destroyAllWindows()

        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()




if __name__ == "__main__":
    main()