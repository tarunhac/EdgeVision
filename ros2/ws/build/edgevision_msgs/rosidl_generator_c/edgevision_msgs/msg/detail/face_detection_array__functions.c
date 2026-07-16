// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from edgevision_msgs:msg/FaceDetectionArray.idl
// generated code does not contain a copyright notice
#include "edgevision_msgs/msg/detail/face_detection_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detections`
#include "edgevision_msgs/msg/detail/face_detection__functions.h"

bool
edgevision_msgs__msg__FaceDetectionArray__init(edgevision_msgs__msg__FaceDetectionArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    edgevision_msgs__msg__FaceDetectionArray__fini(msg);
    return false;
  }
  // detections
  if (!edgevision_msgs__msg__FaceDetection__Sequence__init(&msg->detections, 0)) {
    edgevision_msgs__msg__FaceDetectionArray__fini(msg);
    return false;
  }
  return true;
}

void
edgevision_msgs__msg__FaceDetectionArray__fini(edgevision_msgs__msg__FaceDetectionArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // detections
  edgevision_msgs__msg__FaceDetection__Sequence__fini(&msg->detections);
}

bool
edgevision_msgs__msg__FaceDetectionArray__are_equal(const edgevision_msgs__msg__FaceDetectionArray * lhs, const edgevision_msgs__msg__FaceDetectionArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // detections
  if (!edgevision_msgs__msg__FaceDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
edgevision_msgs__msg__FaceDetectionArray__copy(
  const edgevision_msgs__msg__FaceDetectionArray * input,
  edgevision_msgs__msg__FaceDetectionArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // detections
  if (!edgevision_msgs__msg__FaceDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

edgevision_msgs__msg__FaceDetectionArray *
edgevision_msgs__msg__FaceDetectionArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetectionArray * msg = (edgevision_msgs__msg__FaceDetectionArray *)allocator.allocate(sizeof(edgevision_msgs__msg__FaceDetectionArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(edgevision_msgs__msg__FaceDetectionArray));
  bool success = edgevision_msgs__msg__FaceDetectionArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
edgevision_msgs__msg__FaceDetectionArray__destroy(edgevision_msgs__msg__FaceDetectionArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    edgevision_msgs__msg__FaceDetectionArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
edgevision_msgs__msg__FaceDetectionArray__Sequence__init(edgevision_msgs__msg__FaceDetectionArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetectionArray * data = NULL;

  if (size) {
    data = (edgevision_msgs__msg__FaceDetectionArray *)allocator.zero_allocate(size, sizeof(edgevision_msgs__msg__FaceDetectionArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = edgevision_msgs__msg__FaceDetectionArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        edgevision_msgs__msg__FaceDetectionArray__fini(&data[i - 1]);
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
edgevision_msgs__msg__FaceDetectionArray__Sequence__fini(edgevision_msgs__msg__FaceDetectionArray__Sequence * array)
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
      edgevision_msgs__msg__FaceDetectionArray__fini(&array->data[i]);
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

edgevision_msgs__msg__FaceDetectionArray__Sequence *
edgevision_msgs__msg__FaceDetectionArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  edgevision_msgs__msg__FaceDetectionArray__Sequence * array = (edgevision_msgs__msg__FaceDetectionArray__Sequence *)allocator.allocate(sizeof(edgevision_msgs__msg__FaceDetectionArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = edgevision_msgs__msg__FaceDetectionArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
edgevision_msgs__msg__FaceDetectionArray__Sequence__destroy(edgevision_msgs__msg__FaceDetectionArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    edgevision_msgs__msg__FaceDetectionArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
edgevision_msgs__msg__FaceDetectionArray__Sequence__are_equal(const edgevision_msgs__msg__FaceDetectionArray__Sequence * lhs, const edgevision_msgs__msg__FaceDetectionArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!edgevision_msgs__msg__FaceDetectionArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
edgevision_msgs__msg__FaceDetectionArray__Sequence__copy(
  const edgevision_msgs__msg__FaceDetectionArray__Sequence * input,
  edgevision_msgs__msg__FaceDetectionArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(edgevision_msgs__msg__FaceDetectionArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    edgevision_msgs__msg__FaceDetectionArray * data =
      (edgevision_msgs__msg__FaceDetectionArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!edgevision_msgs__msg__FaceDetectionArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          edgevision_msgs__msg__FaceDetectionArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!edgevision_msgs__msg__FaceDetectionArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
