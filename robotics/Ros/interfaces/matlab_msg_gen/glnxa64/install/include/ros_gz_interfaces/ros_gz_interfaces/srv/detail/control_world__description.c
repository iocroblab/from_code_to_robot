// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:srv/ControlWorld.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/srv/detail/control_world__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__ControlWorld__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x05, 0x7c, 0xd1, 0xcd, 0x69, 0xcc, 0xd1, 0x3a,
      0x18, 0xdd, 0x30, 0x45, 0x95, 0xe3, 0xcd, 0x31,
      0xd5, 0x7a, 0xf3, 0xbb, 0xb6, 0x91, 0x86, 0xc3,
      0xe2, 0x15, 0x77, 0xa6, 0xe5, 0xd5, 0xd2, 0x82,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__ControlWorld_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x96, 0x6e, 0x36, 0x12, 0x1a, 0xc7, 0x84, 0xa9,
      0xf0, 0xbb, 0xab, 0x68, 0x3a, 0x4b, 0xff, 0x9a,
      0x1d, 0x50, 0x26, 0x82, 0xd1, 0xe7, 0x81, 0xe4,
      0x38, 0x1b, 0x7d, 0x7b, 0x29, 0x69, 0x9c, 0x34,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__ControlWorld_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7e, 0x58, 0xbf, 0xf9, 0x9e, 0x11, 0xcf, 0x38,
      0x2a, 0xec, 0x95, 0xa1, 0x08, 0xff, 0x43, 0x09,
      0x7b, 0x81, 0x96, 0xa3, 0x74, 0x7c, 0x6f, 0xd8,
      0xe2, 0x48, 0x52, 0x45, 0xee, 0x1a, 0xee, 0xb8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__ControlWorld_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x86, 0x42, 0xc4, 0x48, 0xf2, 0xd9, 0xec, 0xdc,
      0xc6, 0xb1, 0x30, 0x16, 0xcf, 0x9d, 0xb3, 0xf7,
      0x4e, 0xbc, 0x53, 0xa9, 0x83, 0x68, 0x1d, 0xad,
      0xb5, 0x1f, 0x9e, 0xe5, 0xc8, 0xc3, 0x2b, 0x16,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "ros_gz_interfaces/msg/detail/world_control__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "ros_gz_interfaces/msg/detail/world_reset__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__WorldControl__EXPECTED_HASH = {1, {
    0x5a, 0xb5, 0xd5, 0x7c, 0x81, 0x96, 0x70, 0x08,
    0xa8, 0x69, 0x63, 0x6e, 0x53, 0x2e, 0xc8, 0xb8,
    0xa1, 0xaf, 0xb1, 0xa7, 0xdd, 0xb3, 0x8a, 0x38,
    0xe9, 0x20, 0x53, 0xd0, 0x32, 0xdd, 0x21, 0x45,
  }};
static const rosidl_type_hash_t ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH = {1, {
    0x3c, 0x89, 0xa3, 0x85, 0x89, 0xdb, 0x6e, 0x49,
    0x3c, 0xc1, 0x32, 0xaa, 0x44, 0xb6, 0x9a, 0xc7,
    0xf4, 0x9c, 0x9f, 0xfc, 0x07, 0x70, 0xf5, 0x18,
    0x83, 0x50, 0x0d, 0xa1, 0xf5, 0xb4, 0x27, 0x5e,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char ros_gz_interfaces__srv__ControlWorld__TYPE_NAME[] = "ros_gz_interfaces/srv/ControlWorld";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros_gz_interfaces__msg__WorldControl__TYPE_NAME[] = "ros_gz_interfaces/msg/WorldControl";
static char ros_gz_interfaces__msg__WorldReset__TYPE_NAME[] = "ros_gz_interfaces/msg/WorldReset";
static char ros_gz_interfaces__srv__ControlWorld_Event__TYPE_NAME[] = "ros_gz_interfaces/srv/ControlWorld_Event";
static char ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME[] = "ros_gz_interfaces/srv/ControlWorld_Request";
static char ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME[] = "ros_gz_interfaces/srv/ControlWorld_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__request_message[] = "request_message";
static char ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__response_message[] = "response_message";
static char ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__ControlWorld__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__ControlWorld_Event__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__ControlWorld__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Event__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__ControlWorld__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__ControlWorld__TYPE_NAME, 34, 34},
      {ros_gz_interfaces__srv__ControlWorld__FIELDS, 3, 3},
    },
    {ros_gz_interfaces__srv__ControlWorld__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldControl__EXPECTED_HASH, ros_gz_interfaces__msg__WorldControl__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros_gz_interfaces__msg__WorldControl__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH, ros_gz_interfaces__msg__WorldReset__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = ros_gz_interfaces__msg__WorldReset__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = ros_gz_interfaces__srv__ControlWorld_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = ros_gz_interfaces__srv__ControlWorld_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = ros_gz_interfaces__srv__ControlWorld_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__ControlWorld_Request__FIELD_NAME__world_control[] = "world_control";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__ControlWorld_Request__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__ControlWorld_Request__FIELD_NAME__world_control, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__ControlWorld_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__ControlWorld_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
      {ros_gz_interfaces__srv__ControlWorld_Request__FIELDS, 1, 1},
    },
    {ros_gz_interfaces__srv__ControlWorld_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldControl__EXPECTED_HASH, ros_gz_interfaces__msg__WorldControl__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros_gz_interfaces__msg__WorldControl__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH, ros_gz_interfaces__msg__WorldReset__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = ros_gz_interfaces__msg__WorldReset__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__ControlWorld_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__ControlWorld_Response__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__ControlWorld_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__ControlWorld_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
      {ros_gz_interfaces__srv__ControlWorld_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__info[] = "info";
static char ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__request[] = "request";
static char ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__ControlWorld_Event__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__ControlWorld_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldControl__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__msg__WorldReset__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__ControlWorld_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__ControlWorld_Event__TYPE_NAME, 40, 40},
      {ros_gz_interfaces__srv__ControlWorld_Event__FIELDS, 3, 3},
    },
    {ros_gz_interfaces__srv__ControlWorld_Event__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldControl__EXPECTED_HASH, ros_gz_interfaces__msg__WorldControl__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros_gz_interfaces__msg__WorldControl__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__WorldReset__EXPECTED_HASH, ros_gz_interfaces__msg__WorldReset__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = ros_gz_interfaces__msg__WorldReset__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = ros_gz_interfaces__srv__ControlWorld_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = ros_gz_interfaces__srv__ControlWorld_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "ros_gz_interfaces/WorldControl world_control  # Message to Control world in Gazebo Sim\n"
  "---\n"
  "bool success                                   # Return true if control is successful.";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__ControlWorld__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__ControlWorld__TYPE_NAME, 34, 34},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 178, 178},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__ControlWorld_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__ControlWorld_Request__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__ControlWorld_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__ControlWorld_Response__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__ControlWorld_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__ControlWorld_Event__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__ControlWorld__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__ControlWorld__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_gz_interfaces__msg__WorldControl__get_individual_type_description_source(NULL);
    sources[3] = *ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(NULL);
    sources[4] = *ros_gz_interfaces__srv__ControlWorld_Event__get_individual_type_description_source(NULL);
    sources[5] = *ros_gz_interfaces__srv__ControlWorld_Request__get_individual_type_description_source(NULL);
    sources[6] = *ros_gz_interfaces__srv__ControlWorld_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__ControlWorld_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__ControlWorld_Request__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_gz_interfaces__msg__WorldControl__get_individual_type_description_source(NULL);
    sources[3] = *ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__ControlWorld_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__ControlWorld_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__ControlWorld_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__ControlWorld_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros_gz_interfaces__msg__WorldControl__get_individual_type_description_source(NULL);
    sources[3] = *ros_gz_interfaces__msg__WorldReset__get_individual_type_description_source(NULL);
    sources[4] = *ros_gz_interfaces__srv__ControlWorld_Request__get_individual_type_description_source(NULL);
    sources[5] = *ros_gz_interfaces__srv__ControlWorld_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
