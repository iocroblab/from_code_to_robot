# Interacciones 

A continuación encontrarás un resumen de todas las funciones usadas en el tutorial. Además, se describen a continuación los pasos de configuración para interactuar con el hardware real, dependiendo de tu sistema operativo. 

# StartTutorialApplication

Este comando lanza todas las herramientas del tutorial desde MATLAB usando una interfaz sencilla.


`StartTutorialApplication(Application, Name,Value,...)`


Solo tienes que elegir:

1.  Qué lanzar
2. Ajustes opcionales (robot, controlador, etc.)
### Aplicaciones disponibles
| **Comando**  | **Qué lanza**   |
| :-- | :-- |
| `'Rviz'`  | Visualización del robot   |
| `'Simulation'`  | Simulación Gazebo   |
| `'Hardware'`  | Driver del robot real   |
| `'Teleoperation'`  | Control con teclado   |
| `'Trajectory'`  | Publicador de trayectorias    |
| `'Safety_nodes'`  | Nodo de seguridad   |
| `'Terminal'`  | Terminal ROS listo para usar   |

### **Ajustes de entorno (Docker y workspace)**

Puedes controlar si el tutorial se ejecuta dentro de Docker y qué workspace/contenedor se usa.


**Usar Docker o sistema nativo**


`'Docker',true   % por defecto`

-  `true` → se ejecuta dentro del contenedor Docker del tutorial 
-  `false` → se ejecuta directamente en tu sistema Linux local 

Ejemplo (Linux nativo):


`StartTutorialApplication('Simulation','Docker',false);`


**Seleccionar nombre del contenedor Docker**


`'DockerName','gz-modified'`


Contenedor por defecto: `gz-modified`


Usa esto si creaste tu propio contenedor o lo renombraste.


Ejemplo:


`StartTutorialApplication('Rviz', 'Docker',true, 'DockerName','my_ros_container');`


**Seleccionar workspace**


`'workspace','git_ws'`


Workspace por defecto: `git_ws` (dentro de tu carpeta home)


Cambia esto si usas un workspace ROS diferente.


Ejemplo:


`StartTutorialApplication('Simulation', ...`


 `'workspace','ros2_ws');` 


También puedes usar una ruta absoluta:


`StartTutorialApplication('Terminal', ...`


 `'workspace','/home/user/my_ws');` 

## Opciones más útiles

Seleccionar robot


`'ur_type','ur3e' (por defecto)`


Robots disponibles:

| **Valor**  | **Robot**   |
| :-- | :-- |
| `'ur3e'`  | Universal Robots UR3e   |
| `'ur5e'`  | Universal Robots UR5e   |
| `'ur10e'`  | Universal Robots UR10e   |
| `'ur16e'`  | Universal Robots UR16e   |
| `'ur3'`  | Universal Robots UR3 (serie CB)   |
| `'ur5'`  | Universal Robots UR5 (serie CB)   |
| `'ur10'`  | Universal Robots UR10 (serie CB)   |
| `'threelink'`  | Manipulador tutorial de 3 eslabones   |


**Seleccionar modo de controlador**


`'controller','Torque'`


Modos disponibles:

| **Valor**  | **Efecto**   |
| :-- | :-- |
| `'Position'`  | Control de posición   |
| `'Speed', 'Velocity'`  | Control de velocidad   |
| `'Torque', 'Effort'`  | Control por esfuerzo   |
| `'Trajectory', 'Scaled'`  | Controlador de trayectoria escalada   |


**Opciones solo para hardware**


`'robot_ip','192.168.56.101'`


`'computer_ip','192.168.56.1'   % requerido al usar Docker`

### Ejemplos

**Iniciar simulación con control de par**


`StartTutorialApplication('Simulation', 'ur_type','ur3e', 'controller','Torque');`


**Iniciar driver del robot real**


`StartTutorialApplication('Hardware','robot_ip','192.168.56.101', 'computer_ip','192.168.56.1', 'controller','Trajectory', 'docker',false);`


**Iniciar publicador de trayectoria**


`StartTutorialApplication('Trajectory');`


**Abrir un terminal ROS listo para usar**


`StartTutorialApplication('Terminal');`

# StopTutorialApplication 

StopTutorialApplication('docker',false)


Esta función detendrá todos los procesos ROS actuales.


# SendJointTrajectory

Envía una configuración articular o una trayectoria de configuraciones al controlador.


Entrada 1: array 6xN de configuraciones 


