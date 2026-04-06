
# Installation Guide – From Code to Robot Tutorial

This tutorial provides a **reproducible ROS 2 Jazzy environment** compatible with MATLAB R2025.


It supports:

-  Docker\-based environments (recommended) 
-  Native Ubuntu installation (advanced users) 
# MATLAB Requirements
# Supported Versions
-  MATLAB R2025a 
-  MATLAB R2025b 
# Required Toolboxes
-  Simulink 
-  ROS Toolbox 
-  Robotics System Toolbox 
-  Symbolic Math Toolbox 
-  Universal Robots Support Package 
# Supported Environments

You can run this tutorial using:

-  Windows 11 + WSL2 + Docker 
-  Ubuntu 24 + Docker 
-  Ubuntu 24 Native (no Docker) 
# Installation Using the Script

All environments use:


bash install.sh <mode>

## Script Modes Overview
| **Mode**  | **Installs Docker**  | **Installs ROS**  | **Builds Workspace**  | **Use Case**   |
| :-- | :-- | :-- | :-- | :-- |
| fulldocker  | ✅ Yes  | Inside container  | ✅ Yes  | Fresh machine   |
| docker  | ❌ No  | Inside container  | ✅ Yes  | Docker already installed   |
| fullnative  | ❌ No  | ✅ Yes  | ✅ Yes  | Native Ubuntu   |
| native  | ❌ No  | ❌ No  | ✅ Yes  | ROS already installed   |

## Docker Installation (Recommended)

Docker provides:

-  Reproducibility 
-  MATLAB integration 
-  Easy setup 
# Windows 11 + WSL2 + Docker
# 1. Install WSL2

Install Ubuntu 24:


