// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/SensorNoise
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
#include "ros_gz_interfaces/msg/sensor_noise.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_SensorNoise_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::SensorNoise> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_SensorNoise_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::SensorNoise* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::SensorNoise* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_SensorNoise_common::copy_from_struct(ros_gz_interfaces::msg::SensorNoise* msg, const matlab::data::Struct& arr,
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
        //type
        const matlab::data::TypedArray<uint8_t> type_arr = arr["type"];
        msg->type = type_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'type' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'type' is wrong type; expected a uint8.");
    }
    try {
        //mean
        const matlab::data::TypedArray<double> mean_arr = arr["mean"];
        msg->mean = mean_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mean' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mean' is wrong type; expected a double.");
    }
    try {
        //stddev
        const matlab::data::TypedArray<double> stddev_arr = arr["stddev"];
        msg->stddev = stddev_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'stddev' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'stddev' is wrong type; expected a double.");
    }
    try {
        //bias_mean
        const matlab::data::TypedArray<double> bias_mean_arr = arr["bias_mean"];
        msg->bias_mean = bias_mean_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'bias_mean' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'bias_mean' is wrong type; expected a double.");
    }
    try {
        //bias_stddev
        const matlab::data::TypedArray<double> bias_stddev_arr = arr["bias_stddev"];
        msg->bias_stddev = bias_stddev_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'bias_stddev' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'bias_stddev' is wrong type; expected a double.");
    }
    try {
        //precision
        const matlab::data::TypedArray<double> precision_arr = arr["precision"];
        msg->precision = precision_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'precision' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'precision' is wrong type; expected a double.");
    }
    try {
        //dynamic_bias_stddev
        const matlab::data::TypedArray<double> dynamic_bias_stddev_arr = arr["dynamic_bias_stddev"];
        msg->dynamic_bias_stddev = dynamic_bias_stddev_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'dynamic_bias_stddev' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'dynamic_bias_stddev' is wrong type; expected a double.");
    }
    try {
        //dynamic_bias_correlation_time
        const matlab::data::TypedArray<double> dynamic_bias_correlation_time_arr = arr["dynamic_bias_correlation_time"];
        msg->dynamic_bias_correlation_time = dynamic_bias_correlation_time_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'dynamic_bias_correlation_time' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'dynamic_bias_correlation_time' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_SensorNoise_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::SensorNoise* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","NONE","GAUSSIAN","GAUSSIAN_QUANTIZED","header","type","mean","stddev","bias_mean","bias_stddev","precision","dynamic_bias_stddev","dynamic_bias_correlation_time"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/SensorNoise");
    // NONE
    auto currentElement_NONE = (msg + ctr)->NONE;
    outArray[ctr]["NONE"] = factory.createScalar(currentElement_NONE);
    // GAUSSIAN
    auto currentElement_GAUSSIAN = (msg + ctr)->GAUSSIAN;
    outArray[ctr]["GAUSSIAN"] = factory.createScalar(currentElement_GAUSSIAN);
    // GAUSSIAN_QUANTIZED
    auto currentElement_GAUSSIAN_QUANTIZED = (msg + ctr)->GAUSSIAN_QUANTIZED;
    outArray[ctr]["GAUSSIAN_QUANTIZED"] = factory.createScalar(currentElement_GAUSSIAN_QUANTIZED);
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // type
    auto currentElement_type = (msg + ctr)->type;
    outArray[ctr]["type"] = factory.createScalar(currentElement_type);
    // mean
    auto currentElement_mean = (msg + ctr)->mean;
    outArray[ctr]["mean"] = factory.createScalar(currentElement_mean);
    // stddev
    auto currentElement_stddev = (msg + ctr)->stddev;
    outArray[ctr]["stddev"] = factory.createScalar(currentElement_stddev);
    // bias_mean
    auto currentElement_bias_mean = (msg + ctr)->bias_mean;
    outArray[ctr]["bias_mean"] = factory.createScalar(currentElement_bias_mean);
    // bias_stddev
    auto currentElement_bias_stddev = (msg + ctr)->bias_stddev;
    outArray[ctr]["bias_stddev"] = factory.createScalar(currentElement_bias_stddev);
    // precision
    auto currentElement_precision = (msg + ctr)->precision;
    outArray[ctr]["precision"] = factory.createScalar(currentElement_precision);
    // dynamic_bias_stddev
    auto currentElement_dynamic_bias_stddev = (msg + ctr)->dynamic_bias_stddev;
    outArray[ctr]["dynamic_bias_stddev"] = factory.createScalar(currentElement_dynamic_bias_stddev);
    // dynamic_bias_correlation_time
    auto currentElement_dynamic_bias_correlation_time = (msg + ctr)->dynamic_bias_correlation_time;
    outArray[ctr]["dynamic_bias_correlation_time"] = factory.createScalar(currentElement_dynamic_bias_correlation_time);
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_SensorNoise_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_SensorNoise_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_SensorNoise_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::SensorNoise,ros2_ros_gz_interfaces_msg_SensorNoise_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_SensorNoise_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::SensorNoise,ros2_ros_gz_interfaces_msg_SensorNoise_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_SensorNoise_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::SensorNoise>();
    ros2_ros_gz_interfaces_msg_SensorNoise_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_SensorNoise_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_SensorNoise_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::SensorNoise*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_SensorNoise_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::SensorNoise>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_SensorNoise_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER