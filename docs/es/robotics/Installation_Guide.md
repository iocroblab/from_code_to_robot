# Guía de instalación

Este tutorial proporciona un **entorno ROS 2 Jazzy reproducible** compatible con MATLAB R2025.


Soporta:

-  Entornos basados en Docker (recomendado) 
-  Instalación nativa en Ubuntu (usuarios avanzados) 
# Requisitos de MATLAB
# Versiones compatibles
-  MATLAB R2025a 
-  MATLAB R2025b 
# Toolboxes requeridas
-  Simulink 
-  ROS Toolbox 
-  Robotics System Toolbox 
-  Symbolic Math Toolbox 
-  Universal Robots Support Package 
# Entornos compatibles

Puedes ejecutar este tutorial usando:

-  Windows 11 + WSL2 + Docker 
-  Ubuntu 24 + Docker 
-  Ubuntu 24 nativo (sin Docker) 
# Instalación usando el script

Todos los entornos usan:


bash install.sh <mode>

## Resumen de modos del script
| **Modo**  | **Instala Docker**  | **Instala ROS**  | **Compila el workspace**  | **Caso de uso**   |
| :-- | :-- | :-- | :-- | :-- |
| fulldocker  | ✅ Sí  | Dentro del contenedor  | ✅ Sí  | Máquina nueva   |
| docker  | ❌ No  | Dentro del contenedor  | ✅ Sí  | Docker ya instalado   |
| fullnative  | ❌ No  | ✅ Sí  | ✅ Sí  | Ubuntu nativo   |
| native  | ❌ No  | ❌ No  | ✅ Sí  | ROS ya instalado   |

## Instalación con Docker (recomendado)

Docker proporciona:

-  Reproducibilidad 
-  Integración con MATLAB 
-  Configuración sencilla 
# Windows 11 + WSL2 + Docker
# 1. Instalar WSL2

Instala Ubuntu 24:


[https://learn.microsoft.com/en\-us/windows/wsl/install](https://learn.microsoft.com/en-us/windows/wsl/install)

# 2. Instalar usando el script

Dentro de WSL:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fulldocker`

Esto hará lo siguiente:

-  Instalar Docker Engine 
-  Compilar la imagen Docker del tutorial 
-  Crear el contenedor llamado FCTR\-container 
# Si Docker ya está instalado en WSL 
1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh docker`

Esto hará lo siguiente:

-  Compilar la imagen Docker del tutorial 
-  Crear el contenedor preconfigurado 
# Comportamiento del contenedor Docker

El instalador:

-  Compila la imagen 
-  Crea un contenedor con nombre 
-  Lo deja **detenido** 

MATLAB:

-  Iniciará el contenedor 
-  Se conectará a él 
-  Gestionará automáticamente su ciclo de vida 
# Opciones Docker personalizadas

Si usas un nombre de contenedor personalizado:


StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');


Si la ubicación del workspace es diferente:


StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');

# Ubuntu 24 + Docker
# Si Docker todavía NO está instalado (ruta recomendada)

Instala todo mediante el script:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh fulldocker`
# Si Docker ya está instalado

Para instalar Docker manualmente, sigue: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


Después ejecuta:

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash` `install.sh docker`

Esto hará lo siguiente:

-  Compilar tu imagen Docker **personalizada** del tutorial 
-  Crear el contenedor **`FCTR-container`** (detenido) 
# Instalar Docker manualmente (sin script)

 **Paso 1 —  Instalar Docker** 


Para instalar Docker manualmente, sigue: 


[https://docs.docker.com/engine/install/ubuntu/](https://docs.docker.com/engine/install/ubuntu/)


**Paso 2 — Clonar el repositorio del tutorial**

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack`
# Paso 3 — Compilar la imagen Docker del tutorial

Navega a la carpeta Docker (la ubicación puede variar ligeramente según la estructura del repositorio):


 `docker build` `-t` `from-code-to-robot-tutorial-docker docker` 


Esto compila la **imagen personalizada del tutorial** que contiene:

-  ROS 2 Jazzy 
-  Gazebo / ros\_gz 
-  stack ros2\_control 
-  Workspace del tutorial 
# Paso 4 — Crear el contenedor del tutorial

Crea el contenedor manualmente:


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


Esto crea un **contenedor detenido** llamado:


`FCTR-container`


El contenedor:

-  Todavía no está en ejecución 
-  Será iniciado automáticamente por MATLAB 
# Probar en MATLAB (MATLAB en Ubuntu)

Añade la carpeta `robotics` y sus subcarpetas al path, y luego ejecuta:


`StartTutorialApplication('Rviz','model','ur5e');`


`JointStatesToRviz([0,-pi/2,0,-pi/2,0,0]);`


`StopTutorialApplications();`


`StartTutorialApplication('Simulation','model','ur3e','controller','effort');`


`StopTutorialApplications();`


**Información adicional de Docker**


Si el nombre de tu contenedor es diferente:


`StartTutorialApplication('Rviz','model','ur3','DockerName','YourContainerName');`


Si la ruta de tu workspace es diferente:


`StartTutorialApplication('Rviz','model','ur3','Workspace','path/to/workspace');`

# Instalación nativa en Ubuntu (sin Docker)

La instalación nativa proporciona:

-  Mayor rendimiento 
-  Menor latencia 
-  Mejor acceso al hardware 
# Opción 1 — Instalación nativa automática (con instalación de ROS)

Instala ROS + dependencias + workspace.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh fullnative`

Instala:

-  ROS 2 Jazzy Desktop 
-  Gazebo + ros_gz 
-  stack ros2_control 
-  middleware DDS 
-  Dependencias del workspace 
-  Compilación completa 
# Opción 2 — Solo workspace (ROS ya instalado)

Usa esto si ROS 2 Jazzy ya está instalado.

1.  `git clone -b docker https://github.com/iocroblab/from_code_to_robot_ros2_stack.git`
2. `cd from_code_to_robot_ros2_stack/scripts`
3. `bash install.sh native`

Esto hará lo siguiente:

-  Clonar el workspace 
-  Importar repositorios 
-  Ejecutar rosdep 
-  Compilar con colcon 
# Opción 3 — Configuración manual del workspace nativo (sin script)

Para usuarios avanzados que prefieren configuración manual.


**1. Instalar ROS 2 Jazzy**


Sigue la guía oficial:


[https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debians.html)


**2. Instalar herramientas requeridas**

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

 **3. Instalar paquetes ROS** 

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
### **Inicializar rosdep:**
1.  `sudo rosdep init`
2. `rosdep update`
# 4. Crear workspace
1.  mkdir -p ~/fctr_ws/src
2. cd ~/fctr_ws/src
3. git clone -b jazzy [https://github.com/iocroblab/from_code_to_robot_ros2_stack.git](https://github.com/iocroblab/from_code_to_robot_ros2_stack.git)
4. source /opt/ros/jazzy/setup.bash
5. cd ..
6. `mkdir` `-p` `src/modified-repositories`
7. `vcs` `import` `src/modified-repositories` `<` `src/from_code_to_robot_ros2_stack/stack.repos`
# 5. Compilar workspace
1.  source /opt/ros/jazzy/setup.bash
2. `rosdep` `update`
3. `rosdep` `install` `--ignore-src` `--from-paths` `src` `-y`
4. `colcon` `build` `--symlink-install` `--cmake-args` `-DCMAKE_BUILD_TYPE=Release`
# Uso del modo nativo en MATLAB

Al usar Ubuntu nativo:


StartTutorialApplication('Rviz','model','ur5e','Docker',false);


JointStatesToRviz([0,-pi/2,0,-pi/2,0,0];


StopTutorialApplications('Docker',false);


StartTutorialApplication('Simulation','model','ur3e','controller','effort','Docker',false);


StopTutorialApplications('Docker',false);

# Solución de problemas
### ROS no encontrado

ejecuta y vuelve a intentarlo: 

1.  source /opt/ros/jazzy/setup.bash
### **errores de rosdep**
1.  sudo rosdep init
2. rosdep update

**Errores de permisos de Docker**

1.  sudo usermod -aG docker \$USER

Después cierra sesión y vuelve a iniciarla.**Configuración recomendada**

| **Caso de uso**  | **Modo recomendado**   |
| :-- | :-- |
| Estudiantes / docencia  | Docker   |
| Workflows de MATLAB  | Docker   |
| Robots reales  | Nativo   |
| Simulación de alto rendimiento  | Nativo   |
| Desarrollo  | Nativo   |