// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/Entity.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/entity__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__Entity__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x26, 0x6a, 0x26, 0xf3, 0x77, 0x05, 0x7e, 0xbb,
      0x0a, 0x1f, 0x08, 0xf7, 0xfb, 0x9d, 0xc4, 0x35,
      0xa8, 0x41, 0xd9, 0xec, 0x4f, 0xa3, 0xab, 0x8f,
      0xa0, 0x08, 0x5e, 0x66, 0xe6, 0x53, 0x50, 0x4e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ros_gz_interfaces__msg__Entity__TYPE_NAME[] = "ros_gz_interfaces/msg/Entity";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__Entity__FIELD_NAME__id[] = "id";
static char ros_gz_interfaces__msg__Entity__FIELD_NAME__name[] = "name";
static char ros_gz_interfaces__msg__Entity__FIELD_NAME__type[] = "type";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__Entity__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__Entity__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Entity__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Entity__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__Entity__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
      {ros_gz_interfaces__msg__Entity__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Entity type: constant definition\n"
  "uint8 NONE      = 0\n"
  "uint8 LIGHT     = 1\n"
  "uint8 MODEL     = 2\n"
  "uint8 LINK      = 3\n"
  "uint8 VISUAL    = 4\n"
  "uint8 COLLISION = 5\n"
  "uint8 SENSOR    = 6\n"
  "uint8 JOINT     = 7\n"
  "\n"
  "uint64 id      # Entity unique identifier across all types. Defaults to 0\n"
  "string name    # Entity name, which is not guaranteed to be unique.\n"
  "uint8 type     # Entity type.";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__Entity__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 368, 368},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__Entity__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