Entrada 2 (opcional): tiempo hasta completar


SendJointTrajectory(q\_traj, time\_to\_completion)


**IMPORTANTE**: Al lanzar múltiples simulaciones o drivers, puedes obtener un error al usar la función. Para resolverlo, limpia la función después de reiniciar cualquier aplicación. 

```matlab
clear SendJointTrajectory
```

# SendJointPosition

Envía una configuración articular 6x1 a la simulación. 


SendJointPosition(q) se usa para el forward\_position\_controller. (No se usa en este tutorial) 

# SendJointSpeeds

Envía un array 6x1 de velocidades articulares a la simulación. 


SendJointSpeeds(qd)

# SendJointTorques

Envía un array 6x1 de pares articulares a la simulación. 


SendJointTorques(tau)

# SetRosDomain

SetRosDomain(Domain\_ID) se usa para establecer tu RosDomain a nivel de sistema. Usa esto cuando tu ordenador esté conectado a una red de otros ordenadores ROS para evitar interacciones no deseadas entre ellos. 

# GetJointStates

GetJointStates() devuelve la configuración articular actual como un array 6x1.

# GetJointSpeeds

GetJointSpeeds() devuelve las últimas velocidades articulares como un array 6x1.

# GetJointEfforts

GetJointEfforts() devuelve los últimos pares articulares aplicados como un array 6x1.

# GetJointValues

GetJointValues() devuelve todo lo anterior con una marca de tiempo. También puedes seleccionar solo un valor: 


$begin:math:display$pos\, time$end:math:display$ = GetJointValues('State')


Otras opciones son: 


'speed', 'effort', 'all', 'threelink'


**IMPORTANTE**: Al usar el paquete de simulación del manipulador threelink, debe seleccionarse 'threelink'.

# GetTeleoperation

Esta función está diseñada para usarse con la aplicación 'Teleoperation'. Devuelve un vector twist 6x1 y el modo de trabajo como segunda salida. 


$begin:math:display$twist\, workmode$end:math:display$ = GetTeleopertaion() 

# Visualización (Rviz)

Rviz es una aplicación puramente de visualización. Podemos enviar configuraciones articulares para que se visualicen instantáneamente en el entorno sin simular ningún movimiento real. Puedes interactuar con el robot en Rviz con la función JointStatesToRviz. 

# JointStatesToRviz(.....)

Esta función permite enviar una configuración articular para visualizarla como: 


JointStatesToRviz(q)


También puedes enviar trayectorias para mostrarlas en pasos de tiempo iguales: 


JointStatesToRviz(q\_trajectory, ur\_model, time\_to\_completion)


donde q\_trajectory es un array 6xN. 


puedes definir el time\_to\_completion. Seleccionar un ur\_model permite visualizar la trayectoria del sistema de herramienta o los elipsoides de manipulabilidad. 

### **Entradas opcionales (Name–Value)**

**Funciones de visualización**

-  `'Ellipsoid'` (true/false) – Mostrar elipsoide de manipulabilidad en RViz 
-  `'EllipsoidKind'` – `'trans'` (traslación) $begin:math:display$por defecto$end:math:display$ o `'rot'` (rotación) 
-  `'EllipsoidDuality'` – `'velocity'` (por defecto) o `'effort'` (dual fuerza/par) 
-  `'EllipsoidResolution'` – Resolución de la malla (mayor = más suave) 
-  `'EllipsoidEvery'` – Publicar elipsoide cada N fotogramas (ajuste de rendimiento) 

**Sistemas y topics**

-  `'BaseFrame'` – Sistema de referencia de RViz (por defecto: `base_link`) 
-  `'ToolFrame'` – Sistema del efector final (por defecto: `tool0`) 
-  `'JointStateTopic'` – Topic para estados articulares (por defecto: `/joint_states`) 
-  `'EllipsoidTopic'` – Topic para nube del elipsoide 
-  `'TrajectoryTopic'` – Topic para nube de puntos de trayectoria 

**Visualización de trayectoria**

-  `'Trajectory'` (true/false) – Mostrar trayectoria del EE como nube de puntos amarilla 
-  Se activa automáticamente cuando se proporcionan múltiples estados articulares 
-  `'PrecomputeEllipsoids'` – Precalcular elipsoides para una reproducción más fluida 

**Flags de control**

-  `'SendJointStates'` (true/false) – Activar/desactivar publicación en `/joint_states` 

