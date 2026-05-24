```matlab
clear all; 
```
# Manipulación básica de matrices

En este tutorial explicaremos algunos de los conceptos básicos para trabajar con matrices en MATLAB. 


Activa "Output inline" en el lado derecho de tu barra de desplazamiento. 


 ![image_0.png](Matrix_manipulation_media/image_0.png)

# Crear una matriz
-  Crea una estructura de matriz usando corchetes $begin:math:display$ $end:math:display$ 
-  Separa las columnas con un espacio o una coma ,  
-  Separa las filas con punto y coma ; 
```matlab
syms m11 m12 m13 m21 m22 m23 m31 m32 m33 real
M = [m11, m12, m13 ; %fila separada por punto y coma
     m21, m22, m23 ; %columna separada por coma
     m31  m32  m33] %columna separada por espacio
```
M = 

  $$ \displaystyle \left(\begin{array}{ccc} m_{11}  & m_{12}  & m_{13} \newline m_{21}  & m_{22}  & m_{23} \newline m_{31}  & m_{32}  & m_{33}  \end{array}\right) $$ 
 

La función eye() te permite crear una matriz identidad: 

```matlab
IdentityMatrix = eye(3)
```

```matlabTextOutput
IdentityMatrix = 3x3
     1     0     0
     0     1     0
     0     0     1

```


Para crear una matriz de ceros o unos puedes usar las funciones siguientes. Puedes definir las dimensiones como (fila,columna):

```matlab
OneMatrix = ones(2,4)
```

```matlabTextOutput
OneMatrix = 2x4
     1     1     1     1
     1     1     1     1

```

```matlab
ZeroMatrix = zeros(2,2)
```

```matlabTextOutput
ZeroMatrix = 2x2
     0     0
     0     0

```

# Transponer una matriz

Transpón una matriz añadiéndole un apóstrofo '

```matlab
M_transposed = M'
```
M_transposed = 

  $$ \displaystyle \left(\begin{array}{ccc} m_{11}  & m_{21}  & m_{31} \newline m_{12}  & m_{22}  & m_{32} \newline m_{13}  & m_{23}  & m_{33}  \end{array}\right) $$ 
 

Esto también puede usarse para transformar un vector fila en un vector columna. Puede hacerse con una variable o con el propio array. 

```matlab
syms v1 v2 v3 real
V_column = [v1, v2, v3]
```
V_column = 

  $$ \displaystyle \left(\begin{array}{ccc} v_1  & v_2  & v_3  \end{array}\right) $$ 
 

```matlab
V_row = [v1, v2, v3]'
```
V_row = 

  $$ \displaystyle \left(\begin{array}{c} v_1 \newline v_2 \newline v_3  \end{array}\right) $$ 
 

```matlab
V_row_2 = V_column'
```
V_row_2 = 

  $$ \displaystyle \left(\begin{array}{c} v_1 \newline v_2 \newline v_3  \end{array}\right) $$ 
 
# Invertir una matriz

Para invertir una matriz tenemos varias opciones, como:

```matlab
Sample_Matrix = [1, 2, 3;
                 4, 5, 6;
                 6, 2, 10]
```

```matlabTextOutput
Sample_Matrix = 3x3
     1     2     3
     4     5     6
     6     2    10

```

```matlab
Sample_Matrix_inv_1 = inv(Sample_Matrix)
```

```matlabTextOutput
Sample_Matrix_inv_1 = 3x3
   -1.0556    0.3889    0.0833
    0.1111    0.2222   -0.1667
    0.6111   -0.2778    0.0833

```

```matlab
Sample_Matrix_inv_2 = Sample_Matrix^-1 
```

```matlabTextOutput
Sample_Matrix_inv_2 = 3x3
   -1.0556    0.3889    0.0833
    0.1111    0.2222   -0.1667
    0.6111   -0.2778    0.0833

```

```matlab
Sample_Matrix_inv_3 = eye(3)/Sample_Matrix
```

```matlabTextOutput
Sample_Matrix_inv_3 = 3x3
   -1.0556    0.3889    0.0833
    0.1111    0.2222   -0.1667
    0.6111   -0.2778    0.0833

```

## Invertir una matriz no cuadrada 

Para invertir una matriz no cuadrada puedes usar la pseudoinversa:

 $$ A^{\dagger} ={\left(A^T \cdot A\right)}^{-1} \cdot A^T $$ 
```matlab
Sample_Matrix_non_square = Sample_Matrix(1:3,1:2)
```

```matlabTextOutput
Sample_Matrix_non_square = 3x2
     1     2
     4     5
     6     2

```

```matlab
Sample_Matrix_non_square_inverse_1 = inv(Sample_Matrix_non_square' * Sample_Matrix_non_square) * Sample_Matrix_non_square'
```

```matlabTextOutput
Sample_Matrix_non_square_inverse_1 = 2x3
   -0.0590   -0.0641    0.2192
    0.1214    0.2175   -0.1653

```

```matlab
Sample_Matrix_non_square_inverse_2 = pinv(Sample_Matrix_non_square)
```

```matlabTextOutput
Sample_Matrix_non_square_inverse_2 = 2x3
   -0.0590   -0.0641    0.2192
    0.1214    0.2175   -0.1653

```

# Acceder a elementos de una matriz 

Para acceder a elementos concretos de una matriz puedes incluir (fila,columna) como una extensión de la variable: 

```matlab
M(1,1)
```
ans = 
 $\displaystyle m_{11} $
 

También puedes acceder a secciones de tu matriz si defines una región como (fila\_inicial : fila\_final, columna\_inicial : columna\_final)

```matlab
M(1:2,1:2)
```
ans = 

  $$ \displaystyle \left(\begin{array}{cc} m_{11}  & m_{12} \newline m_{21}  & m_{22}  \end{array}\right) $$ 
 

Con esta notación también podemos escribir en elementos concretos de la matriz y sobrescribirlos:

```matlab
M(1:3, 3)=V_row
```
M = 

  $$ \displaystyle \left(\begin{array}{ccc} m_{11}  & m_{12}  & v_1 \newline m_{21}  & m_{22}  & v_2 \newline m_{31}  & m_{32}  & v_3  \end{array}\right) $$ 
 

```matlab
M(1:2,1:2)=eye(2)
```
M = 

  $$ \displaystyle \left(\begin{array}{ccc} 1 & 0 & v_1 \newline 0 & 1 & v_2 \newline m_{31}  & m_{32}  & v_3  \end{array}\right) $$ 
 
# Combinar matrices 

Para combinar dos matrices 2D en una sola matriz podemos usar la función cat(Dimensión, Matriz\_1, ..., Matriz\_n):

```matlab
Matrix_1 = ones(3)
```

```matlabTextOutput
Matrix_1 = 3x3
     1     1     1
     1     1     1
     1     1     1

```

```matlab
Matrix_2 = ones(3) * 2
```

```matlabTextOutput
Matrix_2 = 3x3
     2     2     2
     2     2     2
     2     2     2

```

```matlab
Matrix_combined_1 = cat(1, Matrix_1, Matrix_2)
```

```matlabTextOutput
Matrix_combined_1 = 6x3
     1     1     1
     1     1     1
     1     1     1
     2     2     2
     2     2     2
     2     2     2

```

```matlab
Matrix_combined_2 = cat(2, Matrix_1, Matrix_2)
```

```matlabTextOutput
Matrix_combined_2 = 3x6
     1     1     1     2     2     2
     1     1     1     2     2     2
     1     1     1     2     2     2

```

```matlab
Matrix_combined_3 = cat(3, Matrix_1, Matrix_2)
```

```matlabTextOutput
Matrix_combined_3 = 
Matrix_combined_3(:,:,1) =

     1     1     1
     1     1     1
     1     1     1

Matrix_combined_3(:,:,2) =

     2     2     2
     2     2     2
     2     2     2

```

```matlab
Matrix_3 = ones(3) * 3;
Matrix_combined_4 = cat(3, Matrix_1, Matrix_2, Matrix_3)
```

```matlabTextOutput
Matrix_combined_4 = 
Matrix_combined_4(:,:,1) =

     1     1     1
     1     1     1
     1     1     1

Matrix_combined_4(:,:,2) =

     2     2     2
     2     2     2
     2     2     2

Matrix_combined_4(:,:,3) =

     3     3     3
     3     3     3
     3     3     3

```

# Operaciones matemáticas con matrices

Para sumar dos matrices del mismo tamaño: 

```matlab
Matrix_4 = [1, 2, 3;
            1, 2, 3;
            1, 2, 3]
```

```matlabTextOutput
Matrix_4 = 3x3
     1     2     3
     1     2     3
     1     2     3

```

