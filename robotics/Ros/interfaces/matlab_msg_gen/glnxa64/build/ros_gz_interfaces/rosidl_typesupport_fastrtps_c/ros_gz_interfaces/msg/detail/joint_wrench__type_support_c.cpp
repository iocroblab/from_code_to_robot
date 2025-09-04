// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros_gz_interfaces:msg/JointWrench.idl
// generated code does not contain a copyright notice
#include "ros_gz_interfaces/msg/detail/joint_wrench__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros_gz_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros_gz_interfaces/msg/detail/joint_wrench__struct.h"
#include "ros_gz_interfaces/msg/detail/joint_wrench__functions.h"
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

#include "geometry_msgs/msg/detail/wrench__functions.h"  // body_1_wrench, body_2_wrench
#include "std_msgs/msg/detail/header__functions.h"  // header
#include "std_msgs/msg/detail/string__functions.h"  // body_1_name, body_2_name
#include "std_msgs/msg/detail/u_int32__functions.h"  // body_1_id, body_2_id

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_geometry_msgs__msg__Wrench(
  const geometry_msgs__msg__Wrench * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_deserialize_geometry_msgs__msg__Wrench(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Wrench * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_geometry_msgs__msg__Wrench(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_geometry_msgs__msg__Wrench(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_key_geometry_msgs__msg__Wrench(
  const geometry_msgs__msg__Wrench * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_key_geometry_msgs__msg__Wrench(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_key_geometry_msgs__msg__Wrench(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Wrench)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_std_msgs__msg__String(
  const std_msgs__msg__String * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_deserialize_std_msgs__msg__String(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__String * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_std_msgs__msg__String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_key_std_msgs__msg__String(
  const std_msgs__msg__String * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_key_std_msgs__msg__String(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_key_std_msgs__msg__String(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, String)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_std_msgs__msg__UInt32(
  const std_msgs__msg__UInt32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_deserialize_std_msgs__msg__UInt32(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__UInt32 * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_std_msgs__msg__UInt32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_std_msgs__msg__UInt32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_key_std_msgs__msg__UInt32(
  const std_msgs__msg__UInt32 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_key_std_msgs__msg__UInt32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_key_std_msgs__msg__UInt32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, UInt32)();


using _JointWrench__ros_msg_type = ros_gz_interfaces__msg__JointWrench;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_serialize_ros_gz_interfaces__msg__JointWrench(
  const ros_gz_interfaces__msg__JointWrench * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: body_1_name
  {
    cdr_serialize_std_msgs__msg__String(
      &ros_message->body_1_name, cdr);
  }

  // Field name: body_1_id
  {
    cdr_serialize_std_msgs__msg__UInt32(
      &ros_message->body_1_id, cdr);
  }

  // Field name: body_2_name
  {
    cdr_serialize_std_msgs__msg__String(
      &ros_message->body_2_name, cdr);
  }

  // Field name: body_2_id
  {
    cdr_serialize_std_msgs__msg__UInt32(
      &ros_message->body_2_id, cdr);
  }

  // Field name: body_1_wrench
  {
    cdr_serialize_geometry_msgs__msg__Wrench(
      &ros_message->body_1_wrench, cdr);
  }

  // Field name: body_2_wrench
  {
    cdr_serialize_geometry_msgs__msg__Wrench(
      &ros_message->body_2_wrench, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_deserialize_ros_gz_interfaces__msg__JointWrench(
  eprosima::fastcdr::Cdr & cdr,
  ros_gz_interfaces__msg__JointWrench * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: body_1_name
  {
    cdr_deserialize_std_msgs__msg__String(cdr, &ros_message->body_1_name);
  }

  // Field name: body_1_id
  {
    cdr_deserialize_std_msgs__msg__UInt32(cdr, &ros_message->body_1_id);
  }

  // Field name: body_2_name
  {
    cdr_deserialize_std_msgs__msg__String(cdr, &ros_message->body_2_name);
  }

  // Field name: body_2_id
  {
    cdr_deserialize_std_msgs__msg__UInt32(cdr, &ros_message->body_2_id);
  }

  // Field name: body_1_wrench
  {
    cdr_deserialize_geometry_msgs__msg__Wrench(cdr, &ros_message->body_1_wrench);
  }

  // Field name: body_2_wrench
  {
    cdr_deserialize_geometry_msgs__msg__Wrench(cdr, &ros_message->body_2_wrench);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t get_serialized_size_ros_gz_interfaces__msg__JointWrench(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointWrench__ros_msg_type * ros_message = static_cast<const _JointWrench__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: body_1_name
  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->body_1_name), current_alignment);

  // Field name: body_1_id
  current_alignment += get_serialized_size_std_msgs__msg__UInt32(
    &(ros_message->body_1_id), current_alignment);

  // Field name: body_2_name
  current_alignment += get_serialized_size_std_msgs__msg__String(
    &(ros_message->body_2_name), current_alignment);

  // Field name: body_2_id
  current_alignment += get_serialized_size_std_msgs__msg__UInt32(
    &(ros_message->body_2_id), current_alignment);

  // Field name: body_1_wrench
  current_alignment += get_serialized_size_geometry_msgs__msg__Wrench(
    &(ros_message->body_1_wrench), current_alignment);

  // Field name: body_2_wrench
  current_alignment += get_serialized_size_geometry_msgs__msg__Wrench(
    &(ros_message->body_2_wrench), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t max_serialized_size_ros_gz_interfaces__msg__JointWrench(
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

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__UInt32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__UInt32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_wrench
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_wrench
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros_gz_interfaces__msg__JointWrench;
    is_plain =
      (
      offsetof(DataType, body_2_wrench) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_serialize_key_ros_gz_interfaces__msg__JointWrench(
  const ros_gz_interfaces__msg__JointWrench * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: body_1_name
  {
    cdr_serialize_key_std_msgs__msg__String(
      &ros_message->body_1_name, cdr);
  }

  // Field name: body_1_id
  {
    cdr_serialize_key_std_msgs__msg__UInt32(
      &ros_message->body_1_id, cdr);
  }

  // Field name: body_2_name
  {
    cdr_serialize_key_std_msgs__msg__String(
      &ros_message->body_2_name, cdr);
  }

  // Field name: body_2_id
  {
    cdr_serialize_key_std_msgs__msg__UInt32(
      &ros_message->body_2_id, cdr);
  }

  // Field name: body_1_wrench
  {
    cdr_serialize_key_geometry_msgs__msg__Wrench(
      &ros_message->body_1_wrench, cdr);
  }

  // Field name: body_2_wrench
  {
    cdr_serialize_key_geometry_msgs__msg__Wrench(
      &ros_message->body_2_wrench, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t get_serialized_size_key_ros_gz_interfaces__msg__JointWrench(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointWrench__ros_msg_type * ros_message = static_cast<const _JointWrench__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: body_1_name
  current_alignment += get_serialized_size_key_std_msgs__msg__String(
    &(ros_message->body_1_name), current_alignment);

  // Field name: body_1_id
  current_alignment += get_serialized_size_key_std_msgs__msg__UInt32(
    &(ros_message->body_1_id), current_alignment);

  // Field name: body_2_name
  current_alignment += get_serialized_size_key_std_msgs__msg__String(
    &(ros_message->body_2_name), current_alignment);

  // Field name: body_2_id
  current_alignment += get_serialized_size_key_std_msgs__msg__UInt32(
    &(ros_message->body_2_id), current_alignment);

  // Field name: body_1_wrench
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Wrench(
    &(ros_message->body_1_wrench), current_alignment);

  // Field name: body_2_wrench
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Wrench(
    &(ros_message->body_2_wrench), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t max_serialized_size_key_ros_gz_interfaces__msg__JointWrench(
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
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__UInt32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_name
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__String(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__UInt32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_1_wrench
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: body_2_wrench
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Wrench(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros_gz_interfaces__msg__JointWrench;
    is_plain =
      (
      offsetof(DataType, body_2_wrench) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _JointWrench__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ros_gz_interfaces__msg__JointWrench * ros_message = static_cast<const ros_gz_interfaces__msg__JointWrench *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ros_gz_interfaces__msg__JointWrench(ros_message, cdr);
}

static bool _JointWrench__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ros_gz_interfaces__msg__JointWrench * ros_message = static_cast<ros_gz_interfaces__msg__JointWrench *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ros_gz_interfaces__msg__JointWrench(cdr, ros_message);
}

static uint32_t _JointWrench__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros_gz_interfaces__msg__JointWrench(
      untyped_ros_message, 0));
}

static size_t _JointWrench__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros_gz_interfaces__msg__JointWrench(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_JointWrench = {
  "ros_gz_interfaces::msg",
  "JointWrench",
  _JointWrench__cdr_serialize,
  _JointWrench__cdr_deserialize,
  _JointWrench__get_serialized_size,
  _JointWrench__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _JointWrench__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JointWrench,
  get_message_typesupport_handle_function,
  &ros_gz_interfaces__msg__JointWrench__get_type_hash,
  &ros_gz_interfaces__msg__JointWrench__get_type_description,
  &ros_gz_interfaces__msg__JointWrench__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_gz_interfaces, msg, JointWrench)() {
  return &_JointWrench__type_support;
}

#if defined(__cplusplus)
}
#endif
