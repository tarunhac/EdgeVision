// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from edgevision_msgs:msg/TrackedDetection.idl
// generated code does not contain a copyright notice

#ifndef EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__FUNCTIONS_H_
#define EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "edgevision_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "edgevision_msgs/msg/detail/tracked_detection__struct.h"

/// Initialize msg/TrackedDetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * edgevision_msgs__msg__TrackedDetection
 * )) before or use
 * edgevision_msgs__msg__TrackedDetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__init(edgevision_msgs__msg__TrackedDetection * msg);

/// Finalize msg/TrackedDetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
void
edgevision_msgs__msg__TrackedDetection__fini(edgevision_msgs__msg__TrackedDetection * msg);

/// Create msg/TrackedDetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * edgevision_msgs__msg__TrackedDetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
edgevision_msgs__msg__TrackedDetection *
edgevision_msgs__msg__TrackedDetection__create();

/// Destroy msg/TrackedDetection message.
/**
 * It calls
 * edgevision_msgs__msg__TrackedDetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
void
edgevision_msgs__msg__TrackedDetection__destroy(edgevision_msgs__msg__TrackedDetection * msg);

/// Check for msg/TrackedDetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__are_equal(const edgevision_msgs__msg__TrackedDetection * lhs, const edgevision_msgs__msg__TrackedDetection * rhs);

/// Copy a msg/TrackedDetection message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__copy(
  const edgevision_msgs__msg__TrackedDetection * input,
  edgevision_msgs__msg__TrackedDetection * output);

/// Initialize array of msg/TrackedDetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * edgevision_msgs__msg__TrackedDetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__Sequence__init(edgevision_msgs__msg__TrackedDetection__Sequence * array, size_t size);

/// Finalize array of msg/TrackedDetection messages.
/**
 * It calls
 * edgevision_msgs__msg__TrackedDetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
void
edgevision_msgs__msg__TrackedDetection__Sequence__fini(edgevision_msgs__msg__TrackedDetection__Sequence * array);

/// Create array of msg/TrackedDetection messages.
/**
 * It allocates the memory for the array and calls
 * edgevision_msgs__msg__TrackedDetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
edgevision_msgs__msg__TrackedDetection__Sequence *
edgevision_msgs__msg__TrackedDetection__Sequence__create(size_t size);

/// Destroy array of msg/TrackedDetection messages.
/**
 * It calls
 * edgevision_msgs__msg__TrackedDetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
void
edgevision_msgs__msg__TrackedDetection__Sequence__destroy(edgevision_msgs__msg__TrackedDetection__Sequence * array);

/// Check for msg/TrackedDetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__Sequence__are_equal(const edgevision_msgs__msg__TrackedDetection__Sequence * lhs, const edgevision_msgs__msg__TrackedDetection__Sequence * rhs);

/// Copy an array of msg/TrackedDetection messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_edgevision_msgs
bool
edgevision_msgs__msg__TrackedDetection__Sequence__copy(
  const edgevision_msgs__msg__TrackedDetection__Sequence * input,
  edgevision_msgs__msg__TrackedDetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EDGEVISION_MSGS__MSG__DETAIL__TRACKED_DETECTION__FUNCTIONS_H_
