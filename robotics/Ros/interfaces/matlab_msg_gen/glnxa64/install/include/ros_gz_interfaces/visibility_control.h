#ifndef ROS_GZ_INTERFACES__VISIBILITY_CONTROL_H_
#define ROS_GZ_INTERFACES__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_GZ_INTERFACES_EXPORT __attribute__ ((dllexport))
    #define ROS_GZ_INTERFACES_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_GZ_INTERFACES_EXPORT __declspec(dllexport)
    #define ROS_GZ_INTERFACES_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_GZ_INTERFACES_BUILDING_LIBRARY
    #define ROS_GZ_INTERFACES_PUBLIC ROS_GZ_INTERFACES_EXPORT
  #else
    #define ROS_GZ_INTERFACES_PUBLIC ROS_GZ_INTERFACES_IMPORT
  #endif
  #define ROS_GZ_INTERFACES_PUBLIC_TYPE ROS_GZ_INTERFACES_PUBLIC
  #define ROS_GZ_INTERFACES_LOCAL
#else
  #define ROS_GZ_INTERFACES_EXPORT __attribute__ ((visibility("default")))
  #define ROS_GZ_INTERFACES_IMPORT
  #if __GNUC__ >= 4
    #define ROS_GZ_INTERFACES_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_GZ_INTERFACES_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_GZ_INTERFACES_PUBLIC
    #define ROS_GZ_INTERFACES_LOCAL
  #endif
  #define ROS_GZ_INTERFACES_PUBLIC_TYPE
#endif
#endif  // ROS_GZ_INTERFACES__VISIBILITY_CONTROL_H_
// Generated 05-Sep-2025 01:32:58
 