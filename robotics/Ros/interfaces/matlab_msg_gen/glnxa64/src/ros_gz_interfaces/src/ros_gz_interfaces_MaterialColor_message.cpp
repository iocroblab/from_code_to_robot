// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/MaterialColor
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
#include "ros_gz_interfaces/msg/material_color.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_MaterialColor_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::MaterialColor> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_MaterialColor_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::MaterialColor* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::MaterialColor* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_MaterialColor_common::copy_from_struct(ros_gz_interfaces::msg::MaterialColor* msg, const matlab::data::Struct& arr,
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
        //entity
        const matlab::data::StructArray entity_arr = arr["entity"];
        auto msgClassPtr_entity = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
        msgClassPtr_entity->copy_from_struct(&msg->entity,entity_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'entity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'entity' is wrong type; expected a struct.");
    }
    try {
        //ambient
        const matlab::data::StructArray ambient_arr = arr["ambient"];
        auto msgClassPtr_ambient = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
        msgClassPtr_ambient->copy_from_struct(&msg->ambient,ambient_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'ambient' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'ambient' is wrong type; expected a struct.");
    }
    try {
        //diffuse
        const matlab::data::StructArray diffuse_arr = arr["diffuse"];
        auto msgClassPtr_diffuse = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
        msgClassPtr_diffuse->copy_from_struct(&msg->diffuse,diffuse_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'diffuse' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'diffuse' is wrong type; expected a struct.");
    }
    try {
        //specular
        const matlab::data::StructArray specular_arr = arr["specular"];
        auto msgClassPtr_specular = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
        msgClassPtr_specular->copy_from_struct(&msg->specular,specular_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'specular' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'specular' is wrong type; expected a struct.");
    }
    try {
        //emissive
        const matlab::data::StructArray emissive_arr = arr["emissive"];
        auto msgClassPtr_emissive = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
        msgClassPtr_emissive->copy_from_struct(&msg->emissive,emissive_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'emissive' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'emissive' is wrong type; expected a struct.");
    }
    try {
        //shininess
        const matlab::data::TypedArray<double> shininess_arr = arr["shininess"];
        msg->shininess = shininess_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'shininess' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'shininess' is wrong type; expected a double.");
    }
    try {
        //entity_match
        const matlab::data::TypedArray<uint8_t> entity_match_arr = arr["entity_match"];
        msg->entity_match = entity_match_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'entity_match' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'entity_match' is wrong type; expected a uint8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_MaterialColor_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::MaterialColor* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","FIRST","ALL","header","entity","ambient","diffuse","specular","emissive","shininess","entity_match"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/MaterialColor");
    // FIRST
    auto currentElement_FIRST = (msg + ctr)->FIRST;
    outArray[ctr]["FIRST"] = factory.createScalar(currentElement_FIRST);
    // ALL
    auto currentElement_ALL = (msg + ctr)->ALL;
    outArray[ctr]["ALL"] = factory.createScalar(currentElement_ALL);
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // entity
    auto currentElement_entity = (msg + ctr)->entity;
    auto msgClassPtr_entity = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
    outArray[ctr]["entity"] = msgClassPtr_entity->get_arr(factory, &currentElement_entity, loader);
    // ambient
    auto currentElement_ambient = (msg + ctr)->ambient;
    auto msgClassPtr_ambient = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["ambient"] = msgClassPtr_ambient->get_arr(factory, &currentElement_ambient, loader);
    // diffuse
    auto currentElement_diffuse = (msg + ctr)->diffuse;
    auto msgClassPtr_diffuse = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["diffuse"] = msgClassPtr_diffuse->get_arr(factory, &currentElement_diffuse, loader);
    // specular
    auto currentElement_specular = (msg + ctr)->specular;
    auto msgClassPtr_specular = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["specular"] = msgClassPtr_specular->get_arr(factory, &currentElement_specular, loader);
    // emissive
    auto currentElement_emissive = (msg + ctr)->emissive;
    auto msgClassPtr_emissive = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["emissive"] = msgClassPtr_emissive->get_arr(factory, &currentElement_emissive, loader);
    // shininess
    auto currentElement_shininess = (msg + ctr)->shininess;
    outArray[ctr]["shininess"] = factory.createScalar(currentElement_shininess);
    // entity_match
    auto currentElement_entity_match = (msg + ctr)->entity_match;
    outArray[ctr]["entity_match"] = factory.createScalar(currentElement_entity_match);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_MaterialColor_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_MaterialColor_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_MaterialColor_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::MaterialColor,ros2_ros_gz_interfaces_msg_MaterialColor_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_MaterialColor_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::MaterialColor,ros2_ros_gz_interfaces_msg_MaterialColor_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_MaterialColor_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::MaterialColor>();
    ros2_ros_gz_interfaces_msg_MaterialColor_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_MaterialColor_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_MaterialColor_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::MaterialColor*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_MaterialColor_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::MaterialColor>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_MaterialColor_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER