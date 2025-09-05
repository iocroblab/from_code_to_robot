// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/Float32Array.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/float32_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__Float32Array__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x81, 0x14, 0xdb, 0x06, 0x2e, 0x00, 0x37, 0x9e,
      0xb8, 0x05, 0x87, 0x9d, 0x94, 0x40, 0xd1, 0x0b,
      0xeb, 0x70, 0x00, 0x35, 0x2a, 0xd9, 0x2b, 0xdc,
      0x4e, 0x13, 0x85, 0xd9, 0x88, 0xbd, 0x6c, 0xd9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ros_gz_interfaces__msg__Float32Array__TYPE_NAME[] = "ros_gz_interfaces/msg/Float32Array";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__Float32Array__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__Float32Array__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__Float32Array__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__Float32Array__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__Float32Array__TYPE_NAME, 34, 34},
      {ros_gz_interfaces__msg__Float32Array__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32[] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__Float32Array__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__Float32Array__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 15, 15},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__Float32Array__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__Float32Array__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
