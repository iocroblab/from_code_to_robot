```matlab
clear all;
```
# Estructures a MATLAB

En aquest tutorial explicarem què són les estructures de MATLAB i com treballar-hi.


Activeu "Output inline" a la dreta de la barra de desplaçament. 


 ![image_0.png](Structures_media/image_0.png)

# Crear una estructura simple

Una estructura és un tipus de dada que agrupa dades relacionades utilitzant camps amb nom.


En pots crear una mitjançant assignació directa o amb la funció struct.

```matlab
robot.name      = 'MyRobot';
robot.DOF       = 6;
robot.payload   = 2.5           
```

```matlabTextOutput
robot = struct with fields:
       name: 'MyRobot'
        DOF: 6
    payload: 2.5000

```


Creació equivalent amb struct()

```matlab
robot2 = struct('name','MyRobot', ...
    'DOF',6, ...
    'payload',2.5)
```

```matlabTextOutput
robot2 = struct with fields:
       name: 'MyRobot'
        DOF: 6
    payload: 2.5000

```

# Estructures imbricades

Les estructures poden contenir altres estructures, permetent dades jeràrquiques.

```matlab
robot2.links(1) = struct('length',0.5,'mass',4.0)
```

```matlabTextOutput
robot2 = struct with fields:
       name: 'MyRobot'
        DOF: 6
    payload: 2.5000
      links: [1x1 struct]

```

```matlab
robot2.links(2) = struct('length',0.4,'mass',3.5)
```

```matlabTextOutput
robot2 = struct with fields:
       name: 'MyRobot'
        DOF: 6
    payload: 2.5000
      links: [1x2 struct]

```


![image_1.png](Structures_media/image_1.png)

# Accedir als camps

S’accedeix als camps amb notació de punt: NomEstructura.NomCamp

## Llegir un camp
```matlab
robotName=robot.name
```

```matlabTextOutput
robotName = 'MyRobot'
```

## Escriure/actualitzar un camp
```matlab
robot.payload = 3.0
```

```matlabTextOutput
robot = struct with fields:
       name: 'MyRobot'
        DOF: 6
    payload: 3

```

## Accedir a un camp imbricat
```matlab
link1_length = robot2.links(1).length
```

```matlabTextOutput
link1_length = 0.5000
```

```matlab
robot2.links(2).length = 0.8;
```
# Noms de camp dinàmics

Pots afegir o accedir a camps amb noms de variable utilitzant parèntesis.

```matlab
newfield = 'maxSpeed';
robot.(newfield) = 1.2;               % adds a new field maxSpeed
```
## Comprovar l’existència abans d’accedir-hi
```matlab
if isfield(robot, newfield)
    RobotMaxSpeed = robot.maxSpeed
end
```

```matlabTextOutput
RobotMaxSpeed = 1.2000
```

# Afegir i eliminar camps

Utilitza setfield i rmfield, o manipulació directa.


Afegir un camp

```matlab
robot = setfield(robot, 'manufacturer', 'UniversalRobots')
```

```matlabTextOutput
robot = struct with fields:
            name: 'MyRobot'
             DOF: 6
         payload: 3
        maxSpeed: 1.2000
    manufacturer: 'UniversalRobots'

```


Eliminar un camp

```matlab
robot = rmfield(robot, 'manufacturer')
```

```matlabTextOutput
robot = struct with fields:
        name: 'MyRobot'
         DOF: 6
     payload: 3
    maxSpeed: 1.2000

```