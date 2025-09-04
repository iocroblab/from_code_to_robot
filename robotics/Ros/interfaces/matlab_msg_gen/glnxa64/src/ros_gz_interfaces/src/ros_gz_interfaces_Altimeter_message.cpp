// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/Altimeter
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
#include "ros_gz_interfaces/msg/altimeter.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_Altimeter_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::Altimeter> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_Altimeter_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::Altimeter* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Altimeter* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_Altimeter_common::copy_from_struct(ros_gz_interfaces::msg::Altimeter* msg, const matlab::data::Struct& arr,
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
        //vertical_position
        const matlab::data::TypedArray<double> vertical_position_arr = arr["vertical_position"];
        msg->vertical_position = vertical_position_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'vertical_position' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'vertical_position' is wrong type; expected a double.");
    }
    try {
        //vertical_velocity
        const matlab::data::TypedArray<double> vertical_velocity_arr = arr["vertical_velocity"];
        msg->vertical_velocity = vertical_velocity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'vertical_velocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'vertical_velocity' is wrong type; expected a double.");
    }
    try {
        //vertical_reference
        const matlab::data::TypedArray<double> vertical_reference_arr = arr["vertical_reference"];
        msg->vertical_reference = vertical_reference_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'vertical_reference' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'vertical_reference' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_Altimeter_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Altimeter* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","vertical_position","vertical_velocity","vertical_reference"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/Altimeter");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // vertical_position
    auto currentElement_vertical_position = (msg + ctr)->vertical_position;
    outArray[ctr]["vertical_position"] = factory.createScalar(currentElement_vertical_position);
    // vertical_velocity
    auto currentElement_vertical_velocity = (msg + ctr)->vertical_velocity;
    outArray[ctr]["vertical_velocity"] = factory.createScalar(currentElement_vertical_velocity);
    // vertical_reference
    auto currentElement_vertical_reference = (msg + ctr)->vertical_reference;
    outArray[ctr]["vertical_reference"] = factory.createScalar(currentElement_vertical_reference);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_Altimeter_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_Altimeter_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_Altimeter_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::Altimeter,ros2_ros_gz_interfaces_msg_Altimeter_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_Altimeter_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::Altimeter,ros2_ros_gz_interfaces_msg_Altimeter_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_Altimeter_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::Altimeter>();
    ros2_ros_gz_interfaces_msg_Altimeter_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_Altimeter_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_Altimeter_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::Altimeter*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_Altimeter_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::Altimeter>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_Altimeter_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER