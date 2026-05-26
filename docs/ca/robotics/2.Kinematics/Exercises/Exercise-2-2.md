```matlab
clear all; 
```
# Exercici 2.2 \- Cinemàtica inversa de braços planars

En aquest exercici calcularàs les solucions de cinemàtica inversa de diferents manipuladors planars.


Si us plau, desa les teves solucions a les variables predefinides!

# Descripció de la tasca:

Calcula les solucions de la cinemàtica inversa per arribar a una posició o postura desitjada.


Respon totes les preguntes i desa la teva solució a la variable correcta

# Tasca 1

![image_0.svg](Exercise-2-2_media/image_0.svg)


Arriba a la posició 

 $$ t_{\textrm{desired}} =\left\lbrack \begin{array}{c} 0\ldotp 3333\newline 0\ldotp 4989\newline 0 \end{array}\right\rbrack $$ 

respecte del marc 0

1.  calcula la solució per arribar a aquesta posició

Fes servir les variables següents per desar la teva solució:

-  sol\_1 (vector fila com: $begin:math:display$q1\,q2$end:math:display$) 
```matlab
sol_1 = []; 
```

```matlabTextOutput
Error en usar atan2
L’argument ha de ser real.
```


Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-2-1')
```
# Tasca 2

![image_1.svg](Exercise-2-2_media/image_1.svg)


Arriba a la posició 

 $$ t_{\textrm{desired}} =\left\lbrack \begin{array}{c} 0\ldotp 2582\newline 0\ldotp 6944\newline 0 \end{array}\right\rbrack $$ 

respecte del marc 0

1.  troba totes les solucions d’aquest problema

Fes servir les variables següents per desar la teva solució:

-  sol\_2 (matriu on cada fila representa una solució com: $begin:math:display$q1\,q2$end:math:display$) 
```matlab
sol_2 = [];
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-2-2')

```
# Tasca 3

![image_2.svg](Exercise-2-2_media/image_2.svg)


Arriba a la postura: 

 $$ T_{\textrm{desired}} =\left\lbrack \begin{array}{cccc} 0\ldotp 3303 & 0\ldotp 9439 & 0 & 0\ldotp 2828\newline 0\ldotp 9439 & -0\ldotp 3303 & 0 & 0\ldotp 6328\newline 0 & 0 & -1 & 0\newline 0 & 0 & 0 & 1 \end{array}\right\rbrack $$ 

respecte del marc 0

1.  Troba totes les solucions de cinemàtica inversa

Fes servir les variables següents per desar la teva solució:

-  sol\_3 (matriu on cada fila representa una solució com: $begin:math:display$q1\,q2\,q3$end:math:display$) 
```matlab
sol_3 = []; 
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-2-3')

```