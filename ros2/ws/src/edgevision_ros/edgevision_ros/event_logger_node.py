import rclpy
from rclpy.node import Node

from edgevision_msgs.msg import TrackedDetectionArray

import sqlite3
from datetime import datetime
from pathlib import Path


class EventLoggerNode(Node):

    def __init__(self):

        super().__init__(
            "event_logger_node"
        )


        # Database path

        self.db_path = (
            "/home/tarun/surveillance_bot/logs/events.db"
        )


        self.create_database()


        self.subscription = self.create_subscription(
            TrackedDetectionArray,
            "/tracked_objects",
            self.callback,
            10
        )


        self.get_logger().info(
            "Event Logger Node Started"
        )



    def create_database(self):

        db = sqlite3.connect(
            self.db_path
        )

        cursor = db.cursor()


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



    def callback(self, msg):

        db = sqlite3.connect(
            self.db_path
        )

        cursor = db.cursor()


        for detection in msg.detections:


            timestamp = datetime.now().strftime(
                "%Y-%m-%d %H:%M:%S"
            )


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
                    "",
                    ""
                )
            )


            self.get_logger().info(
                f"Logged ID:{detection.track_id} "
                f"Name:{detection.name} "
                f"Similarity:{detection.similarity:.3f}"
            )


        db.commit()

        db.close()



def main(args=None):

    rclpy.init(
        args=args
    )


    node = EventLoggerNode()


    try:

        rclpy.spin(node)


    except KeyboardInterrupt:

        pass


    finally:

        node.destroy_node()

        rclpy.shutdown()



if __name__ == "__main__":

    main()