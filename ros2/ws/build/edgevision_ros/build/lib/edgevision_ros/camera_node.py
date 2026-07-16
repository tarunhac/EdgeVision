"""
EdgeVision Camera Node
"""

import os
import sys

# Add the main project directory to Python's import path
PROJECT_ROOT = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "../../../../../")
)

if PROJECT_ROOT not in sys.path:
    sys.path.insert(0, PROJECT_ROOT)

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

from edgevision_core.camera import CameraService


class CameraNode(Node):

    def __init__(self):
        super().__init__("camera_node")

        self.camera = CameraService()
        self.camera.initialize()

        self.bridge = CvBridge()

        self.publisher = self.create_publisher(
            Image,
            "camera/image",
            10
        )

        self.timer = self.create_timer(
            0.033,
            self.publish_frame
        )

        self.get_logger().info("Camera Node Started")

    def publish_frame(self):
        ret, frame = self.camera.read()

        if not ret:
            self.get_logger().warning("Failed to read frame")
            return

        msg = self.bridge.cv2_to_imgmsg(
            frame,
            encoding="bgr8"
        )

        self.publisher.publish(msg)

    def destroy_node(self):
        self.camera.release()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)

    node = CameraNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()