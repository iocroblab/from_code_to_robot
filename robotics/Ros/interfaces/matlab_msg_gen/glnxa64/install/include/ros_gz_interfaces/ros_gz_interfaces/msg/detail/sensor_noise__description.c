// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:msg/SensorNoise.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/msg/detail/sensor_noise__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__msg__SensorNoise__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xca, 0xf7, 0x6d, 0xf5, 0xc8, 0x96, 0x0d, 0x6c,
      0x28, 0xeb, 0xf8, 0x31, 0x8d, 0xd7, 0x50, 0xd9,
      0x4e, 0x38, 0x71, 0xf2, 0xce, 0x15, 0xb0, 0x88,
      0xb5, 0xe9, 0xf6, 0xd9, 0x9a, 0x6c, 0xf0, 0x89,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char ros_gz_interfaces__msg__SensorNoise__TYPE_NAME[] = "ros_gz_interfaces/msg/SensorNoise";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__header[] = "header";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__type[] = "type";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__mean[] = "mean";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__stddev[] = "stddev";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__bias_mean[] = "bias_mean";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__bias_stddev[] = "bias_stddev";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__precision[] = "precision";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__dynamic_bias_stddev[] = "dynamic_bias_stddev";
static char ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__dynamic_bias_correlation_time[] = "dynamic_bias_correlation_time";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__msg__SensorNoise__FIELDS[] = {
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__mean, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__stddev, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__bias_mean, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__bias_stddev, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__precision, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__dynamic_bias_stddev, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__SensorNoise__FIELD_NAME__dynamic_bias_correlation_time, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__msg__SensorNoise__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__msg__SensorNoise__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__msg__SensorNoise__TYPE_NAME, 33, 33},
      {ros_gz_interfaces__msg__SensorNoise__FIELDS, 9, 9},
    },
    {ros_gz_interfaces__msg__SensorNoise__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# A message for specifying sensor noise.\n"
  "\n"
  "# Noise type\n"
  "uint8 NONE               = 0\n"
  "uint8 GAUSSIAN           = 2\n"
  "uint8 GAUSSIAN_QUANTIZED = 3\n"
  "\n"
  "# Optional header data.\n"
  "std_msgs/Header header\n"
  "\n"
  "# The type of noise\n"
  "uint8 type\n"
  "\n"
  "# Noise mean\n"
  "# Used by GAUSSIAN and GAUSSIAN_QUANTIZED\n"
  "float64 mean\n"
  "\n"
  "# Noise standard deviation\n"
  "# Used by GAUSSIAN and GAUSSIAN_QUANTIZED\n"
  "float64 stddev\n"
  "\n"
  "# Noise mean bias\n"
  "# Used by GAUSSIAN and GAUSSIAN_QUANTIZED\n"
  "float64 bias_mean\n"
  "\n"
  "# Noise standard deviation bias\n"
  "float64 bias_stddev\n"
  "\n"
  "# Noise precision\n"
  "# Used by GAUSSIAN_QUANTIZED\n"
  "float64 precision\n"
  "\n"
  "# For type \"gaussian*\", the standard deviation of the noise used to\n"
  "# drive a process to model slow variations in a sensor bias.\n"
  "float64 dynamic_bias_stddev\n"
  "\n"
  "# For type \"gaussian*\", the correlation time in seconds of the\n"
  "# noise used to drive a process to model slow variations in a sensor bias.\n"
  "# A typical value, when used, would be on the order of\n"
  "# 3600 seconds (1 hour).\n"
  "float64 dynamic_bias_correlation_time";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__msg__SensorNoise__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__msg__SensorNoise__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 989, 989},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__msg__SensorNoise__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__msg__SensorNoise__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