**NOTA**: Puedes usar las herramientas de visualización de esta función en simulación estableciendo el flag SendJointStates en false. Con este flag en false, la función solo publicará el elipsoide, pero no los estados articulares, ya que estos los proporciona la propia simulación. 

# Simulación 
# SetSimulationSpeed

Esta función te permite reducir la velocidad de simulación de tu aplicación Gazebo. Llámala con 


SetSimulationSpeed(speed\_factor, 'docker',false) 

# Hardware Universal Robots 

Para interactuar con un robot UR físico, sigue los pasos de configuración dependiendo de tu sistema operativo. 

# Configuración general del cobot

Asegúrate de instalar una versión de PolyScope que permita usar el controlador de esfuerzo. 


Dependiendo de la serie de tu robot, la versión debe ser al menos: 

-  PolyScope X 10.11 
-  PolyScope 5.24 
# Configuración de planos de seguridad del robot

¡Se recomienda probar cualquier código en simulación antes de implementarlo en el hardware real!


Además, se recomienda configurar planos de seguridad en la teach pendant que restrinjan el robot a las zonas físicas seguras de tu entorno de laboratorio. 


Siguiendo la documentación 


[https://www.universal\-robots.com/manuals/EN/HTML/SW10\_6/Content/prod\-usr\-man/software/PolyScopeX/psx\-safety/psx\-planes.htm](https://www.universal-robots.com/manuals/EN/HTML/SW10_6/Content/prod-usr-man/software/PolyScopeX/psx-safety/psx-planes.htm)


puedes definir planos que la herramienta y el codo del robot no puedan sobrepasar. Esto puede ayudar a reducir el riesgo de posibles comportamientos destructivos.

# Notas importantes
-  Al usar el hardware real, empieza con ganancias más pequeñas que en tu simulación e increméntalas gradualmente.  
-  Al usar control por esfuerzo, ten en cuenta que las articulaciones de tu robot físico tienen fricción (que no se considera en simulación). Si tu robot tiene un accesorio tipo gripper, asegúrate de tener en cuenta la masa adicional y el nuevo centro de gravedad en tu modelo dinámico. De lo contrario, puedes tener problemas para alcanzar tu configuración deseada.  
# Configuración en Ubuntu

La comunicación entre el Universal Robot y el ordenador de control se implementa mediante ROS.


El stack de software ROS requerido se proporciona dentro del workspace del tutorial.

### Configuración del robot

Sigue la documentación siguiente para configurar tu hardware UR. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/robot\_setup.html\#robot\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/robot_setup.html#robot-setup>)

### Configuración de red 

Sigue la documentación siguiente para configurar la red en el robot y en tu máquina host Ubuntu. Recuerda las IPs que selecciones, ya que las necesitarás para iniciar el driver de Universal Robots. 


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/setup/network\_setup.html\#network\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/setup/network_setup.html#network-setup>) 

### Configuración adicional

Para una comunicación fiable con el robot y un comportamiento de control estable, se recomienda configurar el sistema host Linux con capacidades de tiempo real. Esto reduce la latencia de comunicación y el jitter temporal durante la operación del robot. Las instrucciones detalladas de configuración están disponibles en la documentación oficial de Universal Robots:


[https://docs.universal\-robots.com/Universal\_Robots\_ROS2\_Documentation/doc/ur\_client\_library/doc/real\_time.html\#real\-time\-setup](<https://docs.universal-robots.com/Universal_Robots_ROS2_Documentation/doc/ur_client_library/doc/real_time.html#real-time-setup>)


**Nota:**


La configuración de tiempo real debe aplicarse en el sistema operativo host. Aplicar ajustes de tiempo real dentro de un contenedor Docker no tiene efecto, ya que los contenedores dependen del kernel del host.

# Conectar al robot
1.  Inicia el robot
2. Asegúrate de que la red esté configurada correctamente
3. Confirma la conexión haciendo ping al robot (en un terminal ejecuta "ping robot\_ip")
4. Inicia un programa nuevo y selecciona el URCap de control externo que descargaste previamente (configuración del robot)
5. Inicia el driver como StartTutorialApplication('Hardare', 'model', urmodel, 'controller', 'velocity', 'robot\_ip',robot\_ip, 'computer\_ip', host\_mashine\_ip)
6. Inicia el programa en la teach pendant
7. Cambia la teach pendant al modo de control remoto

Por defecto cargará el controlador de trayectoria articular escalada, con el que puedes interactuar usando la función SendJointTrajectory. 

# Interactuar con el robot

Todas las funciones que has usado en simulación pueden usarse en el hardware real. Ten cuidado y permanece siempre preparado para pulsar el botón de emergencia. 

# SwitchController

Para cambiar el controlador después de que el driver esté en ejecución puedes usar la función SwitchController("desired controller"). Introduce el controlador deseado como (o su nombre ros2): 

-  Position (no recomendado, usa el controlador de trayectoria en su lugar)  
-  Velocity / Speed  
-  Torque / Effort  
-  Scaled / Trajectory  

# Configuración en Windows (también disponible para Ubuntu)

En Windows, la comunicación directa con el robot se realiza sin ROS. En su lugar, la interacción con el Universal Robot se implementa usando el **MATLAB Hardware Support Package for Universal Robots**, que se basa en el protocolo Real\-Time Data Exchange (RTDE).


Esta interfaz permite comunicación directa entre MATLAB y el controlador del robot y proporciona APIs de alto nivel para ejecución de movimiento, realimentación de estado y acceso a E/S. Las instrucciones de instalación y configuración están disponibles en la documentación oficial de MathWorks:


[https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html)


A diferencia de la configuración en Ubuntu, este enfoque no usa el stack de control basado en ROS. En consecuencia, las utilidades ROS personalizadas y funciones auxiliares proporcionadas en este tutorial no son compatibles con la configuración de Windows.


Sin embargo, la mayoría de operaciones cubiertas en el tutorial (por ejemplo, movimiento articular, ejecución de trayectorias y monitorización de estado) pueden realizarse usando funciones equivalentes de MATLAB proporcionadas por el Hardware Support Package. Las siguientes secciones listan las alternativas correspondientes cuando procede.

# Conectar al robot 
1.  Carga URServerScript.script como programa en la teach pendant
2. Activa Remote Control en la teach pendant
3. Enciende el robot
4. Configura el entorno en MATLAB (Add\-Ons \-\-> Manage Add\-Ons \-\->Setup Robotic System Toolbox Support Package)

### Funciones equivalentes y uso

Empieza configurando tu objeto RTDE como: 

```matlab
robot_ip = '192.168.56.101'; %usa la ip de tu robot
ur = urRTDEClient(robot_ip);
%opcional: ur = urRTDEClient(robot_ip, "RTDEFrequency",500); 
```

Este objeto debe pasarse a todas las funciones RTDE. 


 **Ejemplo:** 

```matlab
q_config = [0,-pi/2,0,-pi/2,0,0]; 
sendJointConfiguration(ur, q_config); 
```

Para interactuar con el robot, sustituye las funciones del tutorial por su equivalente RTDE. 


para más información sobre su uso, consulta [https://www.mathworks.com/help/robotics/get\-started\-urseries\-rtde.html](https://www.mathworks.com/help/robotics/get-started-urseries-rtde.html) 

|||||
| :-- | :-- | :-- | :-- |
| **Función del tutorial**  | **Uso de la función del tutorial**  | **Función RTDE equivalente**  | **Uso de la función RTDE**   |
| GetJointStates  | GetJointStates()  | readJointConfiguration  | readJointConfiguration(ur)   |
| GetJointSpeeds  | GetJointSpeeds()  | readJointVelocity  | readJointVelocity(ur)   |
| SendJointPositions (usado en simulación)  <br> **o**  <br> JointStatesToRviz (usado en los primeros módulos del tutorial para visualización)  | SendJointPositions(q) <br> **o**  <br> JointStatesToRviz(q)  | sendJointConfigurationAndWait  | sendJointConfigurationAndWait(ur, q) <br> opcional: sendJointConfigurationAndWait(ur, q,Endtime=time)    |
| SendJointSpeeds  | SendJointSpeeds(qdot)  | sendSpeedJCommands  | sendSpeedJCommands(ur , qdot)   |
| SendJointTrajectory  | SendJointTrajectory(q\_trajectory, time\_to\_completion)  | followJointWaypoints  | followJointWaypoints(ur, q\_trajectory) <br> opcional: followJointWaypoints(ur, q\_trajectory, waypointTimes=$begin:math:display$t1\,t2\,t3\,t4$end:math:display$) <br> con ti como el tiempo absoluto desde el inicio.   |


 **NOTA:** Actualmente el hardware support package para Universal Robots no incluye una función para enviar comandos de par. Para usar el control por esfuerzo, se recomienda encarecidamente usar una máquina host Ubuntu con kernel de tiempo real. 