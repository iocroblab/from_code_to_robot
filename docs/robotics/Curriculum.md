
# Curriculum

Below you will find the proposed order of tutorials and exercises for the robotics section of the From\-Code\-to\-Robot project. 

# 0. Basics 

This package contains some tutorials explaining how to use basic Matlab functions. Understanding these concepts is crucial for the following parts of the Robotics tutorial. 

## [Matrix Manipulation](./0.Basics/Matrix_manipulation.md) 

This tutorial explains how to setup and use matrices in MATLAB. 

## [Symbolic Math Toolbox](./0.Basics/Symbolic_Math_toolbox.md)

This tutorial explains how to use symbolic variables in MATLAB. 

## [Structures](./0.Basics/Structures.md)

This tutorial illustrates how to access different elements of a structure and how to work with them. 

## [Cells](./0.Basics/Cells.md)

This tutorial illustrates how to access different elements of a cell and how to work with them. 

# 1. Modelling 

This package explains the basics modelling a robot with the Robotic System Toolbox. It contains Tutorials to understand the concepts using the Symbolic Toolbox. 

## [Transforms](./1.Modelling/Tutorial/Transforms.md)

This tutorial explains what a translation and rotation is, how they can be expressed in vectors and matrices and their combination as a homogeneous transform matrix. Additionally different rotation representations are explained. 

### [Exercise 1.1 \- Find the Transforms](./1.Modelling/Exercise/Exercise-1-1.md)

In this exercise you will need to find different transformations to describe the relative pose of two frames. 

## [Modelling with the Robotic System Toolbox](./1.Modelling/Tutorial/Modelling_with_RS_toolbox.md)

This tutorial explains how to setup a robot using the Robotic System Toolbox. 

### [Exercise 1.2 \- Modeling of a Robot ](./1.Modelling/Exercise/Exercise-1-2.md)

In this exercise you will setup a Universal Robot using the Robotic System Toolbox.

### [Exercise 1.3 \- Find the DH parameters](./1.Modelling/Exercise/Exercise-1-3.md)

In this exercise you will compute the DH parameters for an arbitrary robot manipulator and set it up using the Robotic System Toolbox

# 2. Kinematics

This package explains the relations between joint angles and resulting pose of endeffectors. Using this knowlege you will compute required joint angles for a desired pose and trajectories to move the joints in a controlled manner. 

## [Forward Kinematics](./2.Kinematics/Tutorial/Forward_Kinematics.md)

This tutorial explains how to compute the resulting transformation of a manipulator given a joint configuration on the example of a Universal UR3. 

### [Exercise 2.1 \- Forward Kinematics](./2.Kinematics/Exercises/Exercise-2-1.md)

In this exercise you will compute the resulting transform for a given configuration using the Symbolic Toolbox and the Robotic System Toolbox. 

## [Inverse Kinematics](./2.Kinematics/Tutorial/Inverse_Kinematics.md)

This tutorial explains how to compute one or multiple solutions to the question, what joint angles are required to achieve a desired transformation. 

### [Exercise 2.2 \- Inverse Kinematic Planar Arms](./2.Kinematics/Exercises/Exercise-2-2.md)

In this exercise you will compute the inverse kinematic solutions for simple planar robots. 

### [Exercise 2.3 \- Inverse Kinematic Anthropomorpic arm with Spherical Wrist](./2.Kinematics/Exercises/Exercise-2-3.md)

In this exercise you will compute the analytical inverse kinematic solutions for an Anthropomorpic arm with Spherical Wrist using the techniques explained in the tutorial. 

## [Joint Space Trajectory Planning](./2.Kinematics/Tutorial/Joint_Space_Trajectory_Planning.md)

This tutorial explains how to compute a trajectory from one joint state to another using specific velocity profiles. 

### [Exercise 2.4 \- Joint Space Trajectory Planning](./2.Kinematics/Exercises/Exercise-2-4.md)

In this tutorial you will setup different functions to compute trajectories for single joint and complete manipulators. You will adjust the functions to fulfill specific requirements. 

# 3. Differential Kinematics

This package explains the relation between joint velocities and cartesian velocities of the endeffector. Building on this knowlege you will learn how to setup a numerical inverse kinematic algorithm and learn about the manipulability of robots and what challanges occure. 

## [Jacobians](<./3.Differential Kinematics/Tutorial/Jacobians.md>)

This tutorial explains the computations of geometric and analytical Jacobian matrix using the Symbolic Toolbox.  Additionally you will learn how to utilize the Robotic System Toolbox for the computations. 

## [Manipulability](<./3.Differential Kinematics/Tutorial/Manipulability.md>) 

This tutorial explains if and with how much efford a robot can move in specific configurations. It will explain the concept of singularities and redundancy and showcase some examples in Rviz. 

### [Exercise 3.1 \- Jacobian](<./3.Differential Kinematics/Exercise/Exercise-3-1.md>) 

In this exercise you will setup functions to symbolically compute the geometric and analytical jacobians and calculate the required joint speeds to achieve a specific motion. You will visualize this motion in Rviz and will analyze how the manipulability and joint speeds change when being near a singular configuration.

## [Inverse Kinematic Algorithm](<./3.Differential Kinematics/Tutorial/Inverse_Kinematic_Algorithm.md>)

This tutorial explains two approaches on how to utilize the jacobians to setup a numerical inverse kinematic algorithm.

### [Exercise 3.2 \- Inverse Kinematic Algorithm](<./3.Differential Kinematics/Exercise/Exercise-3-2.md>)

In this exercise you will setup the pseudo inverse kinematic algorithm and analyze the convergence and error it procudes. You will use quaternions to compute the orientation error using the analytical jacobian. 

### [Exercise 3.3 \- Velocity Teleoperation](<./3.Differential Kinematics/Exercise/Exercise-3-3.md>)

In this exercise you will simulate a robot and controll the endeffector with your keyboard by computing the required joint speeds. 

# 4. Dynamcis

This package explains the relation between joint states, \- speeds and \- torques using the lagrange formulation. You will also learn how to estimate parameters of your robot given sufficient testing data, this allows you to approximate e.g. the weight or inertia matrices of your robot maipulator. 

## [Dynamics Lagrange Formulation](./4.Dynamics/Tutorial/Dynamics_Lagrange_Formulation.md)

 This tutorial will explain what the different terms of the lagrange formulation are and how they are computed using the Symbolic Toolbox and the Robotic System Toolbox. Additionally a technique for the identification of linear dynamic parameters is presented. 

### [Exercise 4.1 \- Dynamic Term Computations](./4.Dynamics/Exercise/Exercise-4-1.md)

In this exercise you will setup functions to calculate the different terms of the lagrange formulation for an arbitrary manipulator using the symbolic toolbox. 

### [Exercise 4.2 \- Effort\-Based Control using the Dynamic Model ](./4.Dynamics/Exercise/Exercise-4-2.md)

In this exercise you will control a ur3e robot to hold a weight in different configurations using the physics simulation engine gazebo. You will compute the required joint torques to hold a weight using the lagrange formulation. 

### [Exercise 4.3 \- Track a Trajectory ](./4.Dynamics/Exercise/Exercise-4-3.md)

In this exercise you will compute the required joint accelerations to track a given trajectory of joint states. Using these accelerations you will use gazebo to simulate this trajectory. 

# 5. Control 

This package explains differnet approaches to robotic control algorithms. E.g. centeralized and decenteralized control schemes, feedforward control and how Simulink can be utilized for robot control. 


