from setuptools import setup, find_packages

package_name = "edgevision_ros"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(),
    install_requires=[
        "setuptools",
    ],
    zip_safe=True,
    maintainer="tarun",
    maintainer_email="tarunvelu72@gmail.com",
    description="EdgeVision ROS2 interface",
    license="Apache-2.0",
    data_files=[
        (
            "share/ament_index/resource_index/packages",
            ["resource/" + package_name],
        ),
        (
            "share/" + package_name,
            ["package.xml"],
        ),
    ],
    entry_points={
        "console_scripts": [
            "camera_node = edgevision_ros.camera_node:main",
            "detector_node = edgevision_ros.detector_node:main",
            "tracker_node = edgevision_ros.tracker_node:main",
            "perception_node = edgevision_ros.perception_node:main",
            "face_node = edgevision_ros.face_node:main",
            "event_logger_node = edgevision_ros.event_logger_node:main",
        ],
    },
)