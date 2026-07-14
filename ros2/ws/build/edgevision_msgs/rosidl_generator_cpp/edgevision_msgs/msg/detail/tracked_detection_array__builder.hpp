// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from edgevision_msgs:msg/TrackedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__BUILDER_HPP_
#define EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "edgevision_msgs/msg/detail/tracked_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace edgevision_msgs
{

namespace msg
{

namespace builder
{

class Init_TrackedDetectionArray_detections
{
public:
  explicit Init_TrackedDetectionArray_detections(::edgevision_msgs::msg::TrackedDetectionArray & msg)
  : msg_(msg)
  {}
  ::edgevision_msgs::msg::TrackedDetectionArray detections(::edgevision_msgs::msg::TrackedDetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetectionArray msg_;
};

class Init_TrackedDetectionArray_header
{
public:
  Init_TrackedDetectionArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedDetectionArray_detections header(::edgevision_msgs::msg::TrackedDetectionArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrackedDetectionArray_detections(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::edgevision_msgs::msg::TrackedDetectionArray>()
{
  return edgevision_msgs::msg::builder::Init_TrackedDetectionArray_header();
}

}  // namespace edgevision_msgs

#endif  // EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__BUILDER_HPP_
