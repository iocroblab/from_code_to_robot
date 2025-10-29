
```matlab
clear all; 
```
# <span style="color:rgb(213,80,0)">Exercise 2.1 \- Forward Kinematics</span>

In this exercise you will setup the forward kinematics equations for different robot manipulators. 


Please store your solutions in the predefined variables!

# Task description:

Find the DH parameters and setup the forward kinematics for the shown strucutre.


Answer all the questions and store your solution in the correct variable

# Task 1

Given this Spherical Wrist setup. <img src="Exercise-2-1_media/image_0.svg" width="569" alt="image_0.svg">

1.  Find the DH parameters and setup the Forward Kinematics matrix.


Use the following variables  to store your solution:

-  q4 ... q6 (Real Symbolic variable for the Joint angle Theta 4\-6) 
-  q (vector containing the symbolic Joint angles) 
-  A36 (Forward Kinematic Equation) 
```matlab
q = []; 
A36= []; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-1-1')
```
# Task 2
1.  Find the forward kinematics for the joint configuration \[0, 0, 0\]
2. Find the forward kinematics for the joint configuration \[pi/2, 0 , pi/7\]

Use the following variables  to store your solution:

-  T\_1 (Homogeneous Transform for  joint configuration \[0, 0, 0\])  
-  T\_2 (Homogeneous Transform for  joint configuration \[pi/2, 0 , pi/7\])  
```matlab
T_1 = []; 
T_2 = []; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-1-2')

```
# Task 3
1.  Setup the Wrist using the Robotic System toolbox
2. Define the data format as column

use the following names:

-  spherical\_wrist (name of the robot) 
-  world (base of the robot) 
-  wrist\_1\_link ... wrist\_3\_link (body name of the wrist links) 
-  wrist\_1\_joint ... wrist\_3\_joint (joint names of the wrist) 
```matlab
spherical_wrist =[]; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-1-3')

```
# Task 4
1.  Obtain the Transform for the Joint Configuration \[0,\-pi/2,\-pi/2\] from the baseframe to the last wrist frame.

Use the following variables  to store your solution:

-  T\_config (Transform for the Joint Configuration \[0,\-pi/2,\-pi/2\]) 
```matlab
T_config =[]; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-1-4')
```
# Task 5
1.  Using the Robotic System toolbox load a UR10e model
2. Obtain the transform from the baseframe to the first wrist link for the configuration \[0,0,0,0,0,0\]
3. Obtain the transform from the baseframe to the tool0 frame for the configuration \[0, \-pi/2, 0, \-pi/2, 0, 0\]

Use the following variables  to store your solution:

-  ur10e (Name of the robot) 
-  TBW1 (Homogeneous Transform Base to first wrist) 
-  TBT (Homogeneous Transform from Base to tool0) 
```matlab
TBW1 = [];
TBT = []; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-1-5')

```

