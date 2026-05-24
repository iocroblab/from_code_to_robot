```matlab
clear all; 
```
# Ejercicio 2.3 \- Cinemática inversa de un brazo antropomórfico con muñeca esférica

En este ejercicio calcularás la cinemática inversa de un brazo antropomórfico con una muñeca esférica


¡Guarda tus soluciones en las variables predefinidas!

# Descripción de la tarea:

A continuación verás un modelo de un brazo antropomórfico con una muñeca esférica. 


Considera el siguiente conjunto de parámetros DH: 

||||||
| :-: | :-- | :-: | :-: | :-- |
| Eslabón  | a $begin:math:display$m$end:math:display$  | alpha  | d $begin:math:display$m$end:math:display$  | theta   |
| 1  | 0  | pi/2  | 0  | $\displaystyle \theta_1$   |
| 2  | 0.3  | 0  | 0  | $\displaystyle \theta_2$   |
| 3  |   0.2  | pi/2  | 0  | $\displaystyle \theta_3$   |
| 4  | 0  | \-pi/2  | 0.2  | $\displaystyle \theta_4$   |
| 5  | 0  | pi/2  | 0  | $\displaystyle \theta_5$   |
| 6  | 0  | 0  | 0.15  | $\displaystyle \theta_6$   |


![image_0.svg](Exercise-2-3_media/image_0.svg)


En el caso de este manipulador con una muñeca esférica, la solución está desacoplada entre posición y orientación, es decir, las tres articulaciones del brazo se usan para posicionar el efector final, y las tres articulaciones se usan para fijar su orientación.


Dada la posición del efector final $p_{\textrm{ee}}$ y la orientación $R_{\textrm{ee}}$, se deben seguir los siguientes pasos:

1.  Calcula la posición de la muñeca $p_w =p_{\textrm{ee}} -d_6 \cdot z_6$
2. Resuelve la cinemática inversa para el brazo antropomórfico: $\theta_3 ,\theta_2 ,\theta_1$
3. Calcula $R_3^0 \left(\theta_1 ,\theta_2 ,\theta_3 \right)$
4. Calcula $R_6^3 \left(\theta_4 ,\theta_5 ,\theta_6 \right)={R_3^0 }^T \cdot R_{\textrm{ee}}$
5. Resuelve la cinemática inversa para la muñeca esférica: $\theta_4 ,\theta_5 ,\theta_6$

Las cuatro soluciones de la IK del brazo combinadas con las dos soluciones de la muñeca dan como resultado un total de ocho soluciones.


Alcanza la siguiente pose: 

 $$ T_{\textrm{desired}} =\left\lbrack \begin{array}{cccc} 0\ldotp 5 & 0 & 0\ldotp 866 & 0\ldotp 25\newline 0\ldotp 866 & 0 & -0\ldotp 5 & 0\ldotp 1\newline 0 & 1 & 0 & 0\ldotp 35\newline 0 & 0 & 0 & 1 \end{array}\right\rbrack $$ 

Responde todas las preguntas y guarda tu solución en la variable correcta

```matlab
syms q1 q2 q3 q4 q5 q6 real 
% Tabla de parámetros DH
        % a      alpha      d       theta
DH = [    0,     pi/2,     0,       q1;    % Eslabón 1
          0.3,   0,        0,       q2;    % Eslabón 2
          0.2,   pi/2,     0,       q3;    % Eslabón 3
          0,     -pi/2,    0.2,     q4;    % Eslabón 4
          0,     pi/2,     0,       q5;    % Eslabón 5
          0,     0,        0.15,    q6];   % Eslabón 6

Tdesired = [0.5,      0,     0.866, 0.25;
            0.866,    0,    -0.5,  0.1;
            0,        1,     0,    0.35;
            0,        0,     0,    1];
```
# Tarea 1
1.  Calcula la posición de la muñeca $p_w =p_{\textrm{ee}} -d_6 \cdot z_6$
2. Resuelve la cinemática inversa para el brazo antropomórfico: $\theta_3 ,\theta_2 ,\theta_1$

Usa las siguientes variables para guardar tu solución:

-  pee (posición del efector final) 
-  pw (posición de la muñeca) 
-  anthro\_solutions (solución de cinemática inversa donde cada fila es una solución) 
```matlab
pee = [];
pw = [];
anthro_solutions = []; 
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-3-1')
```
# Tarea 2
1.  Calcula $R_3^0 \left(\theta_1 ,\theta_2 ,\theta_3 \right)$
2. Calcula $R_6^3 \left(\theta_4 ,\theta_5 ,\theta_6 \right)={R_3^0 }^T \cdot R_{\textrm{ee}}$

Usa las siguientes variables para guardar tu solución:

-  Ree (rotación del efector final) 
-  R03 (rotación del sistema 0 al sistema 3) 
-  R36 (rotación del sistema 3 al sistema 6) 
```matlab
Ree = []; 
R03 = []; 
R36 = [];
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-3-2')

```
# Tarea 3
1.  Resuelve la cinemática inversa para la muñeca esférica: $\theta_4 ,\theta_5 ,\theta_6$

Usa las siguientes variables para guardar tu solución:

-  spherical\_solutions (solución de cinemática inversa donde cada fila es una solución)  
-  solutions (solución completa de cinemática inversa para el brazo antropomórfico con muñeca esférica, donde cada fila representa una solución única) 
```matlab
spherical_solutions = [];
solutions = [];
```

Puedes comprobar tu trabajo haciendo clic en Run: 

```matlab
 
check_exercise('2-3-3')

```