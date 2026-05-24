```matlab
clear all; 
```
# Exercici 3.1 \- Jacobià 

En aquest exercici configuraràs diferents funcions relacionades amb el jacobià d’un robot UR3e. 


Considera aquest robot UR3e i les seves dimensions. 


![image_0.png](Exercise-3-1_media/image_0.png)

# Tasca 1

Configura el jacobià geomètric fent servir el toolbox simbòlic. L’expressió simbòlica resultant només ha de dependre dels estats articulars 

1.  Troba els paràmetres DH i configura la matriu jacobiana.

Fes servir les variables següents per desar la teva solució:

-  q1 ... q6 (variable simbòlica real per a l’angle articular Theta 1\-6) 
-  Jp (part translacional del jacobià) 
-  Jtheta (part rotacional del jacobià) 
-  J (jacobià complet com $J\left(q\right)=\left\lbrack \begin{array}{c} J_{\theta } \left(q\right)\newline J_p \left(q\right) \end{array}\right\rbrack$ )  

Resol aquest exercici fent servir l’enfocament geomètric! Fes servir la funció: 

-  cross() 

Resol aquest exercici sense fer servir la funció: 

-  dh2tf() 

i sense fer servir la matriu de relació $T_A \left(\Phi \right)$: 

-  $\displaystyle T_A \left(\Phi \right)=\left\lbrack \begin{array}{ccc} 0 & -\sin \left(\phi \right) & \cos \left(\phi \right)\cdot \sin \left(\theta \right)\newline 0 & -\sin \left(\phi \right)\cdot \sin \left(\theta \right) & -\sin \left(\phi \right)\cdot \sin \left(\theta \right)\newline 1 & \cos \left(\theta \right) & \cos \left(\theta \right) \end{array}\right\rbrack$ 
```matlab
Jp = []; 
Jtheta = []; 
J = []; 
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('3-1-1')
```
# Tasca 2

Escriu una funció que calculi el jacobià analític (fent servir angles d’Euler ZYZ) per a una configuració donada. Aquesta funció pren un vector com a entrada: 

1.  Configuracions (q) com a vector fila ( $q\in {\mathbb{R}}^{6\textrm{x1}}$ )

i retorna el jacobià analític com $J_a \left(q\right)=\left\lbrack \begin{array}{c} J_{\Phi \;} \left(q\right)\newline J_p \left(q\right) \end{array}\right\rbrack$ i el seu rang a la configuració.


Fes servir el nom de funció següent per a la teva solució:

-   ComputeAnalyticalJacobian(q) 

Resol aquest exercici fent servir un enfocament analític! Fes servir la funció: 

-  diff() 

Resol aquest exercici sense fer servir la matriu de relació $T_A \left(\Phi \right)$: 

-  $\displaystyle T_A \left(\Phi \right)=\left\lbrack \begin{array}{ccc} 0 & -\sin \left(\phi \right) & \cos \left(\phi \right)\cdot \sin \left(\theta \right)\newline 0 & -\sin \left(\phi \right)\cdot \sin \left(\theta \right) & -\sin \left(\phi \right)\cdot \sin \left(\theta \right)\newline 1 & \cos \left(\theta \right) & \cos \left(\theta \right) \end{array}\right\rbrack$ 
```matlab
function [Ja, Rank] = ComputeAnalyticalJacobian(q)
```

```matlabTextOutput
Ja = 6x6
1.0000    0.0000    0.0000    0.0000    1.0000         0
         0   -0.0000   -0.0000   -0.0000    0.0000         0
         0    1.0000    1.0000    1.0000    0.0000    1.0000
    0.2231   -0.5421   -0.2985   -0.0853    0.0921         0
    0.0000         0         0         0    0.0000         0
         0    0.0000    0.0000    0.0000   -0.0000         0

Rank = 4
```

```matlab

Ja = []; 
Rank = rank(Ja); 

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('3-1-2')
```

