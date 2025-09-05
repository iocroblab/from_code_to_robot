// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros_gz_interfaces:srv/SetEntityPose.idl
// generated code does not contain a copyright notice

#include "ros_gz_interfaces/srv/detail/set_entity_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__SetEntityPose__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0xe4, 0xbc, 0x11, 0xc7, 0xe7, 0x95, 0x5e,
      0xc1, 0xb4, 0xea, 0x7f, 0x94, 0x56, 0xb4, 0x92,
      0x8b, 0x62, 0x9b, 0x12, 0x07, 0x1b, 0x91, 0x1d,
      0x48, 0x74, 0x5c, 0x07, 0x14, 0x83, 0x49, 0x8f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__SetEntityPose_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0x00, 0x33, 0xfa, 0xa9, 0x65, 0xd5, 0x1a,
      0xa4, 0xc0, 0xaf, 0xb2, 0xb6, 0x72, 0xd9, 0x64,
      0x67, 0x87, 0x39, 0x80, 0x81, 0xbb, 0xcd, 0xf5,
      0x11, 0xe4, 0x65, 0x8c, 0xe2, 0x32, 0x0a, 0x19,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__SetEntityPose_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0xef, 0xf2, 0x58, 0x7e, 0xa6, 0x3b, 0x93,
      0x26, 0x4a, 0x53, 0x09, 0xa8, 0x08, 0x88, 0xb0,
      0xe5, 0x36, 0x0d, 0x92, 0x78, 0x6e, 0x48, 0x62,
      0xe0, 0x26, 0xd1, 0x6d, 0xd0, 0x7e, 0xbe, 0xa0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_ros_gz_interfaces
