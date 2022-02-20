# mpc_controller_ros_deploy-
MPC controller developed on MATLAB deployed to be used as a standalone ROS node


## Topics

**/midpoints (input)**

Used for pure pursuit controller, array of points indicating centerline of route.

**/mpcparam (input)**

Used for boundary determination in MPC controller. Contains paramaters for circles representing left and right boundary (center_x, center_y, radius).

**/signal (input)**

Run pure pursuit if signal <= 0, run MPC otherwise.

**/state (output)**

Current state of vehicle. Will be replaced by driving command. Plant simulation is also made by this node which will not be the case when used with a simulator or real vehicle.
