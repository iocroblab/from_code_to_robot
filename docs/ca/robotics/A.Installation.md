
# Installation 
# MATALAB Version Requirements: 
-  MATLAB2025a 
-  MATLAB2025b 
# Required Toolboxes: 
-  Simulink 
-  ROS Toolbox 
-  Robotic System Toolbox  
-  Symbolic Math toolbox  
-  UR Hardware Support Package 
# Operating System / Environment 

You have the following options for using this tutorial on different operating systems: 


Windows 11 + WSL + Docker 


Ubuntu 24 + Docker 


Ubuntu 24


Find the relevant installation procedures below.


For an installation using Docker, you can also refer to the official documentation, after this setup find your installation below and proceed with  **Setup Workspace.** 


[https://de.mathworks.com/help/ros/ug/install\-and\-set\-up\-docker\-for\-ros\-2\-and\-gazebo.html](https://de.mathworks.com/help/ros/ug/install-and-set-up-docker-for-ros-2-and-gazebo.html)


**Due to specific names of the docker image and workspaces, its reccomanded to follow the steps below.**


## Windows 11 + Docker 

Install the Docker by following the steps from the documentation: 

### 1. WSL2

Install WSL2 with the Ubuntu 2024 distribution ([https://learn.microsoft.com/en\-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install))

### 2. Install Docker in WSL2

Go into your WSL Terminal (search wsl in your search bar or open a terminal and type wsl)


Follow the steps described in [https://docs.docker.com/engine/install/ubuntu/\#install\-using\-the\-repository](<<https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository>>) 

### 3. Configurate Docker in WSL2

Follow the steps described in:


[https://docs.docker.com/engine/install/linux\-postinstall/](https://docs.docker.com/engine/install/linux-postinstall/) 

### 4. Clone Docker files 

in your WSL terminal type the following command: 


 `if you use MATLAB2025a replace <branch-name> with R2025a` 


 `if you use MATLAB2025b replace <branch-name> with R2025b` 

-   `git clone --branch <branch-name>` [`https://github.com/mathworks-robotics/Support-and-Docker-Files-for-ROS-Toolbox.git`](https://github.com/mathworks-robotics/Support-and-Docker-Files-for-ROS-Toolbox.git) 
### `5. Build Docker Image`

 `in your WSL terminal type the following commands:` 

-  `cd Support-and-Docker-Files-for-ROS-Toolbox` 
-  `docker build -t gz-modified ros_jazzy/Ubuntu/gazebo` 
### `6. Run Docker`

 `in your WSL terminal execute the following commands:` 

-  `xhost +local:docker` 
-  `docker run -it --env="DISPLAY=\$DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --device /dev/snd --net=host gz-modified bash` 
###  `7. Setup Workspace` 

 `execute the following commands in the docker termainal inside WSL:` 

-  `mkdir -p git_ws/src` 
-  `cd git_ws/src` 
-  `git clone \$REPOSITORY_URL\$` 
-   `cd ..`  
-  `source /opt/ros/jazzy/setup.bash` 
-  `sudo apt update` 
-  `rosdep update` 
-  `rosdep install --from-paths src --ignore-src -r -y` 
-   `colcon build --symlink-install`  
### `8. Test your setup`

`Add the robotics folder and subfolders to your path.`


 `Run in Windows MATLAB (one after the other to see if everything works)` 

-  StartTutorialApplication('Rviz','model','ur5e');  

Result: Open Rviz 

-  JointStatesToRviz([0,-pi/2,0,-pi/2,0,0],'ur5e'); 

Result: Set the ur5e robot to its home configuration 

-  StopTutorialApplication(); 

Result: Close all ROS applicatations

-  StartTutorialApplication('Simulation', 'model','ur3e','controller','effort'); 

Result: Open Rviz and display the ur3e robot dangaling

-  StopTutorialApplication();  

Result: Close all ROS applicatations


# Ubuntu + Docker 

Install the Docker by following the steps from the documentation: 

### 1. Install Docker 

Go into your Terminal


Follow the steps described in [<<https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository>>](<<https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository>>) 

### 2. Configurate Docker

Follow the steps described in:


[https://docs.docker.com/engine/install/linux-postinstall/](https://docs.docker.com/engine/install/linux-postinstall/) 

### 3. Clone Docker files 

In your terminal type the following command: 


 `if you use MATLAB2025a replace <branch-name> with R2025a` 


 `if you use MATLAB2025b replace <branch-name> with R2025b` 

-   `git clone --branch <branch-name>` [`https://github.com/mathworks-robotics/Support-and-Docker-Files-for-ROS-Toolbox.git`](https://github.com/mathworks-robotics/Support-and-Docker-Files-for-ROS-Toolbox.git) 
### `4. Build Docker Image`

 `In your terminal type the following commands:` 

-  `cd Support-and-Docker-Files-for-ROS-Toolbox` 
-  `docker build -t gz-modified ros_jazzy/Ubuntu/gazebo` 
### `5. Run Docker`

 `In your terminal execute the following commands:` 

-  `xhost +local:docker` 
-  `docker run -it --env="DISPLAY=\$DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --device /dev/snd --net=host gz-modified bash` 
###  `6. Setup Workspace` 

 `Execute the following commands in the docker termainal inside WSL:` 

-  `mkdir -p git_ws/src` 
-  `cd git_ws/src` 
-  `git clone \$REPOSITORY_URL\$` 
-   `cd ..`  
-  `source /opt/ros/jazzy/setup.bash` 
-  `sudo apt update` 
-  `rosdep update` 
-  `rosdep install --from-paths src --ignore-src -r -y` 
-   `colcon build --symlink-install`  
### `7. Test your setup`

`Add the robotics folder and subfolders to your path`


 `Run in MATLAB (one after the other to see if everything works)` 

-  StartTutorialApplication('Rviz','model','ur5e');  

Result: Open Rviz 

-  JointStatesToRviz(\[0,\-pi/2,0,\-pi/2,0,0\],'ur5e'); 

Result: Set the ur5e robot to its home configuration 

-  StopTutorialApplication(); 

Result: Close all ROS applicatations

-  StartTutorialApplication('Simulation', 'model','ur3e','controller','effort'); 

Result: Open Rviz and display the ur3e robot dangaling

-  StopTutorialApplication();  

Result: Close all ROS applicatations

# Extra information using Docker

In case you installed the docker using a different name you can extend the StartTutorialApplication function with 'DockerName', 'YourDockerName'


Example: 

-  StartTutorialApplication('Rviz','model','ur3', 'DockerName','YouDockerName');  

If you have setup the workspace in a different place you can extend the StartTutorialApplication function with 'worksapce','path\_to\_your\_workspace'


Example: 

-  StartTutorialApplication('Rviz','model','ur3', 'Workspace','MyTutorialFiles/workspace');  

# Ubuntu

If you have an Ubuntu 24 operating system you can setup your environment without using a docker. This will increase your computational capacity and make simulations smoother. 

### 1. Install ROS2 Jazzy 

Follow the steps described in 


[https://docs.ros.org/en/jazzy/Installation/Alternatives/Ubuntu\-Development\-Setup.html](https://docs.ros.org/en/jazzy/Installation/Alternatives/Ubuntu-Development-Setup.html) 

### 2. Setup Workspace 

Open a terminal and execute the following commands: 

-  `mkdir -p git_ws/src` 
-  `cd git_ws/src` 
-  `git clone \$REPOSITORY_URL\$` 
-   `cd ..`  
-  `source /opt/ros/jazzy/setup.bash` 
-  `sudo apt update` 
-  `rosdep update` 
-  `rosdep install --from-paths src --ignore-src -r -y` 
-   `colcon build --symlink-install`  
###  `3. Test your Setup` 

`Add the robotics folder and subfolders to your path`


 `Run in MATLAB (one after the other to see if everything works)` 


`When using native ubuntu you need to extend the Start and Stop Tutorial application with the optional input 'Docker' false!`

-  StartTutorialApplication('Rviz','model','ur5e', 'Docker',false);  

Result: Open Rviz 

-  JointStatesToRviz(\[0,\-pi/2,0,\-pi/2,0,0\],'ur5e'); 

Result: Set the ur5e robot to its home configuration 

-  StopTutorialApplication('Docker',false); 

Result: Close all ROS applicatations

-  StartTutorialApplication('Simulation', 'model','ur3e','controller','effort','Docker',false); 

Result: Open Rviz and display the ur3e robot dangaling

-  StopTutorialApplication('Docker',false);  

Result: Close all ROS applicatations

# Extra information for Ubuntu Setup 

If you have setup the workspace in a different place you can extend the StartTutorialApplication function with 'worksapce','path\_to\_your\_workspace'


Example: 

-  StartTutorialApplication('Rviz','model','ur3', 'Workspace','MyTutorialFiles/workspace');  

