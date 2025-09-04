// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/Contact.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/contact__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__Contact__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xba, 0x5a, 0xcb, 0xac, 0x28, 0x0b, 0x86, 0x50,
      0xf9, 0xad, 0x7c, 0xaf, 0x99, 0x58, 0x88, 0xff,
      0x8a, 0xca, 0x86, 0x17, 0x42, 0xe0, 0x15, 0x9d,
      0x8d, 0x36, 0xef, 0xe8, 0x46, 0x0d, 0x0d, 0xb3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/wrench__functions.h"
#include "ros_gz_interfaces/msg/detail/entity__functions.h"
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "ros_gz_interfaces/msg/detail/joint_wrench__functions.h"
#include "std_msgs/msg/detail/u_int32__functions.h"
#include "std_msgs/msg/detail/string__functions.h"

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
static const rosidl_type_hash_t geometry_msgs__msg__Wrench__EXPECTED_HASH = {1, {
    0x01, 0x8e, 0x85, 0x19, 0xd5, 0x7c, 0x16, 0xad,
    0xbe, 0x97, 0xc9, 0xfe, 0x14, 0x60, 0xef, 0x21,
    0xfe, 0xc7, 0xe3, 0x1b, 0xc5, 0x41, 0xde, 0x3d,
    0x65, 0x3a, 0x35, 0x89, 0x56, 0x77, 0xce, 0x52,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__Entity__EXPECTED_HASH = {1, {
    0x26, 0x6a, 0x26, 0xf3, 0x77, 0x05, 0x7e, 0xbb,
    0x0a, 0x1f, 0x08, 0xf7, 0xfb, 0x9d, 0xc4, 0x35,
    0xa8, 0x41, 0xd9, 0xec, 0x4f, 0xa3, 0xab, 0x8f,
    0xa0, 0x08, 0x5e, 0x66, 0xe6, 0x53, 0x50, 0x4e,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__JointWrench__EXPECTED_HASH = {1, {
    0xaa, 0x50, 0x61, 0x0f, 0x0b, 0xc1, 0xa9, 0xf1,
    0xf4, 0x2a, 0x04, 0xe6, 0xd7, 0x6d, 0xa7, 0x29,
    0x96, 0x8d, 0x0f, 0x91, 0xb6, 0x2f, 0x48, 0xb2,
    0x04, 0x0c, 0x4d, 0xc8, 0x66, 0xc0, 0x26, 0x86,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t std_msgs__msg__String__EXPECTED_HASH = {1, {
    0xdf, 0x66, 0x8c, 0x74, 0x04, 0x82, 0xbb, 0xd4,
    0x8f, 0xb3, 0x9d, 0x76, 0xa7, 0x0d, 0xfd, 0x4b,
    0xd5, 0x9d, 0xb1, 0x28, 0x80, 0x21, 0x74, 0x35,
    0x03, 0x25, 0x9e, 0x94, 0x8f, 0x6b, 0x1a, 0x18,
  }};
static const rosidl_type_hash_t std_msgs__msg__UInt32__EXPECTED_HASH = {1, {
    0xa5, 0xc8, 0x74, 0x82, 0x9b, 0x75, 0x2b, 0xc5,
    0xfa, 0x19, 0x00, 0x24, 0xb0, 0xad, 0x76, 0xf5,
    0x78, 0xcc, 0x27, 0x82, 0x71, 0xe8, 0x55, 0xc7,
    0xd0, 0x2a, 0x81, 0x8b, 0x35, 0x16, 0xfb, 0x4a,
  }};
#endif

static char ros_gz_interfaces__msg__Contact__TYPE_NAME[] = "ros_gz_interfaces/msg/Contact";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char geometry_msgs__msg__Wrench__TYPE_NAME[] = "geometry_msgs/msg/Wrench";
static char ros_gz_interfaces__msg__Entity__TYPE_NAME[] = "ros_gz_interfaces/msg/Entity";
static char ros_gz_interfaces__msg__JointWrench__TYPE_NAME[] = "ros_gz_interfaces/msg/JointWrench";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char std_msgs__msg__String__TYPE_NAME[] = "std_msgs/msg/String";
static char std_msgs__msg__UInt32__TYPE_NAME[] = "std_msgs/msg/UInt32";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__collision1[] = "collision1";
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__collision2[] = "collision2";
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__positions[] = "positions";
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__normals[] = "normals";
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__depths[] = "depths";
static char ros_gz_interfaces__msg__Contact__FIELD_NAME__wrenches[] = "wrenches";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__Contact__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__collision1, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__collision2, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__positions, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__normals, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__depths, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Contact__FIELD_NAME__wrenches, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {ros_gz_interfaces__msg__JointWrench__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__Contact__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Wrench__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__JointWrench__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__String__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__UInt32__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__Contact__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__Contact__TYPE_NAME, 29, 29},
      {ros_gz_interfaces__msg__Contact__FIELDS, 6, 6},
    },
    {ros_gz_interfaces__msg__Contact__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Wrench__EXPECTED_HASH, geometry_msgs__msg__Wrench__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Wrench__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__Entity__EXPECTED_HASH, ros_gz_interfaces__msg__Entity__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = ros_gz_interfaces__msg__Entity__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__JointWrench__EXPECTED_HASH, ros_gz_interfaces__msg__JointWrench__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = ros_gz_interfaces__msg__JointWrench__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__String__EXPECTED_HASH, std_msgs__msg__String__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__String__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__UInt32__EXPECTED_HASH, std_msgs__msg__UInt32__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__UInt32__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "ros_gz_interfaces/Entity collision1        # Contact collision1\n"
  "ros_gz_interfaces/Entity collision2        # Contact collision2\n"
  "geometry_msgs/Vector3[] positions           # List of contact position\n"
  "geometry_msgs/Vector3[] normals             # List of contact normals\n"
  "float64[] depths                            # List of penetration depths\n"
  "ros_gz_interfaces/JointWrench[] wrenches   # List of joint wrenches including forces/torques";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__Contact__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__Contact__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 435, 435},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__Contact__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__Contact__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Wrench__get_individual_type_description_source(NULL);
    sources[4] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL);
    sources[5] = *ros_gz_interfaces__msg__JointWrench__get_individual_type_description_source(NULL);
    sources[6] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__String__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__UInt32__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
