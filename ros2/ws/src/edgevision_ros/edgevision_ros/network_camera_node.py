import subprocess
import threading

import cv2
import numpy as np

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge


class NetworkCameraNode(Node):

    def __init__(self):
        super().__init__("network_camera_node")

        self.bridge = CvBridge()

        # RTSP stream from the camera server.
        # Currently using the laptop's MediaMTX stream.
        # Later this will be the Raspberry Pi RTSP stream.
        self.stream_url = "rtsp://127.0.0.1:8554/edgevision"

        # Current camera stream format.
        self.width = 1280
        self.height = 720
        self.frame_size = self.width * self.height * 3

        # FFmpeg decodes the RTSP/H.264 stream and outputs
        # raw BGR frames to stdout.
        self.ffmpeg = subprocess.Popen(
            [
                "ffmpeg",
                "-rtsp_transport",
                "tcp",
                "-i",
                self.stream_url,
                "-f",
                "rawvideo",
                "-pix_fmt",
                "bgr24",
                "-"
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            bufsize=10**8
        )

        self.publisher = self.create_publisher(
            Image,
            "/camera/image",
            10
        )

        self.timer = self.create_timer(
            0.033,
            self.publish_frame
        )

        self.get_logger().info(
            "Network Camera Node Started"
        )

    def publish_frame(self):

        raw_frame = self.ffmpeg.stdout.read(
            self.frame_size
        )

        if len(raw_frame) != self.frame_size:
            self.get_logger().warning(
                "Failed to read complete frame from FFmpeg"
            )
            return

        frame = np.frombuffer(
            raw_frame,
            dtype=np.uint8
        ).reshape(
            (self.height, self.width, 3)
        )

        msg = self.bridge.cv2_to_imgmsg(
            frame,
            encoding="bgr8"
        )

        self.publisher.publish(msg)

    def destroy_node(self):

        if self.ffmpeg is not None:
            self.ffmpeg.terminate()

            try:
                self.ffmpeg.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self.ffmpeg.kill()

        cv2.destroyAllWindows()

        super().destroy_node()


def main(args=None):

    rclpy.init(args=args)

    node = NetworkCameraNode()

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