const rosidl_type_hash_t *
ros_gz_interfaces__srv__SetEntityPose_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x65, 0x36, 0x7c, 0xb5, 0xd8, 0x43, 0x65, 0x69,
      0xb5, 0x3d, 0x89, 0xef, 0x8f, 0x0f, 0x00, 0x01,
      0xcf, 0x47, 0xc0, 0xc8, 0xeb, 0x27, 0x52, 0xed,
      0x58, 0xb6, 0xcb, 0xe9, 0xf5, 0x57, 0x94, 0x6a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "ros_gz_interfaces/msg/detail/entity__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
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
static const rosidl_type_hash_t ros_gz_interfaces__msg__Entity__EXPECTED_HASH = {1, {
    0x26, 0x6a, 0x26, 0xf3, 0x77, 0x05, 0x7e, 0xbb,
    0x0a, 0x1f, 0x08, 0xf7, 0xfb, 0x9d, 0xc4, 0x35,
    0xa8, 0x41, 0xd9, 0xec, 0x4f, 0xa3, 0xab, 0x8f,
    0xa0, 0x08, 0x5e, 0x66, 0xe6, 0x53, 0x50, 0x4e,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char ros_gz_interfaces__srv__SetEntityPose__TYPE_NAME[] = "ros_gz_interfaces/srv/SetEntityPose";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char ros_gz_interfaces__msg__Entity__TYPE_NAME[] = "ros_gz_interfaces/msg/Entity";
static char ros_gz_interfaces__srv__SetEntityPose_Event__TYPE_NAME[] = "ros_gz_interfaces/srv/SetEntityPose_Event";
static char ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME[] = "ros_gz_interfaces/srv/SetEntityPose_Request";
static char ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME[] = "ros_gz_interfaces/srv/SetEntityPose_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__request_message[] = "request_message";
static char ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__response_message[] = "response_message";
static char ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__SetEntityPose__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__srv__SetEntityPose_Event__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__SetEntityPose__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
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
  {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Event__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__SetEntityPose__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__SetEntityPose__TYPE_NAME, 35, 35},
      {ros_gz_interfaces__srv__SetEntityPose__FIELDS, 3, 3},
    },
    {ros_gz_interfaces__srv__SetEntityPose__REFERENCED_TYPE_DESCRIPTIONS, 9, 9},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__Entity__EXPECTED_HASH, ros_gz_interfaces__msg__Entity__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = ros_gz_interfaces__msg__Entity__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = ros_gz_interfaces__srv__SetEntityPose_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = ros_gz_interfaces__srv__SetEntityPose_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = ros_gz_interfaces__srv__SetEntityPose_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[8].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__SetEntityPose_Request__FIELD_NAME__entity[] = "entity";
static char ros_gz_interfaces__srv__SetEntityPose_Request__FIELD_NAME__pose[] = "pose";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__SetEntityPose_Request__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__SetEntityPose_Request__FIELD_NAME__entity, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Request__FIELD_NAME__pose, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__SetEntityPose_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
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
  {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__SetEntityPose_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
      {ros_gz_interfaces__srv__SetEntityPose_Request__FIELDS, 2, 2},
    },
    {ros_gz_interfaces__srv__SetEntityPose_Request__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__Entity__EXPECTED_HASH, ros_gz_interfaces__msg__Entity__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = ros_gz_interfaces__msg__Entity__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__SetEntityPose_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__SetEntityPose_Response__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__SetEntityPose_Response__FIELD_NAME__success, 7, 7},
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
ros_gz_interfaces__srv__SetEntityPose_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
      {ros_gz_interfaces__srv__SetEntityPose_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__info[] = "info";
static char ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__request[] = "request";
static char ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field ros_gz_interfaces__srv__SetEntityPose_Event__FIELDS[] = {
  {
    {ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros_gz_interfaces__srv__SetEntityPose_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
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
  {
    {ros_gz_interfaces__msg__Entity__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros_gz_interfaces__srv__SetEntityPose_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros_gz_interfaces__srv__SetEntityPose_Event__TYPE_NAME, 41, 41},
      {ros_gz_interfaces__srv__SetEntityPose_Event__FIELDS, 3, 3},
    },
    {ros_gz_interfaces__srv__SetEntityPose_Event__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros_gz_interfaces__msg__Entity__EXPECTED_HASH, ros_gz_interfaces__msg__Entity__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = ros_gz_interfaces__msg__Entity__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = ros_gz_interfaces__srv__SetEntityPose_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = ros_gz_interfaces__srv__SetEntityPose_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "ros_gz_interfaces/Entity entity    # Gazebo Sim entity.\n"
  "geometry_msgs/Pose pose             # Pose of entity.\n"
  "---\n"
  "bool success                        # Return true if set successfully.";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__SetEntityPose__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__SetEntityPose__TYPE_NAME, 35, 35},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 185, 185},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__SetEntityPose_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__SetEntityPose_Request__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__SetEntityPose_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__SetEntityPose_Response__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
ros_gz_interfaces__srv__SetEntityPose_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros_gz_interfaces__srv__SetEntityPose_Event__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__SetEntityPose__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[10];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 10, 10};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__SetEntityPose__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[5] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL);
    sources[6] = *ros_gz_interfaces__srv__SetEntityPose_Event__get_individual_type_description_source(NULL);
    sources[7] = *ros_gz_interfaces__srv__SetEntityPose_Request__get_individual_type_description_source(NULL);
    sources[8] = *ros_gz_interfaces__srv__SetEntityPose_Response__get_individual_type_description_source(NULL);
    sources[9] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__SetEntityPose_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__SetEntityPose_Request__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[4] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__SetEntityPose_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__SetEntityPose_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros_gz_interfaces__srv__SetEntityPose_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros_gz_interfaces__srv__SetEntityPose_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[5] = *ros_gz_interfaces__msg__Entity__get_individual_type_description_source(NULL);
    sources[6] = *ros_gz_interfaces__srv__SetEntityPose_Request__get_individual_type_description_source(NULL);
    sources[7] = *ros_gz_interfaces__srv__SetEntityPose_Response__get_individual_type_description_source(NULL);
    sources[8] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