[https://learn.microsoft.com/en\-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install)

# 2. Install Using Script

Inside WSL:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fulldocker`

This will:

-  Install Docker Engine 
-  Build the tutorial Docker image 
-  Create the container named FCTR\-container 
# If Docker is already installed in WSL 
1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh docker`

This will:

-  Build the tutorial Docker image 
-  Create the preconfigured container 
# Docker Container Behavior

The installer:

-  Builds the image 
-  Creates a named container 
-  Leaves it **stopped** 

MATLAB will:

-  Start the container 
-  Attach to it 
-  Manage lifecycle automatically 
# Custom Docker Options

If using a custom container name:


StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');


If workspace location differs:


StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');

# Ubuntu 24 + Docker
# If Docker is NOT installed yet (recommended path)

Install everything via script:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh fulldocker`
# If Docker is already installed

To install Docker manually follow: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


Then run:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh docker`

This will:

-  Build your **custom** tutorial Docker image 
-  Create container **`FCTR-container`** (stopped) 
# Manually install docker (no script)

 **Step 1 —  Install docker** 


To install Docker manually follow: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


**Step 2 — Clone the Tutorial Repository**

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack`
# Step 3 — Build the Tutorial Docker Image

Navigate to the Docker folder (location may vary slightly depending on repo structure):


 `docker build` `-t` `from-code-to-robot-tutorial-docker docker` 


This builds the **custom tutorial image** containing:

-  ROS 2 Jazzy 
-  Gazebo / ros\_gz 
-  ros2\_control stack 
-  Tutorial workspace 
# Step 4 — Create the Tutorial Container

Create the container manually:


 `xhost` `+``local:docker`


`docker create \\`


 `--name` `FCTR-container \\` 


 `--env``=``"DISPLAY=``\$DISPLAY``"` `\\` 


 `--env``=``"QT_X11_NO_MITSHM=1"` `\\` 


 `--volume``=``"/tmp/.X11-unix:/tmp/.X11-unix:rw"` `\\` 


 `--device` `/dev/snd \\` 


 `--net``=``host \\`


 `from-code-to-robot-tutorial-docker \\` 


 `bash` `-lc` `"trap : TERM INT; sleep infinity & wait"`


This creates a **stopped container** named:


`FCTR-container`


The container:

-  Is not running yet 
-  Will be started automatically by MATLAB 
# Test in MATLAB (Ubuntu MATLAB)

Add the `robotics` folder and subfolders to path, then run:


`StartTutorialApplication('Rviz','model','ur5e');`


`JointStatesToRviz([0,-pi/2,0,-pi/2,0,0]);`


`StopTutorialApplications();`


`StartTutorialApplication('Simulation','model','ur3e','controller','effort');`


`StopTutorialApplications();`


**Extra Docker info**


If your container name differs:


`StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');`


If your workspace path differs:


`StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');`

# Native Ubuntu Installation (No Docker)

Native installation gives:

-  Higher performance 
-  Lower latency 
-  Better hardware access 
# Option 1 — Automatic Native Install (With ROS installation)

Installs ROS + dependencies + workspace.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fullnative`

Installs:

-  ROS 2 Jazzy Desktop 
-  Gazebo + ros_gz 
-  ros2_control stack 
-  DDS middleware 
-  Workspace dependencies 
-  Full build 
# Option 2 — Workspace Only (ROS already installed)

Use this if ROS 2 Jazzy is already installed.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh native`

This will:

-  Clone workspace 
-  Import repositories 
-  Run rosdep 
-  Build with colcon 
# Option 3 — Manual Native Workspace Setup (No Script)

For advanced users who prefer manual setup.


**1. Install ROS 2 Jazzy**


Follow official guide:


[https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html)


**2. Install Required Tools**

1.  `sudo apt update`
2. `sudo apt install -y \\`
3. `git \\`
4. `build-essential \\`
5. `cmake \\`
6. `pkg-config \\`
7. `python3-pip \\`
8. `python3-venv \\`
9. `python3-colcon-common-extensions \\`
10. `python3-rosdep \\`
11. `python3-vcstool \\`
12. `python3-argcomplete \\`
13. `wget curl`

 **3.Install ROS packages** 

1.  sudo apt install -y \\
2. ros-jazzy-desktop \\
3. ros-jazzy-ros-gz \\
4. ros-jazzy-gz-ros2-control \\
5. ros-jazzy-ros2-control \\
6. ros-jazzy-ros2-controllers \\
7. ros-jazzy-controller-manager \\
8. ros-jazzy-turtlebot3-msgs \\
9. ros-jazzy-rmw-cyclonedds-cpp \\
10. ros-jazzy-rmw-fastrtps-dynamic-cpp \\
11. ros-dev-tools
### **Initialize rosdep:**
1.  `sudo rosdep init`
2. `rosdep update`
# 4. Create Workspace
1.  mkdir -p ~/fctr_ws/src
2. cd ~/fctr_ws/src
3. git clone -b jazzy [https://github.com/iocroblab/from_code_to_robot_ros2_stack.git](https://github.com/iocroblab/from_code_to_robot_ros2_stack.git)
4. source /opt/ros/jazzy/setup.bash
5. cd ..
6. `mkdir` `-p` `src/modified-repositories`
7. `vcs` `import` `src/modified-repositories` `<` `src/from_code_to_robot_ros2_stack/stack.repos`
# 5. Build Workspace
1.  source /opt/ros/jazzy/setup.bash
2. `rosdep` `update`
3. `rosdep` `install` `--ignore-src` `--from-paths` `src` `-y`
4. `colcon` `build` `--symlink-install` `--cmake-args` `-DCMAKE_BUILD_TYPE=Release`
# Using Native Mode in MATLAB

When using native Ubuntu:


StartTutorialApplication('Rviz','model','ur5e','Docker',false);


JointStatesToRviz([0,-pi/2,0,-pi/2,0,0];


StopTutorialApplications('Docker',false);


StartTutorialApplication('Simulation','model','ur3e','controller','effort','Docker',false);


StopTutorialApplications('Docker',false);

# Troubleshooting
### ROS not found

run and try again: 

1.  source /opt/ros/jazzy/setup.bash
### **rosdep errors**
1.  sudo rosdep init
2. rosdep update

**Docker permission errors**

1.  sudo usermod -aG docker \$USER

Then log out and back in.**Recommended Setup**

| **Use Case**  | **Recommended Mode**   |
| :-- | :-- |
| Students / teaching  | Docker   |
| MATLAB workflows  | Docker   |
| Real robots  | Native   |
| Performance simulation  | Native   |
| Development  | Native   |


