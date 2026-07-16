#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__Detection() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__Detection__init(msg: *mut Detection) -> bool;
    fn edgevision_msgs__msg__Detection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Detection>, size: usize) -> bool;
    fn edgevision_msgs__msg__Detection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Detection>);
    fn edgevision_msgs__msg__Detection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Detection>, out_seq: *mut rosidl_runtime_rs::Sequence<Detection>) -> bool;
}

// Corresponds to edgevision_msgs__msg__Detection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Detection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x2: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y2: i32,

}



impl Default for Detection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__Detection__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__Detection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Detection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__Detection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__Detection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__Detection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Detection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Detection where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/Detection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__Detection() }
  }
}


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__DetectionArray() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__DetectionArray__init(msg: *mut DetectionArray) -> bool;
    fn edgevision_msgs__msg__DetectionArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectionArray>, size: usize) -> bool;
    fn edgevision_msgs__msg__DetectionArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectionArray>);
    fn edgevision_msgs__msg__DetectionArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectionArray>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectionArray>) -> bool;
}

// Corresponds to edgevision_msgs__msg__DetectionArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectionArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Detection>,

}



impl Default for DetectionArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__DetectionArray__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__DetectionArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectionArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__DetectionArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__DetectionArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__DetectionArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectionArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectionArray where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/DetectionArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__DetectionArray() }
  }
}


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__TrackedDetection() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__TrackedDetection__init(msg: *mut TrackedDetection) -> bool;
    fn edgevision_msgs__msg__TrackedDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackedDetection>, size: usize) -> bool;
    fn edgevision_msgs__msg__TrackedDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackedDetection>);
    fn edgevision_msgs__msg__TrackedDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackedDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackedDetection>) -> bool;
}

// Corresponds to edgevision_msgs__msg__TrackedDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackedDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub track_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x2: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y2: i32,

}



impl Default for TrackedDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__TrackedDetection__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__TrackedDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackedDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackedDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackedDetection where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/TrackedDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__TrackedDetection() }
  }
}


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__TrackedDetectionArray() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__TrackedDetectionArray__init(msg: *mut TrackedDetectionArray) -> bool;
    fn edgevision_msgs__msg__TrackedDetectionArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackedDetectionArray>, size: usize) -> bool;
    fn edgevision_msgs__msg__TrackedDetectionArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackedDetectionArray>);
    fn edgevision_msgs__msg__TrackedDetectionArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackedDetectionArray>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackedDetectionArray>) -> bool;
}

// Corresponds to edgevision_msgs__msg__TrackedDetectionArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackedDetectionArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections: rosidl_runtime_rs::Sequence<super::super::msg::rmw::TrackedDetection>,

}



impl Default for TrackedDetectionArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__TrackedDetectionArray__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__TrackedDetectionArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackedDetectionArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetectionArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetectionArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__TrackedDetectionArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackedDetectionArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackedDetectionArray where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/TrackedDetectionArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__TrackedDetectionArray() }
  }
}


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__FaceDetection() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__FaceDetection__init(msg: *mut FaceDetection) -> bool;
    fn edgevision_msgs__msg__FaceDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FaceDetection>, size: usize) -> bool;
    fn edgevision_msgs__msg__FaceDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FaceDetection>);
    fn edgevision_msgs__msg__FaceDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FaceDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<FaceDetection>) -> bool;
}

// Corresponds to edgevision_msgs__msg__FaceDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaceDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub track_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub person_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_known: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x2: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y2: i32,

}



impl Default for FaceDetection {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__FaceDetection__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__FaceDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FaceDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FaceDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FaceDetection where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/FaceDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__FaceDetection() }
  }
}


#[link(name = "edgevision_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__FaceDetectionArray() -> *const std::ffi::c_void;
}

#[link(name = "edgevision_msgs__rosidl_generator_c")]
extern "C" {
    fn edgevision_msgs__msg__FaceDetectionArray__init(msg: *mut FaceDetectionArray) -> bool;
    fn edgevision_msgs__msg__FaceDetectionArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FaceDetectionArray>, size: usize) -> bool;
    fn edgevision_msgs__msg__FaceDetectionArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FaceDetectionArray>);
    fn edgevision_msgs__msg__FaceDetectionArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FaceDetectionArray>, out_seq: *mut rosidl_runtime_rs::Sequence<FaceDetectionArray>) -> bool;
}

// Corresponds to edgevision_msgs__msg__FaceDetectionArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaceDetectionArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detections: rosidl_runtime_rs::Sequence<super::super::msg::rmw::FaceDetection>,

}



impl Default for FaceDetectionArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !edgevision_msgs__msg__FaceDetectionArray__init(&mut msg as *mut _) {
        panic!("Call to edgevision_msgs__msg__FaceDetectionArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FaceDetectionArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetectionArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetectionArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { edgevision_msgs__msg__FaceDetectionArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FaceDetectionArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FaceDetectionArray where Self: Sized {
  const TYPE_NAME: &'static str = "edgevision_msgs/msg/FaceDetectionArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__edgevision_msgs__msg__FaceDetectionArray() }
  }
}


