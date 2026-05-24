# Dinámica 

En robótica, comprender la dinámica de un manipulador es esencial para el control preciso del movimiento, la planificación de trayectorias y la interacción con el entorno. La dinámica describe la relación entre fuerzas, pares y el movimiento resultante del robot, capturando la influencia de la inercia, las fuerzas de Coriolis y centrífugas, y la gravedad.


Un enfoque ampliamente usado para derivar las ecuaciones de movimiento es la **formulación de Lagrange**, que proporciona un marco sistemático basado en principios energéticos. Al expresar la energía cinética y potencial del sistema, el método de Lagrange produce un conjunto de ecuaciones diferenciales que describen la evolución de las posiciones y velocidades articulares bajo los pares aplicados. Esta formulación es especialmente conveniente para robots con cinemática compleja o múltiples grados de libertad, ya que evita calcular explícitamente las fuerzas en cada articulación debidas a reacciones de restricción.

# Formulación de Lagrange 

La ecuación:

 $$ B\left(q\right)\cdot \ddot{\;q} +C\left(q,\dot{q} \right)\cdot \dot{q} +F\cdot \dot{q} +g\left(q\right)=\tau $$ 

con la matriz de inercia $B\left(q\right)$, la matriz de Coriolis $C\left(q,\dot{q} \right)$, la matriz de fricción $F$ y el término de gravedad $g\left(q\right)$, describe el par $\tau$ ejercido sobre las articulaciones para una configuración q dada y su velocidad $\dot{q}$. 


Esta formulación de Lagrange puede reescribirse para obtener la ecuación de **dinámica directa**:

 $$ \ddot{q} =B^{-1} \left(q\right)\cdot \left(\tau -C\left(q,\dot{q} \right)\cdot \dot{q} -F\cdot \dot{q} -g\left(q\right)\right) $$ 

que calcula las aceleraciones articulares resultantes de un conjunto dado de pares articulares.

### Ejemplo

Considera este manipulador de dos eslabones


![image_0.svg](Dynamics_Lagrange_Formulation_media/image_0.svg)


con las siguientes propiedades de los eslabones: 

||||||
| :-- | :-- | :-- | :-- | :-- |
| Eslabón  | Masa $begin:math:display$kg$end:math:display$  | Radio $begin:math:display$m$end:math:display$  | Longitud del eslabón $begin:math:display$m$end:math:display$  | Centro de masa $begin:math:display$m$end:math:display$   |
| 1  | 0.5   | 0.04  | 0.5  | 0.25   |
| 2  | 0.7  | 0.04  | 0.7  | 0.35   |


El manipulador puede modelarse usando estos parámetros DH: 

||||||
| :-: | :-: | :-: | :-: | :-- |
| Eslabón  | a $begin:math:display$m$end:math:display$  | alpha  | d $begin:math:display$m$end:math:display$  | theta   |
| 1  | 0.5  | 0  | 0  | $\displaystyle q_1$   |
| 2  | 0.7  | 0  | 0  | $\displaystyle q_2$   |

```matlab
        %a      alpha   d       theta
DH = [0.5,     0,       0,       0;
      0.7,     0,       0,       0];

mass1 = 0.5; 
radius1 = 0.04; 
center_of_mass1 = [DH(1,1)/2,0,0]; 

mass2 = 0.7;
radius2 = 0.04; 
center_of_mass2 = [DH(2,1)/2,0,0]; 

config = [pi/3;pi/2];
```
## Matriz de inercia $B\left(q\right)$ 

La matriz de inercia de un manipulador robótico captura cómo la masa y la geometría del robot influyen en su resistencia al movimiento. Es una matriz simétrica, definida positiva, que depende de la configuración articular $q$, y relaciona las aceleraciones articulares $\ddot{q}$ con los pares articulares requeridos $\tau \;$ en las ecuaciones dinámicas.

 $$ B(q)=\sum_{i=1}^n \Big(m_{l_i } \cdot J_p^{l_i ~T} (q)\cdot J_p^{l_i } (q)+J_{\Theta }^{l_i ~T} (q)\cdot R_i (q)\cdot I_{l_i } \cdot R_i^T (q)\cdot J_{\Theta }^{l_i } (q)\Big) $$ 

con 

-  $m_{l_i }$: masa del eslabón i 
-  $J_P^{l_i }$: parte lineal del jacobiano del eslabón i 
-  $J_{\Theta }^{l_i }$: parte rotacional del jacobiano del eslabón i 
-  $R_i$: matriz de rotación desde el sistema del eslabón i al sistema base 
-  $I_{l_i }$: tensor de inercia del eslabón i en su sistema local 
-  $B\left(q\right)$: matriz de inercia total del manipulador 

Para calcular la matriz de inercia del manipulador de ejemplo, necesitas determinar: 

 $$ B(q)=\sum_{i=1}^2 \Big(m_{l_i } \cdot J_p^{l_i ~T} (q)\cdot J_p^{l_i } (q)+J_{\Theta }^{l_i ~T} (q)\cdot R_i (q)\cdot I_{l_i } \cdot R_i^T (q)\cdot J_{\Theta }^{l_i } (q)\Big) $$ 

