from setuptools import find_packages
from setuptools import setup

setup(
    name='edgevision_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('edgevision_msgs', 'edgevision_msgs.*')),
)
