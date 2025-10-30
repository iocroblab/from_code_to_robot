
```matlab
clear all; 
```
# <span style="color:rgb(213,80,0)">Symbolic Math Toolbox</span>

This tutorial will utilize the symbolic math toolbox. This short tutorial will explain some of the basic functionalities that will be used in future tutorials.


The Symbolic Math Toolbox is a powerful tool for calculations, as it lets us use variables instead of numbers. This can be useful to reuse complex matrices or equations and substitute values when needed. 


Please enable "Output inline" on the right side of your scroll bar. 


 <img src="Symbolic_Math_toolbox_media/image_0.png" width="22" alt="image_0.png">

# Create a Symbolic Variable 

to create a symbolic variable you can use the syms command followed by your desired variables. 

```matlab
syms var
```

If you only work with real numbers, as will be the case for this tutorial, extend the syms with a real to reduce symbolic computations for imaginary numbers. 

```matlab
syms var real
```

You can create multiple variables at once, if you extend it with a number, it will be shown as an indices on display

```matlab
syms var1 var2 var3 real real
MyVars = [var1 var2 var3]
```
MyVars = 
 $\displaystyle \left(\begin{array}{ccc} {\textrm{var}}_1  & {\textrm{var}}_2  & {\textrm{var}}_3  \end{array}\right)$
 

When spelling out greek letters as variables, they be converted into their symbols on display: 

```matlab
syms alpha beta gamma Delta delta 
MyVars = [alpha, beta, gamma, Delta, delta]
```
MyVars = 
 $\displaystyle \left(\begin{array}{ccccc} \alpha  & \beta  & \gamma  & \Delta  & \delta  \end{array}\right)$
 
# Substituting variables

using the subs() function we can substitute symbolic variables for values, making it easy to reuse e.g. equations :

```matlab
syms alpha beta x y z real 
Equation1 = x^2 ;
Equation2 = 2 * x + y;
Value1 = subs(Equation1, x, 3)
```
Value1 = 
 $\displaystyle 9$
 

```matlab
Value2 = subs(Equation2, [x, y], [3, 1])
```
Value2 = 
 $\displaystyle 7$
 

We can combine functions like: 

```matlab
Equation3 = Equation1 + Equation2
```
Equation3 = 
 $\displaystyle x^2 +2\,x+y$
 

```matlab
Equation4 = Equation1 * Equation2
```
Equation4 = 
 $\displaystyle x^2 \,{\left(2\,x+y\right)}$
 

```matlab
Equation5 = subs(Equation4, [x, y], [alpha, beta])
```
Equation5 = 
 $\displaystyle \alpha^2 \,{\left(2\,\alpha +\beta \right)}$
 

You can also substitute vectors for variables resulting in a vector output where each row relates to the corresponding input row. 

```matlab
timevec= linspace(0,10,5)' %this creates an equally spaced row vector from 0 to 10 in 5 steps. 
```

```matlabTextOutput
timevec = 5x1
         0
    2.5000
    5.0000
    7.5000
   10.0000

```

```matlab
EquationVector = subs(Equation4,x,timevec)
```
EquationVector = 
 $\displaystyle \left(\begin{array}{c} 0\newline \frac{25\,y}{4}+\frac{125}{4}\newline 25\,y+250\newline \frac{225\,y}{4}+\frac{3375}{4}\newline 100\,y+2000 \end{array}\right)$
 
# Converting symbolic variables

Sometimes you get error messages when attempting to combining numerical and symbolic variables. Avoid this by converting one of them:


After substituting the Workspace variable is still considered a symbolic variable. Even if your new variable only contains numbers, MATLAB will consider them a symbolic variable, which may lead to difficulties. You can convert it to a numeric by: 

```matlab
ValueDouble = double(Value2)
```

```matlabTextOutput
ValueDouble = 7
```

If you try to insert symbolic variables into numeric variables you need to convert the numeric matrix into a symbolic matrix: 

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
Matrix_symb = [alpha, beta; 
               gamma, delta]
