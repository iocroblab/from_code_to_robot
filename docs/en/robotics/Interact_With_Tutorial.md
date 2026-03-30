
# Interactions 

Below you will find a summary of all functions used in the tutorial. Additionally the setup steps to interact with the real hardware, depending on your operating system, are outlined below. 

# StartTutorialApplication

This command launches all tutorial tools from MATLAB using one simple interface.


`StartTutorialApplication(Application, Name,Value,...)`


You only choose:

1.  What to launch
2. Optional settings (robot, controller, etc.)
### Available Applications
| **Command**  | **What it launches**   |
| :-- | :-- |
| `'Rviz'`  | Robot visualization   |
| `'Simulation'`  | Gazebo simulation   |
| `'Hardware'`  | Real robot driver   |
| `'Teleoperation'`  | Keyboard control   |
| `'Trajectory'`  | Trajectory publisher    |
| `'Safety_nodes'`  | Safety node   |
| `'Terminal'`  | Ready\-to\-use ROS terminal   |

### **Environment Settings (Docker and Workspace)**

You can control whether the tutorial runs inside Docker and which workspace/container is used.


**Use Docker or native system**


`'Docker',true   % default`

-  `true` → runs inside the tutorial Docker container 
-  `false` → runs directly on your local Linux system 

Example (native Linux):


`StartTutorialApplication('Simulation','Docker',false);`


**Select Docker container name**


`'DockerName','gz-modified'`


Default container: `gz-modified`


Use this if you created your own container or renamed it.


Example:


`StartTutorialApplication('Rviz', 'Docker',true, 'DockerName','my_ros_container');`


**Select workspace**


`'workspace','git_ws'`


Default workspace: `git_ws` (inside your home folder)


Change this if you use a different ROS workspace.


Example:


`StartTutorialApplication('Simulation', ...`


 `'workspace','ros2_ws');` 


You can also use an absolute path:


`StartTutorialApplication('Terminal', ...`


 `'workspace','/home/user/my_ws');` 

## Most Useful Options

Select robot


`'ur_type','ur3e' (default)`


Available robots:

| **Value**  | **Robot**   |
| :-- | :-- |
| `'ur3e'`  | Universal Robots UR3e   |
| `'ur5e'`  | Universal Robots UR5e   |
| `'ur10e'`  | Universal Robots UR10e   |
| `'ur16e'`  | Universal Robots UR16e   |
| `'ur3'`  | Universal Robots UR3 (CB series)   |
| `'ur5'`  | Universal Robots UR5 (CB series)   |
| `'ur10'`  | Universal Robots UR10 (CB series)   |
| `'threelink'`  | 3\-link tutorial manipulator   |


**Select controller mode**


`'controller','Torque'`


Available modes:

| **Value**  | **Effect**   |
| :-- | :-- |
| `'Position'`  | Position control   |
| `'Speed', 'Velocity'`  | Velocity control   |
| `'Torque', 'Effort'`  | Effort control   |
| `'Trajectory', 'Scaled'`  | Scaled trajectory controller   |


**Hardware\-only options**


`'robot_ip','192.168.56.101'`


`'computer_ip','192.168.56.1'   % required when using Docker`

### Examples

**Start simulation with torque control**


`StartTutorialApplication('Simulation', 'ur_type','ur3e', 'controller','Torque');`


**Start real robot driver**


`StartTutorialApplication('Hardware','robot_ip','192.168.56.101', 'computer_ip','192.168.56.1', 'controller','Trajectory', 'docker',false);`


**Start trajectory path publisher**


`StartTutorialApplication('Trajectory');`


**Open a ready\-to\-use ROS terminal**


`StartTutorialApplication('Terminal');`

# StopTutorialApplication 

StopTutorialApplication('docker',false)


This function will stop all current ROS processes.


# SendJointTrajectory

Sends a joint configuration or a trajectory of configurations to the controller.


Input 1: 6xN array of configurations 


Input 2 (optional): time to completion


SendJointTrajectory(q\_traj, time\_to\_completion)


**IMPORTANT**: When launching multiple simulations or drivers you may get an error when using the function. To resolve it clear the function after restarting any application. 

```matlab
clear SendJointTrajectory
```

# SendJointPosition

Send a 6x1 joint configuration to the simulation. 


SendJointPosition(q) is used for the forward\_position\_controller. (Not used in this tutorial) 

# SendJointSpeeds

Send a 6x1 joint velocity array to the simulation. 


SendJointSpeeds(qd)

# SendJointTorques

Send a 6x1 joint torque array to the simulation. 


SendJointTorques(tau)

# SetRosDomain

SetRosDomain(Domain\_ID) is used to set your RosDomain systemwide. Use this when your computer is connected to a network of other ROS computers to avoid unwanted interactions between them. 

# GetJointStates

GetJointStates() returns the current joint configuration as a 6x1 array.

# GetJointSpeeds

