// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for ros_gz_interfaces/StringVec
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
#include "ros_gz_interfaces/msg/string_vec.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_msg_StringVec_common : public MATLABROS2MsgInterface<ros_gz_interfaces::msg::StringVec> {
  public:
    virtual ~ros2_ros_gz_interfaces_msg_StringVec_common(){}
    virtual void copy_from_struct(ros_gz_interfaces::msg::StringVec* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::StringVec* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_ros_gz_interfaces_msg_StringVec_common::copy_from_struct(ros_gz_interfaces::msg::StringVec* msg, const matlab::data::Struct& arr,
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
        //data
        const matlab::data::CellArray data_cellarr = arr["data"];
        size_t nelem = data_cellarr.getNumberOfElements();
        for (size_t idx=0; idx < nelem; ++idx){
        	const matlab::data::CharArray data_arr = data_cellarr[idx];
        	msg->data.push_back(data_arr.toAscii());
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'data' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'data' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_ros_gz_interfaces_msg_StringVec_common::get_arr(MDFactory_T& factory, const ros_gz_interfaces::msg::StringVec* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","data"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("ros_gz_interfaces/StringVec");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // data
    auto currentElement_data = (msg + ctr)->data;
    auto dataoutCell = factory.createCellArray({currentElement_data.size(),1});
    for(size_t idxin = 0; idxin < currentElement_data.size(); ++ idxin){
    	dataoutCell[idxin] = factory.createCharArray(currentElement_data[idxin]);
    }
    outArray[ctr]["data"] = dataoutCell;
    }
    return std::move(outArray);
  } 
class ROS_GZ_INTERFACES_EXPORT ros2_ros_gz_interfaces_StringVec_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_ros_gz_interfaces_StringVec_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_ros_gz_interfaces_StringVec_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<ros_gz_interfaces::msg::StringVec,ros2_ros_gz_interfaces_msg_StringVec_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_ros_gz_interfaces_StringVec_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<ros_gz_interfaces::msg::StringVec,ros2_ros_gz_interfaces_msg_StringVec_common>>();
  }
  std::shared_ptr<void> ros2_ros_gz_interfaces_StringVec_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<ros_gz_interfaces::msg::StringVec>();
    ros2_ros_gz_interfaces_msg_StringVec_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_ros_gz_interfaces_StringVec_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_ros_gz_interfaces_msg_StringVec_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (ros_gz_interfaces::msg::StringVec*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_msg_StringVec_common, MATLABROS2MsgInterface<ros_gz_interfaces::msg::StringVec>)
CLASS_LOADER_REGISTER_CLASS(ros2_ros_gz_interfaces_StringVec_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER