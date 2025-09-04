// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/TrackVisual.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/track_visual__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__TrackVisual__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xae, 0x5d, 0x68, 0xf1, 0x13, 0xb3, 0x52, 0x56,
      0xf3, 0x96, 0x20, 0x45, 0x8d, 0x80, 0xe6, 0x31,
      0x50, 0x9b, 0xd7, 0x1a, 0xc6, 0x6f, 0xc0, 0xd5,
      0xa6, 0x2b, 0x75, 0x4a, 0xf2, 0x3a, 0xe2, 0xa3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char ros_gz_interfaces__msg__TrackVisual__TYPE_NAME[] = "ros_gz_interfaces/msg/TrackVisual";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__header[] = "header";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__name[] = "name";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__id[] = "id";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__inherit_orientation[] = "inherit_orientation";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__min_dist[] = "min_dist";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__max_dist[] = "max_dist";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__is_static[] = "is_static";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__use_model_frame[] = "use_model_frame";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__xyz[] = "xyz";
static char ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__inherit_yaw[] = "inherit_yaw";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__TrackVisual__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__inherit_orientation, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__min_dist, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__max_dist, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__is_static, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__use_model_frame, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__xyz, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__TrackVisual__FIELD_NAME__inherit_yaw, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__TrackVisual__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__TrackVisual__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__TrackVisual__TYPE_NAME, 33, 33},
      {ros_gz_interfaces__msg__TrackVisual__FIELDS, 10, 10},
    },
    {ros_gz_interfaces__msg__TrackVisual__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Message for a tracking a rendering::Visual with a rendering::Camera.\n"
  "\n"
  "# Optional header data.\n"
  "std_msgs/Header header\n"
  "\n"
  "# Name of the visual to track.\n"
  "string name\n"
  "\n"
  "# Id of the visual to track.\n"
  "uint32 id\n"
  "\n"
  "# True to have the tracking camera inherit the orientation of\n"
  "# the tracked visual.\n"
  "bool inherit_orientation\n"
  "\n"
  "# Minimum follow distance.\n"
  "float64 min_dist\n"
  "\n"
  "# Maximum follow distance.\n"
  "float64 max_dist\n"
  "\n"
  "# If set to true, the position of the camera is fixed.\n"
  "bool is_static\n"
  "\n"
  "# If set to true, the position of the camera is relative to the.\n"
  "# model reference frame.\n"
  "bool use_model_frame\n"
  "\n"
  "# Position of the camera.\n"
  "geometry_msgs/Vector3 xyz\n"
  "\n"
  "# If set to true, the camera inherits the yaw rotation of the model.\n"
  "bool inherit_yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__TrackVisual__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__TrackVisual__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 726, 726},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__TrackVisual__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__TrackVisual__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
