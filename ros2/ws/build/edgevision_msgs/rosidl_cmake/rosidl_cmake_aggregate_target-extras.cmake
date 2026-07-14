# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target edgevision_msgs::edgevision_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${edgevision_msgs_TARGETS}.
if(edgevision_msgs_TARGETS AND NOT TARGET edgevision_msgs::edgevision_msgs)
  add_library(edgevision_msgs::edgevision_msgs INTERFACE IMPORTED)
  set_target_properties(edgevision_msgs::edgevision_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${edgevision_msgs_TARGETS}")
endif()
