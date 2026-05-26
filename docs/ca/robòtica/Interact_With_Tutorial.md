# Interaccions 

A continuació trobaràs un resum de totes les funcions utilitzades al tutorial. A més, s’hi descriuen els passos de configuració per interactuar amb el maquinari real, depenent del teu sistema operatiu. 

# StartTutorialApplication

Aquesta comanda inicia totes les eines del tutorial des de MATLAB fent servir una única interfície senzilla.


`StartTutorialApplication(Application, Name,Value,...)`


Només has de triar:

1.  Què vols iniciar
2. Configuració opcional (robot, controlador, etc.)
### Aplicacions disponibles
| **Comanda**  | **Què inicia**   |
| :-- | :-- |
| `'Rviz'`  | Visualització del robot   |
| `'Simulation'`  | Simulació Gazebo   |
| `'Hardware'`  | Driver del robot real   |
| `'Teleoperation'`  | Control amb teclat   |
| `'Trajectory'`  | Publicador de trajectòries    |
| `'Safety_nodes'`  | Node de seguretat   |
| `'Terminal'`  | Terminal ROS llest per fer servir   |

### **Configuració d’entorn (Docker i workspace)**

Pots controlar si el tutorial s’executa dins de Docker i quin workspace/contenidor es fa servir.


**Fer servir Docker o sistema natiu**


`'Docker',true   % per defecte`

-  `true` → s’executa dins del contenidor Docker del tutorial 
-  `false` → s’executa directament al teu sistema Linux local 

Exemple (Linux natiu):


`StartTutorialApplication('Simulation','Docker',false);`


**Selecciona el nom del contenidor Docker**


`'DockerName','gz-modified'`


Contenidor per defecte: `gz-modified`


Fes servir això si has creat el teu propi contenidor o l’has reanomenat.


Exemple:


`StartTutorialApplication('Rviz', 'Docker',true, 'DockerName','my_ros_container');`


**Selecciona el workspace**


`'workspace','git_ws'`


Workspace per defecte: `git_ws` (dins de la teva carpeta home)


Canvia-ho si fas servir un workspace ROS diferent.


Exemple:


`StartTutorialApplication('Simulation', ...`


 `'workspace','ros2_ws');` 


També pots fer servir un path absolut:


`StartTutorialApplication('Terminal', ...`


 `'workspace','/home/user/my_ws');` 

## Opcions més útils

Selecciona el robot


`'ur_type','ur3e' (per defecte)`


Robots disponibles:

| **Valor**  | **Robot**   |
| :-- | :-- |
| `'ur3e'`  | Universal Robots UR3e   |
| `'ur5e'`  | Universal Robots UR5e   |
| `'ur10e'`  | Universal Robots UR10e   |
| `'ur16e'`  | Universal Robots UR16e   |
| `'ur3'`  | Universal Robots UR3 (sèrie CB)   |
| `'ur5'`  | Universal Robots UR5 (sèrie CB)   |
| `'ur10'`  | Universal Robots UR10 (sèrie CB)   |
| `'threelink'`  | Manipulador tutorial de 3 enllaços   |


**Selecciona el mode del controlador**


`'controller','Torque'`


Modes disponibles:

| **Valor**  | **Efecte**   |
| :-- | :-- |
| `'Position'`  | Control de posició   |
| `'Speed', 'Velocity'`  | Control de velocitat   |
| `'Torque', 'Effort'`  | Control d’esforç   |
| `'Trajectory', 'Scaled'`  | Controlador de trajectòria escalada   |


**Opcions només per a maquinari**


`'robot_ip','192.168.56.101'`


`'computer_ip','192.168.56.1'   % requerit quan es fa servir Docker`

### Exemples

**Inicia la simulació amb control de parell**


`StartTutorialApplication('Simulation', 'ur_type','ur3e', 'controller','Torque');`


**Inicia el driver del robot real**


`StartTutorialApplication('Hardware','robot_ip','192.168.56.101', 'computer_ip','192.168.56.1', 'controller','Trajectory', 'docker',false);`


**Inicia el publicador del camí de trajectòria**


`StartTutorialApplication('Trajectory');`


**Obre un terminal ROS llest per fer servir**


`StartTutorialApplication('Terminal');`

# StopTutorialApplication 

StopTutorialApplication('docker',false)


Aquesta funció aturarà tots els processos ROS actuals.


# SendJointTrajectory

