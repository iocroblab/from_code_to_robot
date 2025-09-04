start gazebo: 
ros2 launch ur_simulation_gz ur_sim_control.launch.py   initial_joint_controller:=forward_effort_controller   activate_joint_controller:=true

send effort to effort controller: 
ros2 topic pub -r 25 /forward_effort_controller/commands std_msgs/msg/Float64MultiArray -- "{data: [-20,0,0,0,0,0]}"



start Rviz: 
ros2 launch ur_description view_ur.launch.py ur_type:=ur3e

send joints to /joint_states