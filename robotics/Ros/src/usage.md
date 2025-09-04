Execute this code in your docker container to download the required files: 

cd 
mkdir -p fctr/src 
cd fctr/src
git clone --no-checkout https://gitioc.upc.edu/teaching/from-code-to-robot.git
cd from-code-to-robot
git sparse-checkout init --cone
git sparse-checkout set robotics/Ros/src
git checkout Development    # or main, whichever branch you want
cd .. 
colcon build --symlink-install 

start gazebo: 
ros2 launch ur_simulation_gz ur_sim_control.launch.py   initial_joint_controller:=forward_effort_controller   activate_joint_controller:=true

send effort to effort controller: 
ros2 topic pub -r 25 /forward_effort_controller/commands std_msgs/msg/Float64MultiArray -- "{data: [-20,0,0,0,0,0]}"



start Rviz: 
ros2 launch ur_description view_ur.launch.py ur_type:=ur3e

send joints to /joint_states