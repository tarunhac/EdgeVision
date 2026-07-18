import rclpy
from rclpy.node import Node

from edgevision_msgs.msg import TrackedDetection

import sqlite3
from datetime import datetime
from pathlib import Path

import cv2

from edgevision_core.face_snapshot import FaceSnapshotService
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class EventLoggerNode(Node):

    def __init__(self):

        super().__init__(
            "event_logger_node"
        )


        # Database path

        self.db_path = (
            "/home/tarun/surveillance_bot/logs/events.db"
        )

        self.bridge = CvBridge()

        self.latest_frame = None

        self.snapshot = FaceSnapshotService()
        self.snapshot.initialize()
        self.create_database()
        self.logged_tracks = set()
        self.snapshot = FaceSnapshotService()
        self.snapshot.initialize()


        self.subscription = self.create_subscription(
            TrackedDetection,
            "/unknown_person",
            self.callback,
            10
        )
        self.image_subscription = self.create_subscription(
            Image,
            "/camera/image",
            self.image_callback,
            10
        )



    def create_database(self):

        db = sqlite3.connect(
            self.db_path
        )

        cursor = db.cursor()
        
        face_path = ""
        frame_path = ""

        cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS events (

                id INTEGER PRIMARY KEY AUTOINCREMENT,

                timestamp TEXT NOT NULL,

                track_id INTEGER NOT NULL,

                name TEXT NOT NULL,

                similarity REAL NOT NULL,

                face_image TEXT NOT NULL,

                frame_image TEXT NOT NULL
            )
            """
        )


        db.commit()

        db.close()



    def callback(self, detection):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        if detection.track_id in self.logged_tracks:
              return

        self.logged_tracks.add(
        detection.track_id
)
        if self.latest_frame is None:
            self.get_logger().warn(
                "No camera frame received yet."
            )
            return

        face_path, frame_path = self.snapshot.save(
            self.latest_frame,
            detection
        )
        db = sqlite3.connect(self.db_path)
        cursor = db.cursor()

        cursor.execute(
            """
            INSERT INTO events
            (
                timestamp,
                track_id,
                name,
                similarity,
                face_image,
                frame_image
            )
            VALUES (?, ?, ?, ?, ?, ?)
            """,
            (
                timestamp,
                detection.track_id,
                detection.name,
                detection.similarity,
                face_path,
                frame_path
            ),
        )
        db.commit()
        db.close()

        self.get_logger().info(f"Unknown Person Logged ID:{detection.track_id}")

    def image_callback(self, msg):
        self.latest_frame = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8",
        )
      

def main(args=None):
    rclpy.init(args=args)

    node = EventLoggerNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        
        if rclpy.ok():
           rclpy.shutdown()

if __name__ == "__main__":
    main()