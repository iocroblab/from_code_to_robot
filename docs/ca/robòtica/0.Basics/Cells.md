clear all;

# Cell Arrays a MATLAB

En aquest tutorial explicarem què són els cell arrays de MATLAB i com treballar-hi.


Activeu "Output inline" a la dreta de la barra de desplaçament.


![image_0.png](Cells_media/image_0.png)

# Crear un Cell Array

Un cell array és un tipus de dada que pot contenir diferents tipus o mides de dades a cada cel·la.


Utilitza claus { } per definir les cel·les, separant les entrades amb comes o espais, i les files amb punts i coma.


 Defineix un cell array 1×3

```matlab
C = {'text', 42, [1,2,3]}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|42|[1,2,3]|



Defineix un cell array 2×2

```matlab
C2 = { 'pi',    pi; ...
    'matrix', [1 2;3 4] }
```


| |1|2|
|:--:|:--:|:--:|
|1|'pi'|3.1416|
|2|'matrix'|[1,2;3,4]|


# Accedir als elements d’un Cell Array

Utilitza parèntesis ( ) per extreure una cel·la (retorna una cel·la), i claus { } per extreure’n el contingut.


Extreu una cel·la 1×1

```matlab
cell1 = C(2)
```

```matlabTextOutput
cell1 = 1x1 cell array
    {[42]}

```


Extreu el contingut (numèric 42)

```matlab
value42 = C{2}
```

```matlabTextOutput
value42 = 42
```


Accedeix a una part de la matriu dins la cel·la


```matlab
subval = C2{2,2}(1,2)
```

```matlabTextOutput
subval = 2
```

# Modificar elements d’un Cell Array

Assigna dins les cel·les amb claus { } per sobreescriure’n el contingut, o amb parèntesis ( ) per sobreescriure la cel·la sencera.


Canvia el contingut de la segona cel·la a un string

```matlab
C{2} = 'answer'
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,2,3]|



Substitueix la cel·la sencera per una altra cel·la

```matlab
C(3) = {ones(3)}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|



Afegeix una cel·la nova al final

```matlab
C{4} = @sin
```


| |1|2|3|4|
|:--:|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|@sin|


# Cell Arrays imbricats

Les cel·les poden contenir altres cell arrays per a emmagatzematge jeràrquic.


Crea una cel·la imbricada

```matlab
Cnested = { 'level1', { 'level2', { 100, 200 } } }
```


| |1|2|
|:--:|:--:|:--:|
|1|'level1'|1x2 cell|



Accedeix al valor imbricat 200

```matlab
deep200 = Cnested{2}{2}{2}
```

```matlabTextOutput
deep200 = 200
```

# Conversió

Pots convertir entre arrays numèrics i cel·les quan les dimensions coincideixen.


Array numèric

```matlab
A = [10, 20;
     30, 40]
```

```matlabTextOutput
A = 2x2
    10    20
    30    40

```


 Converteix a cell array

```matlab
Acell = num2cell(A)
```


| |1|2|
|:--:|:--:|:--:|
|1|10|20|
|2|30|40|



Converteix de nou a numèric (si totes les cel·les contenen escalars)

```matlab
Anum = cell2mat(Acell)
```

```matlabTextOutput
Anum = 2x2
    10    20
    30    40

```