Envia una configuració articular o una trajectòria de configuracions al controlador.


Entrada 1: array 6xN de configuracions 


Entrada 2 (opcional): temps per completar


SendJointTrajectory(q\_traj, time\_to\_completion)


**IMPORTANT**: Quan iniciïs múltiples simulacions o drivers pots obtenir un error en fer servir la funció. Per resoldre-ho, neteja la funció després de reiniciar qualsevol aplicació. 

```matlab
clear SendJointTrajectory
```

# SendJointPosition

Envia una configuració articular 6x1 a la simulació. 


SendJointPosition(q) es fa servir per al forward\_position\_controller. (No s’utilitza en aquest tutorial) 

# SendJointSpeeds

Envia un array de velocitats articulars 6x1 a la simulació. 


SendJointSpeeds(qd)

# SendJointTorques

Envia un array de parells articulars 6x1 a la simulació. 


SendJointTorques(tau)

# SetRosDomain

SetRosDomain(Domain\_ID) es fa servir per definir el teu RosDomain a tot el sistema. Fes-ho servir quan l’ordinador estigui connectat a una xarxa d’altres ordinadors ROS per evitar interaccions no desitjades entre ells. 

# GetJointStates

GetJointStates() retorna la configuració articular actual com un array 6x1.

# GetJointSpeeds

GetJointSpeeds() retorna les últimes velocitats articulars com un array 6x1.

# GetJointEfforts

GetJointEfforts() retorna els últims parells articulars aplicats com un array 6x1.

# GetJointValues

GetJointValues() retorna tot l’anterior amb una marca temporal. També pots seleccionar només un valor: 


$begin:math:display$pos\, time$end:math:display$ = GetJointValues('State')


Altres opcions són: 


'speed', 'effort', 'all', 'threelink'


**IMPORTANT**: Quan facis servir el paquet de simulació del manipulador threelink, s’ha de seleccionar 'threelink'.

# GetTeleoperation

Aquesta funció està dissenyada per fer-se servir amb l’aplicació 'Teleoperation'. Retorna un vector twist 6x1 i el mode de treball com a segona sortida. 


$begin:math:display$twist\, workmode$end:math:display$ = GetTeleopertaion() 

# Visualització (Rviz)

Rviz és una aplicació purament de visualització. Podem enviar configuracions articulars perquè es visualitzin instantàniament a l’entorn sense simular cap moviment real. Pots interactuar amb el robot a Rviz amb la funció JointStatesToRviz. 

# JointStatesToRviz(.....)

Aquesta funció et permet enviar una configuració articular perquè es visualitzi com: 


JointStatesToRviz(q)


També pots enviar trajectòries perquè es mostrin en passos temporals iguals: 


JointStatesToRviz(q\_trajectory, ur\_model, time\_to\_completion)


on q\_trajectory és un array 6xN. 


pots definir el time\_to\_completion. Seleccionar un ur\_model et permet visualitzar la trajectòria del marc de l’eina o els el·lipsoides de manipulabilitat. 

### **Entrades opcionals (Name–Value)**

**Funcions de visualització**

-  `'Ellipsoid'` (true/false) – Mostra l’el·lipsoide de manipulabilitat a RViz 
-  `'EllipsoidKind'` – `'trans'` (translació) $begin:math:display$per defecte$end:math:display$ o `'rot'` (rotació) 
-  `'EllipsoidDuality'` – `'velocity'` (per defecte) o `'effort'` (dual força/parell) 
-  `'EllipsoidResolution'` – Resolució de la malla (més alta = més suau) 
-  `'EllipsoidEvery'` – Publica l’el·lipsoide cada N frames (ajust de rendiment) 

**Marcs i tòpics**

-  `'BaseFrame'` – Marc de referència de RViz (per defecte: `base_link`) 
-  `'ToolFrame'` – Marc de l’efector final (per defecte: `tool0`) 
-  `'JointStateTopic'` – Tòpic per als estats articulars (per defecte: `/joint_states`) 
-  `'EllipsoidTopic'` – Tòpic per al núvol de l’el·lipsoide 
-  `'TrajectoryTopic'` – Tòpic per al núvol de punts de trajectòria 

**Visualització de trajectòria**

-  `'Trajectory'` (true/false) – Mostra el camí de l’EE com un núvol de punts groc 
-  S’activa automàticament quan es proporcionen múltiples estats articulars 
-  `'PrecomputeEllipsoids'` – Precalcula el·lipsoides per a una reproducció més suau 

