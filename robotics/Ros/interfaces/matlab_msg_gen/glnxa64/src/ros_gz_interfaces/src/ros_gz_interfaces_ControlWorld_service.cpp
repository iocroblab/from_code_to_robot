// Copyright 2021-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/ControlWorldRequest
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
#include "ros_gz_interfaces/srv/control_world.hpp"
#include "visibility_control.h"
#ifndef FOUNDATION_MATLABDATA_API
#include "MDArray.hpp"
#include "StructArray.hpp"
#include "TypedArrayRef.hpp"
#include "Struct.hpp"
#include "ArrayFactory.hpp"
#include "StructRef.hpp"
#include "Reference.hpp"
#endif
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
#include "ROS2ServiceTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_ControlWorldRequest_common : public MATLABROS2MsgInterface<ros_gz_interfaces::srv::ControlWorld::Request> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_ControlWorldRequest_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::srv::ControlWorld::Request* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::srv::ControlWorld::Request* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_ControlWorldRequest_common::copy_from_struct(ros_gz_interfaces::srv::ControlWorld::Request* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //world_control
        const matlab::data::StructArray world_control_arr = arr["world_control"];
        auto msgClassPtr_world_control = getCommonObject<ros_gz_interfaces::msg::WorldControl>("ros2_ros_gz_interfaces_msg_WorldControl_common",loader);
        msgClassPtr_world_control->copy_from_struct(&msg->world_control,world_control_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'world_control' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'world_control' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_ControlWorldRequest_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::srv::ControlWorld::Request* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","world_control"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/ControlWorldRequest");
    // world_control
    auto currentElement_world_control = (msg + ctr)->world_control;
    auto msgClassPtr_world_control = getCommonObject<ros_gz_interfaces::msg::WorldControl>("ros2_ros_gz_interfaces_msg_WorldControl_common",loader);
    outArray[ctr]["world_control"] = msgClassPtr_world_control->get_arr(factory, &currentElement_world_control, loader);
    }
    return std::move(outArray);
  }
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_ControlWorldResponse_common : public MATLABROS2MsgInterface<ros_gz_interfaces::srv::ControlWorld::Response> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_ControlWorldResponse_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::srv::ControlWorld::Response* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::srv::ControlWorld::Response* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_ControlWorldResponse_common::copy_from_struct(ros_gz_interfaces::srv::ControlWorld::Response* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //success
        const matlab::data::TypedArray<bool> success_arr = arr["success"];
        msg->success = success_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'success' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'success' is wrong type; expected a logical.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_ControlWorldResponse_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::srv::ControlWorld::Response* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","success"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/ControlWorldResponse");
    // success
    auto currentElement_success = (msg + ctr)->success;
    outArray[ctr]["success"] = factory.createScalar(currentElement_success);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_ControlWorld_service : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_ControlWorld_service(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABSvcServerInterface> generateSvcServerInterface();
    virtual std::shared_ptr<MATLABSvcClientInterface> generateSvcClientInterface();
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_ControlWorld_service::generatePublisherInterface(ElementType type){
    if(type == eRequest){
        return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::srv::ControlWorld::Request,ros2_ros_gz_interfaces_msg_ControlWorldRequest_common>>();
    }else if(type == eResponse){
        return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::srv::ControlWorld::Response,ros2_ros_gz_interfaces_msg_ControlWorldResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
  }
  std::shared_ptr<MATLABSubscriberInterface> 
          ros2_ros_gz_interfaces_ControlWorld_service::generateSubscriberInterface(ElementType type){
    if(type == eRequest){
        return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::srv::ControlWorld::Request,ros2_ros_gz_interfaces_msg_ControlWorldRequest_common>>();
    }else if(type == eResponse){
        return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::srv::ControlWorld::Response,ros2_ros_gz_interfaces_msg_ControlWorldResponse_common>>();
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_ControlWorld_service::generateCppMessage(ElementType type, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    if(type == eRequest){
        auto msg = std::make_shared<ros_gz_interfaces::srv::ControlWorld::Request>();
        ros2_ros_gz_interfaces_msg_ControlWorldRequest_common commonObj;
        commonObj.mCommonObjMap = commonObjMap;
        commonObj.copy_from_struct(msg.get(), arr[0], loader);
        return msg;
    }else if(type == eResponse){
        auto msg = std::make_shared<ros_gz_interfaces::srv::ControlWorld::Response>();
        ros2_ros_gz_interfaces_msg_ControlWorldResponse_common commonObj;
        commonObj.mCommonObjMap = commonObjMap;
        commonObj.copy_from_struct(msg.get(), arr[0], loader);
        return msg;
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
  }
  std::shared_ptr<MATLABSvcServerInterface> 
          ros2_ros_gz_interfaces_ControlWorld_service::generateSvcServerInterface(){
    return std::make_shared<ROS2SvcServerImpl<ros_gz_interfaces::srv::ControlWorld,ros_gz_interfaces::srv::ControlWorld::Request,ros_gz_interfaces::srv::ControlWorld::Response,ros2_ros_gz_interfaces_msg_ControlWorldRequest_common,ros2_ros_gz_interfaces_msg_ControlWorldResponse_common>>();
  }
  std::shared_ptr<MATLABSvcClientInterface> 
          ros2_ros_gz_interfaces_ControlWorld_service::generateSvcClientInterface(){
    return std::make_shared<ROS2SvcClientImpl<ros_gz_interfaces::srv::ControlWorld,ros_gz_interfaces::srv::ControlWorld::Request,ros_gz_interfaces::srv::ControlWorld::Response,ros2_ros_gz_interfaces_msg_ControlWorldRequest_common,ros2_ros_gz_interfaces_msg_ControlWorldResponse_common,rclcpp::Client<ros_gz_interfaces::srv::ControlWorld>::SharedFuture>>();
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_ControlWorld_service::generateMLMessage(ElementType type, 
                                                    void*  msgPtr ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    if(type == eRequest){
	    ros2_ros_gz_interfaces_msg_ControlWorldRequest_common commonObj;	
        commonObj.mCommonObjMap = commonObjMap;
	    MDFactory_T factory;
	    return commonObj.get_arr(factory, (ros_gz_interfaces::srv::ControlWorld::Request*)msgPtr, loader);
    }else if(type == eResponse){
        ros2_ros_gz_interfaces_msg_ControlWorldResponse_common commonObj;	
        commonObj.mCommonObjMap = commonObjMap;	
	    MDFactory_T factory;
	    return commonObj.get_arr(factory, (ros_gz_interfaces::srv::ControlWorld::Response*)msgPtr, loader);
    }else{
        throw std::invalid_argument("Wrong input, Expected 'Request' or 'Response'");
    }
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_ControlWorldRequest_common, MATLABROS2MsgInterface<ros_gz_interfaces::srv::ControlWorld::Request>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_ControlWorldResponse_common, MATLABROS2MsgInterface<ros_gz_interfaces::srv::ControlWorld::Response>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_ControlWorld_service, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1
