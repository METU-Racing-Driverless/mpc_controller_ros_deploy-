#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>
#include <rosestimation/Mpcparam.h>
#include <rosestimation/Waypoints.h>
#include <std_msgs/Float64.h>
#include "Simulation_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Pose2D* msgPtr, SL_Bus_Simulation_geometry_msgs_Pose2D const* busPtr);
void convertToBus(SL_Bus_Simulation_geometry_msgs_Pose2D* busPtr, geometry_msgs::Pose2D const* msgPtr);

void convertFromBus(rosestimation::Mpcparam* msgPtr, SL_Bus_Simulation_rosestimation_Mpcparam const* busPtr);
void convertToBus(SL_Bus_Simulation_rosestimation_Mpcparam* busPtr, rosestimation::Mpcparam const* msgPtr);

void convertFromBus(rosestimation::Waypoints* msgPtr, SL_Bus_Simulation_rosestimation_Waypoints const* busPtr);
void convertToBus(SL_Bus_Simulation_rosestimation_Waypoints* busPtr, rosestimation::Waypoints const* msgPtr);

void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_Simulation_std_msgs_Float64 const* busPtr);
void convertToBus(SL_Bus_Simulation_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);


#endif
