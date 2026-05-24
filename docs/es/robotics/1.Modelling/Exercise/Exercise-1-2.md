```matlab
clear all; 
```
# Ejercicio 1.2 \- Modelado de un robot

En este ejercicio modelarás un robot Universal UR3e a partir de parámetros DH dados.


 ![image_0.svg](Exercise-1-2_media/image_0.svg)


¡Guarda tus soluciones en las variables predefinidas!

# Descripción de la tarea:

Dados los parámetros DH de un robot UR3e: 

||||||
| :-: | :-- | :-: | :-: | :-: |
| Eslabón  | a $begin:math:display$m$end:math:display$  | alpha  | d $begin:math:display$m$end:math:display$  | theta   |
| 1  | 0  | pi/2  | 0.15185  | 0   |
| 2  | \-0.24355  | 0  | 0  | 0   |
| 3  | \-0.2132  | 0  | 0  | 0   |
| 4  | 0  | pi/2  | 0.13105  | 0   |
| 5  | 0  | \-pi/2  | 0.08535  | 0   |
| 6  | 0  | 0  | 0.0921  | 0   |


¡La base y el sistema de coordenadas de la primera articulación son idénticos!


Responde todas las preguntas y guarda tu solución en la variable correcta

# Tarea 1

1.  Configura la estructura del robot y usa el formato de datos "column"
2. Define cuerpos y nómbralos body\_1, ..., body\_n
3. Define articulaciones y nómbralas joint\_1, ..., joint\_n

Usa las siguientes variables para guardar tu solución:

-  robot (nombre de tu robot) 
-  bodies (nombre de tu variable que contiene los cuerpos) 
-  joints (nombre de tu variable que contiene las articulaciones) 
```matlab
robot = [];
bodies = []; 
joints = []; 
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('1-2-1')
```

```matlabTextOutput
Checking exercise 1-2-1: Variable Structure

Checking variables:
 
Checking Variable robot
[OK] robot is of type rigidBodyTree

Checking robot data format
[OK] Correct data format

Checking Variable bodies
[OK] bodies is of type cell

Checking Variable joints
[OK] joints is of type cell

checking body elements
checking joint elements
```

# Tarea 2

1.  Vincula los parámetros DH a las articulaciones correspondientes.
2. Vincula las articulaciones con sus cuerpos.
3. Añade los cuerpos al robot
```matlab
DH=[
   %a       alpha       d       theta
   0        pi/2        0.15185  0;
   -0.24355 0           0       0;
   -0.2132  0           0       0;
   0        pi/2        0.13105 0;
   0        -pi/2       0.08535 0;
   0        0           0.0921  0;
    ]
```

Añade tu código aquí: 



Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('1-2-2')

```
# Tarea 3
1.  Define la gravedad en dirección Z negativa con una magnitud de $9\ldotp 81\;\frac{m}{s^2 }$ (ver figura anterior)
2. Establece la posición inicial de las articulaciones 1, 3 y 5 en $\frac{\pi }{2}$

Añade tu código aquí:



Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('1-2-3')
```