
```matlab
clear all; 
```
# Exercise 2.4 \- Joint Space Trajectory Planning

In this exercise you will develop functions to compute joint trajectories. 


Please store your solutions in the predefined variables!

# Task description:

Follow the tasks and setup the required functions for different trajectory computations. 


Answer all the questions and store your solution in the correct variable

# Task 1

Write a function that computes a quintic joint trajectory for a single joint. This function takes four inputs: 

1.  initial joint state (q0)
2. target joint state (qf)
3. time to reach pose (t)
4. Intermediate joint states (N)
5. initial velocity (v0)
6. velocity at target joint state (vf)
7. initial acceleration (a0)
8. acceleration at target joint state (af)

and returns the joint trajectory as a where each row corresponds to a joint configuration, the joint speed trajectory, the joint acceleration trajectory and a vector containing the time at each trajectory entry. 


Assume that both, the velocity and acceleration at the start and end of the trajectory are 0. 


Use the following function name for your solution:

-  SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af) 

Solve this exercise without using the functions: 

-  quinticpolytraj() 
```matlab
function [q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af)

end
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-4-1')
```

You can plot your trajectory: 

```matlab
 
q0 = 0; 
qf = pi;
v0 = 0; 
vf = 0; 
a0 = 0;
af = 0; 
T = 8; 
N = 100; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
```
# Task 2

Write a function that takes two joint configurations and computes the quintic trajectory for each joint. You may use your previously defined function


Use the following variables  to store your solution:

-  QuinticConfigurationTrajectory(q0, qt, t, N) 

Solve this exercise without using the functions: 

-  quinticpolytraj() 
```matlab
function q_config_trajectory = QuinticConfigurationTrajectory(q0,qt,t,N)

end
```

You can view your trajectory in Rviz: 

```matlab
 
q0 = zeros(1,6); 
qf = [-pi/7,-pi/2,pi/5,-pi/3,pi/2,pi/4];
v0 = zeros(1,6); 
vf = zeros(1,6); 
a0 = zeros(1,6);
af = zeros(1,6); 
T = 8; 
N = 300; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = QuinticConfigurationTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
JointStatesToRviz(q_trajectory, [], T);

```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-4-2')
```

Notice that you now have a different restriction compared to the tutorial. Thus your function should determine the required constant acceleration. 


The function should have four outputs: 

1.  joint state trajectory q
2. joint speed trajectory qd
3. joint acceleration trajectory qdd
4. time vector timevec

Use the following function name for your solution:

-  SingleTrapezoidalTrajectory(q0, qt, T, N, vc) 

Solve this exercise without using the functions: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = SingleTrapezoidalTrajectory(q0, qt, T, N, vc)

end
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-4-3')
```
# Task 4

Extend your function from Task 3. This function takes six inputs: 

1.  initial joint state (q0)
2. target joint state (qt)
3. time to reach pose (t)
4. number of steps to reach pose (N)
5. cruise velocity (vc)
6. maximum acceleration (amax)

This function should check whether or not the computed joint trajectory results in an acceleration that is larger than a maximum allowed acceleration. If this is the case, the function should increase the time to reach the pose in increments of 0.1s until the resulting acceleration is within the limits. 


You may use your function from Task 3


Use the following function name for your solution:

-  LimitedTrapezoidalTrajectory(q0, qt, t, N, vc, amax) 

The function should have four outputs: 

1.  joint state trajectory q
2. joint speed trajectory qd
3. joint acceleration trajectory qdd
4. time vector

Solve this exercise without using the functions: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = LimitTrapezoidalTrajectory(q0,qt,t,N,vc,amax)

end
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-4-4')
```

