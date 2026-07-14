// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from edgevision_msgs:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
#define EDGEVISION_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detections'
#include "edgevision_msgs/msg/detail/detection__struct.h"

/// Struct defined in msg/DetectionArray in the package edgevision_msgs.
typedef struct edgevision_msgs__msg__DetectionArray
{
  std_msgs__msg__Header header;
  edgevision_msgs__msg__Detection__Sequence detections;
} edgevision_msgs__msg__DetectionArray;

// Struct for a sequence of edgevision_msgs__msg__DetectionArray.
typedef struct edgevision_msgs__msg__DetectionArray__Sequence
{
  edgevision_msgs__msg__DetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} edgevision_msgs__msg__DetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EDGEVISION_MSGS__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
