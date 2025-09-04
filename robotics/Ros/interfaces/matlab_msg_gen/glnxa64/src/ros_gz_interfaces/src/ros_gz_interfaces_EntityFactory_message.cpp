// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/EntityFactory
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
#include "ros_gz_interfaces/msg/entity_factory.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_EntityFactory_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::EntityFactory> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_EntityFactory_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::EntityFactory* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::EntityFactory* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_EntityFactory_common::copy_from_struct(ros_gz_interfaces::msg::EntityFactory* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
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
        //allow_renaming
        const matlab::data::TypedArray<bool> allow_renaming_arr = arr["allow_renaming"];
        msg->allow_renaming = allow_renaming_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'allow_renaming' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'allow_renaming' is wrong type; expected a logical.");
    }
    try {
        //sdf
        const matlab::data::CharArray sdf_arr = arr["sdf"];
        msg->sdf = sdf_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'sdf' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'sdf' is wrong type; expected a string.");
    }
    try {
        //sdf_filename
        const matlab::data::CharArray sdf_filename_arr = arr["sdf_filename"];
        msg->sdf_filename = sdf_filename_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'sdf_filename' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'sdf_filename' is wrong type; expected a string.");
    }
    try {
        //clone_name
        const matlab::data::CharArray clone_name_arr = arr["clone_name"];
        msg->clone_name = clone_name_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'clone_name' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'clone_name' is wrong type; expected a string.");
    }
    try {
        //pose
        const matlab::data::StructArray pose_arr = arr["pose"];
        auto msgClassPtr_pose = getCommonObject<geometry_msgs::msg::Pose>("ros2_geometry_msgs_msg_Pose_common",loader);
        msgClassPtr_pose->copy_from_struct(&msg->pose,pose_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'pose' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'pose' is wrong type; expected a struct.");
    }
    try {
        //relative_to
        const matlab::data::CharArray relative_to_arr = arr["relative_to"];
        msg->relative_to = relative_to_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'relative_to' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'relative_to' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_EntityFactory_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::EntityFactory* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","name","allow_renaming","sdf","sdf_filename","clone_name","pose","relative_to"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/EntityFactory");
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    // allow_renaming
    auto currentElement_allow_renaming = (msg + ctr)->allow_renaming;
    outArray[ctr]["allow_renaming"] = factory.createScalar(currentElement_allow_renaming);
    // sdf
    auto currentElement_sdf = (msg + ctr)->sdf;
    outArray[ctr]["sdf"] = factory.createCharArray(currentElement_sdf);
    // sdf_filename
    auto currentElement_sdf_filename = (msg + ctr)->sdf_filename;
    outArray[ctr]["sdf_filename"] = factory.createCharArray(currentElement_sdf_filename);
    // clone_name
    auto currentElement_clone_name = (msg + ctr)->clone_name;
    outArray[ctr]["clone_name"] = factory.createCharArray(currentElement_clone_name);
    // pose
    auto currentElement_pose = (msg + ctr)->pose;
    auto msgClassPtr_pose = getCommonObject<geometry_msgs::msg::Pose>("ros2_geometry_msgs_msg_Pose_common",loader);
    outArray[ctr]["pose"] = msgClassPtr_pose->get_arr(factory, &currentElement_pose, loader);
    // relative_to
    auto currentElement_relative_to = (msg + ctr)->relative_to;
    outArray[ctr]["relative_to"] = factory.createCharArray(currentElement_relative_to);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_EntityFactory_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_EntityFactory_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_EntityFactory_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::EntityFactory,ros2_ros_gz_interfaces_msg_EntityFactory_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_EntityFactory_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::EntityFactory,ros2_ros_gz_interfaces_msg_EntityFactory_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_EntityFactory_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::EntityFactory>();
    ros2_ros_gz_interfaces_msg_EntityFactory_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_EntityFactory_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_EntityFactory_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::EntityFactory*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_EntityFactory_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::EntityFactory>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_EntityFactory_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER