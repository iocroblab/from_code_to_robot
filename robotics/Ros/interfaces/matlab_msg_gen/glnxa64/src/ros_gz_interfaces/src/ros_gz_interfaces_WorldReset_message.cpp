// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/WorldReset
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
#include "ros_gz_interfaces/msg/world_reset.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_WorldReset_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::WorldReset> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_WorldReset_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::WorldReset* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::WorldReset* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_WorldReset_common::copy_from_struct(ros_gz_interfaces::msg::WorldReset* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //all
        const matlab::data::TypedArray<bool> all_arr = arr["all"];
        msg->all = all_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'all' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'all' is wrong type; expected a logical.");
    }
    try {
        //time_only
        const matlab::data::TypedArray<bool> time_only_arr = arr["time_only"];
        msg->time_only = time_only_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'time_only' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'time_only' is wrong type; expected a logical.");
    }
    try {
        //model_only
        const matlab::data::TypedArray<bool> model_only_arr = arr["model_only"];
        msg->model_only = model_only_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'model_only' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'model_only' is wrong type; expected a logical.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_WorldReset_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::WorldReset* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","all","time_only","model_only"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/WorldReset");
    // all
    auto currentElement_all = (msg + ctr)->all;
    outArray[ctr]["all"] = factory.createScalar(currentElement_all);
    // time_only
    auto currentElement_time_only = (msg + ctr)->time_only;
    outArray[ctr]["time_only"] = factory.createScalar(currentElement_time_only);
    // model_only
    auto currentElement_model_only = (msg + ctr)->model_only;
    outArray[ctr]["model_only"] = factory.createScalar(currentElement_model_only);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_WorldReset_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_WorldReset_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_WorldReset_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::WorldReset,ros2_ros_gz_interfaces_msg_WorldReset_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_WorldReset_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::WorldReset,ros2_ros_gz_interfaces_msg_WorldReset_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_WorldReset_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::WorldReset>();
    ros2_ros_gz_interfaces_msg_WorldReset_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_WorldReset_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_WorldReset_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::WorldReset*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_WorldReset_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::WorldReset>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_WorldReset_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER