from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'edgevision_ros'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(),
    data_files=[
        (
            'share/ament_index/resource_index/packages',
            ['resource/' + package_name]
        ),
        (
            'share/' + package_name,
            ['package.xml']
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tarun',
    maintainer_email='tarunvelu72@gmail.com',
    description='EdgeVision ROS2 interface',
    license='Apache-2.0',

    entry_points={
        'console_scripts': [
            'camera_node = edgevision_ros.camera_node:main',
        ],
    },
)