```matlab
clear all; 
```
# Exercici 1.3 \- Trobar els paràmetres DH

En aquest exercici calcularàs els paràmetres DH d’un manipulador robòtic arbitrari, configuraràs les equacions utilitzant la toolbox simbòlica i definiràs el robot amb la Robotic System Toolbox. 


Guarda les teves solucions a les variables predefinides!

# Descripció de la tasca:

Troba els paràmetres DH i les transformacions homogènies per descriure el manipulador robòtic següent:


![image_0.svg](Exercise-1-3_media/image_0.svg)


Respon totes les preguntes i guarda la teva solució a la variable correcta.

# Tasca 1
1.  Defineix variables simbòliques reals per a cada articulació (q1, ..., qn)
2. Guarda-les en un array columna (q)
3. Defineix els límits de posició per a cadascuna de les articulacions; per a les articulacions rotacionals el límit és $\pm 2\pi \;$ (limit\_1, ..., limit\_n)

Utilitza les variables següents per guardar la teva solució:

-  qi (posició de l’articulació i) 
-  q (un array amb tots els estats simbòlics de les articulacions) 
-  limit\_i (array amb el valor mínim i màxim permès de l’articulació) 
```matlab
q=[];
limit_1=[];
```

Pots comprovar la feina fent clic a Run: 

```matlab
 
check_exercise('1-3-1')
```
# Tasca 2
1.  calcula els paràmetres DH, incloent-hi les articulacions simbòliques a la seva posició correcta.
2. Calcula la transformació homogènia entre la base i la primera articulació (TB0)
3. Calcula la transformació homogènia entre el sistema 3 i el sistema de l’eina (T4tool)

Pots utilitzar la funció dh2tf(DH) per obtenir la transformació homogènia a partir d’una fila de paràmetres DH. 


Utilitza les variables següents per guardar la teva solució:

-  DH (a , alpha, d, theta) 
-  TB0 (transformació homogènia de la base al sistema 0) 
-  T3tool 
```matlab
DH=[
   %a       alpha       d       theta

   ];
TB0 = [];
T3tool = []; 
```

Pots comprovar la feina fent clic a Run: 

```matlab
 
check_exercise('1-3-2')

```
# Tasca 3
1.  Configura el robot utilitzant la Robotic System Toolbox
2. Defineix el format de dades com a column

utilitza els noms següents:

-  body\_base (nom del cos per al desplaçament de la base) 
-  base\_link (nom de l’articulació per a body\_base) 
-  body\_1, ..., body\_n (cossos per a les articulacions) 
-  joint\_1, ..., joint\_n (articulacions del robot) 
-  tool (nom del cos de l’eina) 
-  tool\_link (nom de l’articulació per al cos de l’eina) 

Utilitza les variables següents per guardar la teva solució:

-  robot (nom del teu robot) 
-  bodies (cell array que conté tots els cossos) 
-  joints (cell array que conté totes les articulacions) 

Nota: 


per utilitzar els paràmetres DH que has configurat prèviament, els has de convertir a double. Utilitza la funció subs() per substituir les teves variables simbòliques per valors numèrics. Recorda que la toolbox ignorarà qualsevol element del camp controlat (per exemple, theta per a articulacions rotacionals)

```matlab
bodies = [];
joints = []; 
robot = [];
```

Pots comprovar la feina fent clic a Run: 

```matlab
 
check_exercise('1-3-3')
```
# Tasca 4
1.  Estableix la configuració inicial perquè el robot coincideixi amb la imatge (utilitza el límit inferior per a la primera articulació)
2. Estableix els límits de les articulacions


Pots comprovar la feina fent clic a Run: 

```matlab
 
check_exercise('1-3-4')
```