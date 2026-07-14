// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from edgevision_msgs:msg/TrackedDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__STRUCT_H_
#define EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__STRUCT_H_

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
#include "edgevision_msgs/msg/detail/tracked_detection__struct.h"

/// Struct defined in msg/TrackedDetectionArray in the package edgevision_msgs.
typedef struct edgevision_msgs__msg__TrackedDetectionArray
{
  std_msgs__msg__Header header;
  edgevision_msgs__msg__TrackedDetection__Sequence detections;
} edgevision_msgs__msg__TrackedDetectionArray;

// Struct for a sequence of edgevision_msgs__msg__TrackedDetectionArray.
typedef struct edgevision_msgs__msg__TrackedDetectionArray__Sequence
{
  edgevision_msgs__msg__TrackedDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} edgevision_msgs__msg__TrackedDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION_ARRAY__STRUCT_H_
