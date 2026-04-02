
# Demonstration
```matlab
StartTutorialApplication('Rviz','ur3e');
```

```matlabTextOutput
gz-modified
```

```matlab
StartTutorialApplication('Simulation', 'Controller', 'velocity'); 
```

```matlab
config = [0,-pi/3,0,-pi/2,0,0]; 
JointStatesToRviz(config); 
```

```matlab

JointStatesToRviz(config, 'ur3e',[], 'Ellipsoid',true); 
```

```matlab
load("LinearTrajectorySingular.mat")
JointStatesToRviz(q_traj_ex, 'ur3e', T_example, 'Trajectory', false)
```

```matlabTextOutput
ans = logical
   1

```

```matlab
JointStatesToRviz(q_traj_ex, 'ur3e', T_example)
```

```matlabTextOutput
ans = logical
   1

```

```matlab
JointStatesToRviz(q_traj_ex, 'ur3e', 5*T_example, 'Ellipsoid', true)
```

```matlabTextOutput
ans = logical
   1

```

```matlab
JointStatesToRviz(q_traj_ex, 'ur3e', T_example, 'Ellipsoid', true, 'EllipsoidKind', 'rot')
```

```matlabTextOutput
ans = logical
   1

```

```matlab
plotTrajectory(q_traj_ex, q_dot_traj, linspace(0,T_example, size(q_traj_ex,2)))
```

```matlab
StopTutorialApplications(); 
StartTutorialApplication('Simulation', 'Controller', 'velocity'); 
```

```matlabTextOutput
Error using JointStatesToRviz (line 406)
JointConfiguration must have 6 columns.
```


