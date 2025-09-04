// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/Light
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
#include "ros_gz_interfaces/msg/light.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_Light_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::Light> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_Light_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::Light* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Light* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_Light_common::copy_from_struct(ros_gz_interfaces::msg::Light* msg, const matlab::data::Struct& arr,
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
        //type
        const matlab::data::TypedArray<uint8_t> type_arr = arr["type"];
        msg->type = type_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'type' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'type' is wrong type; expected a uint8.");
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
        //attenuation_constant
        const matlab::data::TypedArray<float> attenuation_constant_arr = arr["attenuation_constant"];
        msg->attenuation_constant = attenuation_constant_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'attenuation_constant' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'attenuation_constant' is wrong type; expected a single.");
    }
    try {
        //attenuation_linear
        const matlab::data::TypedArray<float> attenuation_linear_arr = arr["attenuation_linear"];
        msg->attenuation_linear = attenuation_linear_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'attenuation_linear' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'attenuation_linear' is wrong type; expected a single.");
    }
    try {
        //attenuation_quadratic
        const matlab::data::TypedArray<float> attenuation_quadratic_arr = arr["attenuation_quadratic"];
        msg->attenuation_quadratic = attenuation_quadratic_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'attenuation_quadratic' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'attenuation_quadratic' is wrong type; expected a single.");
    }
    try {
        //direction
        const matlab::data::StructArray direction_arr = arr["direction"];
        auto msgClassPtr_direction = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_direction->copy_from_struct(&msg->direction,direction_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'direction' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'direction' is wrong type; expected a struct.");
    }
    try {
        //range
        const matlab::data::TypedArray<float> range_arr = arr["range"];
        msg->range = range_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'range' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'range' is wrong type; expected a single.");
    }
    try {
        //cast_shadows
        const matlab::data::TypedArray<bool> cast_shadows_arr = arr["cast_shadows"];
        msg->cast_shadows = cast_shadows_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'cast_shadows' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'cast_shadows' is wrong type; expected a logical.");
    }
    try {
        //spot_inner_angle
        const matlab::data::TypedArray<float> spot_inner_angle_arr = arr["spot_inner_angle"];
        msg->spot_inner_angle = spot_inner_angle_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'spot_inner_angle' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'spot_inner_angle' is wrong type; expected a single.");
    }
    try {
        //spot_outer_angle
        const matlab::data::TypedArray<float> spot_outer_angle_arr = arr["spot_outer_angle"];
        msg->spot_outer_angle = spot_outer_angle_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'spot_outer_angle' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'spot_outer_angle' is wrong type; expected a single.");
    }
    try {
        //spot_falloff
        const matlab::data::TypedArray<float> spot_falloff_arr = arr["spot_falloff"];
        msg->spot_falloff = spot_falloff_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'spot_falloff' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'spot_falloff' is wrong type; expected a single.");
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
        //parent_id
        const matlab::data::TypedArray<uint32_t> parent_id_arr = arr["parent_id"];
        msg->parent_id = parent_id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'parent_id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'parent_id' is wrong type; expected a uint32.");
    }
    try {
        //intensity
        const matlab::data::TypedArray<float> intensity_arr = arr["intensity"];
        msg->intensity = intensity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'intensity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'intensity' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_Light_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Light* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","name","POINT","SPOT","DIRECTIONAL","type","pose","diffuse","specular","attenuation_constant","attenuation_linear","attenuation_quadratic","direction","range","cast_shadows","spot_inner_angle","spot_outer_angle","spot_falloff","id","parent_id","intensity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/Light");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // name
    auto currentElement_name = (msg + ctr)->name;
    outArray[ctr]["name"] = factory.createCharArray(currentElement_name);
    // POINT
    auto currentElement_POINT = (msg + ctr)->POINT;
    outArray[ctr]["POINT"] = factory.createScalar(currentElement_POINT);
    // SPOT
    auto currentElement_SPOT = (msg + ctr)->SPOT;
    outArray[ctr]["SPOT"] = factory.createScalar(currentElement_SPOT);
    // DIRECTIONAL
    auto currentElement_DIRECTIONAL = (msg + ctr)->DIRECTIONAL;
    outArray[ctr]["DIRECTIONAL"] = factory.createScalar(currentElement_DIRECTIONAL);
    // type
    auto currentElement_type = (msg + ctr)->type;
    outArray[ctr]["type"] = factory.createScalar(currentElement_type);
    // pose
    auto currentElement_pose = (msg + ctr)->pose;
    auto msgClassPtr_pose = getCommonObject<geometry_msgs::msg::Pose>("ros2_geometry_msgs_msg_Pose_common",loader);
    outArray[ctr]["pose"] = msgClassPtr_pose->get_arr(factory, &currentElement_pose, loader);
    // diffuse
    auto currentElement_diffuse = (msg + ctr)->diffuse;
    auto msgClassPtr_diffuse = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["diffuse"] = msgClassPtr_diffuse->get_arr(factory, &currentElement_diffuse, loader);
    // specular
    auto currentElement_specular = (msg + ctr)->specular;
    auto msgClassPtr_specular = getCommonObject<std_msgs::msg::ColorRGBA>("ros2_std_msgs_msg_ColorRGBA_common",loader);
    outArray[ctr]["specular"] = msgClassPtr_specular->get_arr(factory, &currentElement_specular, loader);
    // attenuation_constant
    auto currentElement_attenuation_constant = (msg + ctr)->attenuation_constant;
    outArray[ctr]["attenuation_constant"] = factory.createScalar(currentElement_attenuation_constant);
    // attenuation_linear
    auto currentElement_attenuation_linear = (msg + ctr)->attenuation_linear;
    outArray[ctr]["attenuation_linear"] = factory.createScalar(currentElement_attenuation_linear);
    // attenuation_quadratic
    auto currentElement_attenuation_quadratic = (msg + ctr)->attenuation_quadratic;
    outArray[ctr]["attenuation_quadratic"] = factory.createScalar(currentElement_attenuation_quadratic);
    // direction
    auto currentElement_direction = (msg + ctr)->direction;
    auto msgClassPtr_direction = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["direction"] = msgClassPtr_direction->get_arr(factory, &currentElement_direction, loader);
    // range
    auto currentElement_range = (msg + ctr)->range;
    outArray[ctr]["range"] = factory.createScalar(currentElement_range);
    // cast_shadows
    auto currentElement_cast_shadows = (msg + ctr)->cast_shadows;
    outArray[ctr]["cast_shadows"] = factory.createScalar(currentElement_cast_shadows);
    // spot_inner_angle
    auto currentElement_spot_inner_angle = (msg + ctr)->spot_inner_angle;
    outArray[ctr]["spot_inner_angle"] = factory.createScalar(currentElement_spot_inner_angle);
    // spot_outer_angle
    auto currentElement_spot_outer_angle = (msg + ctr)->spot_outer_angle;
    outArray[ctr]["spot_outer_angle"] = factory.createScalar(currentElement_spot_outer_angle);
    // spot_falloff
    auto currentElement_spot_falloff = (msg + ctr)->spot_falloff;
    outArray[ctr]["spot_falloff"] = factory.createScalar(currentElement_spot_falloff);
    // id
    auto currentElement_id = (msg + ctr)->id;
    outArray[ctr]["id"] = factory.createScalar(currentElement_id);
    // parent_id
    auto currentElement_parent_id = (msg + ctr)->parent_id;
    outArray[ctr]["parent_id"] = factory.createScalar(currentElement_parent_id);
    // intensity
    auto currentElement_intensity = (msg + ctr)->intensity;
    outArray[ctr]["intensity"] = factory.createScalar(currentElement_intensity);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_Light_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_Light_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_Light_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::Light,ros2_ros_gz_interfaces_msg_Light_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_Light_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::Light,ros2_ros_gz_interfaces_msg_Light_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_Light_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::Light>();
    ros2_ros_gz_interfaces_msg_Light_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_Light_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_Light_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::Light*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_Light_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::Light>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_Light_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER