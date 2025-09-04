// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/EntityFactory.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/entity_factory__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__EntityFactory__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x30, 0xd0, 0x15, 0xe2, 0x6a, 0x60, 0xc3, 0x7f,
      0x44, 0xfc, 0xfb, 0x19, 0xb5, 0x2b, 0x27, 0x95,
      0x70, 0x20, 0x70, 0x5b, 0x0b, 0xa3, 0x14, 0xe6,
      0xca, 0x37, 0xa5, 0xe0, 0xd2, 0xf6, 0x09, 0x1d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
#endif

static char ros_gz_interfaces__msg__EntityFactory__TYPE_NAME[] = "ros_gz_interfaces/msg/EntityFactory";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__name[] = "name";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__allow_renaming[] = "allow_renaming";
static char ros_gz_interfaces__msg__EntityFactory__DEFAULT_VALUE__allow_renaming[] = "False";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__sdf[] = "sdf";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__sdf_filename[] = "sdf_filename";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__clone_name[] = "clone_name";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__pose[] = "pose";
static char ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__relative_to[] = "relative_to";
static char ros_gz_interfaces__msg__EntityFactory__DEFAULT_VALUE__relative_to[] = "world";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__EntityFactory__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__allow_renaming, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__EntityFactory__DEFAULT_VALUE__allow_renaming, 5, 5},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__sdf, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__sdf_filename, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__clone_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__pose, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__EntityFactory__FIELD_NAME__relative_to, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {ros_gz_interfaces__msg__EntityFactory__DEFAULT_VALUE__relative_to, 5, 5},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__EntityFactory__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__EntityFactory__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__EntityFactory__TYPE_NAME, 35, 35},
      {ros_gz_interfaces__msg__EntityFactory__FIELDS, 7, 7},
    },
    {ros_gz_interfaces__msg__EntityFactory__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name                             # New name for the entity, overrides the name on the SDF\n"
  "bool allow_renaming false               # Whether the server is allowed to rename the entity in case of\n"
  "                                        # overlap with existing entities.\n"
  "\n"
  "# Only one method is supported at a time (sdf,sdf_filename,clone_name)\n"
  "string sdf                              # SDF description in string format\n"
  "string sdf_filename                     # Full path to SDF file.\n"
  "string clone_name                       # Name of entity to clone\n"
  "\n"
  "geometry_msgs/Pose pose                 # Pose where the entity will be spawned in the world.\n"
  "string relative_to \"world\"              # Pose is defined relative to the frame of this entity.";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__EntityFactory__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__EntityFactory__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 744, 744},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__EntityFactory__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__EntityFactory__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
