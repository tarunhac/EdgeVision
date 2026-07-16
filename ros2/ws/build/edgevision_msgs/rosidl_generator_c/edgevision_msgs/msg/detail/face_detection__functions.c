// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from edgevision_msgs:msg/FaceDetection.idl
// generated code does not contain a copyright notice
#include "edgevision_msgs/msg/detail/face_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `person_name`
#include "rosidl_runtime_c/string_functions.h"

bool
edgevision_msgs__msg__FaceDetection__init(edgevision_msgs__msg__FaceDetection * msg)
{
  if (!msg) {
    return false;
  }
  // track_id
  // person_name
  if (!rosidl_runtime_c__String__init(&msg->person_name)) {
    edgevision_msgs__msg__FaceDetection__fini(msg);
    return false;
  }
  // is_known
  // confidence
  // x1
  // y1
  // x2
  // y2
  return true;
}

void
edgevision_msgs__msg__FaceDetection__fini(edgevision_msgs__msg__FaceDetection * msg)
{
  if (!msg) {
    return;
  }
  // track_id
  // person_name
  rosidl_runtime_c__String__fini(&msg->person_name);
  // is_known
  // confidence
  // x1
  // y1
  // x2
  // y2
}

bool
edgevision_msgs__msg__FaceDetection__are_equal(const edgevision_msgs__msg__FaceDetection * lhs, const edgevision_msgs__msg__FaceDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // track_id
  if (lhs->track_id != rhs->track_id) {
    return false;
  }
  // person_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->person_name), &(rhs->person_name)))
  {
    return false;
  }
  // is_known
  if (lhs->is_known != rhs->is_known) {
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
  return true;
}

bool
edgevision_msgs__msg__FaceDetection__copy(
  const edgevision_msgs__msg__FaceDetection * input,
  edgevision_msgs__msg__FaceDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // track_id
  output->track_id = input->track_id;
  // person_name
  if (!rosidl_runtime_c__String__copy(
      &(input->person_name), &(output->person_name)))
  {
    return false;
  }
  // is_known
  output->is_known = input->is_known;
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
  return true;
}

edgevision_msgs__msg__FaceDetection *
edgevision_msgs__msg__FaceDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetection * msg = (edgevision_msgs__msg__FaceDetection *)allocator.allocate(sizeof(edgevision_msgs__msg__FaceDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(edgevision_msgs__msg__FaceDetection));
  bool success = edgevision_msgs__msg__FaceDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
edgevision_msgs__msg__FaceDetection__destroy(edgevision_msgs__msg__FaceDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    edgevision_msgs__msg__FaceDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
edgevision_msgs__msg__FaceDetection__Sequence__init(edgevision_msgs__msg__FaceDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetection * data = NULL;

  if (size) {
    data = (edgevision_msgs__msg__FaceDetection *)allocator.zero_allocate(size, sizeof(edgevision_msgs__msg__FaceDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = edgevision_msgs__msg__FaceDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        edgevision_msgs__msg__FaceDetection__fini(&data[i - 1]);
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
edgevision_msgs__msg__FaceDetection__Sequence__fini(edgevision_msgs__msg__FaceDetection__Sequence * array)
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
      edgevision_msgs__msg__FaceDetection__fini(&array->data[i]);
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

edgevision_msgs__msg__FaceDetection__Sequence *
edgevision_msgs__msg__FaceDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetection__Sequence * array = (edgevision_msgs__msg__FaceDetection__Sequence *)allocator.allocate(sizeof(edgevision_msgs__msg__FaceDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = edgevision_msgs__msg__FaceDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
edgevision_msgs__msg__FaceDetection__Sequence__destroy(edgevision_msgs__msg__FaceDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    edgevision_msgs__msg__FaceDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
edgevision_msgs__msg__FaceDetection__Sequence__are_equal(const edgevision_msgs__msg__FaceDetection__Sequence * lhs, const edgevision_msgs__msg__FaceDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!edgevision_msgs__msg__FaceDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
edgevision_msgs__msg__FaceDetection__Sequence__copy(
  const edgevision_msgs__msg__FaceDetection__Sequence * input,
  edgevision_msgs__msg__FaceDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(edgevision_msgs__msg__FaceDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    edgevision_msgs__msg__FaceDetection * data =
      (edgevision_msgs__msg__FaceDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!edgevision_msgs__msg__FaceDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          edgevision_msgs__msg__FaceDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!edgevision_msgs__msg__FaceDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