Los jacobianos del centro de masa de cada eslabón son: 

 $$ J_P^{l_1 } =\left\lbrack \begin{array}{cc} -l_1 \cdot \sin \left(\theta_1 \right) & 0\newline l_1 \cdot \cos \left(\theta_1 \right) & 0\newline 0 & 0 \end{array}\right\rbrack $$ 

 $$ J_P^{l_2 } =\left\lbrack \begin{array}{cc} -a_1 \cdot \sin \left(\theta_1 \right)-l_2 \cdot \sin \left(\theta_1 +\theta_2 \right) & -l_2 \cdot \sin \left(\theta_1 +\theta_2 \right)\newline a_1 \cdot \cos \left(\theta_1 \right)+l_2 \cdot \cos \left(\theta_1 +\theta_2 \right) & l_2 \cdot \cos \left(\theta_1 +\theta_2 \right)\newline 0 & 0 \end{array}\right\rbrack $$ 

 $$ J_{\Theta }^{l_1 } =\left\lbrack \begin{array}{cc} 0 & 0\newline 0 & 0\newline 1 & 0 \end{array}\right\rbrack $$ 

 $$ J_{\Theta }^{l_2 } =\left\lbrack \begin{array}{cc} 0 & 0\newline 0 & 0\newline 1 & 1 \end{array}\right\rbrack $$ 

Observa cómo los jacobianos del eslabón 1 solo consideran el primer eslabón y tienen 0 en las columnas correspondientes a los eslabones siguientes. 

## Cálculo de la inercia

Considera los brazos como cilindros. El tensor de inercia de un cilindro macizo, con radio r, longitud a y eje principal en x, se calcula como: 

 $$ I_{\textrm{xx}} =\frac{1}{2}\cdot m\cdot r^2 $$ 

 $$ I_{\textrm{yy}} =I_{\textrm{zz}} =\frac{1}{12}\cdot m\cdot a^2 +\frac{1}{4}\cdot m\cdot r^2 $$ 

lo que da como resultado el tensor de inercia $I$ (ubicado alrededor del centro de masa)

 $$ I=\left\lbrack \begin{array}{ccc} I_{\textrm{xx}}  & 0 & 0\newline 0 & I_{\textrm{yy}}  & 0\newline 0 & 0 & I_{\textrm{zz}}  \end{array}\right\rbrack $$ 
### Implementación en MATLAB \- Symbolic Toolbox

Este código calcula la matriz de inercia para el manipulador robótico de dos eslabones de ejemplo. 

```matlab
syms a1 a2 l1 l2 q1 q2 m1 m2 theta_i alpha_i a_i d_i m_i r_i l_i r1 r2 real 

p0 = [0,0,0]';
z0 = [0,0,1]'; 
origin = [0,0,0,1]'; 
Ai = [cos(theta_i), -sin(theta_i)*cos(alpha_i), sin(theta_i)*sin(alpha_i), a_i*cos(theta_i);
    sin(theta_i), cos(theta_i)*cos(alpha_i), -cos(theta_i)*sin(alpha_i), a_i*sin(theta_i);
    0, sin(alpha_i), cos(alpha_i), d_i;
    0, 0, 0, 1];

Ixx=0.5*m_i*r_i^2; 
Iyy=1/4*m_i*(1/3 * a_i^2 +r_i^2 );
Izz=Iyy;
LinkInertiaMatrix=diag([Ixx,Iyy,Izz]);

%% INERTIA MATRIX
A01_l = subs(Ai,{a_i,d_i,alpha_i,theta_i},{ l1, 0, 0, q1});
A01 = subs(Ai,{a_i,d_i,alpha_i,theta_i},{a1,0,0,q1}); 
R1 = A01(1:3,1:3);
z1 = R1*z0; 
p1 = A01*origin; 

A12_l = subs(Ai,{a_i,d_i,alpha_i,theta_i},{ l2, 0, 0, q2});

A02_l = A01*A12_l;
R2 = A02_l(1:3,1:3);

pl1 = A01_l*origin;
pl2 = A02_l*origin;
JP_l1 = [cross(z0,pl1(1:3)-p0(1:3)), [0 0 0]'];
JP_l2 = [cross(z0,pl2(1:3)-p0(1:3)), cross(z1,pl2(1:3)-p1(1:3))];
Jtheta_l1 = [z0 [0 0 0]'];
Jtheta_l2 = [z0 z1];
B1 = simplify(m1*JP_l1'*JP_l1);
B2 = simplify(m2*JP_l2'*JP_l2);


I_1 = subs(LinkInertiaMatrix,{a_i, m_i, r_i},{a1, m1, r1});
Il1 = R1*I_1*R1';

I_2 = subs(LinkInertiaMatrix,{a_i, m_i,r_i},{a2, m2,r2});
Il2 = R2*I_2*R2';

B3 = Jtheta_l1'*Il1*Jtheta_l1;
B4 = Jtheta_l2'*Il2*Jtheta_l2;

B = simplify(B1+B2+B3+B4);

B_twolink = (subs(B, [a1, m1, r1, l1, a2, m2, r2, l2], [DH(1,1), mass1, radius1, center_of_mass1(1), DH(2,1), mass2, radius2, center_of_mass2(1)]));
B_twolink_subs = double(subs(B_twolink, [q1 q2], config.'))
```

```matlabTextOutput
B_twolink_subs = 2x2
    0.3315    0.1146
    0.1146    0.1146

```

#
## Robotic System Toolbox 

La Robotic System Toolbox nos permite calcular la matriz de inercia. 


El centro de masa se configura como una propiedad de estructura de un cuerpo, como un vector $\left\lbrack \begin{array}{ccc} x & y & z \end{array}\right\rbrack$ relativo al sistema del cuerpo en $\left\lbrack \mathrm{m}\right\rbrack$. Esto significa que, para nuestro manipulador, la distancia en x es negativa.


la matriz de inercia se pasa como un vector de la forma: $\left\lbrack \begin{array}{cccccc} I_{\textrm{xx}}  & I_{\textrm{yy}}  & I_{\textrm{zz}}  & I_{\textrm{yz}}  & I_{\textrm{xz}}  & I_{\textrm{xy}}  \end{array}\right\rbrack \;\textrm{en}\;\left\lbrack \frac{\textrm{kg}}{{\mathrm{m}}^2 }\right\rbrack$, sin embargo, la inercia usada por la RS Toolbox está alrededor del sistema de la articulación. Para convertir la inercia calculada previamente, necesitas aplicar el teorema de ejes paralelos. 


