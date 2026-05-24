# Exercici 4.1 \- Càlcul de termes dinàmics

En aquest exercici configuraràs funcions per calcular els termes dinàmics de la formulació de Lagrange per a un manipulador de tres enllaços. 


![image_0.svg](Exercise-4-1_media/image_0.svg)

|||||||
| :-- | :-- | :-- | :-- | :-- | :-- |
| Enllaç  | Massa $begin:math:display$kg$end:math:display$  | Amplada de l’enllaç $begin:math:display$m$end:math:display$  | Alçada de l’enllaç $begin:math:display$m$end:math:display$  | Longitud de l’enllaç $begin:math:display$m$end:math:display$  | Centre de massa $begin:math:display$m$end:math:display$   |
| 1  | 5  | 0.1  | 0.1  | 0.3  | 0.15   |
| 2  | 3  | 0.1  | 0.1  | 0.5  | 0.25   |
| 3  | 3  | 0.1  | 0.1  | 0.5  | 0.25   |


El manipulador es pot modelar fent servir aquests paràmetres DH: 

||||||
| :-: | :-: | :-- | :-: | :-- |
| Enllaç  | a $begin:math:display$m$end:math:display$  | alpha  | d $begin:math:display$m$end:math:display$  | theta   |
| 1  | 0.3  | $\displaystyle \frac{\pi }{2}$  | 0.2  | $\displaystyle q_1$   |
| 2  | 0.5  | 0  | 0  | $\displaystyle q_2$   |
| 3  | 0.5  | 0  | 0  | $\displaystyle q_3$   |


Per a aquest tutorial considera només els tres enllaços de barra. 


Pots calcular-ne la inèrcia de la manera següent: 


![image_1.png](Exercise-4-1_media/image_1.png)

 $$ I_{\textrm{xx}} =\frac{1}{12}\cdot \;m\cdot \left(w^2 +h^2 \right) $$ 

 $$ I_{\textrm{yy}} =I =\frac{1}{12}\cdot \;m\cdot \left(w^2 +h^2 \right) $$ 

 $$ I_{\textrm{zz}} =\frac{1}{12}\cdot \;m\cdot \left(w^2 +L^2 \right) $$ 
# Tasca 1: Configuració

Calcula les inèrcies dels enllaços al seu centre de massa i desa-les a les variables: 

-  I1 
-  I2 
-  I3 

Configura un array simbòlic q que contingui les variables simbòliques **reals** següents per als angles articulars

-  q1 
-  q2 
-  q3 

Configura un array simbòlic qd que contingui les variables simbòliques **reals** següents per a les velocitats articulars

-  qd1 
-  qd2 
-  qd3 
```matlab

I1 = [];
I2 = []; 
I3 = []; 
q  = []; 
qd = []; 

```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('4-1-1')
```
# Tasca 2: Configura el robot 

Carrega el fitxer urdf per al manipulador de tres enllaços fent servir

-  importrobot("threelink\_noInertia.urdf") 

Desa’l a la variable

-  threelink 
-  Defineix la gravetat com $\left\lbrack \begin{array}{c} 0\newline 0\newline -9\ldotp 81 \end{array}\right\rbrack$ 
-  Defineix les inèrcies en el marc correcte 
-  Defineix el centre de massa de cada cos 

*pista: recorda fer servir el desplaçament d’eixos paral·lels*

```matlab
threelink = []; 

```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('4-1-2')
```
# Tasca 3: Matriu d’inèrcia

Construeix la matriu d’inèrcia per al manipulador de tres enllaços fent servir el toolbox simbòlic. 


Desa la matriu a la variable

-  B (B ha de dependre de q1, q2, q3) 
```matlab
B = 0;
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('4-1-3')
```
# Tasca 3: Matriu de Coriolis 

Construeix la matriu de Coriolis per al manipulador de tres enllaços fent servir el toolbox simbòlic. 


Desa la matriu a la variable

-  C (C ha de dependre de q1, q2, q3, qd1, qd2, qd3) 
```matlab
C = 0; 
```

*pista: en cas que verifiquis la teva matriu tu mateix, recorda que la funció del toolbox velocityProduct retorna C\*qd*


Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('4-1-4')
```
# Tasca 5: Compensació de gravetat 

Construeix el terme de compensació de gravetat per al manipulador de tres enllaços fent servir el toolbox simbòlic. 


Desa la matriu a la variable

-  G (G ha de dependre de q1, q2, q3) 
```matlab
G = 0; 
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('4-1-5')

```