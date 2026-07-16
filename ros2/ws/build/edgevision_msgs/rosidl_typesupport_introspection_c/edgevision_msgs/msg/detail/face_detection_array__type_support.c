// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from edgevision_msgs:msg/FaceDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "edgevision_msgs/msg/detail/face_detection_array__rosidl_typesupport_introspection_c.h"
#include "edgevision_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "edgevision_msgs/msg/detail/face_detection_array__functions.h"
#include "edgevision_msgs/msg/detail/face_detection_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "edgevision_msgs/msg/face_detection.h"
// Member `detections`
#include "edgevision_msgs/msg/detail/face_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  edgevision_msgs__msg__FaceDetectionArray__init(message_memory);
}

void edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_fini_function(void * message_memory)
{
  edgevision_msgs__msg__FaceDetectionArray__fini(message_memory);
}

size_t edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__size_function__FaceDetectionArray__detections(
  const void * untyped_member)
{
  const edgevision_msgs__msg__FaceDetection__Sequence * member =
    (const edgevision_msgs__msg__FaceDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_const_function__FaceDetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const edgevision_msgs__msg__FaceDetection__Sequence * member =
    (const edgevision_msgs__msg__FaceDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_function__FaceDetectionArray__detections(
  void * untyped_member, size_t index)
{
  edgevision_msgs__msg__FaceDetection__Sequence * member =
    (edgevision_msgs__msg__FaceDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__fetch_function__FaceDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const edgevision_msgs__msg__FaceDetection * item =
    ((const edgevision_msgs__msg__FaceDetection *)
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_const_function__FaceDetectionArray__detections(untyped_member, index));
  edgevision_msgs__msg__FaceDetection * value =
    (edgevision_msgs__msg__FaceDetection *)(untyped_value);
  *value = *item;
}

void edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__assign_function__FaceDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  edgevision_msgs__msg__FaceDetection * item =
    ((edgevision_msgs__msg__FaceDetection *)
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_function__FaceDetectionArray__detections(untyped_member, index));
  const edgevision_msgs__msg__FaceDetection * value =
    (const edgevision_msgs__msg__FaceDetection *)(untyped_value);
  *item = *value;
}

bool edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__resize_function__FaceDetectionArray__detections(
  void * untyped_member, size_t size)
{
  edgevision_msgs__msg__FaceDetection__Sequence * member =
    (edgevision_msgs__msg__FaceDetection__Sequence *)(untyped_member);
  edgevision_msgs__msg__FaceDetection__Sequence__fini(member);
  return edgevision_msgs__msg__FaceDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(edgevision_msgs__msg__FaceDetectionArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(edgevision_msgs__msg__FaceDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__size_function__FaceDetectionArray__detections,  // size() function pointer
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_const_function__FaceDetectionArray__detections,  // get_const(index) function pointer
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__get_function__FaceDetectionArray__detections,  // get(index) function pointer
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__fetch_function__FaceDetectionArray__detections,  // fetch(index, &value) function pointer
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__assign_function__FaceDetectionArray__detections,  // assign(index, value) function pointer
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__resize_function__FaceDetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_members = {
  "edgevision_msgs__msg",  // message namespace
  "FaceDetectionArray",  // message name
  2,  // number of fields
  sizeof(edgevision_msgs__msg__FaceDetectionArray),
  edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_member_array,  // message members
  edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_type_support_handle = {
  0,
  &edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_edgevision_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, edgevision_msgs, msg, FaceDetectionArray)() {
  edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, edgevision_msgs, msg, FaceDetection)();
  if (!edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_type_support_handle.typesupport_identifier) {
    edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &edgevision_msgs__msg__FaceDetectionArray__rosidl_typesupport_introspection_c__FaceDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