**Flags de control**

-  `'SendJointStates'` (true/false) – Activa/desactiva la publicació de `/joint_states` 

**NOTA**: Pots fer servir les eines de visualització d’aquesta funció en simulació definint el flag SendJointStates a false. Amb aquest flag a false, la funció només publicarà l’el·lipsoide però no els estats articulars, ja que aquests són proporcionats per la simulació mateixa. 

# Simulació 
# SetSimulationSpeed

Aquesta funció et permet reduir la velocitat de simulació de la teva aplicació Gazebo. Crida-la amb 


SetSimulationSpeed(speed\_factor, 'docker',false) 

# Maquinari Universal Robots 

Per interactuar amb un robot UR físic, segueix els passos de configuració segons el teu sistema operatiu. 

# Configuració general del cobot

Assegura’t d’instal·lar una versió de PolyScope que permeti l’ús del controlador d’esforç. 


Depenent de la sèrie del teu robot, la versió hauria de ser com a mínim: 

-  PolyScope X 10.11 
-  PolyScope 5.24 
# Configuració de plans de seguretat del robot

Es recomana provar qualsevol codi en simulació abans d’implementar-lo al maquinari real!


A més, es recomana configurar plans de seguretat al teach pendant que restringeixin el robot a les zones físiques segures del teu entorn de laboratori. 


Seguint la documentació 


