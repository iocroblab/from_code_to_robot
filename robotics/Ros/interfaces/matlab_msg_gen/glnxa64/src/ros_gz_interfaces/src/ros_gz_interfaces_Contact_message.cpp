// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/Contact
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
#include "ros_gz_interfaces/msg/contact.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_Contact_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::Contact> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_Contact_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::Contact* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Contact* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_Contact_common::copy_from_struct(ros_gz_interfaces::msg::Contact* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //collision1
        const matlab::data::StructArray collision1_arr = arr["collision1"];
        auto msgClassPtr_collision1 = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
        msgClassPtr_collision1->copy_from_struct(&msg->collision1,collision1_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'collision1' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'collision1' is wrong type; expected a struct.");
    }
    try {
        //collision2
        const matlab::data::StructArray collision2_arr = arr["collision2"];
        auto msgClassPtr_collision2 = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
        msgClassPtr_collision2->copy_from_struct(&msg->collision2,collision2_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'collision2' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'collision2' is wrong type; expected a struct.");
    }
    try {
        //positions
        const matlab::data::StructArray positions_arr = arr["positions"];
        for (auto _positionsarr : positions_arr) {
        	geometry_msgs::msg::Vector3 _val;
        auto msgClassPtr_positions = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_positions->copy_from_struct(&_val,_positionsarr,loader);
        	msg->positions.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'positions' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'positions' is wrong type; expected a struct.");
    }
    try {
        //normals
        const matlab::data::StructArray normals_arr = arr["normals"];
        for (auto _normalsarr : normals_arr) {
        	geometry_msgs::msg::Vector3 _val;
        auto msgClassPtr_normals = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
        msgClassPtr_normals->copy_from_struct(&_val,_normalsarr,loader);
        	msg->normals.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'normals' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'normals' is wrong type; expected a struct.");
    }
    try {
        //depths
        const matlab::data::TypedArray<double> depths_arr = arr["depths"];
        size_t nelem = depths_arr.getNumberOfElements();
        	msg->depths.resize(nelem);
        	std::copy(depths_arr.begin(), depths_arr.begin()+nelem, msg->depths.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'depths' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'depths' is wrong type; expected a double.");
    }
    try {
        //wrenches
        const matlab::data::StructArray wrenches_arr = arr["wrenches"];
        for (auto _wrenchesarr : wrenches_arr) {
        	ros_gz_interfaces::msg::JointWrench _val;
        auto msgClassPtr_wrenches = getCommonObject<ros_gz_interfaces::msg::JointWrench>("ros2_ros_gz_interfaces_msg_JointWrench_common",loader);
        msgClassPtr_wrenches->copy_from_struct(&_val,_wrenchesarr,loader);
        	msg->wrenches.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'wrenches' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'wrenches' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_Contact_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::Contact* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","collision1","collision2","positions","normals","depths","wrenches"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/Contact");
    // collision1
    auto currentElement_collision1 = (msg + ctr)->collision1;
    auto msgClassPtr_collision1 = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
    outArray[ctr]["collision1"] = msgClassPtr_collision1->get_arr(factory, &currentElement_collision1, loader);
    // collision2
    auto currentElement_collision2 = (msg + ctr)->collision2;
    auto msgClassPtr_collision2 = getCommonObject<ros_gz_interfaces::msg::Entity>("ros2_ros_gz_interfaces_msg_Entity_common",loader);
    outArray[ctr]["collision2"] = msgClassPtr_collision2->get_arr(factory, &currentElement_collision2, loader);
    // positions
    auto currentElement_positions = (msg + ctr)->positions;
    auto msgClassPtr_positions = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["positions"] = msgClassPtr_positions->get_arr(factory,&currentElement_positions[0],loader,currentElement_positions.size());
    // normals
    auto currentElement_normals = (msg + ctr)->normals;
    auto msgClassPtr_normals = getCommonObject<geometry_msgs::msg::Vector3>("ros2_geometry_msgs_msg_Vector3_common",loader);
    outArray[ctr]["normals"] = msgClassPtr_normals->get_arr(factory,&currentElement_normals[0],loader,currentElement_normals.size());
    // depths
    auto currentElement_depths = (msg + ctr)->depths;
    outArray[ctr]["depths"] = factory.createArray<ros_gz_interfaces::msg::Contact::_depths_type::const_iterator, double>({currentElement_depths.size(), 1}, currentElement_depths.begin(), currentElement_depths.end());
    // wrenches
    auto currentElement_wrenches = (msg + ctr)->wrenches;
    auto msgClassPtr_wrenches = getCommonObject<ros_gz_interfaces::msg::JointWrench>("ros2_ros_gz_interfaces_msg_JointWrench_common",loader);
    outArray[ctr]["wrenches"] = msgClassPtr_wrenches->get_arr(factory,&currentElement_wrenches[0],loader,currentElement_wrenches.size());
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_Contact_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_Contact_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_Contact_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::Contact,ros2_ros_gz_interfaces_msg_Contact_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_Contact_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::Contact,ros2_ros_gz_interfaces_msg_Contact_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_Contact_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::Contact>();
    ros2_ros_gz_interfaces_msg_Contact_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_Contact_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_Contact_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::Contact*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_Contact_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::Contact>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_Contact_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER