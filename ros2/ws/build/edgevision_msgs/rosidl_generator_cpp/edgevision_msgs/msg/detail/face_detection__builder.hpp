// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from edgevision_msgs:msg/FaceDetection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__BUILDER_HPP_
#define EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "edgevision_msgs/msg/detail/face_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace edgevision_msgs
{

namespace msg
{

namespace builder
{

class Init_FaceDetection_y2
{
public:
  explicit Init_FaceDetection_y2(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  ::edgevision_msgs::msg::FaceDetection y2(::edgevision_msgs::msg::FaceDetection::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_x2
{
public:
  explicit Init_FaceDetection_x2(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_y2 x2(::edgevision_msgs::msg::FaceDetection::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_FaceDetection_y2(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_y1
{
public:
  explicit Init_FaceDetection_y1(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_x2 y1(::edgevision_msgs::msg::FaceDetection::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_FaceDetection_x2(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_x1
{
public:
  explicit Init_FaceDetection_x1(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_y1 x1(::edgevision_msgs::msg::FaceDetection::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_FaceDetection_y1(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_confidence
{
public:
  explicit Init_FaceDetection_confidence(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_x1 confidence(::edgevision_msgs::msg::FaceDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_FaceDetection_x1(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_is_known
{
public:
  explicit Init_FaceDetection_is_known(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_confidence is_known(::edgevision_msgs::msg::FaceDetection::_is_known_type arg)
  {
    msg_.is_known = std::move(arg);
    return Init_FaceDetection_confidence(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_person_name
{
public:
  explicit Init_FaceDetection_person_name(::edgevision_msgs::msg::FaceDetection & msg)
  : msg_(msg)
  {}
  Init_FaceDetection_is_known person_name(::edgevision_msgs::msg::FaceDetection::_person_name_type arg)
  {
    msg_.person_name = std::move(arg);
    return Init_FaceDetection_is_known(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

class Init_FaceDetection_track_id
{
public:
  Init_FaceDetection_track_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FaceDetection_person_name track_id(::edgevision_msgs::msg::FaceDetection::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return Init_FaceDetection_person_name(msg_);
  }

private:
  ::edgevision_msgs::msg::FaceDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::edgevision_msgs::msg::FaceDetection>()
{
  return edgevision_msgs::msg::builder::Init_FaceDetection_track_id();
}

}  // namespace edgevision_msgs

#endif  // EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__BUILDER_HPP_