[https://www.universal\-robots.com/manuals/EN/HTML/SW10\_6/Content/prod\-usr\-man/software/PolyScopeX/psx\-safety/psx\-planes.htm](https://www.universal-robots.com/manuals/EN/HTML/SW10_6/Content/prod-usr-man/software/PolyScopeX/psx-safety/psx-planes.htm)


pots definir plans que l’eina i el colze del robot no puguin travessar. Això pot ajudar a reduir el risc d’un comportament potencialment destructiu.

# Notes importants
-  Quan facis servir el maquinari real, comença amb guanys més petits que en la simulació i augmenta’ls gradualment.  
-  Quan facis servir el control d’esforç, tingues en compte que les articulacions del teu robot físic tenen fricció (que no es considera en la simulació). Si el teu robot té un gripper acoblat, assegura’t de tenir en compte la massa addicional i el nou centre de gravetat en el teu model dinàmic. Altrament pots tenir problemes per arribar a la configuració desitjada.  
# Configuració a Ubuntu

La comunicació entre el Universal Robot i l’ordinador de control s’implementa via ROS.


La pila de programari ROS requerida es proporciona dins del workspace del tutorial.

### Configuració del robot

Segueix la documentació següent per configurar el teu maquinari UR. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/robot\_setup.html\#robot\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/robot_setup.html#robot-setup>)

### Configuració de xarxa 

Segueix la documentació següent per configurar la xarxa al robot i a la teva màquina host Ubuntu. Recorda les IPs que seleccionis, ja que les necessitaràs per iniciar el driver de Universal Robots. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/network\_setup.html\#network\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/network_setup.html#network-setup>) 

### Configuració addicional

Per a una comunicació fiable amb el robot i un comportament de control estable, es recomana configurar el sistema host Linux amb capacitats de temps real. Això redueix la latència de comunicació i el jitter temporal durant l’operació del robot. Les instruccions detallades de configuració estan disponibles a la documentació oficial de Universal Robots:


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/real\_time.html\#real\-time\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/real_time.html#real-time-setup>)


**Nota:**


La configuració de temps real s’ha d’aplicar al sistema operatiu host. Aplicar configuracions de temps real dins d’un contenidor Docker no té efecte, ja que els contenidors depenen del kernel del host.

# Connecta’t al robot
1.  Inicia el robot
2. Assegura’t que la xarxa estigui configurada correctament
3. Confirma la connexió fent ping al robot (en un terminal executa "ping robot\_ip")
4. Inicia un programa nou i selecciona l’URCap d’external control que has descarregat prèviament (configuració del robot)
5. Inicia el driver com StartTutorialApplication('Hardare', 'model', urmodel, 'controller', 'velocity', 'robot\_ip',robot\_ip, 'computer\_ip', host\_mashine\_ip)
6. Inicia el programa al teach pendant
7. Posa el teach pendant en mode de control remot

Per defecte carregarà el controlador de trajectòria articular escalada, amb el qual pots interactuar fent servir la funció SendJointTrajectory. 

# Interactua amb el robot

Totes les funcions que has fet servir en simulació es poden fer servir amb el maquinari real. Ves amb compte i estigues sempre a punt per prémer el botó d’emergència. 

# SwitchController

Per canviar el controlador després que el driver estigui en execució, pots fer servir la funció SwitchController("desired controller") per canviar el controlador. Introdueix el controlador desitjat com (o el seu nom ros2): 

-  Position (no recomanat, fes servir el controlador de trajectòria en lloc d’aquest)  
-  Velocity / Speed  
-  Torque / Effort  
-  Scaled / Trajectory  

# Configuració a Windows (també disponible per a Ubuntu)

A Windows, la comunicació directa amb el robot es fa sense ROS. En lloc d’això, la interacció amb el Universal Robot s’implementa fent servir el **MATLAB Hardware Support Package for Universal Robots**, que es basa en el protocol Real\-Time Data Exchange (RTDE).


Aquesta interfície permet la comunicació directa entre MATLAB i el controlador del robot i proporciona APIs d’alt nivell per a l’execució de moviments, feedback d’estat i accés a I/O. Les instruccions d’instal·lació i configuració estan disponibles a la documentació oficial de MathWorks:


[https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html)


En contrast amb la configuració a Ubuntu, aquest enfocament no fa servir la pila de control basada en ROS. En conseqüència, les utilitats ROS personalitzades i les funcions auxiliars proporcionades en aquest tutorial no són compatibles amb la configuració de Windows.


Tanmateix, la majoria d’operacions cobertes al tutorial (p. ex., moviment articular, execució de trajectòries i monitoratge d’estat) es poden realitzar fent servir funcions equivalents de MATLAB proporcionades pel Hardware Support Package. Les seccions següents llisten les alternatives corresponents quan escau.

# Connecta’t al robot 
1.  Carrega URServerScript.script com a programa al teach pendant
2. Activa Remote Control al teach pendant
3. Encén el robot
4. Configura l’entorn a Matlab (Add\-Ons \-\-> Manage Add\-Ons \-\->Setup Robotic System Toolbox Support Package)

### Funcions equivalents i ús

Comença configurant el teu objecte RTDE com: 

```matlab
robot_ip = '192.168.56.101'; %fes servir la ip del teu robot
ur = urRTDEClient(robot_ip);
%opcional: ur = urRTDEClient(robot_ip, "RTDEFrequency",500); 
```

Aquest objecte s’ha de passar a totes les funcions RTDE. 


 **Exemple:** 

```matlab
q_config = [0,-pi/2,0,-pi/2,0,0]; 
sendJointConfiguration(ur, q_config); 
```

Per interactuar amb el robot, substitueix les funcions del tutorial pel seu equivalent RTDE. 


per a més informació sobre el seu ús consulta [https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html) 

|||||
| :-- | :-- | :-- | :-- |
| **Funció del tutorial**  | **Ús de la funció del tutorial**  | **Funció RTDE equivalent**  | **Ús de la funció RTDE**   |
| GetJointStates  | GetJointStates()  | readJointConfiguration  | readJointConfiguration(ur)   |
| GetJointSpeeds  | GetJointSpeeds()  | readJointVelocity  | readJointVelocity(ur)   |
| SendJointPositions (utilitzada en simulació)  <br> **o**  <br> JointStatesToRviz (utilitzada als primers mòduls del tutorial per a visualització)  | SendJointPositions(q) <br> **o**  <br> JointStatesToRviz(q)  | sendJointConfigurationAndWait  | sendJointConfigurationAndWait(ur, q) <br> opcional: sendJointConfigurationAndWait(ur, q,Endtime=time)    |
| SendJointSpeeds  | SendJointSpeeds(qdot)  | sendSpeedJCommands  | sendSpeedJCommands(ur , qdot)   |
| SendJointTrajectory  | SendJointTrajectory(q\_trajectory, time\_to\_completion)  | followJointWaypoints  | followJointWaypoints(ur, q\_trajectory) <br> opcional: followJointWaypoints(ur, q\_trajectory, waypointTimes=$begin:math:display$t1\,t2\,t3\,t4$end:math:display$) <br> amb ti com el temps absolut des de l’inici.   |


 **NOTA:** Actualment, el hardware support package per a Universal Robots no inclou cap funció per enviar comandes de parell. Per fer servir el control d’esforç, és molt recomanable utilitzar una màquina host Ubuntu amb un kernel de temps real. 