// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_gz_interfaces:srv/DeleteEntity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros_gz_interfaces/srv/delete_entity.hpp"


#ifndef ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__TRAITS_HPP_
#define ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros_gz_interfaces/srv/detail/delete_entity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'entity'
#include "ros_gz_interfaces/msg/detail/entity__traits.hpp"

namespace ros_gz_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteEntity_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: entity
  {
    out << "entity: ";
    to_flow_style_yaml(msg.entity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteEntity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: entity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entity:\n";
    to_block_style_yaml(msg.entity, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteEntity_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_gz_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_gz_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_gz_interfaces::srv::DeleteEntity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_gz_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_gz_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_gz_interfaces::srv::DeleteEntity_Request & msg)
{
  return ros_gz_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_gz_interfaces::srv::DeleteEntity_Request>()
{
  return "ros_gz_interfaces::srv::DeleteEntity_Request";
}

template<>
inline const char * name<ros_gz_interfaces::srv::DeleteEntity_Request>()
{
  return "ros_gz_interfaces/srv/DeleteEntity_Request";
}

template<>
struct has_fixed_size<ros_gz_interfaces::srv::DeleteEntity_Request>
  : std::integral_constant<bool, has_fixed_size<ros_gz_interfaces::msg::Entity>::value> {};

template<>
struct has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Request>
  : std::integral_constant<bool, has_bounded_size<ros_gz_interfaces::msg::Entity>::value> {};

template<>
struct is_message<ros_gz_interfaces::srv::DeleteEntity_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros_gz_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteEntity_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteEntity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteEntity_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_gz_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_gz_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_gz_interfaces::srv::DeleteEntity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_gz_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_gz_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_gz_interfaces::srv::DeleteEntity_Response & msg)
{
  return ros_gz_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_gz_interfaces::srv::DeleteEntity_Response>()
{
  return "ros_gz_interfaces::srv::DeleteEntity_Response";
}

template<>
inline const char * name<ros_gz_interfaces::srv::DeleteEntity_Response>()
{
  return "ros_gz_interfaces/srv/DeleteEntity_Response";
}

template<>
struct has_fixed_size<ros_gz_interfaces::srv::DeleteEntity_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_gz_interfaces::srv::DeleteEntity_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace ros_gz_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteEntity_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteEntity_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteEntity_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros_gz_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros_gz_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros_gz_interfaces::srv::DeleteEntity_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros_gz_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros_gz_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros_gz_interfaces::srv::DeleteEntity_Event & msg)
{
  return ros_gz_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros_gz_interfaces::srv::DeleteEntity_Event>()
{
  return "ros_gz_interfaces::srv::DeleteEntity_Event";
}

template<>
inline const char * name<ros_gz_interfaces::srv::DeleteEntity_Event>()
{
  return "ros_gz_interfaces/srv/DeleteEntity_Event";
}

template<>
struct has_fixed_size<ros_gz_interfaces::srv::DeleteEntity_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Event>
  : std::integral_constant<bool, has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Request>::value && has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<ros_gz_interfaces::srv::DeleteEntity_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_gz_interfaces::srv::DeleteEntity>()
{
  return "ros_gz_interfaces::srv::DeleteEntity";
}

template<>
inline const char * name<ros_gz_interfaces::srv::DeleteEntity>()
{
  return "ros_gz_interfaces/srv/DeleteEntity";
}

template<>
struct has_fixed_size<ros_gz_interfaces::srv::DeleteEntity>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_gz_interfaces::srv::DeleteEntity_Request>::value &&
    has_fixed_size<ros_gz_interfaces::srv::DeleteEntity_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_gz_interfaces::srv::DeleteEntity>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Request>::value &&
    has_bounded_size<ros_gz_interfaces::srv::DeleteEntity_Response>::value
  >
{
};

template<>
struct is_service<ros_gz_interfaces::srv::DeleteEntity>
  : std::true_type
{
};

template<>
struct is_service_request<ros_gz_interfaces::srv::DeleteEntity_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_gz_interfaces::srv::DeleteEntity_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_GZ_INTERFACES__SRV__DETAIL__DELETE_ENTITY__TRAITS_HPP_
