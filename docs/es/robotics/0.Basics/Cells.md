clear all;

# Arrays de celdas en MATLAB

En este tutorial explicaremos qué son los arrays de celdas de MATLAB y cómo trabajar con ellos.


Activa "Output inline" en el lado derecho de tu barra de desplazamiento.


![image_0.png](Cells_media/image_0.png)

# Crear un array de celdas

Un array de celdas es un tipo de dato que puede contener diferentes tipos o tamaños de datos en cada celda.


Usa llaves { } para definir celdas, separando las entradas con comas o espacios, y las filas con punto y coma.


 Define un array de celdas de 1×3

```matlab
C = {'text', 42, [1,2,3]}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|42|[1,2,3]|



Define un array de celdas de 2×2

```matlab
C2 = { 'pi',    pi; ...
    'matrix', [1 2;3 4] }
```


| |1|2|
|:--:|:--:|:--:|
|1|'pi'|3.1416|
|2|'matrix'|[1,2;3,4]|


# Acceder a elementos de celdas

Usa paréntesis ( ) para extraer una celda (devuelve una celda), y llaves { } para extraer su contenido.


Extrae una celda de 1×1

```matlab
cell1 = C(2)
```

```matlabTextOutput
cell1 = 1x1 cell array
    {[42]}

```


Extrae el contenido (numérico 42)

```matlab
value42 = C{2}
```

```matlabTextOutput
value42 = 42
```


Accede a parte de la matriz dentro de la celda


```matlab
subval = C2{2,2}(1,2)
```

```matlabTextOutput
subval = 2
```

# Modificar elementos de celdas

Asigna dentro de las celdas con llaves { } para sobrescribir el contenido, o con paréntesis ( ) para sobrescribir la propia celda.


Cambia el contenido de la segunda celda a una cadena

```matlab
C{2} = 'answer'
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,2,3]|



Sustituye la celda completa por otra celda

```matlab
C(3) = {ones(3)}
```


| |1|2|3|
|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|



Añade una celda nueva al final

```matlab
C{4} = @sin
```


| |1|2|3|4|
|:--:|:--:|:--:|:--:|:--:|
|1|'text'|'answer'|[1,1,1;1,1,1;1,1,1]|@sin|


# Arrays de celdas anidados

Las celdas pueden contener otros arrays de celdas para un almacenamiento jerárquico.


Crea una celda anidada

```matlab
Cnested = { 'level1', { 'level2', { 100, 200 } } }
```


| |1|2|
|:--:|:--:|:--:|
|1|'level1'|1x2 cell|



Accede al valor profundamente anidado 200

```matlab
deep200 = Cnested{2}{2}{2}
```

```matlabTextOutput
deep200 = 200
```

# Conversión

Puedes convertir entre arrays numéricos y celdas cuando las dimensiones coinciden.


Array numérico

```matlab
A = [10, 20;
     30, 40]
```

```matlabTextOutput
A = 2x2
    10    20
    30    40

```


 Convertir a array de celdas

```matlab
Acell = num2cell(A)
```


| |1|2|
|:--:|:--:|:--:|
|1|10|20|
|2|30|40|



Convertir de nuevo a numérico (si todas las celdas contienen escalares)

```matlab
Anum = cell2mat(Acell)
```

```matlabTextOutput
Anum = 2x2
    10    20
    30    40

```