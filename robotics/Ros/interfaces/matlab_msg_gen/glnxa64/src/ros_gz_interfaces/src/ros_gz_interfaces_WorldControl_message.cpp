// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/WorldControl
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
#include "ros_gz_interfaces/msg/world_control.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_WorldControl_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::WorldControl> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_WorldControl_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::WorldControl* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::WorldControl* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_WorldControl_common::copy_from_struct(ros_gz_interfaces::msg::WorldControl* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //pause
        const matlab::data::TypedArray<bool> pause_arr = arr["pause"];
        msg->pause = pause_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'pause' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'pause' is wrong type; expected a logical.");
    }
    try {
        //step
        const matlab::data::TypedArray<bool> step_arr = arr["step"];
        msg->step = step_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'step' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'step' is wrong type; expected a logical.");
    }
    try {
        //multi_step
        const matlab::data::TypedArray<uint32_t> multi_step_arr = arr["multi_step"];
        msg->multi_step = multi_step_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'multi_step' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'multi_step' is wrong type; expected a uint32.");
    }
    try {
        //reset
        const matlab::data::StructArray reset_arr = arr["reset"];
        auto msgClassPtr_reset = getCommonObject<ros_gz_interfaces::msg::WorldReset>("ros2_ros_gz_interfaces_msg_WorldReset_common",loader);
        msgClassPtr_reset->copy_from_struct(&msg->reset,reset_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'reset' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'reset' is wrong type; expected a struct.");
    }
    try {
        //seed
        const matlab::data::TypedArray<uint32_t> seed_arr = arr["seed"];
        msg->seed = seed_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'seed' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'seed' is wrong type; expected a uint32.");
    }
    try {
        //run_to_sim_time
        const matlab::data::StructArray run_to_sim_time_arr = arr["run_to_sim_time"];
        auto msgClassPtr_run_to_sim_time = getCommonObject<builtin_interfaces::msg::Time>("ros2_builtin_interfaces_msg_Time_common",loader);
        msgClassPtr_run_to_sim_time->copy_from_struct(&msg->run_to_sim_time,run_to_sim_time_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'run_to_sim_time' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'run_to_sim_time' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_WorldControl_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::WorldControl* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","pause","step","multi_step","reset","seed","run_to_sim_time"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/WorldControl");
    // pause
    auto currentElement_pause = (msg + ctr)->pause;
    outArray[ctr]["pause"] = factory.createScalar(currentElement_pause);
    // step
    auto currentElement_step = (msg + ctr)->step;
    outArray[ctr]["step"] = factory.createScalar(currentElement_step);
    // multi_step
    auto currentElement_multi_step = (msg + ctr)->multi_step;
    outArray[ctr]["multi_step"] = factory.createScalar(currentElement_multi_step);
    // reset
    auto currentElement_reset = (msg + ctr)->reset;
    auto msgClassPtr_reset = getCommonObject<ros_gz_interfaces::msg::WorldReset>("ros2_ros_gz_interfaces_msg_WorldReset_common",loader);
    outArray[ctr]["reset"] = msgClassPtr_reset->get_arr(factory, &currentElement_reset, loader);
    // seed
    auto currentElement_seed = (msg + ctr)->seed;
    outArray[ctr]["seed"] = factory.createScalar(currentElement_seed);
    // run_to_sim_time
    auto currentElement_run_to_sim_time = (msg + ctr)->run_to_sim_time;
    auto msgClassPtr_run_to_sim_time = getCommonObject<builtin_interfaces::msg::Time>("ros2_builtin_interfaces_msg_Time_common",loader);
    outArray[ctr]["run_to_sim_time"] = msgClassPtr_run_to_sim_time->get_arr(factory, &currentElement_run_to_sim_time, loader);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_WorldControl_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_WorldControl_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_WorldControl_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::WorldControl,ros2_ros_gz_interfaces_msg_WorldControl_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_WorldControl_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::WorldControl,ros2_ros_gz_interfaces_msg_WorldControl_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_WorldControl_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::WorldControl>();
    ros2_ros_gz_interfaces_msg_WorldControl_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_WorldControl_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_WorldControl_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::WorldControl*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_WorldControl_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::WorldControl>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_WorldControl_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER