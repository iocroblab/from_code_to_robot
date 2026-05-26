# Currículum

A continuación encontrarás el orden propuesto de tutoriales y ejercicios para la sección de robótica del proyecto From\-Code\-to\-Robot. 

# 0. Básicos 

Este paquete contiene algunos tutoriales que explican cómo usar funciones básicas de MATLAB. Entender estos conceptos es crucial para las siguientes partes del tutorial de robótica. 

## [Manipulación de matrices](./0.Basics/Matrix_manipulation.md) 

Este tutorial explica cómo configurar y usar matrices en MATLAB. 

## [Symbolic Math Toolbox](./0.Basics/Symbolic_Math_toolbox.md)

Este tutorial explica cómo usar variables simbólicas en MATLAB. 

## [Estructuras](./0.Basics/Structures.md)

Este tutorial ilustra cómo acceder a diferentes elementos de una estructura y cómo trabajar con ellos. 

## [Cells](./0.Basics/Cells.md)

Este tutorial ilustra cómo acceder a diferentes elementos de una celda y cómo trabajar con ellos. 

## [Simulink](./0.Basics/Simulink.md)

Este tutorial explica los conceptos básicos de Simulink 

# 1. Modelado 

Este paquete explica los conceptos básicos para modelar un robot con la Robotic System Toolbox. Contiene tutoriales para entender los conceptos usando la Symbolic Toolbox. 

## [Transformaciones](./1.Modelling/Tutorial/Transforms.md)

Este tutorial explica qué son una traslación y una rotación, cómo pueden expresarse en vectores y matrices y su combinación como una matriz de transformación homogénea. Además, se explican diferentes representaciones de rotación. 

### [Ejercicio 1.1 \- Encontrar las transformaciones](./1.Modelling/Exercise/Exercise-1-1.md)

En este ejercicio tendrás que encontrar diferentes transformaciones para describir la pose relativa de dos sistemas. 

## [Modelado con la Robotic System Toolbox](./1.Modelling/Tutorial/Modelling_with_RS_toolbox.md)

Este tutorial explica cómo configurar un robot usando la Robotic System Toolbox. 

### [Ejercicio 1.2 \- Modelado de un robot ](./1.Modelling/Exercise/Exercise-1-2.md)

En este ejercicio configurarás un Universal Robot usando la Robotic System Toolbox.

### [Ejercicio 1.3 \- Encontrar los parámetros DH](./1.Modelling/Exercise/Exercise-1-3.md)

En este ejercicio calcularás los parámetros DH para un manipulador robótico arbitrario y lo configurarás usando la Robotic System Toolbox

# 2. Cinemática

Este paquete explica las relaciones entre los ángulos articulares y la pose resultante de los efectores finales. Usando este conocimiento calcularás los ángulos articulares necesarios para una pose deseada y trayectorias para mover las articulaciones de forma controlada. 

## [Cinemática directa](./2.Kinematics/Tutorial/Forward_Kinematics.md)

Este tutorial explica cómo calcular la transformación resultante de un manipulador dada una configuración articular usando el ejemplo de un Universal UR3. 

### [Ejercicio 2.1 \- Cinemática directa](./2.Kinematics/Exercises/Exercise-2-1.md)

En este ejercicio calcularás la transformación resultante para una configuración dada usando la Symbolic Toolbox y la Robotic System Toolbox. 

## [Cinemática inversa](./2.Kinematics/Tutorial/Inverse_Kinematics.md)

Este tutorial explica cómo calcular una o múltiples soluciones a la pregunta de qué ángulos articulares se requieren para lograr una transformación deseada. 

### [Ejercicio 2.2 \- Cinemática inversa de brazos planares](./2.Kinematics/Exercises/Exercise-2-2.md)

En este ejercicio calcularás las soluciones de cinemática inversa para robots planares simples. 

### [Ejercicio 2.3 \- Cinemática inversa de brazo antropomórfico con muñeca esférica](./2.Kinematics/Exercises/Exercise-2-3.md)

En este ejercicio calcularás las soluciones analíticas de cinemática inversa para un brazo antropomórfico con muñeca esférica usando las técnicas explicadas en el tutorial. 

## [Planificación de trayectorias en espacio articular](./2.Kinematics/Tutorial/Joint_Space_Trajectory_Planning.md)

Este tutorial explica cómo calcular una trayectoria desde un estado articular a otro usando perfiles de velocidad específicos. 

### [Ejercicio 2.4 \- Planificación de trayectorias en espacio articular](./2.Kinematics/Exercises/Exercise-2-4.md)

En este tutorial configurarás diferentes funciones para calcular trayectorias para una sola articulación y para manipuladores completos. Ajustarás las funciones para cumplir requisitos específicos. 

# 3. Cinemática diferencial

Este paquete explica la relación entre velocidades articulares y velocidades cartesianas del efector final. Sobre este conocimiento aprenderás a configurar un algoritmo numérico de cinemática inversa y aprenderás sobre la manipulabilidad de los robots y qué desafíos aparecen. 

## [Jacobianos](<./3.Differential Kinematics/Tutorial/Jacobians.md>)

Este tutorial explica los cálculos de la matriz jacobiana geométrica y analítica usando la Symbolic Toolbox. Además, aprenderás cómo utilizar la Robotic System Toolbox para los cálculos. 

## [Manipulabilidad](<./3.Differential Kinematics/Tutorial/Manipulability.md>) 

Este tutorial explica si un robot puede moverse en configuraciones específicas y con cuánto esfuerzo. Explicará el concepto de singularidades y redundancia y mostrará algunos ejemplos en Rviz. 

### [Ejercicio 3.1 \- Jacobiano](<./3.Differential Kinematics/Exercise/Exercise-3-1.md>) 

En este ejercicio configurarás funciones para calcular simbólicamente los jacobianos geométrico y analítico y calcular las velocidades articulares necesarias para lograr un movimiento específico. Visualizarás este movimiento en Rviz y analizarás cómo cambian la manipulabilidad y las velocidades articulares al estar cerca de una configuración singular.

## [Algoritmo de cinemática inversa](<./3.Differential Kinematics/Tutorial/Inverse_Kinematic_Algorithm.md>)

Este tutorial explica dos enfoques sobre cómo utilizar los jacobianos para configurar un algoritmo numérico de cinemática inversa.

### [Ejercicio 3.2 \- Algoritmo de cinemática inversa](<./3.Differential Kinematics/Exercise/Exercise-3-2.md>)

En este ejercicio configurarás el algoritmo de cinemática inversa con pseudoinversa y analizarás la convergencia y el error que produce. Usarás cuaterniones para calcular el error de orientación usando el jacobiano analítico. 

### [Ejercicio 3.3 \- Teleoperación por velocidad](<./3.Differential Kinematics/Exercise/Exercise-3-3.md>)

En este ejercicio simularás un robot y controlarás el efector final con tu teclado calculando las velocidades articulares requeridas. 

# 4. Dinámica

Este paquete explica la relación entre estados articulares, velocidades y pares usando la formulación de Lagrange. También aprenderás cómo estimar parámetros de tu robot dados datos de prueba suficientes, lo que permite aproximar, por ejemplo, el peso o matrices de inercia de tu manipulador robótico. 

## [Formulación de Lagrange de la dinámica](./4.Dynamics/Tutorial/Dynamics_Lagrange_Formulation.md)

 Este tutorial explicará qué son los diferentes términos de la formulación de Lagrange y cómo se calculan usando la Symbolic Toolbox y la Robotic System Toolbox. Además, se presenta una técnica para la identificación de parámetros dinámicos lineales. 

### [Ejercicio 4.1 \- Cálculo de términos dinámicos](./4.Dynamics/Exercise/Exercise-4-1.md)

En este ejercicio configurarás funciones para calcular los diferentes términos de la formulación de Lagrange para un manipulador arbitrario usando la toolbox simbólica. 

### [Ejercicio 4.2 \- Control basado en esfuerzo usando el modelo dinámico ](./4.Dynamics/Exercise/Exercise-4-2.md)

En este ejercicio controlarás un robot ur3e para sostener un peso en diferentes configuraciones usando el motor de simulación física Gazebo. Calcularás los pares articulares requeridos para sostener un peso usando la formulación de Lagrange. 

# 5. Control 

Este paquete explica diferentes enfoques para algoritmos de control robótico. Por ejemplo, esquemas de control centralizados y descentralizados.

## [Esquemas de control](<./5.Control/Tutorial/Control Schemes.md>)

Este tutorial explica las ideas básicas detrás de diferentes esquemas de control. 

### [Ejercicio 5.1 \- Control por esfuerzo de Threelink usando matrices simbólicas](./5.Control/Exercises/Exercise1/Exercise-5-1.md)

En este ejercicio controlarás un manipulador threelink usando un algoritmo de dinámica inversa. Configurarás un esquema de control en Simulink usando las matrices simbólicas que has calculado en el Ejercicio 4.1 y calcularás matrices más eficientes para reducir la carga computacional. 

### [Ejercicio 5.2 \- Control por esfuerzo de Threelink usando control PD y extensiones](./5.Control/Exercises/Exercise2/Exercise-5-2.md)

En este ejercicio controlarás un manipulador threelink usando control de par y configurarás un esquema de control PD que se aumenta con términos adicionales a lo largo del ejercicio. El resultado es un PID + compensación de gravedad

### [Ejercicio 5.3 \- Control por esfuerzo de UR usando Robotic System Toolbox](./5.Control/Exercises/Exercise3/Exercise-5-3.md)

En este ejercicio controlarás un robot UR de tu elección usando un esquema de control por dinámica inversa mediante los bloques de Simulink de la Robotic System Toolbox. 

### [Ejercicio 5.4 \- Universal Robots en espacio de tarea usando control de velocidad](./5.Control/Exercises/Exercise4/Exercise-5-4.md)

En este ejercicio controlarás un robot UR en espacio de tarea usando un esquema de jacobiano inverso. 

### [Ejercicio 5.5 \- Universal Robots en espacio de tarea usando control por esfuerzo](./5.Control/Exercises/Exercse5/Exercise-5-5.md)

En este ejercicio controlarás un robot UR en espacio de tarea usando un esquema centralizado y descentralizado. 

# 6. Proyecto final

Ahora combinarás tu trabajo de Visión por Computador e IA con tus conocimientos de robótica para detectar y rastrear una fruta y usarla para teleoperar el robot. 