```matlab
clear all
```
# Exercici 3.3 \- Teleoperació per velocitat

En aquest exercici escriuràs un codi per teleoperar un robot universal de la teva elecció. 


Quan facis servir una interfície de teleoperació, utilitzaràs el teclat per controlar un robot simulat. 

# Tasca: 

Escriu un codi que mapi la velocitat cartesiana desitjada a l’espai articular i enviï les velocitats articulars a l’entorn de simulació. La velocitat cartesiana que s’ha de controlar és respecte del marc Base o del marc EndEffector. 

# Eines: 

Pots fer servir funcions predefinides per recuperar informació de l’entorn de simulació. 

-  GetJointStates() retorna un vector que conté la configuració actual com $\vec{q} \in {\mathbb{R}}^{6\textrm{x1}}$ 
-  GetTeleoperation() retorna un vector que conté la velocitat cartesiana com $\vec{v} =\left\lbrack \begin{array}{c} \dot{x} \newline \dot{y} \newline \dot{z} \newline \omega_x \newline \omega_y \newline \omega_z  \end{array}\right\rbrack$ i  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; una cadena que conté el marc de referència actual com $\textrm{Mode}\in \left\lbrack \textrm{"Base"},\textrm{"EndEffector"}\right\rbrack$ 

-  SendJointSpeeds(q\_dot) publicarà les velocitats articulars calculades a l’entorn de simulació 
# Consells d’implementació: 
-  Pots triar modelar el robot fent servir el Robotic System Toolbox o el Symbolic Toolbox.  
-  Fes servir la funció waitfor(time) per implementar un retard entre emissions; comença amb una freqüència de 50 Hz.  
### Pistes: 
-  Recorda que el Robotic System Toolbox retorna el jacobià com $J=\left\lbrack \begin{array}{c} J_{\Theta \;} \newline J_p  \end{array}\right\rbrack$ 
-  Si norm(q\_dot) > 1 hauries de normalitzar les velocitats com $q_{\textrm{dot},\textrm{norm}} =\frac{q_{\textrm{dot}} }{\textrm{norm}\left(q_{\textrm{dot}} \right)}$; això et permet analitzar millor el comportament prop de singularitats.  
-  Depenent de la potència de processament del teu ordinador, potser podràs representar l’el·lipsoide de manipulabilitat cridant JointStatesToRviz(q, ur\_model, $begin:math:display$ $end:math:display$, 'Ellipsoid', true, 'SendJointStates', false) amb la configuració actual. Si fas servir un sistema operatiu Windows amb Docker, això pot anar lent. Pots provar de disminuir la resolució de l’el·lipsoide amb JointStatesToRviz(q, ur\_model, $begin:math:display$ $end:math:display$, 'Ellipsoid', true, 'EllipsoidResolution', 15, 'SendJointStates', false) o emetre’l només cada n passos.  
# Interfície de teleoperació

El programa de teleoperació dona les opcions d’entrada següents: 


Velocitat desitjada (lineal o angular) controlada per les tecles W\-A\-S\-D\-SPACE\-CTRL; consulta el terminal per a més informació)

-  W per a ${\dot{x} }^+ \;\textrm{o}\;\omega_x^+$ 
-  S per a ${\dot{x} }^- \;\textrm{o}\;\omega_x^-$ 
-  D per a ${\dot{y} }^+ \;\textrm{o}\;\omega_y^+$ 
-  A per a ${\dot{y} }^- \;\textrm{o}\;\omega_y^-$ 
-  SPACE per a ${\dot{z} }^+ \;\textrm{o}\;\omega_z^+$ 
-  CTRL (Control) per a  ${\dot{z} }^- \;\textrm{o}\;\omega_z^-$ 

Pots alternar entre velocitat angular o lineal prement: 

-  TAB  

Pots alternar el marc de referència de "Base" a "EndEffector" prement: 

-  M 

Pots duplicar la comanda de velocitat mantenint premut: 

-  SHIFT 

Per aturar el programa prem: 

-  q o ESC 

Pots veure els controls al terminal: 


![image_0.png](Exercise-3-3_media/image_0.png)

# Inicia les aplicacions: 

Per iniciar els programes i simulacions necessaris, executa-ho (una vegada): 

```matlab
% StartTutorialApplication('Simulation', 'Controller','Speed','model','ur5e'); 
% StartTutorialApplication('Teleoperation');
```

Si ho executes en un sistema Ubuntu natiu (sense Docker): 

```matlab
StartTutorialApplication('Simulation', 'Controller', 'Speed', 'Docker',false,'model','ur5e'); 
StartTutorialApplication('Teleoperation', 'Docker', false);
```

Per veure la trajectòria de l’efector final pots executar: 

```matlab
% StartTutorialApplication('Trajectory'); 
% Si fas servir ROS en un sistema Ubuntu natiu, fes servir: 
StartTutorialApplication('Trajectory', 'Docker', false);
```
# Codi aquí: 
```matlab
%%afegeix aquí el teu codi de configuració: 

while true
    try %%try ajuda a evitar que el codi falli quan s’inicia abans que els programes estiguin en execució
        %%afegeix aquí el teu codi del bucle: 


    end
end
```