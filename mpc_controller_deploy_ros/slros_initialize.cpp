#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Simulation";

// For Block Simulation/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_Simulation_std_msgs_Float64> Sub_Simulation_292;

// For Block Simulation/Subscribe1
SimulinkSubscriber<rosestimation::Mpcparam, SL_Bus_Simulation_rosestimation_Mpcparam> Sub_Simulation_110;

// For Block Simulation/Subscribe2
SimulinkSubscriber<rosestimation::Waypoints, SL_Bus_Simulation_rosestimation_Waypoints> Sub_Simulation_266;

// For Block Simulation/Publish1
SimulinkPublisher<geometry_msgs::Pose2D, SL_Bus_Simulation_geometry_msgs_Pose2D> Pub_Simulation_156;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

