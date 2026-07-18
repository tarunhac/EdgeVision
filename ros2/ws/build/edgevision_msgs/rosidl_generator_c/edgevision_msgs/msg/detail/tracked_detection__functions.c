// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from edgevision_msgs:msg/TrackedDetection.idl
// generated code does not contain a copyright notice
#include "edgevision_msgs/msg/detail/tracked_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_name`
// Member `name`
// Member `face_image`
// Member `frame_image`
#include "rosidl_runtime_c/string_functions.h"

bool
edgevision_msgs__msg__TrackedDetection__init(edgevision_msgs__msg__TrackedDetection * msg)
{
  if (!msg) {
    return false;
  }
  // track_id
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    edgevision_msgs__msg__TrackedDetection__fini(msg);
    return false;
  }
  // confidence
  // x1
  // y1
  // x2
  // y2
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    edgevision_msgs__msg__TrackedDetection__fini(msg);
    return false;
  }
  // similarity
  // face_image
  if (!rosidl_runtime_c__String__init(&msg->face_image)) {
    edgevision_msgs__msg__TrackedDetection__fini(msg);
    return false;
  }
  // frame_image
  if (!rosidl_runtime_c__String__init(&msg->frame_image)) {
    edgevision_msgs__msg__TrackedDetection__fini(msg);
    return false;
  }
  return true;
}

void
edgevision_msgs__msg__TrackedDetection__fini(edgevision_msgs__msg__TrackedDetection * msg)
{
  if (!msg) {
    return;
  }
  // track_id
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // confidence
  // x1
  // y1
  // x2
  // y2
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // similarity
  // face_image
  rosidl_runtime_c__String__fini(&msg->face_image);
  // frame_image
  rosidl_runtime_c__String__fini(&msg->frame_image);
}

bool
edgevision_msgs__msg__TrackedDetection__are_equal(const edgevision_msgs__msg__TrackedDetection * lhs, const edgevision_msgs__msg__TrackedDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // track_id
  if (lhs->track_id != rhs->track_id) {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // similarity
  if (lhs->similarity != rhs->similarity) {
    return false;
  }
  // face_image
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->face_image), &(rhs->face_image)))
  {
    return false;
  }
  // frame_image
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_image), &(rhs->frame_image)))
  {
    return false;
  }
  return true;
}

bool
edgevision_msgs__msg__TrackedDetection__copy(
  const edgevision_msgs__msg__TrackedDetection * input,
  edgevision_msgs__msg__TrackedDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // track_id
  output->track_id = input->track_id;
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // similarity
  output->similarity = input->similarity;
  // face_image
  if (!rosidl_runtime_c__String__copy(
      &(input->face_image), &(output->face_image)))
  {
    return false;
  }
  // frame_image
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_image), &(output->frame_image)))
  {
    return false;
  }
  return true;
}

edgevision_msgs__msg__TrackedDetection *
edgevision_msgs__msg__TrackedDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__TrackedDetection * msg = (edgevision_msgs__msg__TrackedDetection *)allocator.allocate(sizeof(edgevision_msgs__msg__TrackedDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(edgevision_msgs__msg__TrackedDetection));
  bool success = edgevision_msgs__msg__TrackedDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
edgevision_msgs__msg__TrackedDetection__destroy(edgevision_msgs__msg__TrackedDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    edgevision_msgs__msg__TrackedDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
edgevision_msgs__msg__TrackedDetection__Sequence__init(edgevision_msgs__msg__TrackedDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__TrackedDetection * data = NULL;

  if (size) {
    data = (edgevision_msgs__msg__TrackedDetection *)allocator.zero_allocate(size, sizeof(edgevision_msgs__msg__TrackedDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = edgevision_msgs__msg__TrackedDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        edgevision_msgs__msg__TrackedDetection__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
edgevision_msgs__msg__TrackedDetection__Sequence__fini(edgevision_msgs__msg__TrackedDetection__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      edgevision_msgs__msg__TrackedDetection__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

edgevision_msgs__msg__TrackedDetection__Sequence *
edgevision_msgs__msg__TrackedDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__TrackedDetection__Sequence * array = (edgevision_msgs__msg__TrackedDetection__Sequence *)allocator.allocate(sizeof(edgevision_msgs__msg__TrackedDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = edgevision_msgs__msg__TrackedDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
edgevision_msgs__msg__TrackedDetection__Sequence__destroy(edgevision_msgs__msg__TrackedDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    edgevision_msgs__msg__TrackedDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
edgevision_msgs__msg__TrackedDetection__Sequence__are_equal(const edgevision_msgs__msg__TrackedDetection__Sequence * lhs, const edgevision_msgs__msg__TrackedDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!edgevision_msgs__msg__TrackedDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
edgevision_msgs__msg__TrackedDetection__Sequence__copy(
  const edgevision_msgs__msg__TrackedDetection__Sequence * input,
  edgevision_msgs__msg__TrackedDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(edgevision_msgs__msg__TrackedDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    edgevision_msgs__msg__TrackedDetection * data =
      (edgevision_msgs__msg__TrackedDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!edgevision_msgs__msg__TrackedDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          edgevision_msgs__msg__TrackedDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!edgevision_msgs__msg__TrackedDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
