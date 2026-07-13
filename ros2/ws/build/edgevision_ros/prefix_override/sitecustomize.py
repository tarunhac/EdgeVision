import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/tarun/surveillance_bot/ros2/ws/install/edgevision_ros'
