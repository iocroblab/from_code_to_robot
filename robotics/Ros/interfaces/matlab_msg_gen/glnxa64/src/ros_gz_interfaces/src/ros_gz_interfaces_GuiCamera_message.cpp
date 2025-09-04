// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/GuiCamera
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
#include "ros_gz_interfaces/msg/gui_camera.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_GuiCamera_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::GuiCamera> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_GuiCamera_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::GuiCamera* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::GuiCamera* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_GuiCamera_common::copy_from_struct(ros_gz_interfaces::msg::GuiCamera* msg, const matlab::data::Struct& arr,
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
        //view_controller
        const matlab::data::CharArray view_controller_arr = arr["view_controller"];
        msg->view_controller = view_controller_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'view_controller' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'view_controller' is wrong type; expected a string.");
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
        //track
        const matlab::data::StructArray track_arr = arr["track"];
        auto msgClassPtr_track = getCommonObject<ros_gz_interfaces::msg::TrackVisual>("ros2_ros_gz_interfaces_msg_TrackVisual_common",loader);
        msgClassPtr_track->copy_from_struct(&msg->track,track_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'track' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'track' is wrong type; expected a struct.");
    }
    try {
        //projection_type
        const matlab::data::CharArray projection_type_arr = arr["projection_type"];
        msg->projection_type = projection_type_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'projection_type' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'projection_type' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_GuiCamera_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::GuiCamera* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","name","view_controller","pose","track","projection_type"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/GuiCamera");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    // view_controller
    auto currentElement_view_controller = (msg + ctr)->view_controller;
    outArray[ctr]["view_controller"] = factory.createCharArray(currentElement_view_controller);
    // pose
    auto currentElement_pose = (msg + ctr)->pose;
    auto msgClassPtr_pose = getCommonObject<geometry_msgs::msg::Pose>("ros2_geometry_msgs_msg_Pose_common",loader);
    outArray[ctr]["pose"] = msgClassPtr_pose->get_arr(factory, &currentElement_pose, loader);
    // track
    auto currentElement_track = (msg + ctr)->track;
    auto msgClassPtr_track = getCommonObject<ros_gz_interfaces::msg::TrackVisual>("ros2_ros_gz_interfaces_msg_TrackVisual_common",loader);
    outArray[ctr]["track"] = msgClassPtr_track->get_arr(factory, &currentElement_track, loader);
    // projection_type
    auto currentElement_projection_type = (msg + ctr)->projection_type;
    outArray[ctr]["projection_type"] = factory.createCharArray(currentElement_projection_type);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_GuiCamera_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_GuiCamera_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_GuiCamera_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::GuiCamera,ros2_ros_gz_interfaces_msg_GuiCamera_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_GuiCamera_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::GuiCamera,ros2_ros_gz_interfaces_msg_GuiCamera_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_GuiCamera_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::GuiCamera>();
    ros2_ros_gz_interfaces_msg_GuiCamera_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_GuiCamera_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_GuiCamera_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::GuiCamera*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_GuiCamera_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::GuiCamera>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_GuiCamera_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER