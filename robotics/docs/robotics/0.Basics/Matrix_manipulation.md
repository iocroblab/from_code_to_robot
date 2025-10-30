
```matlab
clear all; 
```
# <span style="color:rgb(213,80,0)">Basic Matrix manipulation</span>

In this tutorial we will explain some of the basics of working with matrices in matlab. 


Please enable "Output inline" on the right side of your scroll bar. 


 <img src="Matrix_manipulation_media/image_0.png" width="22" alt="image_0.png">

# Create a Matrix
-  Create a matrix structure by using square brackets \[ \] 
-  Separate columns by a space or comma ,  
-  Separate rows by semicolon ; 
```matlab
syms m11 m12 m13 m21 m22 m23 m31 m32 m33 real
M = [m11, m12, m13 ; %row separated by semicolon
     m21, m22, m23 ; %column separated by comma
     m31  m32  m33] %column separated by space
```
M = 
 $\displaystyle \left(\begin{array}{ccc} m_{11}  & m_{12}  & m_{13} \newline m_{21}  & m_{22}  & m_{23} \newline m_{31}  & m_{32}  & m_{33}  \end{array}\right)$
 

The functions eye() lets you create an identity matrix: 

```matlab
IdentityMatrix = eye(3)
```

```matlabTextOutput
IdentityMatrix = 3x3
     1     0     0
     0     1     0
     0     0     1

```

To create a matrix of zeros or ones you can use the functions below. You can define the dimensions as (row,column):

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
# Transpose a Matrix

Transpose a matrix by extending it with an apostrophe '

```matlab
M_transposed = M'
```
M_transposed = 
 $\displaystyle \left(\begin{array}{ccc} m_{11}  & m_{21}  & m_{31} \newline m_{12}  & m_{22}  & m_{32} \newline m_{13}  & m_{23}  & m_{33}  \end{array}\right)$
 

This can also be used to transform a row vector in a column vector. This can be done with a variable or with the array itself. 

```matlab
syms v1 v2 v3 real
V_column = [v1, v2, v3]
```
V_column = 
 $\displaystyle \left(\begin{array}{ccc} v_1  & v_2  & v_3  \end{array}\right)$
 

```matlab
V_row = [v1, v2, v3]'
```
V_row = 
 $\displaystyle \left(\begin{array}{c} v_1 \newline v_2 \newline v_3  \end{array}\right)$
 

```matlab
V_row_2 = V_column'
```
V_row_2 = 
 $\displaystyle \left(\begin{array}{c} v_1 \newline v_2 \newline v_3  \end{array}\right)$
 
# Invert a Matrix

To invert a matrix we have a few options such as:

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
## Invert a non square Matrix 

To invert a non square Matrix you can use the pseudo inverse:

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
# Access Matrix Elements 

To access a specific elements of a matrix you can include (row,column) as an extension of the variable: 

```matlab
M(1,1)
```
ans = 
 $\displaystyle m_{11} $
 

You can also access sections of your matrix if you define a region as (start\_row : end\_row, start\_column : end\_column)

```matlab
M(1:2,1:2)
```
ans = 
 $\displaystyle \left(\begin{array}{cc} m_{11}  & m_{12} \newline m_{21}  & m_{22}  \end{array}\right)$
 

With this Notation we can also write into specific elements of the matrix and override them:

```matlab
M(1:3, 3)=V_row
```
M = 
 $\displaystyle \left(\begin{array}{ccc} m_{11}  & m_{12}  & v_1 \newline m_{21}  & m_{22}  & v_2 \newline m_{31}  & m_{32}  & v_3  \end{array}\right)$
 

```matlab
M(1:2,1:2)=eye(2)
```
M = 
 $\displaystyle \left(\begin{array}{ccc} 1 & 0 & v_1 \newline 0 & 1 & v_2 \newline m_{31}  & m_{32}  & v_3  \end{array}\right)$
 
# Combining Matrices 

To combine two 2D matrices into one Matrix we can use the cat(Dimension, Matrix\_1, ..., Matrix\_n) function:

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
# Mathematical Operations with Matrices

To add two matrices of the same size: 

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

To subtract matrices of the same size: 

```matlab
Matrix_subtracted = Matrix_4 - Matrix_1
```

```matlabTextOutput
Matrix_subtracted = 3x3
     0     1     2
     0     1     2
     0     1     2

```

To multiply two matrices: 

```matlab
Matrix_multiply =  Matrix_2 * Matrix_4
```

```matlabTextOutput
Matrix_multiply = 3x3
     6    12    18
     6    12    18
     6    12    18

```

To have element\-wise operations like

 $$ \left\lbrack \begin{array}{cc} \textrm{m11} & \textrm{m12}\newline \textrm{m21} & \textrm{m22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11}\cdot \;\textrm{b11} & \textrm{a12}\cdot \textrm{b12}\newline \textrm{a21}\cdot \textrm{b21} & \textrm{a22}\cdot \textrm{b22} \end{array}\right\rbrack =\left\lbrack \begin{array}{cc} \textrm{a11} & \textrm{a12}\newline \textrm{a21} & \textrm{a22} \end{array}\right\rbrack \ldotp \times \left\lbrack \begin{array}{cc} \textrm{b11} & \textrm{b12}\newline \textrm{b21} & \textrm{b22} \end{array}\right\rbrack $$ 

we can add a . in front of the operator: 

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
# Other useful Functions 
### Dimensions

To get the dimensions of a Matrix you can use the size() function: 

```matlab
[rows, columns, dimensions] = size(Matrix_combined_4)
```

```matlabTextOutput
rows = 3
columns = 3
dimensions = 3
```

if you are only interested in some of the dimensions: 

```matlab
[rows, ~, ~] = size(Matrix_4)
```

```matlabTextOutput
rows = 3
```
### Summing of Matrix elements

You can sum matrix column elements by using the sum() function: 

```matlab
Matrix_column_sum = sum(Matrix_4)
```

```matlabTextOutput
Matrix_column_sum = 1x3
     3     6     9

```

you can add all the elements of a Matrix to each other by giving the option input "all":

```matlab
Matrix_total_sum = sum(Matrix_4,"all")
```

```matlabTextOutput
Matrix_total_sum = 18
```
### Maximum/Minimum

You can extract the maximum or minimum value of each column by using the max() or min() function 

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

To get the maximum or minimum of the entire matrix you can give the optional input \[\] and "all"

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
### Rank

Using the rank() function you can extract the rank of you matrix, which is defined as the number of linearly independent columns (or rows) in that matrix. The rank provides insight into the dimensionality of the column space of the matrix.


For an identity matrix the rank is the same as its rows/columns. The Identity matrix is "full rank". 

```matlab
IdentityRank = rank(eye(4))
```

```matlabTextOutput
IdentityRank = 4
```

However for the Matrix 4, which contains the same row multiple times the rank is only 1. 

```matlab
MatrixRank = rank(Matrix_4)
```

```matlabTextOutput
MatrixRank = 1
```