Para este cilindro, solo $I_{\textrm{yy}}$ e $I_{\textrm{zz}}$ se alterarán como: 

 $$ I_{\textrm{yy}}^{\prime } =I_{\textrm{zz}}^{\prime } =I_{\textrm{yy}} +m\cdot l_i^2 $$ 

como x yace en el eje articular, $I_{\textrm{xx}}$ no cambia.  

```matlab
twolink = rigidBodyTree("DataFormat","column"); 
bodies = cell(2,1);
joints = cell(2,1);

bodies{1} = rigidBody('body_1');
bodies{2} = rigidBody('body_2');

joints{1} = rigidBodyJoint('joint_1', 'revolute');
joints{2} = rigidBodyJoint('joint_2', 'revolute');

% 1) Inercia respecto al CoM (cilindro macizo de longitud a a lo largo de x)
Ixx1_C = 0.5*mass1*radius1^2;
Iyy1_C = (1/12)*mass1*(3*radius1^2 + DH(1,1)^2);
Izz1_C = Iyy1_C;

Ixx2_C = 0.5*mass2*radius2^2;
Iyy2_C = (1/12)*mass2*(3*radius2^2 + DH(2,1)^2);
Izz2_C = Iyy2_C;

% 2) Desplazamiento de ejes paralelos al origen del sistema del cuerpo (r = [lc,0,0])
lc1 = center_of_mass1(1); lc2 = center_of_mass2(1);

Ixx1_O = Ixx1_C;
Iyy1_O = Iyy1_C + mass1*lc1^2;
Izz1_O = Izz1_C + mass1*lc1^2;

Ixx2_O = Ixx2_C;
Iyy2_O = Iyy2_C + mass2*lc2^2;
Izz2_O = Izz2_C + mass2*lc2^2;

Inertia_1 = [Ixx1_O, Iyy1_O, Izz1_O, 0, 0, 0];
Inertia_2 = [Ixx2_O, Iyy2_O, Izz2_O, 0, 0, 0];

% 3) Asigna a los cuerpos rígidos
bodies{1}.Mass = mass1; 
bodies{2}.Mass = mass2;

bodies{1}.CenterOfMass = -center_of_mass1;
bodies{2}.CenterOfMass = -center_of_mass2;

bodies{1}.Inertia = Inertia_1;
bodies{2}.Inertia = Inertia_2;

% 4) Sigue usando DH estándar:
setFixedTransform(joints{1}, DH(1,:), 'dh');
setFixedTransform(joints{2}, DH(2,:), 'dh');

% Añade cuerpos y articulaciones al árbol de cuerpos rígidos
bodies{1}.Joint = joints{1}; 
bodies{2}.Joint = joints{2}; 

twolink.addBody(bodies{1}, 'base');
twolink.addBody(bodies{2}, 'body_1');
B_toolbox = massMatrix(twolink, config) 
```

```matlabTextOutput
B_toolbox = 2x2
    0.3315    0.1146
    0.1146    0.1146

```

## Matriz de Coriolis $C\left(q,\dot{q} \right)$ 

La matriz de Coriolis captura las fuerzas dependientes de la velocidad que aparecen cuando las articulaciones del manipulador se mueven simultáneamente. Estas fuerzas, conocidas como fuerzas de Coriolis y centrífugas, pueden afectar significativamente el movimiento, especialmente a altas velocidades o en robots con eslabones largos o pesados. 


Los términos centrípetos son proporcionales a ${\dot{q_j } }^2$ y los términos de Coriolis son proporcionales a $\dot{q_i } \cdot \dot{q_j }$ 

 $$ C\left(q,\dot{q} \right)=\left\lbrack \begin{array}{cccc} c_{11}  & c_{12}  & \cdots  & c_{1n} \newline c_{21}  & c_{22}  & \cdots  & c_{2n} \newline \vdots  & \vdots  & \ddots  & \vdots \newline c_{\textrm{n1}}  & c_{\textrm{n2}}  & \cdots  & c_{\textrm{nn}}  \end{array}\right\rbrack $$ 

 $$ c_{\textrm{ij}} =\sum_{k=1}^n c_{\textrm{ijk}} \cdot \dot{q_k } $$ 

 $$ c_{ijk} (q,\dot{q} )=\frac{1}{2}\left(\frac{\partial b_{ij} }{\partial q_k }+\frac{\partial b_{ik} }{\partial q_j }-\frac{\partial b_{kj} }{\partial q_i }\right) $$ 

con 

 $$ B\left(q\right)=\left\lbrack \begin{array}{cccc} b_{11}  & b_{12}  & \cdots  & b_{1n} \newline b_{21}  & b_{22}  & \cdots  & b_{2n} \newline \vdots  & \vdots  & \ddots  & \vdots \newline b_{\textrm{n1}}  & b_{\textrm{n2}}  & \cdots  & b_{\textrm{nn}}  \end{array}\right\rbrack $$ 

donde $C\left(q,\dot{q} \right)\in {\mathbb{R}}^{\textrm{nxn}}$ donde $\dot{q} \in {\mathbb{R}}^{\textrm{nx1}}$ 

### Implementación en MATLAB \- Symbolic Toolbox

Para el ejemplo del manipulador de dos eslabones, deben resolverse las siguientes ecuaciones: 

 $$ C\left(q,\dot{q} \right)=\left\lbrack \begin{array}{cc} c_{11}  & c_{12} \newline c_{21}  & c_{22}  \end{array}\right\rbrack $$ 

 $$ c_{\textrm{ij}} =\sum_{k=1}^2 c_{\textrm{ijk}} \cdot \dot{q_k } $$ 
```matlab
jointVel = [pi/4; pi/10]; 
%% CORIOLIS MATRIX
syms qdot1 qdot2 real 
%Coriolis and centrifugal terms
b11 = B_twolink(1,1);
b12 = B_twolink(1,2);
b21 = B_twolink(2,1);
b22 = B_twolink(2,2);

%cijk = simplify(0.5*(diff(bij,qk) + diff(bik,qj)-diff(bjk,qi)))
c111 = simplify(0.5*(diff(b11,q1) + diff(b11,q1)-diff(b11,q1)));
c112 = simplify(0.5*(diff(b11,q2) + diff(b12,q1)-diff(b12,q1)));
c121 = c112;
c122 = simplify(0.5*(diff(b12,q2) + diff(b12,q2)-diff(b22,q1)));
c211 = simplify(0.5*(diff(b21,q1) + diff(b21,q1)-diff(b11,q2)));
c212 = simplify(0.5*(diff(b21,q2) + diff(b22,q1)-diff(b12,q2)));
c221 = c212;
c222 = simplify(0.5*(diff(b22,q2) + diff(b22,q2)-diff(b22,q2)));
c11 = c111*qdot1+c112*qdot2;
c12 = c121*qdot1+c122*qdot2;
c21 = c211*qdot1+c212*qdot2;
c22 = c221*qdot1+c222*qdot2;

C = [c11 c12; c21 c22]
```
C = 

  $$ \displaystyle \left(\begin{array}{cc} -\frac{49\,{\textrm{qdot}}_2 \,\sin \left(q_2 \right)}{400} & -\frac{49\,{\textrm{qdot}}_1 \,\sin \left(q_2 \right)}{400}-\frac{49\,{\textrm{qdot}}_2 \,\sin \left(q_2 \right)}{400}\newline \frac{49\,{\textrm{qdot}}_1 \,\sin \left(q_2 \right)}{400} & 0 \end{array}\right) $$ 
 

```matlab
C_product = double(subs(C, [q1,q2, qdot1, qdot2],[config', jointVel']))*jointVel    
```

```matlabTextOutput
C_product = 2x1
   -0.0725
    0.0756

```


## Robotic System Toolbox 

La función velocityProduct devuelve el producto de $C\left(q,\dot{q} \right)\cdot \dot{q}$ en lugar de solo la matriz. 

```matlab
C_toolbox = velocityProduct(twolink, config, jointVel)
```

```matlabTextOutput
C_toolbox = 2x1
   -0.0725
    0.0756

```

# Término de gravedad $g\left(q\right)$ 

En manipuladores robóticos, el término de gravedad representa los pares requeridos en cada articulación para contrarrestar el efecto de la gravedad sobre los eslabones. Depende de la configuración del robot, la distribución de masa de cada eslabón y la posición de sus centros de masa. Este término es crucial para el control del movimiento, ya que permite al robot mantener posiciones estáticas o seguir trayectorias mientras compensa las fuerzas gravitatorias. En aplicaciones prácticas, el cálculo preciso de las fuerzas gravitatorias garantiza una operación estable y eficiente, especialmente para manipuladores ligeros o flexibles donde los efectos de la gravedad son significativos.


Empieza identificando la dirección de la gravedad en el sistema cero. En el ejemplo del manipulador de dos eslabones, el eje y es la dirección de influencia. 

 $$ g_0 =\left\lbrack \begin{array}{c} 0\newline -g\newline 0 \end{array}\right\rbrack $$ 

con $g=9\ldotp 81\;\frac{\mathrm{m}}{{\mathrm{s}}^2 }$ 


forma el término de gravedad como: 

 $$ g\left(q\right)=\left\lbrack \begin{array}{cccc} g_1 \left(q\right) & g_2 \left(q\right) & \cdots  & g_n \left(q\right) \end{array}\right\rbrack $$ 

con $g_i \left(q\right)=-\sum_{j=1}^n m_{l_j } \cdot g_0^T \cdot J_{P_i }^{l_j }$ 

## Implementación en MATLAB \- Symbolic Toolbox
```matlab
syms g real
g0 = [0 -g 0]';
g1 = simplify(-m1*g0'*JP_l1(:,1) - m2*g0'*JP_l2(:,1))
```
g1 = 
 $\displaystyle g\,m_2 \,{\left(l_2 \,\cos \left(q_1 +q_2 \right)+a_1 \,\cos \left(q_1 \right)\right)}+g\,l_1 \,m_1 \,\cos \left(q_1 \right)$
 

```matlab
g2 = simplify(-m1*g0'*JP_l1(:,2) - m2*g0'*JP_l2(:,2))
```
g2 = 
 $\displaystyle g\,l_2 \,m_2 \,\cos \left(q_1 +q_2 \right)$
 

```matlab
G = [g1 g2]'
```
G = 

  $$ \displaystyle \left(\begin{array}{c} g\,m_2 \,{\left(l_2 \,\cos \left(q_1 +q_2 \right)+a_1 \,\cos \left(q_1 \right)\right)}+g\,l_1 \,m_1 \,\cos \left(q_1 \right)\newline g\,l_2 \,m_2 \,\cos \left(q_1 +q_2 \right) \end{array}\right) $$ 
 

```matlab
G_subs = double(subs(G, [m1,m2,a1,a2,l1,l2,g, q1,q2], [mass1, mass2, DH(1,1), DH(2,1), center_of_mass1(1), center_of_mass2(1), 9.81, config']))
```

```matlabTextOutput
G_subs = 2x1
    0.2484
   -2.0814

```


## Robotic System Toolbox 
```matlab
twolink.Gravity = [0,-9.81,0]; 
G_toolbox = gravityTorque(twolink, config)
```

```matlabTextOutput
G_toolbox = 2x1
    0.2484
   -2.0814

```

# Término de fricción $F$ 

