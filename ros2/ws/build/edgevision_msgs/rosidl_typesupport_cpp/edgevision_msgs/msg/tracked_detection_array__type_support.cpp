// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from edgevision_msgs:msg/TrackedDetectionArray.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "edgevision_msgs/msg/detail/tracked_detection_array__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace edgevision_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _TrackedDetectionArray_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrackedDetectionArray_type_support_ids_t;

static const _TrackedDetectionArray_type_support_ids_t _TrackedDetectionArray_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TrackedDetectionArray_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrackedDetectionArray_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrackedDetectionArray_type_support_symbol_names_t _TrackedDetectionArray_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, edgevision_msgs, msg, TrackedDetectionArray)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, edgevision_msgs, msg, TrackedDetectionArray)),
  }
};

typedef struct _TrackedDetectionArray_type_support_data_t
{
  void * data[2];
} _TrackedDetectionArray_type_support_data_t;

static _TrackedDetectionArray_type_support_data_t _TrackedDetectionArray_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrackedDetectionArray_message_typesupport_map = {
  2,
  "edgevision_msgs",
  &_TrackedDetectionArray_message_typesupport_ids.typesupport_identifier[0],
  &_TrackedDetectionArray_message_typesupport_symbol_names.symbol_name[0],
  &_TrackedDetectionArray_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TrackedDetectionArray_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrackedDetectionArray_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace edgevision_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<edgevision_msgs::msg::TrackedDetectionArray>()
{
  return &::edgevision_msgs::msg::rosidl_typesupport_cpp::TrackedDetectionArray_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, edgevision_msgs, msg, TrackedDetectionArray)() {
  return get_message_type_support_handle<edgevision_msgs::msg::TrackedDetectionArray>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
