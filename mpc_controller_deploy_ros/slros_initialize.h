#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "Simulation_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Simulation/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_Simulation_std_msgs_Float64> Sub_Simulation_292;

// For Block Simulation/Subscribe1
extern SimulinkSubscriber<rosestimation::Mpcparam, SL_Bus_Simulation_rosestimation_Mpcparam> Sub_Simulation_110;

// For Block Simulation/Subscribe2
extern SimulinkSubscriber<rosestimation::Waypoints, SL_Bus_Simulation_rosestimation_Waypoints> Sub_Simulation_266;

// For Block Simulation/Publish1
extern SimulinkPublisher<geometry_msgs::Pose2D, SL_Bus_Simulation_geometry_msgs_Pose2D> Pub_Simulation_156;

void slros_node_init(int argc, char** argv);

#endif