GetJointSpeeds() returns the latest joint velocities as a 6x1 array.

# GetJointEfforts

GetJointEfforts() returns the latest applied joint torques as a 6x1 array.

# GetJointValues

GetJointValues() returns all of the above with a timestamp. You can also only select one value: 


\[pos, time\] = GetJointValues('State')


Other options are: 


'speed', 'effort', 'all', 'threelink'


**IMPORTANT**: When using the threelink manipulator simulation package, 'threelink' has to be selected.

# GetTeleoperation

This function is designed to be used with the 'Teleoperation' application. It returns a 6x1 twist vector and the workmode as a second output. 


\[twist, workmode\] = GetTeleopertaion() 

# Visualization (Rviz)

Rviz is a purely visualization application. We can send joint configurations to be instantly visualized in the environment without any real movement being simulated. You can interact with the robot in Rviz with the function JointStatesToRviz. 

# JointStatesToRviz(.....)

This function allows you to send a joint configuration to be visualized as : 


JointStatesToRviz(q)


You can also send trajectories to be displayed in equal timesteps: 


JointStatesToRviz(q\_trajectory, ur\_model, time\_to\_completion)


where q\_trajectory is a 6xN array. 


you can define the time\_to\_completion. Selecting a ur\_model lets you visualize the trajectory of the tool frame or the manipulability ellipsoids. 

### **Optional Inputs (Name–Value)**

**Visualization features**

-  `'Ellipsoid'` (true/false) – Show manipulability ellipsoid in RViz 
-  `'EllipsoidKind'` – `'trans'` (translation) \[default\] or `'rot'` (rotation) 
-  `'EllipsoidDuality'` – `'velocity'` (default) or `'effort'` (force/torque dual) 
-  `'EllipsoidResolution'` – Mesh resolution (higher = smoother) 
-  `'EllipsoidEvery'` – Publish ellipsoid every Nth frame (performance tuning) 

**Frames and topics**

-  `'BaseFrame'` – RViz reference frame (default: `base_link`) 
-  `'ToolFrame'` – End\-effector frame (default: `tool0`) 
-  `'JointStateTopic'` – Topic for joint states (default: `/joint_states`) 
-  `'EllipsoidTopic'` – Topic for ellipsoid cloud 
-  `'TrajectoryTopic'` – Topic for trajectory pointcloud 

**Trajectory visualization**

-  `'Trajectory'` (true/false) – Show EE path as yellow pointcloud 
-  Auto\-enabled when multiple joint states are provided 
-  `'PrecomputeEllipsoids'` – Precompute ellipsoids for smoother playback 

**Control flags**

-  `'SendJointStates'` (true/false) – Enable/disable publishing `/joint_states` 

**NOTE**: You can the visualization tools of this function in simulation by setting the SendJointStates flag to false. With this flag set to false the function will only publish the Ellipsoid but not the joint states as they are provided by the simulation itself. 

# Simulation 
# SetSimulationSpeed

This function lets your reduce the simulation speed of your gazebo application. Call it with 


SetSimulationSpeed(speed\_factor, 'docker',false) 

# Univeral Robots Hardware 

To interact with a physical UR robot, follow the setup steps depending on your operating system. 

# General Cobot Setup

Make sure to install a polyscope version that allows the use of the effort controller. 


Depending on your robot series the version should be at least: 

-  PolyScope X 10.11 
-  PolyScope 5.24 
# Robot Safety Plane Setup

It is recommanded to test any code in simulation before implementing it on the real hardare!


Additionally it is recommanded to setup safety planes in the teach pendant that constrain the robot to the physical safe zones in your laboratory environment. 


Following the documentation 