El término de fricción en la dinámica del robot tiene en cuenta los pares resistivos en las articulaciones debidos a la fricción interna en motores, engranajes y rodamientos. A diferencia de los términos de inercia, Coriolis o gravedad, la fricción es no conservativa y depende del movimiento de las articulaciones en lugar de su configuración.


El término de fricción consta de dos partes, la fricción viscosa dependiente de $B_m$ escalada por el cuadrado de la relación de transmisión $G^2$ y la fricción de Coulomb $T_c$ escalada por $G$.

 $$ F\cdot \dot{q} =B_m \cdot G^2 \cdot \dot{q} +T_c \cdot \textrm{sign}\left(\dot{q} \right) $$ 
## Implementación en MATLAB \- Symbolic Toolbox
```matlab
syms bm1 bm2 Tc1 Tc2 G1 G2 qdot real 
F = [bm1, bm2].*[G1, G2].^2
```
F = 

  $$ \displaystyle \left(\begin{array}{cc} {G_1 }^2 \,{\textrm{bm}}_1  & {G_2 }^2 \,{\textrm{bm}}_2  \end{array}\right) $$ 
 

```matlab

F_torque = F * qdot + sign(qdot)* [Tc1, Tc2]
```
F_torque = 

  $$ \displaystyle \left(\begin{array}{cc} {\textrm{bm}}_1 \,\textrm{qdot}\,{G_1 }^2 +{\textrm{Tc}}_1 \,\textrm{sign}\left(\textrm{qdot}\right) & {\textrm{bm}}_2 \,\textrm{qdot}\,{G_2 }^2 +{\textrm{Tc}}_2 \,\textrm{sign}\left(\textrm{qdot}\right) \end{array}\right) $$ 
 

Por ahora, la Robotic System Toolbox ofrece una función para calcular el término de fricción. Si los parámetros son conocidos, necesitas añadirlos al par calculado por las funciones de la toolbox.

# Funciones de dinámica de Robotic System Toolbox

 La Robotic System Toolbox ofrece otras funciones para calcular los términos dinámicos como un conjunto. 


La función de dinámica de la toolbox excluye el término de fricción, por lo que la ecuación se convierte en: 

 $$ B\left(q\right)\cdot \;\ddot{\;q} +C\left(q,\dot{q} \right)\cdot \dot{q} +g\left(q\right)=\tau $$ 

La función externalForce() devuelve la matriz de fuerza externa para una fuerza deseada en un sistema especificado del manipulador: 

```matlab
                                  % Mx My Mz Fx Fy Fz
                               %in [Nm Nm Nm N  N  N] 
desired_endeffector_forces_body1 = [0, 0, 0, 0, 1, 0];
desired_endeffector_forces_body2 = [0, 0, 0, 5, 0, 0];

fext1 = externalForce(twolink,'body_1', desired_endeffector_forces_body1', config)
```

```matlabTextOutput
fext1 = 6x2
         0         0
         0         0
    0.5000         0
   -0.8660         0
    0.5000         0
         0         0

```

```matlab
fext2 = externalForce(twolink,'body_2', desired_endeffector_forces_body2', config)
```

```matlabTextOutput
fext2 = 6x2
         0         0
         0         0
         0    2.5000
         0   -4.3301
         0    2.5000
         0         0

```


Sumar matrices de fuerzas externas combina las fuerzas externas. Esto puede usarse para un robot con múltiples efectores finales: 

```matlab
total_external_forces = fext1 + fext2
```

```matlabTextOutput
total_external_forces = 6x2
         0         0
         0         0
    0.5000    2.5000
   -0.8660   -4.3301
    0.5000    2.5000
         0         0

```


Para calcular las aceleraciones articulares requeridas puedes usar la función forwardDynamics() con la matriz de fuerza externa como entrada: 

```matlab
q_dot_dot = forwardDynamics(twolink, config, [],[], total_external_forces)
```

```matlabTextOutput
q_dot_dot = 2x1
    3.0900
   15.0706

```


La salida de esta función es un vector que contiene las aceleraciones articulares requeridas para cumplir el requisito de entrada (aquí son las fuerzas externas). 


 La función forwardDynamics también permite la velocidad articular como entrada: 

```matlab
q_dot = [-pi/2; pi/5]; 
q_dot_dot_vel = forwardDynamics(twolink, config, q_dot)
```

```matlabTextOutput
q_dot_dot_vel = 2x1
  -10.2416
   25.7650

```


 o pares articulares: 

```matlab
tau = [5; 5]; 
q_dot_dot_torque = forwardDynamics(twolink, config, [], tau) 
```

```matlabTextOutput
q_dot_dot_torque = 2x1
  -10.7434
   72.5289

```


Para calcular los pares articulares requeridos, usa la función inverseDynamics(): 

```matlab
tau_vel = inverseDynamics(twolink, config, q_dot)
```

```matlabTextOutput
tau_vel = 2x1
    0.4419
   -1.7792

```

```matlab
tau_accel = inverseDynamics(twolink, config, [], q_dot_dot)
```

```matlabTextOutput
tau_accel = 2x1
     3
     0

```

```matlab
tau_force = inverseDynamics(twolink, config, [],[], fext1)
```

```matlabTextOutput
tau_force = 2x1
   -0.2516
   -2.0814

```


La salida de esta función es un vector que contiene los pares articulares requeridos para cumplir el requisito de entrada. 

# Parametrización e identificación 

Una propiedad importante del modelo dinámico es la linealidad respecto a los parámetros dinámicos. Esto nos permite reescribir la ecuación dinámica: 

 $$ B\left(q\right)\cdot \;\ddot{\;q} +C\left(q,\dot{q} \right)\cdot \dot{q} +F\cdot \dot{q} +g\left(q\right)=\tau $$ 