```
Matrix_symb = 
 $\displaystyle \left(\begin{array}{cc} \alpha  & \beta \newline \gamma  & \delta  \end{array}\right)$
 

```matlab
Matrix_combined = sym(Matrix_1)
```
Matrix_combined = 
 $\displaystyle \left(\begin{array}{ccc} 1 & 1 & 1\newline 1 & 1 & 1\newline 1 & 1 & 1 \end{array}\right)$
 

```matlab
Matrix_combined(1:2,1:2) = Matrix_symb
```
Matrix_combined = 
 $\displaystyle \left(\begin{array}{ccc} \alpha  & \beta  & 1\newline \gamma  & \delta  & 1\newline 1 & 1 & 1 \end{array}\right)$
 
# Working with Symbolic Variables 

The Symbolic Math Toolbox gives us some powerful tools when doing calculus. 

## Differentiating with Symbolic Variables 

We can differentiate an expression like: 

```matlab
Equation = x^2 + x * y^2 + y^3 + 5
```
Equation = 
 $\displaystyle x^2 +x\,y^2 +y^3 +5$
 

```matlab
diff_Eq1 = diff(Equation, x)
```
diff_Eq1 = 
 $\displaystyle y^2 +2\,x$
 

You can also differentiate w.r.t. multiple variables at once: 

```matlab
diff_Eq2 = diff(Equation, x, y)
```
diff_Eq2 = 
 $\displaystyle 2\,y$
 

```matlab
diff_Eq3 = diff(Equation, x, x)
```
diff_Eq3 = 
 $\displaystyle 2$
 

```matlab
diff_Eq4 = diff(Equation, y, y)
```
diff_Eq4 = 
 $\displaystyle 2\,x+6\,y$
 

This can also be used in a matrix, where each element 

```matlab
MatrixEquation = [x^2,      x*y,       x*y*z; 
                  x*y,      y^2,       y*z  ; 
                  x*y*z,    y*z,       z^2  ]
```
MatrixEquation = 
 $\displaystyle \left(\begin{array}{ccc} x^2  & x\,y & x\,y\,z\newline x\,y & y^2  & y\,z\newline x\,y\,z & y\,z & z^2  \end{array}\right)$
 

```matlab
diff_Matrix1 = diff(MatrixEquation, x)
```
diff_Matrix1 = 
 $\displaystyle \left(\begin{array}{ccc} 2\,x & y & y\,z\newline y & 0 & 0\newline y\,z & 0 & 0 \end{array}\right)$
 

```matlab
diff_Matrix2 = diff(MatrixEquation, x,y)
```
diff_Matrix2 = 
 $\displaystyle \left(\begin{array}{ccc} 0 & 1 & z\newline 1 & 0 & 0\newline z & 0 & 0 \end{array}\right)$
 

```matlab
diff_Matrix3 = diff(MatrixEquation, x,y,z)
```
diff_Matrix3 = 
 $\displaystyle \left(\begin{array}{ccc} 0 & 0 & 1\newline 0 & 0 & 0\newline 1 & 0 & 0 \end{array}\right)$
 
## Rewriting Equations

We can rewrite expressions using the symbolic toolbox: 

```matlab
Eq = (x + 1) * (x + y)
```
Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 

The collect() function will return an equation where all expressions are pooled based on the desired variable and its identical powers 

```matlab
Eq_collect_x = collect(Eq, x)
```
Eq_collect_x = 
 $\displaystyle x^2 +{\left(y+1\right)}\,x+y$
 

The simplify() function lets us factorize an expression and applying cancellation rules

```matlab
Simple_Eq = simplify(Eq_collect_x)
```
Simple_Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 
## Solving Equations

The symbolic toolbox also allows us to solve for variables: 

```matlab
syms a b real
Eq1 = a * 5 + b == 0
```
Eq1 = 
 $\displaystyle 5\,a+b=0$
 

```matlab
Eq2 = a * 15 + b == 4
```
Eq2 = 
 $\displaystyle 15\,a+b=4$
 

```matlab
solutions = solve([Eq1, Eq2], [a, b])
```

```matlabTextOutput
solutions = struct with fields:
    a: 2/5
    b: -2

```

We can also let it solve for a variable that depends on others: 

```matlab
parameter_solution_a = solve(Eq1, a)
```
parameter_solution_a = 
 $\displaystyle -\frac{b}{5}$
 
