```matlab
clear all; 
```
# Manipulació bàsica de matrius

En aquest tutorial explicarem alguns dels conceptes bàsics per treballar amb matrius a MATLAB. 


Activeu "Output inline" a la dreta de la barra de desplaçament. 


 ![image_0.png](Matrix_manipulation_media/image_0.png)

# Crear una matriu
-  Crea una estructura de matriu utilitzant claudàtors $begin:math:display$ $end:math:display$ 
-  Separa les columnes amb un espai o una coma ,  
-  Separa les files amb un punt i coma ; 
```matlab
syms m11 m12 m13 m21 m22 m23 m31 m32 m33 real
M = [m11, m12, m13 ; %row separated by semicolon
     m21, m22, m23 ; %column separated by comma
     m31  m32  m33] %column separated by space
```
M = 

  $$ \displaystyle \left(\begin{array}{ccc} m_{11}  & m_{12}  & m_{13} \newline m_{21}  & m_{22}  & m_{23} \newline m_{31}  & m_{32}  & m_{33}  \end{array}\right) $$ 
 

La funció eye() et permet crear una matriu identitat: 

```matlab
IdentityMatrix = eye(3)
```

```matlabTextOutput
IdentityMatrix = 3x3
     1     0     0
     0     1     0
     0     0     1

```


Per crear una matriu de zeros o uns, pots utilitzar les funcions següents. Pots definir les dimensions com (fila,columna):

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

# Transposar una matriu

Transposa una matriu afegint-hi un apòstrof '

```matlab
M_transposed = M'
```
M_transposed = 

  $$ \displaystyle \left(\begin{array}{ccc} m_{11}  & m_{21}  & m_{31} \newline m_{12}  & m_{22}  & m_{32} \newline m_{13}  & m_{23}  & m_{33}  \end{array}\right) $$ 
 

Això també es pot utilitzar per transformar un vector fila en un vector columna. Es pot fer amb una variable o amb l’array mateix. 

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
 
# Invertir una matriu

Per invertir una matriu tenim diverses opcions, com ara:

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

## Invertir una matriu no quadrada 

Per invertir una matriu no quadrada pots utilitzar la pseudoinversa:

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

# Accedir als elements d’una matriu 

Per accedir a un element específic d’una matriu, pots incloure (fila,columna) com a extensió de la variable: 

```matlab
M(1,1)
```
ans = 
 $\displaystyle m_{11} $
 

També pots accedir a seccions de la matriu si defineixes una regió com (fila\_inicial : fila\_final, columna\_inicial : columna\_final)

```matlab
M(1:2,1:2)
```
ans = 

  $$ \displaystyle \left(\begin{array}{cc} m_{11}  & m_{12} \newline m_{21}  & m_{22}  \end{array}\right) $$ 
 

Amb aquesta notació també podem escriure en elements específics de la matriu i sobreescriure’ls:

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
 
# Combinar matrius 

Per combinar dues matrius 2D en una sola matriu, podem utilitzar la funció cat(Dimensió, Matriu\_1, ..., Matriu\_n):

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

# Operacions matemàtiques amb matrius

Per sumar dues matrius de la mateixa mida: 

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


Per restar matrius de la mateixa mida: 

```matlab
Matrix_subtracted = Matrix_4 - Matrix_1
```

```matlabTextOutput
Matrix_subtracted = 3x3
     0     1     2
     0     1     2
     0     1     2

```


Per multiplicar dues matrius: 

```matlab
Matrix_multiply =  Matrix_2 * Matrix_4
```

```matlabTextOutput
Matrix_multiply = 3x3
     6    12    18
     6    12    18
     6    12    18

```


Per tenir operacions element a element com

 $$ \left\lbrack \begin{array}{cc} \textrm{m11} & \textrm{m12}\newline \textrm{m21} & \textrm{m22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11}\cdot \;\textrm{b11} & \textrm{a12}\cdot \textrm{b12}\newline \textrm{a21}\cdot \textrm{b21} & \textrm{a22}\cdot \textrm{b22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11} & \textrm{a12}\newline \textrm{a21} & \textrm{a22} \end{array}\right\rbrack \ldotp \times \left\lbrack \begin{array}{cc} \textrm{b11} & \textrm{b12}\newline \textrm{b21} & \textrm{b22} \end{array}\right\rbrack $$ 

podem afegir un . davant de l’operador: 

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

# Altres funcions útils 
### Dimensions

Per obtenir les dimensions d’una matriu pots utilitzar la funció size(): 

```matlab
[rows, columns, dimensions] = size(Matrix_combined_4)
```

```matlabTextOutput
rows = 3
columns = 3
dimensions = 3
```


si només t’interessen algunes de les dimensions: 

```matlab
[rows, ~, ~] = size(Matrix_4)
```

```matlabTextOutput
rows = 3
```

### Suma d’elements d’una matriu

Pots sumar els elements de les columnes d’una matriu utilitzant la funció sum(): 

```matlab
Matrix_column_sum = sum(Matrix_4)
```

```matlabTextOutput
Matrix_column_sum = 1x3
     3     6     9

```


pots sumar tots els elements d’una matriu entre ells donant l’input opcional "all":

```matlab
Matrix_total_sum = sum(Matrix_4,"all")
```

```matlabTextOutput
Matrix_total_sum = 18
```

### Màxim/Mínim

Pots extreure el valor màxim o mínim de cada columna utilitzant la funció max() o min() 

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

Per obtenir el màxim o el mínim de tota la matriu, pots donar l’input opcional $begin:math:display$$end:math:display$ i "all"

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

### Rang

Utilitzant la funció rank() pots extreure el rang de la teva matriu, que es defineix com el nombre de columnes (o files) linealment independents en aquella matriu. El rang proporciona informació sobre la dimensionalitat de l’espai de columnes de la matriu.


Per a una matriu identitat, el rang és el mateix que el nombre de files/columnes. La matriu identitat és de "rang complet". 

```matlab
IdentityRank = rank(eye(4))
```

```matlabTextOutput
IdentityRank = 4
```


Tanmateix, per a la Matriu 4, que conté la mateixa fila diverses vegades, el rang és només 1. 

```matlab
MatrixRank = rank(Matrix_4)
```

```matlabTextOutput
MatrixRank = 1
```