```matlab
Matrix_added = Matrix_1 + Matrix_4
```

```matlabTextOutput
Matrix_added = 3x3
     2     3     4
     2     3     4
     2     3     4

```


Para restar matrices del mismo tamaño: 

```matlab
Matrix_subtracted = Matrix_4 - Matrix_1
```

```matlabTextOutput
Matrix_subtracted = 3x3
     0     1     2
     0     1     2
     0     1     2

```


Para multiplicar dos matrices: 

```matlab
Matrix_multiply =  Matrix_2 * Matrix_4
```

```matlabTextOutput
Matrix_multiply = 3x3
     6    12    18
     6    12    18
     6    12    18

```


Para realizar operaciones elemento a elemento como

 $$ \left\lbrack \begin{array}{cc} \textrm{m11} & \textrm{m12}\newline \textrm{m21} & \textrm{m22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11}\cdot \;\textrm{b11} & \textrm{a12}\cdot \textrm{b12}\newline \textrm{a21}\cdot \textrm{b21} & \textrm{a22}\cdot \textrm{b22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11} & \textrm{a12}\newline \textrm{a21} & \textrm{a22} \end{array}\right\rbrack \ldotp \times \left\lbrack \begin{array}{cc} \textrm{b11} & \textrm{b12}\newline \textrm{b21} & \textrm{b22} \end{array}\right\rbrack $$ 

podemos añadir un . delante del operador: 

```matlab
Matrix_element_multiply =  Matrix_2 .* Matrix_4
```

```matlabTextOutput
Matrix_element_multiply = 3x3
     2     4     6
     2     4     6
     2     4     6

```

```matlab
Matrix_element_devision = Matrix_4 ./ Matrix_2
```

```matlabTextOutput
Matrix_element_devision = 3x3
    0.5000    1.0000    1.5000
    0.5000    1.0000    1.5000
    0.5000    1.0000    1.5000

```

```matlab
Matrix_element_squared = Matrix_4.^2
```

```matlabTextOutput
Matrix_element_squared = 3x3
     1     4     9
     1     4     9
     1     4     9

```

# Otras funciones útiles 
### Dimensiones

Para obtener las dimensiones de una matriz puedes usar la función size(): 

```matlab
[rows, columns, dimensions] = size(Matrix_combined_4)
```

```matlabTextOutput
rows = 3
columns = 3
dimensions = 3
```


si solo te interesan algunas de las dimensiones: 

```matlab
[rows, ~, ~] = size(Matrix_4)
```

```matlabTextOutput
rows = 3
```

### Suma de elementos de una matriz

Puedes sumar los elementos de las columnas de una matriz usando la función sum(): 

```matlab
Matrix_column_sum = sum(Matrix_4)
```

```matlabTextOutput
Matrix_column_sum = 1x3
     3     6     9

```


puedes sumar entre sí todos los elementos de una matriz proporcionando la opción de entrada "all":

```matlab
Matrix_total_sum = sum(Matrix_4,"all")
```

```matlabTextOutput
Matrix_total_sum = 18
```

### Máximo/Mínimo

Puedes extraer el valor máximo o mínimo de cada columna usando la función max() o min() 

```matlab
Max_column = max(Matrix_4)
```

```matlabTextOutput
Max_column = 1x3
     1     2     3

```

```matlab
Min_column = min(Matrix_4);
```

Para obtener el máximo o mínimo de toda la matriz puedes proporcionar la entrada opcional $begin:math:display$$end:math:display$ y "all"

```matlab
MaxAll = max(Matrix_4, [], "all")
```

```matlabTextOutput
MaxAll = 3
```

```matlab
MinAll = min(Matrix_4, [], "all")
```

```matlabTextOutput
MinAll = 1
```

### Rango

Usando la función rank() puedes extraer el rango de tu matriz, que se define como el número de columnas (o filas) linealmente independientes en esa matriz. El rango proporciona información sobre la dimensionalidad del espacio de columnas de la matriz.


Para una matriz identidad, el rango es igual a su número de filas/columnas. La matriz identidad es de "rango completo". 

```matlab
IdentityRank = rank(eye(4))
```

```matlabTextOutput
IdentityRank = 4
```


Sin embargo, para la Matriz 4, que contiene la misma fila varias veces, el rango es solo 1. 

```matlab
MatrixRank = rank(Matrix_4)
```

```matlabTextOutput
MatrixRank = 1
```