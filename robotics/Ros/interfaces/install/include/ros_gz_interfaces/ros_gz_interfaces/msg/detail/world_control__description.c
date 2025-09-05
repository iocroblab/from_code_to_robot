// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/WorldControl.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/world_control__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__WorldControl__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5a, 0xb5, 0xd5, 0x7c, 0x81, 0x96, 0x70, 0x08,
      0xa8, 0x69, 0x63, 0x6e, 0x53, 0x2e, 0xc8, 0xb8,
      0xa1, 0xaf, 0xb1, 0xa7, 0xdd, 0xb3, 0x8a, 0x38,
      0xe9, 0x20, 0x53, 0xd0, 0x32, 0xdd, 0x21, 0x45,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "ros_gz_interfaces/msg/detail/world_reset__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH = {1, {
    0x3c, 0x89, 0xa3, 0x85, 0x89, 0xdb, 0x6e, 0x49,
    0x3c, 0xc1, 0x32, 0xaa, 0x44, 0xb6, 0x9a, 0xc7,
    0xf4, 0x9c, 0x9f, 0xfc, 0x07, 0x70, 0xf5, 0x18,
    0x83, 0x50, 0x0d, 0xa1, 0xf5, 0xb4, 0x27, 0x5e,
  }};
#endif

static char ros_gz_interfaces__msg__WorldControl__TYPE_NAME[] = "ros_gz_interfaces/msg/WorldControl";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros_gz_interfaces__msg__WorldReset__TYPE_NAME[] = "ros_gz_interfaces/msg/WorldReset";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__pause[] = "pause";
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__step[] = "step";
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__multi_step[] = "multi_step";
static char ros_gz_interfaces__msg__WorldControl__DEFAULT_VALUE__multi_step[] = "0";
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__reset[] = "reset";
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__seed[] = "seed";
static char ros_gz_interfaces__msg__WorldControl__FIELD_NAME__run_to_sim_time[] = "run_to_sim_time";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__WorldControl__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__pause, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__step, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__multi_step, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__WorldControl__DEFAULT_VALUE__multi_step, 1, 1},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__reset, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__seed, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__FIELD_NAME__run_to_sim_time, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__WorldControl__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__WorldControl__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
      {ros_gz_interfaces__msg__WorldControl__FIELDS, 6, 6},
    },
    {ros_gz_interfaces__msg__WorldControl__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH, ros_gz_interfaces__msg__WorldReset__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros_gz_interfaces__msg__WorldReset__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool pause                                  # Paused state.\n"
  "bool step                                   #\n"
  "uint32 multi_step 0                         # Paused after stepping multi_step.\n"
  "ros_gz_interfaces/WorldReset reset         #\n"
  "uint32 seed                                 #\n"
  "builtin_interfaces/Time run_to_sim_time     # A simulation time in the future to run to and\n"
  "                                            # then pause.";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__WorldControl__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 427, 427},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__WorldControl__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__WorldControl__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
