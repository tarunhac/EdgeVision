import rclpy
from rclpy.node import Node

from edgevision_msgs.msg import DetectionArray


class TrackerNode(Node):

    def __init__(self):
        super().__init__("tracker_node")

        self.subscription = self.create_subscription(
            DetectionArray,
            "/detections",
            self.detection_callback,
            10
        )

        self.get_logger().info("Tracker Node Started")

    def detection_callback(self, msg):

        self.get_logger().info(
            f"Received {len(msg.detections)} detections"
        )


def main(args=None):

    rclpy.init(args=args)

    node = TrackerNode()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()