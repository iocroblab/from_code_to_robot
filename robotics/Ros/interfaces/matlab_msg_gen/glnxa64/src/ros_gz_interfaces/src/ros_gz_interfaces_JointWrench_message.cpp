// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/JointWrench
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
#include "ros_gz_interfaces/msg/joint_wrench.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_JointWrench_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::JointWrench> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_JointWrench_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::JointWrench* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::JointWrench* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_JointWrench_common::copy_from_struct(ros_gz_interfaces::msg::JointWrench* msg, const matlab::data::Struct& arr,
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
        //body_1_name
        const matlab::data::StructArray body_1_name_arr = arr["body_1_name"];
        auto msgClassPtr_body_1_name = getCommonObject<std_msgs::msg::String>("ros2_std_msgs_msg_String_common",loader);
        msgClassPtr_body_1_name->copy_from_struct(&msg->body_1_name,body_1_name_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_1_name' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_1_name' is wrong type; expected a struct.");
    }
    try {
        //body_1_id
        const matlab::data::StructArray body_1_id_arr = arr["body_1_id"];
        auto msgClassPtr_body_1_id = getCommonObject<std_msgs::msg::UInt32>("ros2_std_msgs_msg_UInt32_common",loader);
        msgClassPtr_body_1_id->copy_from_struct(&msg->body_1_id,body_1_id_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_1_id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_1_id' is wrong type; expected a struct.");
    }
    try {
        //body_2_name
        const matlab::data::StructArray body_2_name_arr = arr["body_2_name"];
        auto msgClassPtr_body_2_name = getCommonObject<std_msgs::msg::String>("ros2_std_msgs_msg_String_common",loader);
        msgClassPtr_body_2_name->copy_from_struct(&msg->body_2_name,body_2_name_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_2_name' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_2_name' is wrong type; expected a struct.");
    }
    try {
        //body_2_id
        const matlab::data::StructArray body_2_id_arr = arr["body_2_id"];
        auto msgClassPtr_body_2_id = getCommonObject<std_msgs::msg::UInt32>("ros2_std_msgs_msg_UInt32_common",loader);
        msgClassPtr_body_2_id->copy_from_struct(&msg->body_2_id,body_2_id_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_2_id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_2_id' is wrong type; expected a struct.");
    }
    try {
        //body_1_wrench
        const matlab::data::StructArray body_1_wrench_arr = arr["body_1_wrench"];
        auto msgClassPtr_body_1_wrench = getCommonObject<geometry_msgs::msg::Wrench>("ros2_geometry_msgs_msg_Wrench_common",loader);
        msgClassPtr_body_1_wrench->copy_from_struct(&msg->body_1_wrench,body_1_wrench_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_1_wrench' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_1_wrench' is wrong type; expected a struct.");
    }
    try {
        //body_2_wrench
        const matlab::data::StructArray body_2_wrench_arr = arr["body_2_wrench"];
        auto msgClassPtr_body_2_wrench = getCommonObject<geometry_msgs::msg::Wrench>("ros2_geometry_msgs_msg_Wrench_common",loader);
        msgClassPtr_body_2_wrench->copy_from_struct(&msg->body_2_wrench,body_2_wrench_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'body_2_wrench' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'body_2_wrench' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_JointWrench_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::JointWrench* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","body_1_name","body_1_id","body_2_name","body_2_id","body_1_wrench","body_2_wrench"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/JointWrench");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // body_1_name
    auto currentElement_body_1_name = (msg + ctr)->body_1_name;
    auto msgClassPtr_body_1_name = getCommonObject<std_msgs::msg::String>("ros2_std_msgs_msg_String_common",loader);
    outArray[ctr]["body_1_name"] = msgClassPtr_body_1_name->get_arr(factory, &currentElement_body_1_name, loader);
    // body_1_id
    auto currentElement_body_1_id = (msg + ctr)->body_1_id;
    auto msgClassPtr_body_1_id = getCommonObject<std_msgs::msg::UInt32>("ros2_std_msgs_msg_UInt32_common",loader);
    outArray[ctr]["body_1_id"] = msgClassPtr_body_1_id->get_arr(factory, &currentElement_body_1_id, loader);
    // body_2_name
    auto currentElement_body_2_name = (msg + ctr)->body_2_name;
    auto msgClassPtr_body_2_name = getCommonObject<std_msgs::msg::String>("ros2_std_msgs_msg_String_common",loader);
    outArray[ctr]["body_2_name"] = msgClassPtr_body_2_name->get_arr(factory, &currentElement_body_2_name, loader);
    // body_2_id
    auto currentElement_body_2_id = (msg + ctr)->body_2_id;
    auto msgClassPtr_body_2_id = getCommonObject<std_msgs::msg::UInt32>("ros2_std_msgs_msg_UInt32_common",loader);
    outArray[ctr]["body_2_id"] = msgClassPtr_body_2_id->get_arr(factory, &currentElement_body_2_id, loader);
    // body_1_wrench
    auto currentElement_body_1_wrench = (msg + ctr)->body_1_wrench;
    auto msgClassPtr_body_1_wrench = getCommonObject<geometry_msgs::msg::Wrench>("ros2_geometry_msgs_msg_Wrench_common",loader);
    outArray[ctr]["body_1_wrench"] = msgClassPtr_body_1_wrench->get_arr(factory, &currentElement_body_1_wrench, loader);
    // body_2_wrench
    auto currentElement_body_2_wrench = (msg + ctr)->body_2_wrench;
    auto msgClassPtr_body_2_wrench = getCommonObject<geometry_msgs::msg::Wrench>("ros2_geometry_msgs_msg_Wrench_common",loader);
    outArray[ctr]["body_2_wrench"] = msgClassPtr_body_2_wrench->get_arr(factory, &currentElement_body_2_wrench, loader);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_JointWrench_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_JointWrench_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_JointWrench_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::JointWrench,ros2_ros_gz_interfaces_msg_JointWrench_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_JointWrench_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::JointWrench,ros2_ros_gz_interfaces_msg_JointWrench_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_JointWrench_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::JointWrench>();
    ros2_ros_gz_interfaces_msg_JointWrench_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_JointWrench_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_JointWrench_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::JointWrench*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_JointWrench_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::JointWrench>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_JointWrench_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER