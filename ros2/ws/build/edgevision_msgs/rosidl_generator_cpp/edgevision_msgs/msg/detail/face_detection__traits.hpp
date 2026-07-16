// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from edgevision_msgs:msg/FaceDetection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__TRAITS_HPP_
#define EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "edgevision_msgs/msg/detail/face_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace edgevision_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FaceDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: track_id
  {
    out << "track_id: ";
    rosidl_generator_traits::value_to_yaml(msg.track_id, out);
    out << ", ";
  }

  // member: person_name
  {
    out << "person_name: ";
    rosidl_generator_traits::value_to_yaml(msg.person_name, out);
    out << ", ";
  }

  // member: is_known
  {
    out << "is_known: ";
    rosidl_generator_traits::value_to_yaml(msg.is_known, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: x2
  {
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FaceDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: track_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_id: ";
    rosidl_generator_traits::value_to_yaml(msg.track_id, out);
    out << "\n";
  }

  // member: person_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "person_name: ";
    rosidl_generator_traits::value_to_yaml(msg.person_name, out);
    out << "\n";
  }

  // member: is_known
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_known: ";
    rosidl_generator_traits::value_to_yaml(msg.is_known, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FaceDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace edgevision_msgs

namespace rosidl_generator_traits
{

[[deprecated("use edgevision_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const edgevision_msgs::msg::FaceDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  edgevision_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use edgevision_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const edgevision_msgs::msg::FaceDetection & msg)
{
  return edgevision_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<edgevision_msgs::msg::FaceDetection>()
{
  return "edgevision_msgs::msg::FaceDetection";
}

template<>
inline const char * name<edgevision_msgs::msg::FaceDetection>()
{
  return "edgevision_msgs/msg/FaceDetection";
}

template<>
struct has_fixed_size<edgevision_msgs::msg::FaceDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<edgevision_msgs::msg::FaceDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<edgevision_msgs::msg::FaceDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EDGEVISION_MSGS__MSG__DETAIL__FACE_DETECTION__TRAITS_HPP_