a una forma regresora: 

 $$ \tau =Y\left(q,\dot{q} ,\ddot{q} \right)\cdot \Pi \left(m,I\right) $$ 

Intentamos estimar los valores relevantes del tensor de inercia y la masa del eslabón. 


Configura los términos dinámicos para que dependan de estas variables. Asumiendo que los eslabones son homogéneos en términos de distribución de masa, su centro de masa estará ubicado en $0\ldotp 5\cdot \;\textrm{longitud}\;\textrm{del}\;\textrm{eslabón}$.

## Configurar términos dinámicos
```matlab
syms m1 Ixx1 Iyy1 Izz1 m2 Ixx2 Iyy2 Izz2 %dynamic parameters
syms q1 q2 qdot1 qdot2 qdotdot1 qdotdot2 %joint values

a1 = 0.5; 
l1 = a1/2;
a2 = 0.7; 
l2 = a2/2; 

I_1 = diag([Ixx1, Iyy1, Izz1]); 
I_2 = diag([Ixx2, Iyy2, Izz2]);

```

Configura la matriz B

```matlab
A01_l = subs(Ai,{a_i,d_i,alpha_i,theta_i},{ l1, 0, 0, q1});
A01 = subs(Ai,{a_i,d_i,alpha_i,theta_i},{a1,0,0,q1}); 
R1 = A01(1:3,1:3);
z1 = R1*z0; 
p1 = A01*origin; 

A12_l = subs(Ai,{a_i,d_i,alpha_i,theta_i},{ l2, 0, 0, q2});

A02_l = A01*A12_l;
R2 = A02_l(1:3,1:3);

pl1 = A01_l*origin;
pl2 = A02_l*origin;
JP_l1 = [cross(z0,pl1(1:3)-p0(1:3)), [0 0 0]'];
JP_l2 = [cross(z0,pl2(1:3)-p0(1:3)), cross(z1,pl2(1:3)-p1(1:3))];
Jtheta_l1 = [z0 [0 0 0]'];
Jtheta_l2 = [z0 z1];
B1 = simplify(m1*JP_l1'*JP_l1);
B2 = simplify(m2*JP_l2'*JP_l2);

Il1 = R1*I_1*R1';

Il2 = R2*I_2*R2';

B3 = Jtheta_l1'*Il1*Jtheta_l1;
B4 = Jtheta_l2'*Il2*Jtheta_l2;

B = simplify(B1+B2+B3+B4);
```

Configura la matriz de Coriolis: 

```matlab
b11 = B(1,1);
b12 = B(1,2);
b21 = B(2,1);
b22 = B(2,2);

%cijk = simplify(0.5*(diff(bij,qk) + diff(bik,qj)-diff(bjk,qi)))
c111 = simplify(0.5*(diff(b11,q1) + diff(b11,q1)-diff(b11,q1)));
c112 = simplify(0.5*(diff(b11,q2) + diff(b12,q1)-diff(b12,q1)));
c121 = c112;
c122 = simplify(0.5*(diff(b12,q2) + diff(b12,q2)-diff(b22,q1)));
c211 = simplify(0.5*(diff(b21,q1) + diff(b21,q1)-diff(b11,q2)));
c212 = simplify(0.5*(diff(b21,q2) + diff(b22,q1)-diff(b12,q2)));
c221 = c212;
c222 = simplify(0.5*(diff(b22,q2) + diff(b22,q2)-diff(b22,q2)));
c11 = c111*qdot1+c112*qdot2;
c12 = c121*qdot1+c122*qdot2;
c21 = c211*qdot1+c212*qdot2;
c22 = c221*qdot1+c222*qdot2;

C = [c11 c12; c21 c22]
```
C = 

  $$ \displaystyle \begin{array}{l} \left(\begin{array}{cc} -\frac{7\,m_2 \,{\textrm{qdot}}_2 \,\sigma_3 }{80} & -\frac{7\,m_2 \,{\textrm{qdot}}_2 \,\sigma_4 }{40}-\sigma_1 \newline \sigma_1 -\frac{7\,m_2 \,{\textrm{qdot}}_2 \,\sigma_2 }{80} & -\frac{7\,m_2 \,{\textrm{qdot}}_1 \,\sigma_2 }{80} \end{array}\right)\\\mathrm{}\\\textrm{where}\\\mathrm{}\\\;\;\sigma_1 =\frac{7\,m_2 \,{\textrm{qdot}}_1 \,\sigma_3 }{80}\\\mathrm{}\\\;\;\sigma_2 =\sin \left(\overline{q_1 } -q_1 +\overline{q_2 } \right)-\sigma_4 \\\mathrm{}\\\;\;\sigma_3 =\sin \left(\overline{q_1 } -q_1 +\overline{q_2 } \right)+\sigma_4 \\\mathrm{}\\\;\;\sigma_4 =\sin \left(q_1 +q_2 -\overline{q_1 } \right)\end{array} $$ 
 



Configura el término de gravedad: 

```matlab
g0 = [0 -9.81 0]';
g1 = simplify(-m1*g0'*JP_l1(:,1) - m2*g0'*JP_l2(:,1))
```
g1 = 
 $\displaystyle \frac{981\,m_2 \,{\left(\frac{7\,\cos \left(q_1 +q_2 \right)}{20}+\frac{\cos \left(q_1 \right)}{2}\right)}}{100}+\frac{981\,m_1 \,\cos \left(q_1 \right)}{400}$
 

```matlab
g2 = simplify(-m1*g0'*JP_l1(:,2) - m2*g0'*JP_l2(:,2))
```
g2 = 
 $\displaystyle \frac{6867\,m_2 \,\cos \left(q_1 +q_2 \right)}{2000}$
 