```matlabTextOutput
Error en usar fileread (línia 10)
No s’ha pogut obrir el fitxer exercises\exercise-3-1-2.json. No existeix aquest fitxer o directori.

Error a check_exercise (línia 8)
    data = jsondecode( fileread(json_file) );
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
```

# Tasca 3

Escriu una funció que calculi les velocitats articulars requerides per aconseguir un moviment translacional específic de l’efector final per a una configuració donada. Considera només la posició de l’efector final i no la seva orientació. Aquesta funció pren dos vectors com a entrada: 

1.  configuració (q) com a vector fila ( $q\in {\mathbb{R}}^{6\textrm{x1}}$ )
2. moviment desitjat v, relatiu al marc base, com a vector fila on $v=\left\lbrack \begin{array}{c} \dot{x} \newline \dot{y} \newline \dot{z}  \end{array}\right\rbrack$

i retorna les velocitats articulars requerides com a vector fila ( $\dot{q} \in {\mathbb{R}}^{6\textrm{x1}}$ ) i el rang del jacobià.


Fes servir el nom de funció següent per a la teva solució:

-   ComputeJointSpeed(q,v) 

Resol aquest exercici fent servir un enfocament geomètric! Fes servir la funció: 

-  cross() 
```matlab
function [qdot , Rank]= ComputeJointSpeed(q,v)

qdot = []; 
Rank = []; 

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('3-1-3')
```
# Tasca 4

Fes servir la teva funció de la Tasca 3 per calcular una trajectòria que segueixi el moviment desitjat. 


Aproxima els nous estats articulars amb $q_{k+1} =q_k +\dot{q} \cdot \Delta t$ on $\dot{q}$ és la velocitat articular calculada per a la configuració $q_k$. 


La funció pren quatre entrades: 

1.  Configuració articular inicial (q)
2. moviment desitjat (v)
3. pas temporal (dt)
4. temps total (T)

La funció té tres sortides: 

1.  Trajectòria d’estats articulars ( $q_{\textrm{traj}} \in {\mathbb{R}}^{6\textrm{xN}}$ on N és la quantitat de punts de la trajectòria, normalment $N=\frac{T}{\Delta t}$ )
2. Trajectòria de velocitats articulars ( $\dot{q_{\textrm{traj}} } \in {\mathbb{R}}^{6\textrm{xN}}$ )
3. Success, false si el manipulador arriba a una singularitat en les dimensions del moviment desitjat (success $\in \left\lbrack \textrm{false},\textrm{true}\right\rbrack$ ). Si s’arriba a una singularitat, la funció ha d’acabar i enviar els estats articulars fins a la singularitat

Fes servir el nom de funció següent per a la teva solució:

-   ComputeLinearTrajectory(q, v, dt, T) 
```matlab
function [q_traj, qdot_traj, success] = ComputeLinearTrajectory(q,v, dt, T)

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('3-1-4')
```

Pots visualitzar la teva trajectòria a Rviz: 

```matlab
  

q_example = [-2.5408, -1.3607, 0.7146, 0.3767, 1.7134, 0]';
v_example = [-0.5;-0.5;0]; 
dt_example =0.01; 
T_example = 1; 
[q_traj_ex, q_dot_traj ,success_example] = ComputeLinearTrajectory(q_example, v_example, dt_example, T_example); 

if success_example
    JointStatesToRviz(q_traj_ex, 'ur3e', T_example);
else
    [~,points_until_singular,~] = size(q_traj_ex);
    Time_until_singular = points_until_singular*dt; 
    JointStatesToRviz(q_traj_ex, 'ur3e', Time_until_singular, 'Ellipsoid', true); 
end

plotTrajectory(q_traj_ex, q_dot_traj, linspace(0,T_example,T_example/dt_example))
```

Prova d’ajustar alguns paràmetres i observa com es comporta la trajectòria. Tingues en compte que el càlcul pot trigar una mica depenent de la resolució i del maquinari. 