import rclpy
from rclpy.node import Node

from ros2.ws.src.edgevision_ros.edgevision_ros.paths import KNOWN_FACES_DIR
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from edgevision_ros.paths import KNOWN_FACES_DIR
from ultralytics import YOLO

from edgevision_core.event_logger import EventLogger
from edgevision_ros.face_recognizer import FaceRecognizer

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
        self.model = YOLO(
            "yolov8n.pt"
        )

        # Face recognizer
        self.face_recognizer = FaceRecognizer(
            str(KNOWN_FACES_DIR)
        )

        # Cache recognized identities
        self.identity_cache = {}

        # Event logger
        self.event_logger = EventLogger()
        self.event_logger.initialize()

        self.get_logger().info(
            "Face Recognizer Loaded"
        )

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

        self.tracked_publisher = self.create_publisher(
            TrackedDetectionArray,
            "/tracked_objects",
            10
        )
        self.unknown_publisher = self.create_publisher(
            TrackedDetection,
            "/unknown_person",
            10
        )

        self.get_logger().info(
            "Perception Node Started"
        )

    def image_callback(self, msg):

        frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        results = self.model.track(
            frame,
            persist=True,
            tracker="bytetrack.yaml",
            classes=[0]
        )

        annotated_frame = frame.copy()

        detection_array = DetectionArray()
        detection_array.header = msg.header

        tracked_array = TrackedDetectionArray()
        tracked_array.header = msg.header

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

            detection_array.detections.append(
                detection
            )

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

            # -----------------------------
            # Face Recognition
            # -----------------------------

            person_roi = frame[
                detection.y1:detection.y2,
                detection.x1:detection.x2
            ]

            if tracked.track_id in self.identity_cache:

                name, similarity = self.identity_cache[
                    tracked.track_id
                ]

            else:

                name, similarity, _, _ = (
                    self.face_recognizer.recognize(
                        person_roi
                    )
                )

                self.identity_cache[
                    tracked.track_id
                ] = (
                    name,
                    similarity
                )

            tracked.name = name
            tracked.similarity = float(similarity)

            # -----------------------------
            # Log Unknown Person
            # -----------------------------

            if tracked.name == "Unknown":
                

                class LoggedDetection:
                    pass

                logged_detection = LoggedDetection()

                logged_detection.track_id = tracked.track_id
                logged_detection.name = tracked.name
                logged_detection.similarity = tracked.similarity

                logged_detection.x1 = detection.x1
                logged_detection.y1 = detection.y1
                logged_detection.x2 = detection.x2
                logged_detection.y2 = detection.y2


                tracked.face_image = ""
                tracked.frame_image = ""
                
                self.unknown_publisher.publish(
                   tracked
               )

            tracked_array.detections.append(
                tracked
            )

            # -----------------------------
            # Draw Bounding Box
            # -----------------------------

            cv2.rectangle(
                annotated_frame,
                (detection.x1, detection.y1),
                (detection.x2, detection.y2),
                (255, 0, 0),
                2
            )

            label = (
                f"ID:{tracked.track_id} {tracked.name}"
            )

            cv2.putText(
                annotated_frame,
                label,
                (
                    detection.x1,
                    detection.y1 - 10
                ),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (255, 0, 0),
                2
            )

        annotated_msg = self.bridge.cv2_to_imgmsg(
            annotated_frame,
            encoding="bgr8"
        )

        annotated_msg.header = msg.header

        self.image_publisher.publish(
            annotated_msg
        )

        self.detection_publisher.publish(
            detection_array
        )

        self.tracked_publisher.publish(
            tracked_array
        )

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

        node.event_logger.shutdown()

        cv2.destroyAllWindows()

        if rclpy.ok():

            node.destroy_node()

            if rclpy.ok():
                rclpy.shutdown()


if __name__ == "__main__":

    main()