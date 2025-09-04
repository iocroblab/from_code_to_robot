// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/TrackVisual
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4265)
#pragma warning(disable : 4456)
#pragma warning(disable : 4458)
#pragma warning(disable : 4946)
#pragma warning(disable : 4244)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "ros_gz_interfaces/msg/track_visual.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_TrackVisual_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::TrackVisual> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_TrackVisual_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::TrackVisual* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::TrackVisual* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_TrackVisual_common::copy_from_struct(ros_gz_interfaces::msg::TrackVisual* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["header"];
        auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'header' is wrong type; expected a struct.");
    }
    try {
        //name
        const matlab::data::CharArray name_arr = arr["name"];
        msg->name = name_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'name' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'name' is wrong type; expected a string.");
    }
    try {
        //id
        const matlab::data::TypedArray<uint32_t> id_arr = arr["id"];
        msg->id = id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'id' is wrong type; expected a uint32.");
    }
    try {
        //inherit_orientation
        const matlab::data::TypedArray<bool> inherit_orientation_arr = arr["inherit_orientation"];
        msg->inherit_orientation = inherit_orientation_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'inherit_orientation' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'inherit_orientation' is wrong type; expected a logical.");
    }
    try {
        //min_dist
        const matlab::data::TypedArray<double> min_dist_arr = arr["min_dist"];
        msg->min_dist = min_dist_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'min_dist' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'min_dist' is wrong type; expected a double.");
    }
    try {
        //max_dist
        const matlab::data::TypedArray<double> max_dist_arr = arr["max_dist"];
        msg->max_dist = max_dist_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'max_dist' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'max_dist' is wrong type; expected a double.");
    }
    try {
        //is_static
        const matlab::data::TypedArray<bool> is_static_arr = arr["is_static"];
        msg->is_static = is_static_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'is_static' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'is_static' is wrong type; expected a logical.");
    }
    try {
        //use_model_frame
        const matlab::data::TypedArray<bool> use_model_frame_arr = arr["use_model_frame"];
        msg->use_model_frame = use_model_frame_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'use_model_frame' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'use_model_frame' is wrong type; expected a logical.");
    }
    try {
        //xyz
        const matlab::data::StructArray xyz_arr = arr["xyz"];
        auto msgClassPtr_xyz = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_xyz->copy_from_struct(&msg->xyz,xyz_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'xyz' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'xyz' is wrong type; expected a struct.");
    }
    try {
        //inherit_yaw
        const matlab::data::TypedArray<bool> inherit_yaw_arr = arr["inherit_yaw"];
        msg->inherit_yaw = inherit_yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'inherit_yaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'inherit_yaw' is wrong type; expected a logical.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_TrackVisual_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::TrackVisual* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","name","id","inherit_orientation","min_dist","max_dist","is_static","use_model_frame","xyz","inherit_yaw"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/TrackVisual");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    // id
    auto currentElement_id = (msg + ctr)->id;
    outArray[ctr]["id"] = factory.createScalar(currentElement_id);
    // inherit_orientation
    auto currentElement_inherit_orientation = (msg + ctr)->inherit_orientation;
    outArray[ctr]["inherit_orientation"] = factory.createScalar(currentElement_inherit_orientation);
    // min_dist
    auto currentElement_min_dist = (msg + ctr)->min_dist;
    outArray[ctr]["min_dist"] = factory.createScalar(currentElement_min_dist);
    // max_dist
    auto currentElement_max_dist = (msg + ctr)->max_dist;
    outArray[ctr]["max_dist"] = factory.createScalar(currentElement_max_dist);
    // is_static
    auto currentElement_is_static = (msg + ctr)->is_static;
    outArray[ctr]["is_static"] = factory.createScalar(currentElement_is_static);
    // use_model_frame
    auto currentElement_use_model_frame = (msg + ctr)->use_model_frame;
    outArray[ctr]["use_model_frame"] = factory.createScalar(currentElement_use_model_frame);
    // xyz
    auto currentElement_xyz = (msg + ctr)->xyz;
    auto msgClassPtr_xyz = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["xyz"] = msgClassPtr_xyz->get_arr(factory, &currentElement_xyz, loader);
    // inherit_yaw
    auto currentElement_inherit_yaw = (msg + ctr)->inherit_yaw;
    outArray[ctr]["inherit_yaw"] = factory.createScalar(currentElement_inherit_yaw);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_TrackVisual_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_TrackVisual_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_TrackVisual_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::TrackVisual,ros2_ros_gz_interfaces_msg_TrackVisual_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_TrackVisual_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::TrackVisual,ros2_ros_gz_interfaces_msg_TrackVisual_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_TrackVisual_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::TrackVisual>();
    ros2_ros_gz_interfaces_msg_TrackVisual_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_TrackVisual_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_TrackVisual_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::TrackVisual*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_TrackVisual_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::TrackVisual>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_TrackVisual_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER