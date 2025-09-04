// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_gz_interfaces:srv/DeleteEntity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_gz_interfaces/srv/delete_entity.h"


#ifndef ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__STRUCT_H_
#define ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'entity'
#include "ros_gz_interfaces/msg/detail/entity__struct.h"

/// Struct defined in srv/DeleteEntity in the package ros_gz_interfaces.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Request
{
  /// Gazebo Sim entity to be deleted.
  ros_gz_interfaces__msg__Entity entity;
} ros_gz_interfaces__srv__DeleteEntity_Request;

// Struct for a sequence of ros_gz_interfaces__srv__DeleteEntity_Request.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Request__Sequence
{
  ros_gz_interfaces__srv__DeleteEntity_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_gz_interfaces__srv__DeleteEntity_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/DeleteEntity in the package ros_gz_interfaces.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Response
{
  /// Return true if deletion is successful.
  bool success;
} ros_gz_interfaces__srv__DeleteEntity_Response;

// Struct for a sequence of ros_gz_interfaces__srv__DeleteEntity_Response.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Response__Sequence
{
  ros_gz_interfaces__srv__DeleteEntity_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_gz_interfaces__srv__DeleteEntity_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ros_gz_interfaces__srv__DeleteEntity_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ros_gz_interfaces__srv__DeleteEntity_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/DeleteEntity in the package ros_gz_interfaces.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ros_gz_interfaces__srv__DeleteEntity_Request__Sequence request;
  ros_gz_interfaces__srv__DeleteEntity_Response__Sequence response;
} ros_gz_interfaces__srv__DeleteEntity_Event;

// Struct for a sequence of ros_gz_interfaces__srv__DeleteEntity_Event.
typedef struct ros_gz_interfaces__srv__DeleteEntity_Event__Sequence
{
  ros_gz_interfaces__srv__DeleteEntity_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_gz_interfaces__srv__DeleteEntity_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__STRUCT_H_
