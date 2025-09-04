// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros_gz_interfaces:msg/WorldControl.idl
// generated code does not contain a copyright notice
#include "ros_gz_interfaces/msg/detail/world_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros_gz_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros_gz_interfaces/msg/detail/world_control__struct.h"
#include "ros_gz_interfaces/msg/detail/world_control__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // run_to_sim_time
#include "ros_gz_interfaces/msg/detail/world_reset__functions.h"  // reset

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_deserialize_builtin_interfaces__msg__Time(
  eprosima::fastcdr::Cdr & cdr,
  builtin_interfaces__msg__Time * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
bool cdr_serialize_key_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t get_serialized_size_key_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
size_t max_serialized_size_key_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ros_gz_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();

bool cdr_serialize_ros_gz_interfaces__msg__WorldReset(
  const ros_gz_interfaces__msg__WorldReset * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_ros_gz_interfaces__msg__WorldReset(
  eprosima::fastcdr::Cdr & cdr,
  ros_gz_interfaces__msg__WorldReset * ros_message);

size_t get_serialized_size_ros_gz_interfaces__msg__WorldReset(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_ros_gz_interfaces__msg__WorldReset(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_ros_gz_interfaces__msg__WorldReset(
  const ros_gz_interfaces__msg__WorldReset * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_ros_gz_interfaces__msg__WorldReset(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_ros_gz_interfaces__msg__WorldReset(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_gz_interfaces, msg, WorldReset)();


using _WorldControl__ros_msg_type = ros_gz_interfaces__msg__WorldControl;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_serialize_ros_gz_interfaces__msg__WorldControl(
  const ros_gz_interfaces__msg__WorldControl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pause
  {
    cdr << (ros_message->pause ? true : false);
  }

  // Field name: step
  {
    cdr << (ros_message->step ? true : false);
  }

  // Field name: multi_step
  {
    cdr << ros_message->multi_step;
  }

  // Field name: reset
  {
    cdr_serialize_ros_gz_interfaces__msg__WorldReset(
      &ros_message->reset, cdr);
  }

  // Field name: seed
  {
    cdr << ros_message->seed;
  }

  // Field name: run_to_sim_time
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->run_to_sim_time, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_deserialize_ros_gz_interfaces__msg__WorldControl(
  eprosima::fastcdr::Cdr & cdr,
  ros_gz_interfaces__msg__WorldControl * ros_message)
{
  // Field name: pause
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->pause = tmp ? true : false;
  }

  // Field name: step
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->step = tmp ? true : false;
  }

  // Field name: multi_step
  {
    cdr >> ros_message->multi_step;
  }

  // Field name: reset
  {
    cdr_deserialize_ros_gz_interfaces__msg__WorldReset(cdr, &ros_message->reset);
  }

  // Field name: seed
  {
    cdr >> ros_message->seed;
  }

  // Field name: run_to_sim_time
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->run_to_sim_time);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t get_serialized_size_ros_gz_interfaces__msg__WorldControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorldControl__ros_msg_type * ros_message = static_cast<const _WorldControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pause
  {
    size_t item_size = sizeof(ros_message->pause);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: step
  {
    size_t item_size = sizeof(ros_message->step);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: multi_step
  {
    size_t item_size = sizeof(ros_message->multi_step);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reset
  current_alignment += get_serialized_size_ros_gz_interfaces__msg__WorldReset(
    &(ros_message->reset), current_alignment);

  // Field name: seed
  {
    size_t item_size = sizeof(ros_message->seed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: run_to_sim_time
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->run_to_sim_time), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t max_serialized_size_ros_gz_interfaces__msg__WorldControl(
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

  // Field name: pause
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: step
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: multi_step
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: reset
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_ros_gz_interfaces__msg__WorldReset(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: seed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: run_to_sim_time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
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
    using DataType = ros_gz_interfaces__msg__WorldControl;
    is_plain =
      (
      offsetof(DataType, run_to_sim_time) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
bool cdr_serialize_key_ros_gz_interfaces__msg__WorldControl(
  const ros_gz_interfaces__msg__WorldControl * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: pause
  {
    cdr << (ros_message->pause ? true : false);
  }

  // Field name: step
  {
    cdr << (ros_message->step ? true : false);
  }

  // Field name: multi_step
  {
    cdr << ros_message->multi_step;
  }

  // Field name: reset
  {
    cdr_serialize_key_ros_gz_interfaces__msg__WorldReset(
      &ros_message->reset, cdr);
  }

  // Field name: seed
  {
    cdr << ros_message->seed;
  }

  // Field name: run_to_sim_time
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->run_to_sim_time, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t get_serialized_size_key_ros_gz_interfaces__msg__WorldControl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorldControl__ros_msg_type * ros_message = static_cast<const _WorldControl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: pause
  {
    size_t item_size = sizeof(ros_message->pause);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: step
  {
    size_t item_size = sizeof(ros_message->step);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: multi_step
  {
    size_t item_size = sizeof(ros_message->multi_step);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: reset
  current_alignment += get_serialized_size_key_ros_gz_interfaces__msg__WorldReset(
    &(ros_message->reset), current_alignment);

  // Field name: seed
  {
    size_t item_size = sizeof(ros_message->seed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: run_to_sim_time
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->run_to_sim_time), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_gz_interfaces
size_t max_serialized_size_key_ros_gz_interfaces__msg__WorldControl(
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
  // Field name: pause
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: step
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: multi_step
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: reset
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_ros_gz_interfaces__msg__WorldReset(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: seed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: run_to_sim_time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
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
    using DataType = ros_gz_interfaces__msg__WorldControl;
    is_plain =
      (
      offsetof(DataType, run_to_sim_time) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _WorldControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ros_gz_interfaces__msg__WorldControl * ros_message = static_cast<const ros_gz_interfaces__msg__WorldControl *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ros_gz_interfaces__msg__WorldControl(ros_message, cdr);
}

static bool _WorldControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ros_gz_interfaces__msg__WorldControl * ros_message = static_cast<ros_gz_interfaces__msg__WorldControl *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ros_gz_interfaces__msg__WorldControl(cdr, ros_message);
}

static uint32_t _WorldControl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros_gz_interfaces__msg__WorldControl(
      untyped_ros_message, 0));
}

static size_t _WorldControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros_gz_interfaces__msg__WorldControl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WorldControl = {
  "ros_gz_interfaces::msg",
  "WorldControl",
  _WorldControl__cdr_serialize,
  _WorldControl__cdr_deserialize,
  _WorldControl__get_serialized_size,
  _WorldControl__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _WorldControl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WorldControl,
  get_message_typesupport_handle_function,
  &ros_gz_interfaces__msg__WorldControl__get_type_hash,
  &ros_gz_interfaces__msg__WorldControl__get_type_description,
  &ros_gz_interfaces__msg__WorldControl__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_gz_interfaces, msg, WorldControl)() {
  return &_WorldControl__type_support;
}

#if defined(__cplusplus)
}
#endif