[https://www.universal\-robots.com/manuals/EN/HTML/SW10\_6/Content/prod\-usr\-man/software/PolyScopeX/psx\-safety/psx\-planes.htm](https://www.universal-robots.com/manuals/EN/HTML/SW10_6/Content/prod-usr-man/software/PolyScopeX/psx-safety/psx-planes.htm)


you can define planes that the robot tool and elbow cannot pass. This can help to reduce the risk of potential destructive behavior.

# Important Notes
-  When using the real hardare, start with smaller gains as in your simulation and increase them gradually.  
-  When using the effort control, keep in mind that your physical robot joints have friction (which is not considered in simulation). If your robot has a gripper attachment, make sure to account for the additional mass and new center of gravity in your dynamic model. Otherwise you may face trouble reaching your desired configuration.  
# Ubuntu Setup

Communication between the Universal Robot and the control computer is implemented via ROS.


The required ROS software stack is provided within the tutorial workspace.

### Robot Setup

Follow the documentation below to setup your UR hardware. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/robot\_setup.html\#robot\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/robot_setup.html#robot-setup>)

### Network Setup 

Follow the documentation below to setup your network on the robot and your ubuntu host mashine. Remember the IPs that you select as you will need them to start the universal robots driver. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/network\_setup.html\#network\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/network_setup.html#network-setup>) 

### Additional Setup

For reliable robot communication and stable control behavior, it is recommended to configure the Linux host system with real\-time capabilities. This reduces communication latency and timing jitter during robot operation. Detailed setup instructions are available in the official Universal Robots documentation:


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/real\_time.html\#real\-time\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/real_time.html#real-time-setup>)


**Note:**


The real\-time configuration must be applied on the host operating system. Applying real\-time settings inside a Docker container has no effect, as containers rely on the host kernel.

# Connect to the Robot
1.  Start the Robot
2. Make sure the network is setup correctly
3. Confirm connection by pinging the robot (In a terminal run "ping robot\_ip")
4. Start a new program and select the external control URCap you've downloaded previously (Robot setup)
5. Start the Driver as StartTutorialApplication('Hardare', 'model', urmodel, 'controller', 'velocity', 'robot\_ip',robot\_ip, 'computer\_ip', host\_mashine\_ip)
6. Start program on the teach pendant
7. Set the teach pendant to remote control mode

By default it will load the scaled joint trajectory controller which you can interact with using the SendJointTrajectory function. 

# Interact with the Robot

All functions you have been using in simulation can be used with on the real hardware. Be cautios and always ready to hit the emergency button. 

# SwitchController

To change the controller after the driver is running you can use the function SwitchController("desired controller") to change the controller. Input the desired controller as (or their ros2 name): 

-  Position (not recommanded, use trajectory controller instead)  
-  Velocity / Speed  
-  Torque / Effort  
-  Scaled / Trajectory  

# Windows Setup (also availibe for Ubuntu)

On Windows, direct robot communication is performed without ROS. Instead, the interaction with the Universal Robot is implemented using the **MATLAB Hardware Support Package for Universal Robots**, which relies on the Real\-Time Data Exchange (RTDE) protocol.


This interface enables direct communication between MATLAB and the robot controller and provides high\-level APIs for motion execution, state feedback, and I/O access. Installation and configuration instructions are available in the official MathWorks documentation:


[https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html)


In contrast to the Ubuntu setup, this approach does not use the ROS\-based control stack. Consequently, the custom ROS utilities and helper functions provided in this tutorial are not compatible with the Windows configuration.


However, most operations covered in the tutorial (e.g., joint motion, trajectory execution, and state monitoring) can be performed using equivalent MATLAB functions provided by the Hardware Support Package. The following sections list the corresponding alternatives where applicable.

# Connect To The Robot 
1.  Load URServerScript.script as Programm on the teach pendant
2. Enable Remote Control on the teach pendant
3. Turn on Robot
4. Setup Environment on Matlab (Add\-Ons \-\-> Manage Add\-Ons \-\->Setup Robotic System Toolbox Support Package)

### Equivalent Functions and usage

Start by setting up your RTDE object as: 

```matlab
robot_ip = '192.168.56.101'; %use your robot ip
ur = urRTDEClient(robot_ip);
%optinal: ur = urRTDEClient(robot_ip, "RTDEFrequency",500); 
```

This object needs to be parsed to all RTDE functions. 


 **Example:** 

```matlab
q_config = [0,-pi/2,0,-pi/2,0,0]; 
sendJointConfiguration(ur, q_config); 
```

To interact with the robot substitute the tutorial functions for their RTDE equivalent. 


for more information on their usage please refer [https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html) 

|||||
| :-- | :-- | :-- | :-- |
| **Tutorial Function**  | **Tutorial FUnction Usage**  | **RTDE Function Equivalent**  | **RTDE Function Usage**   |
| GetJointStates  | GetJointStates()  | readJointConfiguration  | readJointConfiguration(ur)   |
| GetJointSpeeds  | GetJointSpeeds()  | readJointVelocity  | readJointVelocity(ur)   |
| SendJointPositions (used in Simulation)  <br> **or**  <br> JointStatesToRviz (used in early tutorial modules for Visualization)  | SendJointPositions(q) <br> **or**  <br> JointStatesToRviz(q)  | sendJointConfigurationAndWait  | sendJointConfigurationAndWait(ur, q) <br> optional: sendJointConfigurationAndWait(ur, q,Endtime=time)    |
| SendJointSpeeds  | SendJointSpeeds(qdot)  | sendSpeedJCommands  | sendSpeedJCommands(ur , qdot)   |
| SendJointTrajectory  | SendJointTrajectory(q\_trajectory, time\_to\_completion)  | followJointWaypoints  | followJointWaypoints(ur, q\_trajectory) <br> optional: followJointWaypoints(ur, q\_trajectory, waypointTimes=\[t1,t2,t3,t4\]) <br> with ti being the absolute time from the start.   |


 **NOTE:** Currently the hardware support package for universal robots does not include a function to send torque commands. To use the effort control, it is highly recommanded to use a ubuntu host mashine with a real time kernel. 


