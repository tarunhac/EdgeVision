// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from edgevision_msgs:msg/TrackedDetection.idl
// generated code does not contain a copyright notice
#include "edgevision_msgs/msg/detail/tracked_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "edgevision_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "edgevision_msgs/msg/detail/tracked_detection__struct.h"
#include "edgevision_msgs/msg/detail/tracked_detection__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // class_name, face_image, frame_image, name
#include "rosidl_runtime_c/string_functions.h"  // class_name, face_image, frame_image, name

// forward declare type support functions


using _TrackedDetection__ros_msg_type = edgevision_msgs__msg__TrackedDetection;

static bool _TrackedDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TrackedDetection__ros_msg_type * ros_message = static_cast<const _TrackedDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: track_id
  {
    cdr << ros_message->track_id;
  }

  // Field name: class_name
  {
    const rosidl_runtime_c__String * str = &ros_message->class_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: x1
  {
    cdr << ros_message->x1;
  }

  // Field name: y1
  {
    cdr << ros_message->y1;
  }

  // Field name: x2
  {
    cdr << ros_message->x2;
  }

  // Field name: y2
  {
    cdr << ros_message->y2;
  }

  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: similarity
  {
    cdr << ros_message->similarity;
  }

  // Field name: face_image
  {
    const rosidl_runtime_c__String * str = &ros_message->face_image;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: frame_image
  {
    const rosidl_runtime_c__String * str = &ros_message->frame_image;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _TrackedDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TrackedDetection__ros_msg_type * ros_message = static_cast<_TrackedDetection__ros_msg_type *>(untyped_ros_message);
  // Field name: track_id
  {
    cdr >> ros_message->track_id;
  }

  // Field name: class_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->class_name.data) {
      rosidl_runtime_c__String__init(&ros_message->class_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->class_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'class_name'\n");
      return false;
    }
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: x1
  {
    cdr >> ros_message->x1;
  }

  // Field name: y1
  {
    cdr >> ros_message->y1;
  }

  // Field name: x2
  {
    cdr >> ros_message->x2;
  }

  // Field name: y2
  {
    cdr >> ros_message->y2;
  }

  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: similarity
  {
    cdr >> ros_message->similarity;
  }

  // Field name: face_image
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->face_image.data) {
      rosidl_runtime_c__String__init(&ros_message->face_image);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->face_image,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'face_image'\n");
      return false;
    }
  }

  // Field name: frame_image
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->frame_image.data) {
      rosidl_runtime_c__String__init(&ros_message->frame_image);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->frame_image,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'frame_image'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_edgevision_msgs
size_t get_serialized_size_edgevision_msgs__msg__TrackedDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TrackedDetection__ros_msg_type * ros_message = static_cast<const _TrackedDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name track_id
  {
    size_t item_size = sizeof(ros_message->track_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name class_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->class_name.size + 1);
  // field.name confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x1
  {
    size_t item_size = sizeof(ros_message->x1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y1
  {
    size_t item_size = sizeof(ros_message->y1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x2
  {
    size_t item_size = sizeof(ros_message->x2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y2
  {
    size_t item_size = sizeof(ros_message->y2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name similarity
  {
    size_t item_size = sizeof(ros_message->similarity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name face_image
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->face_image.size + 1);
  // field.name frame_image
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->frame_image.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _TrackedDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_edgevision_msgs__msg__TrackedDetection(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_edgevision_msgs
size_t max_serialized_size_edgevision_msgs__msg__TrackedDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: track_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: class_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: confidence
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: similarity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: face_image
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: frame_image
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = edgevision_msgs__msg__TrackedDetection;
    is_plain =
      (
      offsetof(DataType, frame_image) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TrackedDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_edgevision_msgs__msg__TrackedDetection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TrackedDetection = {
  "edgevision_msgs::msg",
  "TrackedDetection",
  _TrackedDetection__cdr_serialize,
  _TrackedDetection__cdr_deserialize,
  _TrackedDetection__get_serialized_size,
  _TrackedDetection__max_serialized_size
};

static rosidl_message_type_support_t _TrackedDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TrackedDetection,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, edgevision_msgs, msg, TrackedDetection)() {
  return &_TrackedDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
