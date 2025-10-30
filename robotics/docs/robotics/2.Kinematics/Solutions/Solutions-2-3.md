
```matlab
clear all; 
```
# <span style="color:rgb(213,80,0)">Exercise 2.3 \- Inverse Kinematic Anthropomorpic arm with Spherical Wrist</span>

In this Exercise you will compute the inverse kinematic of an antropomorphic arm with a spherical wrist


Please store your solutions in the predefined variables!

# Task description:

below you will see a model of an Anthropomorphic arm with a spherical wrist. 


Consider the following set of DH parameters: 

|      |      |      |      |      |
| :-: | :-- | :-: | :-: | :-- |
| Link <br>  | a \[m\] <br>  | alpha <br>  | d \[m\] <br>  | theta <br>   |
| 1 <br>  | 0 <br>  | pi/2 <br>  | 0 <br>  | $\displaystyle \theta_1$ <br>   |
| 2 <br>  | 0.3 <br>  | 0 <br>  | 0 <br>  | $\displaystyle \theta_2$ <br>   |
| 3 <br>  |   0.2 <br>  | pi/2 <br>  | 0 <br>  | $\displaystyle \theta_3$ <br>   |
| 4 <br>  | 0 <br>  | \-pi/2 <br>  | 0.2 <br>  | $\displaystyle \theta_4$ <br>   |
| 5 <br>  | 0 <br>  | pi/2 <br>  | 0 <br>  | $\displaystyle \theta_5$ <br>   |
| 6 <br>  | 0 <br>  | 0 <br>  | 0.15 <br>  | $\displaystyle \theta_6$ <br>   |
|      |      |      |      |       |


<p style="text-align:left">
   <img src="Solutions-2-3_media/image_0.svg" width="413" alt="image_0.svg">
</p>


In the case of this manipulator with a spherical wrist, the solution is decoupled between position and orientation, i.e. the three joints of the arm are used to position the end\-effector, and thethree joints are used to fix its orientation.


Given the end\-effector position $p_{\textrm{ee}}$ and orientation $R_{\textrm{ee}}$ , the following steps should be followed:

1.  Compute the wrist position $p_w =p_{\textrm{ee}} -d_6 \cdot z_6$
2. Solve inverse kinematics for the Anthropomorphic Arm: $\theta_3 ,\theta_2 ,\theta_1$
3. Compute $R_3^0 \left(\theta_1 ,\theta_2 ,\theta_3 \right)$
4. Compute $R_6^3 \left(\theta_4 ,\theta_5 ,\theta_6 \right)={R_3^0 }^T \cdot R_{\textrm{ee}}$
5. Solve inverse kinematics for Spherical Wrist: $\theta_4 ,\theta_5 ,\theta_6$

The four solutions of the IK of the arm combined with the two solution of the wrist result in a total of eight solutions.


Reach the following pose: 

 $$ T_{\textrm{desired}} =\left\lbrack \begin{array}{cccc} 0\ldotp 5 & 0 & 0\ldotp 866 & 0\ldotp 25\newline 0\ldotp 866 & 0 & -0\ldotp 5 & 0\ldotp 1\newline 0 & 1 & 0 & 0\ldotp 35\newline 0 & 0 & 0 & 1 \end{array}\right\rbrack $$ 

Answer all the questions and store your solution in the correct variable

```matlab
syms q1 q2 q3 q4 q5 q6 real 
% DH Parameters Table
        % a      alpha      d       theta
DH = [    0,     pi/2,     0,       q1;    % Link 1
          0.3,   0,        0,       q2;    % Link 2
          0.2,   pi/2,     0,       q3;    % Link 3
          0,     -pi/2,    0.2,     q4;    % Link 4
          0,     pi/2,     0,       q5;    % Link 5s
          0,     0,        0.15,    q6];   % Link 6

Tdesired = [0.5,      0,     0.866, 0.25;
            0.866,    0,    -0.5,  0.1;
            0,        1,     0,    0.35;
            0,        0,     0,    1];
```
# Task 1
1.  Compute the wrist position $p_w =p_{\textrm{ee}} -d_6 \cdot z_6$
2. Solve inverse kinematics for the Anthropomorphic Arm: $\theta_3 ,\theta_2 ,\theta_1$

Use the following variables  to store your solution:

