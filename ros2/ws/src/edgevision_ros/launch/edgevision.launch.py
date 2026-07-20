from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    return LaunchDescription(

        [

            Node(
                package="edgevision_ros",
                executable="camera_node",
                name="camera_node",
                output="screen"
            ),

            Node(
                package="edgevision_ros",
                executable="perception_node",
                name="perception_node",
                output="screen"
            ),

            Node(
                package="edgevision_ros",
                executable="event_logger_node",
                name="event_logger_node",
                output="screen"
            ),
            Node(
                package="edgevision_ros",
                executable="tracker_node",
                name="tracker_node",
                output="screen"
             ),

        ]

    )