```matlab
G = [g1 g2]'
```
G = 

  $$ \displaystyle \left(\begin{array}{c} \frac{981\,\cos \left(\overline{q_1 } \right)\,\overline{m_1 } }{400}+\frac{981\,\overline{m_2 } \,{\left(\frac{\cos \left(\overline{q_1 } \right)}{2}+\frac{7\,\cos \left(\overline{q_1 } +\overline{q_2 } \right)}{20}\right)}}{100}\newline \frac{6867\,\cos \left(\overline{q_1 } +\overline{q_2 } \right)\,\overline{m_2 } }{2000} \end{array}\right) $$ 
 
## Analizar términos dinámicos y construir regresor
```matlab
q = [q1; q2]; 
qdot = [qdot1; qdot2]; 
qdotdot = [qdotdot1; qdotdot2];
tau = B*qdotdot + C*qdot + G
```
tau = 

  $$ \displaystyle \begin{array}{l} \left(\begin{array}{c} \frac{981\,\cos \left(\overline{q_1 } \right)\,\overline{m_1 } }{400}-{\textrm{qdot}}_2 \,{\left(\frac{7\,m_2 \,{\textrm{qdot}}_2 \,\sigma_7 }{40}+\sigma_5 \right)}+{\textrm{qdotdot}}_1 \,{\left({\textrm{Izz}}_1 +{\textrm{Izz}}_2 +\frac{m_1 \,\cos \left(q_1 -\overline{q_1 } \right)}{16}+m_2 \,\sigma_2 \,\sigma_6 +m_2 \,\sigma_1 \,{\left(\frac{\sin \left(\overline{q_1 } \right)}{2}+\frac{7\,\sigma_4 }{20}\right)}\right)}+\frac{981\,\overline{m_2 } \,\sigma_6 }{100}+{\textrm{qdotdot}}_2 \,{\left({\textrm{Izz}}_2 +\frac{7\,m_2 \,\cos \left(q_1 +q_2 -\overline{q_1 } \right)}{40}+\sigma_3 \right)}-\frac{7\,m_2 \,{\textrm{qdot}}_1 \,{\textrm{qdot}}_2 \,{\left(\sigma_8 +\sigma_7 \right)}}{80}\newline {\textrm{qdotdot}}_1 \,{\left({\textrm{Izz}}_2 +\frac{7\,m_2 \,\sigma_9 \,\sigma_2 }{20}+\frac{7\,m_2 \,\sigma_4 \,\sigma_1 }{20}\right)}-{\textrm{qdot}}_1 \,{\left(\frac{7\,m_2 \,{\textrm{qdot}}_2 \,{\left(\sigma_8 -\sigma_7 \right)}}{80}-\sigma_5 \right)}+{\textrm{qdotdot}}_2 \,{\left({\textrm{Izz}}_2 +\sigma_3 \right)}+\frac{6867\,\sigma_9 \,\overline{m_2 } }{2000}-\frac{7\,m_2 \,{\textrm{qdot}}_1 \,{\textrm{qdot}}_2 \,{\left(\sigma_8 -\sigma_7 \right)}}{80} \end{array}\right)\\\mathrm{}\\\textrm{where}\\\mathrm{}\\\;\;\sigma_1 =\frac{7\,\sin \left(q_1 +q_2 \right)}{20}+\frac{\sin \left(q_1 \right)}{2}\\\mathrm{}\\\;\;\sigma_2 =\frac{7\,\cos \left(q_1 +q_2 \right)}{20}+\frac{\cos \left(q_1 \right)}{2}\\\mathrm{}\\\;\;\sigma_3 =\frac{49\,m_2 \,\cos \left(q_1 +q_2 -\overline{q_1 } -\overline{q_2 } \right)}{400}\\\mathrm{}\\\;\;\sigma_4 =\sin \left(\overline{q_1 } +\overline{q_2 } \right)\\\mathrm{}\\\;\;\sigma_5 =\frac{7\,m_2 \,{\textrm{qdot}}_1 \,{\left(\sigma_8 +\sigma_7 \right)}}{80}\\\mathrm{}\\\;\;\sigma_6 =\frac{\cos \left(\overline{q_1 } \right)}{2}+\frac{7\,\sigma_9 }{20}\\\mathrm{}\\\;\;\sigma_7 =\sin \left(q_1 +q_2 -\overline{q_1 } \right)\\\mathrm{}\\\;\;\sigma_8 =\sin \left(\overline{q_1 } -q_1 +\overline{q_2 } \right)\\\mathrm{}\\\;\;\sigma_9 =\cos \left(\overline{q_1 } +\overline{q_2 } \right)\end{array} $$ 
 

```matlab

vars = symvar(tau);   % all symbolic variables

% kinematic variables
kin_vars = [q1 q2 qdot1 qdot2 qdotdot1 qdotdot2];

% dynamic parameters to be estimated 
param_pi = setdiff(vars, kin_vars)
```
param_pi = 

  $$ \displaystyle \left(\begin{array}{cccc} {\textrm{Izz}}_1  & {\textrm{Izz}}_2  & m_1  & m_2  \end{array}\right) $$ 
 



observa cómo param\_pi depende solo de Izz y las masas

