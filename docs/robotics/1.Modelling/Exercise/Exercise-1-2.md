
```matlab
clear all; 
```
# Exercise 1.2 \- Modeling of a Robot

In this exercise you will model a Universal UR3e robot from given DH parameters.


 ![image_0.svg](Exercise-1-2_media/image_0.svg)


Please store your solutions in the predefined variables!

# Task description:

Given the DH parameters of a UR3e Robot: 

|      |      |      |      |      |
| :-: | :-- | :-: | :-: | :-: |
| Link <br>  | a \[m\] <br>  | alpha <br>  | d \[m\] <br>  | theta <br>   |
| 1 <br>  | 0 <br>  | pi/2 <br>  | 0.15185 <br>  | 0 <br>   |
| 2 <br>  | \-0.24355 <br>  | 0 <br>  | 0 <br>  | 0 <br>   |
| 3 <br>  | \-0.2132 <br>  | 0 <br>  | 0 <br>  | 0 <br>   |
| 4 <br>  | 0 <br>  | pi/2 <br>  | 0.13105 <br>  | 0 <br>   |
| 5 <br>  | 0 <br>  | \-pi/2 <br>  | 0.08535 <br>  | 0 <br>   |
| 6 <br>  | 0 <br>  | 0 <br>  | 0.0921 <br>  | 0 <br>   |
|      |      |      |      |       |


The base and the coordinate frame of the first joint are identical!


Answer all the questions and store your solution in the correct variable

# Task 1

1.  Setup the robot structure and use the data format "column"
2. Define bodies, name them body\_1, ..., body\_n
3. Define joints, name them joint\_1, ..., joint\_n

Use the following variables to store your solution:

-  robot (name of your robot) 
-  bodies (name of your variable containing the bodies) 
-  joints (name of your variable containing the joints) 
```matlab
robot = [];
bodies = []; 
joints = []; 
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('1-2-1')
```

```matlabTextOutput
Checking exercise 1-2-1: Variable Structure

Checking variables:
 
Checking Variable robot
[OK] robot is of type rigidBodyTree

Checking robot data format
[OK] Correct data format

Checking Variable bodies
[OK] bodies is of type cell

Checking Variable joints
[OK] joints is of type cell

checking body elements
checking joint elements
```
# Task 2

1.  Link the DH parameters to the corresponding joints.
2. Link the joints to their bodies.
3. Add the bodies to the robot
```matlab
DH=[
   %a       alpha       d       theta
   0        pi/2        0.15185  0;
   -0.24355 0           0       0;
   -0.2132  0           0       0;
   0        pi/2        0.13105 0;
   0        -pi/2       0.08535 0;
   0        0           0.0921  0;
    ]
```

Add your code here: 



You can check your work by clicking the Run: 

```matlab
 
check_exercise('1-2-2')

```
# Task 3
1.  Define the gravity to be in negative Z direction with a magnitude of $9\ldotp 81\;\frac{m}{s^2 }$ (see figure above)
2. Set the home position for joints 1, 3 and 5 to $\frac{\pi }{2}$

Add your code here:



You can check your work by clicking the Run: 

```matlab
 
check_exercise('1-2-3')
```
