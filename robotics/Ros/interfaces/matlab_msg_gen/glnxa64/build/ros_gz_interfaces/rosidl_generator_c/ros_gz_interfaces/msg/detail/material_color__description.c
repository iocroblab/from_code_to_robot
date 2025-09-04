// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/MaterialColor.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/material_color__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__MaterialColor__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x54, 0xb6, 0x5a, 0xf3, 0xb2, 0x12, 0xe1, 0x28,
      0x50, 0x32, 0x0f, 0xb8, 0x72, 0x0c, 0xd0, 0x67,
      0xcb, 0x74, 0xd9, 0x61, 0xca, 0xb8, 0x13, 0x91,
      0x8f, 0xa0, 0xc9, 0x46, 0x17, 0xdb, 0x39, 0x13,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "ros_gz_interfaces/msg/detail/entity__functions.h"
#include "std_msgs/msg/detail/color_rgba__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__Entity__EXPECTED_HASH = {1, {
    0x26, 0x6a, 0x26, 0xf3, 0x77, 0x05, 0x7e, 0xbb,
    0x0a, 0x1f, 0x08, 0xf7, 0xfb, 0x9d, 0xc4, 0x35,
    0xa8, 0x41, 0xd9, 0xec, 0x4f, 0xa3, 0xab, 0x8f,
    0xa0, 0x08, 0x5e, 0x66, 0xe6, 0x53, 0x50, 0x4e,
  }};
static const rosidl_type_hash_t std_msgs__msg__ColorRGBA__EXPECTED_HASH = {1, {
    0x77, 0xa7, 0xa5, 0xb9, 0xae, 0x47, 0x73, 0x06,
    0x09, 0x76, 0x65, 0x10, 0x6e, 0x04, 0x13, 0xba,
    0x74, 0x44, 0x02, 0x45, 0xb1, 0xf3, 0xd0, 0xc6,
    0xd6, 0x40, 0x5f, 0xe5, 0xc7, 0x81, 0x3f, 0xe8,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char ros_gz_interfaces__msg__MaterialColor__TYPE_NAME[] = "ros_gz_interfaces/msg/MaterialColor";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros_gz_interfaces__msg__Entity__TYPE_NAME[] = "ros_gz_interfaces/msg/Entity";
static char std_msgs__msg__ColorRGBA__TYPE_NAME[] = "std_msgs/msg/ColorRGBA";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__header[] = "header";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__entity[] = "entity";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__ambient[] = "ambient";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__diffuse[] = "diffuse";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__specular[] = "specular";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__emissive[] = "emissive";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__shininess[] = "shininess";
static char ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__entity_match[] = "entity_match";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__MaterialColor__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__entity, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__ambient, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ColorRGBA__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__diffuse, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ColorRGBA__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__specular, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ColorRGBA__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__emissive, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ColorRGBA__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__shininess, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__MaterialColor__FIELD_NAME__entity_match, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__MaterialColor__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ColorRGBA__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__MaterialColor__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__MaterialColor__TYPE_NAME, 35, 35},
      {ros_gz_interfaces__msg__MaterialColor__FIELDS, 8, 8},
    },
    {ros_gz_interfaces__msg__MaterialColor__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__Entity__EXPECTED_HASH, ros_gz_interfaces__msg__Entity__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros_gz_interfaces__msg__Entity__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ColorRGBA__EXPECTED_HASH, std_msgs__msg__ColorRGBA__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__ColorRGBA__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Entities that match to apply material color: constant definition\n"
  "uint8 FIRST     = 0\n"
  "uint8 ALL       = 1\n"
  "\n"
  "std_msgs/Header header            # Optional header data\n"
  "ros_gz_interfaces/Entity entity   # Entity to change material color\n"
  "std_msgs/ColorRGBA ambient        # Ambient color\n"
  "std_msgs/ColorRGBA diffuse        # Diffuse color\n"
  "std_msgs/ColorRGBA specular       # Specular color\n"
  "std_msgs/ColorRGBA emissive       # Emissive color\n"
  "float64 shininess                 # Specular exponent\n"
  "uint8 entity_match                # Entities that match to apply material color";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__MaterialColor__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__MaterialColor__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 569, 569},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__MaterialColor__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__MaterialColor__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__ColorRGBA__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
