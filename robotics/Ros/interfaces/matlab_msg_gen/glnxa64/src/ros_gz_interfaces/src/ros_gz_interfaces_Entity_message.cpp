// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/Entity
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
#include "ros_gz_interfaces/msg/entity.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_Entity_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::Entity> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_Entity_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::Entity* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Entity* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_Entity_common::copy_from_struct(ros_gz_interfaces::msg::Entity* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //id
        const matlab::data::TypedArray<uint64_t> id_arr = arr["id"];
        msg->id = id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'id' is wrong type; expected a uint64.");
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
        //type
        const matlab::data::TypedArray<uint8_t> type_arr = arr["type"];
        msg->type = type_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'type' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'type' is wrong type; expected a uint8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_Entity_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Entity* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","NONE","LIGHT","MODEL","LINK","VISUAL","COLLISION","SENSOR","JOINT","id","name","type"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/Entity");
    // NONE
    auto currentElement_NONE = (msg + ctr)->NONE;
    outArray[ctr]["NONE"] = factory.createScalar(currentElement_NONE);
    // LIGHT
    auto currentElement_LIGHT = (msg + ctr)->LIGHT;
    outArray[ctr]["LIGHT"] = factory.createScalar(currentElement_LIGHT);
    // MODEL
    auto currentElement_MODEL = (msg + ctr)->MODEL;
    outArray[ctr]["MODEL"] = factory.createScalar(currentElement_MODEL);
    // LINK
    auto currentElement_LINK = (msg + ctr)->LINK;
    outArray[ctr]["LINK"] = factory.createScalar(currentElement_LINK);
    // VISUAL
    auto currentElement_VISUAL = (msg + ctr)->VISUAL;
    outArray[ctr]["VISUAL"] = factory.createScalar(currentElement_VISUAL);
    // COLLISION
    auto currentElement_COLLISION = (msg + ctr)->COLLISION;
    outArray[ctr]["COLLISION"] = factory.createScalar(currentElement_COLLISION);
    // SENSOR
    auto currentElement_SENSOR = (msg + ctr)->SENSOR;
    outArray[ctr]["SENSOR"] = factory.createScalar(currentElement_SENSOR);
    // JOINT
    auto currentElement_JOINT = (msg + ctr)->JOINT;
    outArray[ctr]["JOINT"] = factory.createScalar(currentElement_JOINT);
    // id
    auto currentElement_id = (msg + ctr)->id;
    outArray[ctr]["id"] = factory.createScalar(currentElement_id);
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    // type
    auto currentElement_type = (msg + ctr)->type;
    outArray[ctr]["type"] = factory.createScalar(currentElement_type);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_Entity_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_Entity_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_Entity_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::Entity,ros2_ros_gz_interfaces_msg_Entity_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_Entity_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::Entity,ros2_ros_gz_interfaces_msg_Entity_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_Entity_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::Entity>();
    ros2_ros_gz_interfaces_msg_Entity_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_Entity_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_Entity_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::Entity*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_Entity_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::Entity>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_Entity_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER