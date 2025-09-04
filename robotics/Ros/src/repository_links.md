Rviz: 

Gazebo: 
https://github.com/UniversalRobots/Universal_Robots_ROS2_GZ_Simulation.git


Other Ros extentions :


sudo apt install ros-jazzy-controller-manager
sudo apt install ros-jazzy-ros2-controllers ros-jazzy-ros2-control
sudo apt install ros-jazzy-rqt-joint-trajectory-controller
sudo apt install ros-jazzy-rqt-controller-manager
sudo apt install ros-jazzy-ros-gz ros-jazzy-gz-ros2-control ros-jazzy-ros-gz-bridge
sudo apt install ros-jazzy-ros-gz-image ros-jazzy-ros-gz-interfaces ros-jazzy-ros-gz-sim
sudo apt install ros-jazzy-ros-gz-sim-demos ros-jazzy-ur-simulation-gz
sudo apt install ros-jazzy-controller-manager
sudo apt install ros-jazzy-ros2-controllers ros-jazzy-ros2-control
sudo apt install ros-jazzy-rqt-joint-trajectory-controller
sudo apt install ros-jazzy-rqt-controller-manager
sudo apt install ros-jazzy-ros-gz ros-jazzy-gz-ros2-control ros-jazzy-ros-gz-bridge
sudo apt install ros-jazzy-ros-gz-image ros-jazzy-ros-gz-interfaces ros-jazzy-ros-gz-sim
sudo apt install ros-jazzy-ros-gz-sim-demos ros-jazzy-ur-simulation-gz

sudo apt update
rosdep update
rosdep install --from-paths src --ignore-src -r -y


rqt --force-discover