```matlab
[c1 ,t1]= coeffs(tau(1),param_pi)
```
c1 = 

  $$ \displaystyle \begin{array}{l} \left(\begin{array}{ccccc} {\textrm{qdotdot}}_1  & {\textrm{qdotdot}}_1 +{\textrm{qdotdot}}_2  & \frac{{\textrm{qdotdot}}_1 \,\cos \left(q_1 -\overline{q_1 } \right)}{16} & {\textrm{qdotdot}}_2 \,{\left(\frac{49\,\cos \left(q_1 +q_2 -\overline{q_1 } -\overline{q_2 } \right)}{400}+\frac{7\,\cos \left(q_1 +q_2 -\overline{q_1 } \right)}{40}\right)}-{\textrm{qdot}}_2 \,{\left(\frac{7\,{\textrm{qdot}}_1 \,\sigma_2 }{80}+\frac{7\,{\textrm{qdot}}_2 \,\sigma_3 }{40}\right)}+{\textrm{qdotdot}}_1 \,{\left({\left(\frac{7\,\cos \left(q_1 +q_2 \right)}{20}+\frac{\cos \left(q_1 \right)}{2}\right)}\,\sigma_1 +{\left(\frac{7\,\sin \left(q_1 +q_2 \right)}{20}+\frac{\sin \left(q_1 \right)}{2}\right)}\,{\left(\frac{\sin \left(\overline{q_1 } \right)}{2}+\frac{7\,\sin \left(\overline{q_1 } +\overline{q_2 } \right)}{20}\right)}\right)}-\frac{7\,{\textrm{qdot}}_1 \,{\textrm{qdot}}_2 \,\sigma_2 }{80} & \frac{981\,\cos \left(\overline{q_1 } \right)\,\overline{m_1 } }{400}+\frac{981\,\overline{m_2 } \,\sigma_1 }{100} \end{array}\right)\\\mathrm{}\\\textrm{where}\\\mathrm{}\\\;\;\sigma_1 =\frac{\cos \left(\overline{q_1 } \right)}{2}+\frac{7\,\cos \left(\overline{q_1 } +\overline{q_2 } \right)}{20}\\\mathrm{}\\\;\;\sigma_2 =\sin \left(\overline{q_1 } -q_1 +\overline{q_2 } \right)+\sigma_3 \\\mathrm{}\\\;\;\sigma_3 =\sin \left(q_1 +q_2 -\overline{q_1 } \right)\end{array} $$ 
 
t1 = 

  $$ \displaystyle \left(\begin{array}{ccccc} {\textrm{Izz}}_1  & {\textrm{Izz}}_2  & m_1  & m_2  & 1 \end{array}\right) $$ 
 

```matlab
[c2, t2] = coeffs(tau(2),param_pi)
```
c2 = 

  $$ \displaystyle \begin{array}{l} \left(\begin{array}{ccc} {\textrm{qdotdot}}_1 +{\textrm{qdotdot}}_2  & {\textrm{qdotdot}}_1 \,{\left(\frac{7\,\sigma_2 \,{\left(\frac{7\,\cos \left(q_1 +q_2 \right)}{20}+\frac{\cos \left(q_1 \right)}{2}\right)}}{20}+\frac{7\,\sin \left(\overline{q_1 } +\overline{q_2 } \right)\,{\left(\frac{7\,\sin \left(q_1 +q_2 \right)}{20}+\frac{\sin \left(q_1 \right)}{2}\right)}}{20}\right)}+{\textrm{qdot}}_1 \,{\left(\frac{7\,{\textrm{qdot}}_1 \,{\left(\sigma_1 +\sigma_3 \right)}}{80}-\frac{7\,{\textrm{qdot}}_2 \,{\left(\sigma_1 -\sigma_3 \right)}}{80}\right)}+\frac{49\,{\textrm{qdotdot}}_2 \,\cos \left(q_1 +q_2 -\overline{q_1 } -\overline{q_2 } \right)}{400}-\frac{7\,{\textrm{qdot}}_1 \,{\textrm{qdot}}_2 \,{\left(\sigma_1 -\sigma_3 \right)}}{80} & \frac{6867\,sigma_2 \,\overline{m_2 } }{2000} \end{array}\right)\\\mathrm{}\\\textrm{where}\\\mathrm{}\\\;\;\sigma_1 =\sin \left(\overline{q_1 } -q_1 +\overline{q_2 } \right)\\\mathrm{}\\\;\;\sigma_2 =\cos \left(\overline{q_1 } +\overline{q_2 } \right)\\\mathrm{}\\\;\;\sigma_3 =\sin \left(q_1 +q_2 -\overline{q_1 } \right)\end{array} $$ 
 
t2 = 

  $$ \displaystyle \left(\begin{array}{ccc} {\textrm{Izz}}_2  & m_2  & 1 \end{array}\right) $$ 
 

observa cómo c2 depende solo de $I_{\textrm{zz},2} \;\textrm{y}\;m_2$. Esto será importante al construir el regresor. Asegúrate de que los índices de tus variables deseadas coincidan en ambos casos:  

```matlab
Y_sym = [c1(1), c1(2), c1(3), c1(4); 
            0,  c2(1), 0 ,    c2(2)]; 
```
## Estimar parámetros

Carga identification\_ex y usa los valores articulares registrados

```matlab
%load("identification_ex.mat"); 
load("Resources/identification_ex.mat");

%Identify dynamic parameters using data from simulated executions
% Regressor
N = size(qout,1);         % number of time instants
d = size(q,1);                    % number of joints
P = size(Y_sym,2);        % number of dynamic parameters

% --- Initialize empty containers -----------------------------------------
YY = [];               % big regressor (2N x P)
Tau = [];              % stacked torques (2N x 1)

% --- Loop over all samples and append ------------------------------------
for i = 1:N

    % Evaluate regressor for this time instant
    Yi = double(subs(Y_sym, ...
        {qdotdot1, qdotdot2, qdot1, qdot2, q1, q2}, ...
        {qddout(i,1), qddout(i,2), ...
         qdout(i,1),  qdout(i,2), ...
         qout(i,1),   qout(i,2)}));

    % Append regressor rows
    YY = [YY; Yi];

    % Get torques at this instant and append
    tau_i = tauout(i, 1:d).';   % convert to column
    Tau = [Tau; tau_i];
end

% Least squares estimate of parameters
pi_hat = pinv(YY) * Tau
```

```matlabTextOutput
pi_hat = 4x1
    0.5229
    0.0294
    0.0327
    2.3543

```