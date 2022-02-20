#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Simulation_geometry_msgs_Pose2D and geometry_msgs::Pose2D

void convertFromBus(geometry_msgs::Pose2D* msgPtr, SL_Bus_Simulation_geometry_msgs_Pose2D const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose2D");

  msgPtr->theta =  busPtr->Theta;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
}

void convertToBus(SL_Bus_Simulation_geometry_msgs_Pose2D* busPtr, geometry_msgs::Pose2D const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose2D");

  busPtr->Theta =  msgPtr->theta;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
}


// Conversions between SL_Bus_Simulation_rosestimation_Mpcparam and rosestimation::Mpcparam

void convertFromBus(rosestimation::Mpcparam* msgPtr, SL_Bus_Simulation_rosestimation_Mpcparam const* busPtr)
{
  const std::string rosMessageType("rosestimation/Mpcparam");

  convertFromBusVariablePrimitiveArray(msgPtr->left_parameters, busPtr->LeftParameters, busPtr->LeftParameters_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->right_parameters, busPtr->RightParameters, busPtr->RightParameters_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->targetPoint, busPtr->TargetPoint, busPtr->TargetPoint_SL_Info);
}

void convertToBus(SL_Bus_Simulation_rosestimation_Mpcparam* busPtr, rosestimation::Mpcparam const* msgPtr)
{
  const std::string rosMessageType("rosestimation/Mpcparam");

  convertToBusVariablePrimitiveArray(busPtr->LeftParameters, busPtr->LeftParameters_SL_Info, msgPtr->left_parameters, slros::EnabledWarning(rosMessageType, "left_parameters"));
  convertToBusVariablePrimitiveArray(busPtr->RightParameters, busPtr->RightParameters_SL_Info, msgPtr->right_parameters, slros::EnabledWarning(rosMessageType, "right_parameters"));
  convertToBusVariablePrimitiveArray(busPtr->TargetPoint, busPtr->TargetPoint_SL_Info, msgPtr->targetPoint, slros::EnabledWarning(rosMessageType, "targetPoint"));
}


// Conversions between SL_Bus_Simulation_rosestimation_Waypoints and rosestimation::Waypoints

void convertFromBus(rosestimation::Waypoints* msgPtr, SL_Bus_Simulation_rosestimation_Waypoints const* busPtr)
{
  const std::string rosMessageType("rosestimation/Waypoints");

  convertFromBusVariablePrimitiveArray(msgPtr->x, busPtr->X, busPtr->X_SL_Info);
  convertFromBusVariablePrimitiveArray(msgPtr->y, busPtr->Y, busPtr->Y_SL_Info);
}

void convertToBus(SL_Bus_Simulation_rosestimation_Waypoints* busPtr, rosestimation::Waypoints const* msgPtr)
{
  const std::string rosMessageType("rosestimation/Waypoints");

  convertToBusVariablePrimitiveArray(busPtr->X, busPtr->X_SL_Info, msgPtr->x, slros::EnabledWarning(rosMessageType, "x"));
  convertToBusVariablePrimitiveArray(busPtr->Y, busPtr->Y_SL_Info, msgPtr->y, slros::EnabledWarning(rosMessageType, "y"));
}


// Conversions between SL_Bus_Simulation_std_msgs_Float64 and std_msgs::Float64

void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_Simulation_std_msgs_Float64 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float64");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_Simulation_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float64");

  busPtr->Data =  msgPtr->data;
}

