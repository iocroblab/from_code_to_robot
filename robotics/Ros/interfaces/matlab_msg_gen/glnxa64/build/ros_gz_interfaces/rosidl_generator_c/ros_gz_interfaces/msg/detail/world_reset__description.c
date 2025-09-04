// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/WorldReset.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/world_reset__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__WorldReset__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3c, 0x89, 0xa3, 0x85, 0x89, 0xdb, 0x6e, 0x49,
      0x3c, 0xc1, 0x32, 0xaa, 0x44, 0xb6, 0x9a, 0xc7,
      0xf4, 0x9c, 0x9f, 0xfc, 0x07, 0x70, 0xf5, 0x18,
      0x83, 0x50, 0x0d, 0xa1, 0xf5, 0xb4, 0x27, 0x5e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ros_gz_interfaces__msg__WorldReset__TYPE_NAME[] = "ros_gz_interfaces/msg/WorldReset";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__WorldReset__FIELD_NAME__all[] = "all";
static char ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__all[] = "False";
static char ros_gz_interfaces__msg__WorldReset__FIELD_NAME__time_only[] = "time_only";
static char ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__time_only[] = "False";
static char ros_gz_interfaces__msg__WorldReset__FIELD_NAME__model_only[] = "model_only";
static char ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__model_only[] = "False";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__WorldReset__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__WorldReset__FIELD_NAME__all, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__all, 5, 5},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__FIELD_NAME__time_only, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__time_only, 5, 5},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__FIELD_NAME__model_only, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__WorldReset__DEFAULT_VALUE__model_only, 5, 5},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__WorldReset__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
      {ros_gz_interfaces__msg__WorldReset__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool all false            # Reset time and model\n"
  "bool time_only false      # Reset time only\n"
  "bool model_only false     # Reset model only";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 138, 138},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__WorldReset__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
