```matlab
clear all; 
```
# Ejercicio 2.4 \- Planificación de trayectorias en el espacio articular

En este ejercicio desarrollarás funciones para calcular trayectorias articulares. 


¡Guarda tus soluciones en las variables predefinidas!

# Descripción de la tarea:

Sigue las tareas y configura las funciones necesarias para diferentes cálculos de trayectorias. 


Responde todas las preguntas y guarda tu solución en la variable correcta

# Tarea 1

Escribe una función que calcule una trayectoria articular quíntica para una sola articulación. Esta función toma cuatro entradas: 

1.  estado articular inicial (q0)
2. estado articular objetivo (qf)
3. tiempo para alcanzar la pose (t)
4. estados articulares intermedios (N)
5. velocidad inicial (v0)
6. velocidad en el estado articular objetivo (vf)
7. aceleración inicial (a0)
8. aceleración en el estado articular objetivo (af)

y devuelve la trayectoria articular, donde cada fila corresponde a una configuración articular, la trayectoria de velocidad articular, la trayectoria de aceleración articular y un vector que contiene el tiempo en cada entrada de la trayectoria. 


Asume que tanto la velocidad como la aceleración al inicio y al final de la trayectoria son 0. 


Usa el siguiente nombre de función para tu solución:

-  SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af) 

Resuelve este ejercicio sin usar las funciones: 

-  quinticpolytraj() 
```matlab
function [q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af)

end
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-4-1')
```

Puedes representar gráficamente tu trayectoria: 

```matlab
 
q0 = 0; 
qf = pi;
v0 = 0; 
vf = 0; 
a0 = 0;
af = 0; 
T = 8; 
N = 100; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
```
# Tarea 2

Escribe una función que tome dos configuraciones articulares y calcule la trayectoria quíntica para cada articulación. Puedes usar tu función definida previamente


Usa las siguientes variables para guardar tu solución:

-  QuinticConfigurationTrajectory(q0, qt, t, N) 

Resuelve este ejercicio sin usar las funciones: 

-  quinticpolytraj() 
```matlab
function q_config_trajectory = QuinticConfigurationTrajectory(q0,qt,t,N)

end
```

Puedes ver tu trayectoria en Rviz: 

```matlab
 
q0 = zeros(1,6); 
qf = [-pi/7,-pi/2,pi/5,-pi/3,pi/2,pi/4];
v0 = zeros(1,6); 
vf = zeros(1,6); 
a0 = zeros(1,6);
af = zeros(1,6); 
T = 8; 
N = 300; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = QuinticConfigurationTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
JointStatesToRviz(q_trajectory, [], T);

```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-4-2')
```

Observa que ahora tienes una restricción diferente en comparación con el tutorial. Por tanto, tu función debe determinar la aceleración constante requerida. 


La función debe tener cuatro salidas: 

1.  trayectoria del estado articular q
2. trayectoria de velocidad articular qd
3. trayectoria de aceleración articular qdd
4. vector de tiempo timevec

Usa el siguiente nombre de función para tu solución:

-  SingleTrapezoidalTrajectory(q0, qt, T, N, vc) 

Resuelve este ejercicio sin usar las funciones: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = SingleTrapezoidalTrajectory(q0, qt, T, N, vc)

end
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-4-3')
```
# Tarea 4

Amplía tu función de la Tarea 3. Esta función toma seis entradas: 

1.  estado articular inicial (q0)
2. estado articular objetivo (qt)
3. tiempo para alcanzar la pose (t)
4. número de pasos para alcanzar la pose (N)
5. velocidad de crucero (vc)
6. aceleración máxima (amax)

Esta función debe comprobar si la trayectoria articular calculada da como resultado una aceleración mayor que la aceleración máxima permitida. Si es así, la función debe aumentar el tiempo para alcanzar la pose en incrementos de 0.1s hasta que la aceleración resultante esté dentro de los límites. 


Puedes usar tu función de la Tarea 3


Usa el siguiente nombre de función para tu solución:

-  LimitedTrapezoidalTrajectory(q0, qt, t, N, vc, amax) 

La función debe tener cuatro salidas: 

1.  trayectoria del estado articular q
2. trayectoria de velocidad articular qd
3. trayectoria de aceleración articular qdd
4. vector de tiempo

Resuelve este ejercicio sin usar las funciones: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = LimitTrapezoidalTrajectory(q0,qt,t,N,vc,amax)

end
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-4-4')
```