-  pee (endeffector position) 
-  pw (the wrist position) 
-  anthro\_solutions (inverse kinematic solution where each row is a solution) 
```matlab

a2 = DH(2,1);
a3 = DH(3,1)+DH(4,3); %a3+d4
d6 = DH(6,3);

pee = Tdesired(1:3,4);
pw = pee - d6* Tdesired(1:3,3);
pwx = pw(1); 
pwy = pw(2); 
pwz = pw(3);

T04 = dh2tf(DH(1:4,:));
c3 = (pwx^2+pwy^2+pwz^2-a2^2-a3^2)/(2*a2*a3);
s3 = sqrt(1-c3^2);
theta3 = [atan2(s3,c3); atan2(-s3,c3)];

c2_I = (sqrt(pwx^2+pwy^2)*(a2+a3*c3)+pwz*a3*s3)/(a2^2+a3^2+2*a2*a3*c3);
c2_II = (-(sqrt(pwx^2+pwy^2)*(a2+a3*c3))+pwz*a3*s3)/(a2^2+a3^2+2*a2*a3*c3);
c2_III = (sqrt(pwx^2+pwy^2)*(a2+a3*c3)+pwz*a3*-s3)/(a2^2+a3^2+2*a2*a3*c3);
c2_IV = (-(sqrt(pwx^2+pwy^2)*(a2+a3*c3))+pwz*a3*-s3)/(a2^2+a3^2+2*a2*a3*c3);

s2_I = (pwz*(a2+a3*c3)-sqrt(pwx^2+pwy^2)*a3*s3)/(a2^2+a3^2+2*a2*a3*c3); 
s2_II = (pwz*(a2+a3*c3)+sqrt(pwx^2+pwy^2)*a3*s3)/(a2^2+a3^2+2*a2*a3*c3); 
s2_III = (pwz*(a2+a3*c3)-sqrt(pwx^2+pwy^2)*a3*-s3)/(a2^2+a3^2+2*a2*a3*c3); 
s2_IV = (pwz*(a2+a3*c3)+sqrt(pwx^2+pwy^2)*a3*-s3)/(a2^2+a3^2+2*a2*a3*c3); 

theta2 = [atan2(s2_I,c2_I);
          atan2(s2_II,c2_II);
          atan2(s2_III,c2_III);
          atan2(s2_IV,c2_IV)];

theta1 = [atan2(pwy,pwx); 
          atan2(-pwy,-pwx)];

anthro_solutions = [theta1(1), theta2(1), theta3(1); 
                    theta1(1), theta2(3), theta3(2); 
                    theta1(2), theta2(2), theta3(1); 
                    theta1(2), theta2(4), theta3(2); 
    ]; 

T05 = dh2tf(DH(1:5,:)); 
for i=1:4
    currentT = (subs(T05, [q1, q2, q3], anthro_solutions(i, :)));
    vec= double(currentT(1:3,4))
   
end
```

```matlabTextOutput
vec = 3x1
    0.2547
    0.3712
    0.1970

vec = 3x1
    0.0407
    0.0594
    0.1044

vec = 3x1
   -0.0189
   -0.0275
    0.4903

vec = 3x1
    0.0335
    0.0489
    0.1121

```

```matlab
vpa(pw)
```
ans = 
 $\displaystyle \left(\begin{array}{c} 0.1201\newline 0.175\newline 0.35 \end{array}\right)$
 

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-3-1')
```

```matlabTextOutput
Error using fileread (line 10)
Could not open file exercises\exercise-2-3-1.json. No such file or directory.

Error in check_exercise (line 8)
    data = jsondecode( fileread(json_file) );
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
```
# Task 2
1.  Compute $R_3^0 \left(\theta_1 ,\theta_2 ,\theta_3 \right)$
2. Compute $R_6^3 \left(\theta_4 ,\theta_5 ,\theta_6 \right)={R_3^0 }^T \cdot R_{\textrm{ee}}$

Use the following variables  to store your solution:

-  Ree (Rotation of the end\-effector) 
-  R03 (Rotation from frame 0 to frame 3) 
-  R36 (Rotation from frame 3 to frame 6) 
```matlab
Ree = Tdesired(1:3,1:3); 
T03 = subs(T03, [q1,q2,q3], anthro_solutions(1,:)); 
R36 = simplify(T03(1:3,1:3)'*Ree);
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-3-2')

```
# Task 3
1.  Solve inverse kinematics for Spherical Wrist: $\theta_4 ,\theta_5 ,\theta_6$

Use the following variables  to store your solution:

-  spherical\_solutions (inverse kinematic solution where each row is a solution)  
-  solutions (complete inverse kinematic solution for the anthropomorpic arm with spherical wrist, where each row represents a unique solution) 
```matlab
ax = R36(1,3); 
ay = R36(2,3); 
az = R36(3,3); 
nz = R36(3,1); 
sz = R36(3,2); 

theta5_p = atan2(sqrt(ax^2+ay^2),az);
theta5_n = atan2(-sqrt(ax^2+ay^2),az);

theta4_p = atan2(ay,ax);
theta6_p = atan2(sz,-nz);

theta4_n = atan2(-ay,-ax);
theta6_n = atan2(-sz,nz);

spherical_solutions = [theta4_p, theta5_p, theta6_p; 
                       theta4_n, theta5_n, theta6_n];

solutions = [];
for i=1:4
solutions = [solutions; anthro_solutions(i,:), spherical_solutions(1,:); anthro_solutions(i,:), spherical_solutions(2,:)];
end

error=0; 
T06 = dh2tf(DH);
joints = [q1,q2,q3,q4,q5,q6]; 
for i=1:8
    currentT=double(subs(T06, joints, solutions(i,:))) 
error=error+ sum(Tdesired-currentT,"all"); 

end

disp(error)
```

You can check your work by clicking the Run: 

```matlab
 
check_exercise('2-3-3')

```
