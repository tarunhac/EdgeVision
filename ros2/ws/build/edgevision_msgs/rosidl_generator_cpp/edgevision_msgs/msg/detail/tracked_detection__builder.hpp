// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from edgevision_msgs:msg/TrackedDetection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__BUILDER_HPP_
#define EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "edgevision_msgs/msg/detail/tracked_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace edgevision_msgs
{

namespace msg
{

namespace builder
{

class Init_TrackedDetection_y2
{
public:
  explicit Init_TrackedDetection_y2(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  ::edgevision_msgs::msg::TrackedDetection y2(::edgevision_msgs::msg::TrackedDetection::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_x2
{
public:
  explicit Init_TrackedDetection_x2(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  Init_TrackedDetection_y2 x2(::edgevision_msgs::msg::TrackedDetection::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_TrackedDetection_y2(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_y1
{
public:
  explicit Init_TrackedDetection_y1(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  Init_TrackedDetection_x2 y1(::edgevision_msgs::msg::TrackedDetection::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_TrackedDetection_x2(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_x1
{
public:
  explicit Init_TrackedDetection_x1(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  Init_TrackedDetection_y1 x1(::edgevision_msgs::msg::TrackedDetection::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_TrackedDetection_y1(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_confidence
{
public:
  explicit Init_TrackedDetection_confidence(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  Init_TrackedDetection_x1 confidence(::edgevision_msgs::msg::TrackedDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TrackedDetection_x1(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_class_name
{
public:
  explicit Init_TrackedDetection_class_name(::edgevision_msgs::msg::TrackedDetection & msg)
  : msg_(msg)
  {}
  Init_TrackedDetection_confidence class_name(::edgevision_msgs::msg::TrackedDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_TrackedDetection_confidence(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

class Init_TrackedDetection_track_id
{
public:
  Init_TrackedDetection_track_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackedDetection_class_name track_id(::edgevision_msgs::msg::TrackedDetection::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return Init_TrackedDetection_class_name(msg_);
  }

private:
  ::edgevision_msgs::msg::TrackedDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::edgevision_msgs::msg::TrackedDetection>()
{
  return edgevision_msgs::msg::builder::Init_TrackedDetection_track_id();
}

}  // namespace edgevision_msgs

#endif  // EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__BUILDER_HPP_
