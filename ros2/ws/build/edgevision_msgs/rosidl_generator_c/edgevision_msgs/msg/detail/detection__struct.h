// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from edgevision_msgs:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
#define EDGEVISION_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Detection in the package edgevision_msgs.
typedef struct edgevision_msgs__msg__Detection
{
  rosidl_runtime_c__String class_name;
  float confidence;
  int32_t x1;
  int32_t y1;
  int32_t x2;
  int32_t y2;
} edgevision_msgs__msg__Detection;

// Struct for a sequence of edgevision_msgs__msg__Detection.
typedef struct edgevision_msgs__msg__Detection__Sequence
{
  edgevision_msgs__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} edgevision_msgs__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EDGEVISION_MSGS__MSG__DETAIL__DETECTION__STRUCT_H_
