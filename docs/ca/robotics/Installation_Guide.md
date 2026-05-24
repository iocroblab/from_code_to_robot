# Guia d’instal·lació

Aquest tutorial proporciona un **entorn ROS 2 Jazzy reproduïble** compatible amb MATLAB R2025.


Admet:

-  Entorns basats en Docker (recomanat) 
-  Instal·lació nativa a Ubuntu (usuaris avançats) 
# Requisits de MATLAB
# Versions admeses
-  MATLAB R2025a 
-  MATLAB R2025b 
# Toolboxes requerits
-  Simulink 
-  ROS Toolbox 
-  Robotics System Toolbox 
-  Symbolic Math Toolbox 
-  Universal Robots Support Package 
# Entorns admesos

Pots executar aquest tutorial fent servir:

-  Windows 11 + WSL2 + Docker 
-  Ubuntu 24 + Docker 
-  Ubuntu 24 natiu (sense Docker) 
# Instal·lació fent servir l’script

Tots els entorns fan servir:


bash install.sh <mode>

## Visió general dels modes de l’script
| **Mode**  | **Instal·la Docker**  | **Instal·la ROS**  | **Construeix el workspace**  | **Cas d’ús**   |
| :-- | :-- | :-- | :-- | :-- |
| fulldocker  | ✅ Sí  | Dins del contenidor  | ✅ Sí  | Màquina nova   |
| docker  | ❌ No  | Dins del contenidor  | ✅ Sí  | Docker ja instal·lat   |
| fullnative  | ❌ No  | ✅ Sí  | ✅ Sí  | Ubuntu natiu   |
| native  | ❌ No  | ❌ No  | ✅ Sí  | ROS ja instal·lat   |

## Instal·lació amb Docker (recomanada)

Docker proporciona:

-  Reproduïbilitat 
-  Integració amb MATLAB 
-  Configuració senzilla 
# Windows 11 + WSL2 + Docker
# 1. Instal·la WSL2

Instal·la Ubuntu 24:


[https://learn.microsoft.com/en\-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install)

# 2. Instal·la-ho fent servir l’script

Dins de WSL:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fulldocker`

Això farà:

-  Instal·lar Docker Engine 
-  Construir la imatge Docker del tutorial 
-  Crear el contenidor anomenat FCTR\-container 
# Si Docker ja està instal·lat a WSL 
1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh docker`

Això farà:

-  Construir la imatge Docker del tutorial 
-  Crear el contenidor preconfigurat 
# Comportament del contenidor Docker

L’instal·lador:

-  Construeix la imatge 
-  Crea un contenidor amb nom 
-  El deixa **aturat** 

MATLAB:

-  Iniciarà el contenidor 
-  S’hi connectarà 
-  Gestionarà automàticament el cicle de vida 
# Opcions Docker personalitzades

Si fas servir un nom de contenidor personalitzat:


StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');


Si la ubicació del workspace és diferent:


StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');

# Ubuntu 24 + Docker
# Si Docker ENCARA NO està instal·lat (camí recomanat)

Instal·la-ho tot mitjançant l’script:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh fulldocker`
# Si Docker ja està instal·lat

Per instal·lar Docker manualment segueix: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


Després executa:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh docker`

Això farà:

-  Construir la teva imatge Docker **personalitzada** del tutorial 
-  Crear el contenidor **`FCTR-container`** (aturat) 
# Instal·la Docker manualment (sense script)

 **Pas 1 — Instal·la Docker** 


Per instal·lar Docker manualment segueix: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


**Pas 2 — Clona el repositori del tutorial**

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack`
# Pas 3 — Construeix la imatge Docker del tutorial

Navega a la carpeta Docker (la ubicació pot variar lleugerament segons l’estructura del repositori):


 `docker build` `-t` `from-code-to-robot-tutorial-docker docker` 


Això construeix la **imatge personalitzada del tutorial** que conté:

-  ROS 2 Jazzy 
-  Gazebo / ros\_gz 
-  stack ros2\_control 
-  Workspace del tutorial 
# Pas 4 — Crea el contenidor del tutorial

Crea el contenidor manualment:


 `xhost` `+``local:docker`


`docker create \\`


 `--name` `FCTR-container \\` 


 `--env``=``"DISPLAY=``\$DISPLAY``"` `\\` 


 `--env``=``"QT_X11_NO_MITSHM=1"` `\\` 


 `--volume``=``"/tmp/.X11-unix:/tmp/.X11-unix:rw"` `\\` 


 `--device` `/dev/snd \\` 


 `--net``=``host \\`


 `from-code-to-robot-tutorial-docker \\` 


 `bash` `-lc` `"trap : TERM INT; sleep infinity & wait"`


Això crea un **contenidor aturat** anomenat:


`FCTR-container`


El contenidor:

-  Encara no està en execució 
-  MATLAB l’iniciarà automàticament 
# Prova a MATLAB (MATLAB a Ubuntu)

Afegeix la carpeta `robotics` i les seves subcarpetes al path, i després executa:


`StartTutorialApplication('Rviz','model','ur5e');`


`JointStatesToRviz([0,-pi/2,0,-pi/2,0,0]);`


`StopTutorialApplications();`


`StartTutorialApplication('Simulation','model','ur3e','controller','effort');`


`StopTutorialApplications();`


**Informació extra de Docker**


Si el nom del teu contenidor és diferent:


`StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');`


Si el path del teu workspace és diferent:


`StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');`

# Instal·lació nativa a Ubuntu (sense Docker)

La instal·lació nativa ofereix:

-  Més rendiment 
-  Menor latència 
-  Millor accés al maquinari 
# Opció 1 — Instal·lació nativa automàtica (amb instal·lació de ROS)

Instal·la ROS + dependències + workspace.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fullnative`

Instal·la:

-  ROS 2 Jazzy Desktop 
-  Gazebo + ros_gz 
-  stack ros2_control 
-  middleware DDS 
-  dependències del workspace 
-  compilació completa 
# Opció 2 — Només workspace (ROS ja instal·lat)

Fes servir això si ROS 2 Jazzy ja està instal·lat.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh native`

Això farà:

-  Clonar el workspace 
-  Importar repositoris 
-  Executar rosdep 
-  Compilar amb colcon 
# Opció 3 — Configuració manual del workspace natiu (sense script)

Per a usuaris avançats que prefereixen la configuració manual.


**1. Instal·la ROS 2 Jazzy**


Segueix la guia oficial:


[https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html)


**2. Instal·la les eines requerides**

1.  `sudo apt update`
2. `sudo apt install -y \\`
3. `git \\`
4. `build-essential \\`
5. `cmake \\`
6. `pkg-config \\`
7. `python3-pip \\`
8. `python3-venv \\`
9. `python3-colcon-common-extensions \\`
10. `python3-rosdep \\`
11. `python3-vcstool \\`
12. `python3-argcomplete \\`
13. `wget curl`

 **3. Instal·la els paquets de ROS** 

1.  sudo apt install -y \\
2. ros-jazzy-desktop \\
3. ros-jazzy-ros-gz \\
4. ros-jazzy-gz-ros2-control \\
5. ros-jazzy-ros2-control \\
6. ros-jazzy-ros2-controllers \\
7. ros-jazzy-controller-manager \\
8. ros-jazzy-turtlebot3-msgs \\
9. ros-jazzy-rmw-cyclonedds-cpp \\
10. ros-jazzy-rmw-fastrtps-dynamic-cpp \\
11. ros-dev-tools
### **Inicialitza rosdep:**
1.  `sudo rosdep init`
2. `rosdep update`
# 4. Crea el workspace
1.  mkdir -p ~/fctr_ws/src
2. cd ~/fctr_ws/src
3. git clone -b jazzy [https://github.com/iocroblab/from_code_to_robot_ros2_stack.git](https://github.com/iocroblab/from_code_to_robot_ros2_stack.git)
4. source /opt/ros/jazzy/setup.bash
5. cd ..
6. `mkdir` `-p` `src/modified-repositories`
7. `vcs` `import` `src/modified-repositories` `<` `src/from_code_to_robot_ros2_stack/stack.repos`
# 5. Compila el workspace
1.  source /opt/ros/jazzy/setup.bash
2. `rosdep` `update`
3. `rosdep` `install` `--ignore-src` `--from-paths` `src` `-y`
4. `colcon` `build` `--symlink-install` `--cmake-args` `-DCMAKE_BUILD_TYPE=Release`
# Ús del mode natiu a MATLAB

Quan facis servir Ubuntu natiu:


StartTutorialApplication('Rviz','model','ur5e','Docker',false);


JointStatesToRviz([0,-pi/2,0,-pi/2,0,0];


StopTutorialApplications('Docker',false);


StartTutorialApplication('Simulation','model','ur3e','controller','effort','Docker',false);


StopTutorialApplications('Docker',false);

# Resolució de problemes
### ROS no trobat

executa-ho i torna-ho a provar: 

1.  source /opt/ros/jazzy/setup.bash
### **errors de rosdep**
1.  sudo rosdep init
2. rosdep update

**Errors de permisos de Docker**

1.  sudo usermod -aG docker \$USER

Després tanca sessió i torna a iniciar-la.**Configuració recomanada**

| **Cas d’ús**  | **Mode recomanat**   |
| :-- | :-- |
| Estudiants / docència  | Docker   |
| Fluxos de treball amb MATLAB  | Docker   |
| Robots reals  | Natiu   |
| Simulació de rendiment  | Natiu   |
| Desenvolupament  | Natiu   |