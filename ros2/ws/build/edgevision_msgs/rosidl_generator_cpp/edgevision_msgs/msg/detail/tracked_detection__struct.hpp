// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from edgevision_msgs:msg/TrackedDetection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__STRUCT_HPP_
#define EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__edgevision_msgs__msg__TrackedDetection __attribute__((deprecated))
#else
# define DEPRECATED__edgevision_msgs__msg__TrackedDetection __declspec(deprecated)
#endif

namespace edgevision_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrackedDetection_
{
  using Type = TrackedDetection_<ContainerAllocator>;

  explicit TrackedDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->track_id = 0l;
      this->class_name = "";
      this->confidence = 0.0f;
      this->x1 = 0l;
      this->y1 = 0l;
      this->x2 = 0l;
      this->y2 = 0l;
      this->name = "";
      this->similarity = 0.0f;
    }
  }

  explicit TrackedDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc),
    name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->track_id = 0l;
      this->class_name = "";
      this->confidence = 0.0f;
      this->x1 = 0l;
      this->y1 = 0l;
      this->x2 = 0l;
      this->y2 = 0l;
      this->name = "";
      this->similarity = 0.0f;
    }
  }

  // field types and members
  using _track_id_type =
    int32_t;
  _track_id_type track_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _x1_type =
    int32_t;
  _x1_type x1;
  using _y1_type =
    int32_t;
  _y1_type y1;
  using _x2_type =
    int32_t;
  _x2_type x2;
  using _y2_type =
    int32_t;
  _y2_type y2;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _similarity_type =
    float;
  _similarity_type similarity;

  // setters for named parameter idiom
  Type & set__track_id(
    const int32_t & _arg)
  {
    this->track_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__x1(
    const int32_t & _arg)
  {
    this->x1 = _arg;
    return *this;
  }
  Type & set__y1(
    const int32_t & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__x2(
    const int32_t & _arg)
  {
    this->x2 = _arg;
    return *this;
  }
  Type & set__y2(
    const int32_t & _arg)
  {
    this->y2 = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__similarity(
    const float & _arg)
  {
    this->similarity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__edgevision_msgs__msg__TrackedDetection
    std::shared_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__edgevision_msgs__msg__TrackedDetection
    std::shared_ptr<edgevision_msgs::msg::TrackedDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackedDetection_ & other) const
  {
    if (this->track_id != other.track_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->x1 != other.x1) {
      return false;
    }
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->x2 != other.x2) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->similarity != other.similarity) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackedDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackedDetection_

// alias to use template instance with default allocator
using TrackedDetection =
  edgevision_msgs::msg::TrackedDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace edgevision_msgs

#endif  // EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__STRUCT_HPP_
