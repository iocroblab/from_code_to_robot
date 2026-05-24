# Ejercicio 4.2 \- Control basado en esfuerzo usando el modelo dinámico 

En este ejercicio implementarás un **controlador PD en espacio articular** con **compensación de gravedad y dinámica** para un manipulador UR. El objetivo es llevar todas las articulaciones del robot suavemente hacia una configuración deseada (`qd`) respetando los límites de par articular.

# Tarea

Tu controlador operará en el **modo de control por esfuerzo**, lo que significa que enviará directamente **pares articulares** al robot simulado.


En cada paso de control:

1.  Leerás las posiciones y velocidades articulares actuales desde el simulador.
2. Calcularás el modelo dinámico del robot (matriz de masas, términos de Coriolis/centrífugos y pares de gravedad).
3. Calcularás los pares de control usando una ley PD en el espacio articular.
4. Aplicarás **saturación de par** para mantenerte dentro de los límites físicos de los actuadores.
5. Enviarás los pares calculados de vuelta al simulador.
# Importar el robot

En lugar de usar la librería estándar de MATLAB, para este ejercicio importa el robot usando el archivo URDF bruto. 

-  importrobot($begin:math:display$\"robotics\/Resources\/urdf\/ur5e\.urdf\"$end:math:display$); 

Pista: recuerda establecer la gravedad y la estructura de datos. Aunque puedes definir la estructura de datos durante la importación, la gravedad debe definirse después. 

# Funciones para interactuar con la simulación

Usa las siguientes funciones auxiliares para comunicarte con el simulador:

-   **`[q, q_dot, ~] = GetJointValues('All')`** Lee las **posiciones articulares** actuales (`q`, en radianes) y las **velocidades articulares** (`q_dot`, en radianes/segundo) desde la red ROS. Ambas se devuelven como vectores columna 6×1. 
-  **`SendJointTorques(tau\_sat)`** Envía un vector 6×1 de pares (en **Nm**) a las articulaciones del robot. El comando debe respetar los límites de par del robot. 
# **Estructura del controlador**

El controlador PD implementado con compensación dinámica tiene la siguiente forma general:

 $$ \tau =M\left(q\right)\cdot v+C\left(q,\dot{q} \right)\cdot \;\dot{q} +g\left(q\right) $$ 

con la entrada v: 

 $$ v=\left(\textrm{Kp}\cdot e+\textrm{Kd}\cdot \dot{e} \right) $$ 

y los errores: 

 $$ e=q_{\textrm{desired}} -q $$ 

 $\dot{e} =\dot{q_{\textrm{desired}} } -\dot{q}$ en nuestro caso $\dot{q_{\textrm{desired}} } =0$ 


y una gravedad de $\left\lbrack \begin{array}{c} 0\newline 0\newline -9\ldotp 81 \end{array}\right\rbrack$ 

# Diseño de ganancias

Este esquema no requiere ganancias altas, ya que las no linealidades se cancelan mediante los términos dinámicos y la entrada se escala con la matriz de inercia. Empieza definiendo las matrices de ganancia diagonales usando este enfoque: 

 $$ {\textrm{Kp}}_i \;=\;\omega_i^2 $$ 

 $$ {\textrm{Kd}}_i \;=\;2\cdot \;\zeta \cdot \omega_{i\;} $$ 

con 

 $$ \zeta =0\ldotp 7 $$ 

y

 $$ \omega_i =\frac{4}{\;\zeta \cdot T_{s,i} } $$ 

usando $T_{s,i} \in \left\lbrack 0\ldotp 8,1\ldotp 5\right\rbrack$. Da un tiempo de establecimiento mayor a las articulaciones con límites de par más altos. 

## Ajuste de ganancias 

Analiza el comportamiento de Kp y Kd y su impacto en el comportamiento del robot. Escala gradualmente Kp y/o Kd para estabilizar el robot en su posición inicial $q=\left\lbrack 0,-\frac{\pi }{2},0,-\frac{\pi }{2},0,0\right\rbrack$ 

# Saturación de par

Los robots reales no pueden producir par infinito.


Para evitar comandos poco realistas, debes aplicar **saturación de par**. 

 $$ \tau_{\textrm{sat}} \le \tau_{\max } $$ 

Usa la figura siguiente para construir el vector de límites de par específico para tu robot. 


(Si simulas un robot diferente, asegúrate de actualizar los límites de par)


![image_0.png](Exercise-4-2_media/image_0.png)

# Temporización

Puedes controlar la frecuencia de tu controlador usando las funciones: 

-  r = rateControl(frequency) 
-  waitfor(r) 
# Otras propiedades: 

Este controlador necesita ser rápido. Intenta alcanzar una frecuencia de 50 - 200 Hz para una simulación estable. Si tu hardware no es capaz de ello, puedes reducir la velocidad de simulación usando la función:

-  SetSimulationSpeed(Speedfactor) con Speedfactor $\in \left(\left\lbrack 0,1\right\rbrack \right)$ 
-  o SetSimulationSpeed(Speedfactor, 'docker',false) para Ubuntu nativo  
# Visualización opcional: 

Puedes almacenar los estados articulares, velocidades y pares y visualizarlos usando la función: 

-  plotTrajectory(qstorage, qdstorage, tau_storage) 

Inicia la simulación ejecutando: 

```matlab
%StartTutorialApplication('Simulation','Controller', 'Effort', 'Model','ur3e');
%Si usas ROS en un sistema Ubuntu nativo, usa: 
StartTutorialApplication('Simulation','Controller', 'Effort', 'Model','ur3e', 'Docker', false);
```

Para ver la trayectoria del efector final puedes ejecutar: 

```matlab
%StartTutorialApplication('Trajectory'); 
%Si usas ROS en un sistema Ubuntu nativo, usa: 
StartTutorialApplication('Trajectory', 'Docker', false);
StartTutorialApplication('Safety_nodes','docker',false); %envía un par 0 cuando no se ha enviado ningún otro comando
```
### Carga el robot y configura el vector de gravedad
```matlab
robot = []; 
robot.Gravity = []; 

```
### Configura aquí tus parámetros
```matlab
tau_lim = [];
Kp = []
Kd = []; 
q_desired = []; 
qd_desired = []; 
```
### Configura tu bucle de control

puedes usar tic y toc para ejecutar el bucle while durante un tiempo deseado. 


comprueba el rendimiento de tu hardware y analiza tu tasa de publicación. Para hacerlo, incrementa un contador en cada ejecución del bucle y, después de que el bucle haya terminado, divídelo por el tiempo transcurrido. 

```matlab

qstorage = []; 
qdstorage = []; 
tau_storage = []; 
time = []; 
Execution_time = 10; 
count = 0; 
t0 = tic; 

while toc(t0)<Execution_time

end

```
### Representa gráficamente tu trayectoria 
```matlab
plotTrajectory(qstorage,qdstorage,tau_storage)
```
# Prueba un modelo diferente 

Inspecciona los efectos de un modelo dinámico incorrecto cargando el robot ur3e en tu workspace de MATLAB mientras simulas un modelo ur5e.

```matlab
StopTutorialApplications('docker',false); 
clear SendJointTorques GetJointValues
```

```matlab
StartTutorialApplication('Simulation','Controller', 'Effort', 'Model','ur5e', 'Docker', false);
StartTutorialApplication('Trajectory', 'Docker', false);
StartTutorialApplication('Safety_nodes','docker',false); %envía un par 0 cuando no se ha enviado ningún otro comando
```

```matlab
tau_lim = [150 150 150 28 28 28]'; %UR5e
robot = importrobot(["robotics/Resources/urdf/ur3e.urdf"], DataFormat="column");
g = [0,0,-9.81]';
robot.Gravity=g;

```