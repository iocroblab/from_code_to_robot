```matlab
clear all; 
```
# Symbolic Math Toolbox

Este tutorial utilizará Symbolic Math Toolbox. Este breve tutorial explicará algunas de las funcionalidades básicas que se usarán en futuros tutoriales.


Symbolic Math Toolbox es una herramienta potente para cálculos, ya que nos permite usar variables en lugar de números. Esto puede ser útil para reutilizar matrices o ecuaciones complejas y sustituir valores cuando sea necesario. 


Activa "Output inline" en el lado derecho de tu barra de desplazamiento. 


 ![image_0.png](Symbolic_Math_toolbox_media/image_0.png)

# Crear una variable simbólica 

Para crear una variable simbólica puedes usar el comando syms seguido de las variables deseadas. 

```matlab
syms var
```

Si solo trabajas con números reales, como será el caso en este tutorial, amplía syms con real para reducir los cálculos simbólicos con números imaginarios. 

```matlab
syms var real
```

Puedes crear varias variables a la vez; si la amplías con un número, se mostrará como índices en la visualización

```matlab
syms var1 var2 var3 real real
MyVars = [var1 var2 var3]
```
MyVars = 

  $$ \displaystyle \left(\begin{array}{ccc} {\textrm{var}}_1  & {\textrm{var}}_2  & {\textrm{var}}_3  \end{array}\right) $$ 
 

Cuando escribes letras griegas como variables, se convertirán en sus símbolos en la visualización: 

```matlab
syms alpha beta gamma Delta delta 
MyVars = [alpha, beta, gamma, Delta, delta]
```
MyVars = 

  $$ \displaystyle \left(\begin{array}{ccccc} \alpha  & \beta  & \gamma  & \Delta  & \delta  \end{array}\right) $$ 
 
# Sustituir variables

Usando la función subs() podemos sustituir variables simbólicas por valores, lo que facilita reutilizar, por ejemplo, ecuaciones:

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
 

Podemos combinar funciones como: 

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
 

También puedes sustituir vectores por variables, lo que da como resultado una salida vectorial donde cada fila corresponde a la fila de entrada correspondiente. 

```matlab
timevec= linspace(0,10,5)' %esto crea un vector columna igualmente espaciado de 0 a 10 en 5 pasos. 
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

  $$ \displaystyle \left(\begin{array}{c} 0\newline \frac{25\,y}{4}+\frac{125}{4}\newline 25\,y+250\newline \frac{225\,y}{4}+\frac{3375}{4}\newline 100\,y+2000 \end{array}\right) $$ 
 
# Convertir variables simbólicas

A veces aparecen mensajes de error al intentar combinar variables numéricas y simbólicas. Evítalo convirtiendo una de ellas:


Después de sustituir, la variable del Workspace sigue considerándose una variable simbólica. Aunque tu nueva variable solo contenga números, MATLAB la considerará una variable simbólica, lo que puede causar dificultades. Puedes convertirla a numérica con: 

```matlab
ValueDouble = double(Value2)
```

```matlabTextOutput
ValueDouble = 7
```


Si intentas insertar variables simbólicas en variables numéricas, necesitas convertir la matriz numérica en una matriz simbólica: 

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

  $$ \displaystyle \left(\begin{array}{cc} \alpha  & \beta \newline \gamma  & \delta  \end{array}\right) $$ 
 

```matlab
Matrix_combined = sym(Matrix_1)
```
Matrix_combined = 

  $$ \displaystyle \left(\begin{array}{ccc} 1 & 1 & 1\newline 1 & 1 & 1\newline 1 & 1 & 1 \end{array}\right) $$ 
 

```matlab
Matrix_combined(1:2,1:2) = Matrix_symb
```
Matrix_combined = 

  $$ \displaystyle \left(\begin{array}{ccc} \alpha  & \beta  & 1\newline \gamma  & \delta  & 1\newline 1 & 1 & 1 \end{array}\right) $$ 
 
# Trabajar con variables simbólicas 

Symbolic Math Toolbox nos ofrece algunas herramientas potentes al hacer cálculo. 

## Derivar con variables simbólicas 

Podemos derivar una expresión como: 

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
 

También puedes derivar respecto a varias variables a la vez: 

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
 

Esto también puede usarse en una matriz, donde cada elemento 

```matlab
MatrixEquation = [x^2,      x*y,       x*y*z; 
                  x*y,      y^2,       y*z  ; 
                  x*y*z,    y*z,       z^2  ]
```
MatrixEquation = 

  $$ \displaystyle \left(\begin{array}{ccc} x^2  & x\,y & x\,y\,z\newline x\,y & y^2  & y\,z\newline x\,y\,z & y\,z & z^2  \end{array}\right) $$ 
 

```matlab
diff_Matrix1 = diff(MatrixEquation, x)
```
diff_Matrix1 = 

  $$ \displaystyle \left(\begin{array}{ccc} 2\,x & y & y\,z\newline y & 0 & 0\newline y\,z & 0 & 0 \end{array}\right) $$ 
 

```matlab
diff_Matrix2 = diff(MatrixEquation, x,y)
```
diff_Matrix2 = 

  $$ \displaystyle \left(\begin{array}{ccc} 0 & 1 & z\newline 1 & 0 & 0\newline z & 0 & 0 \end{array}\right) $$ 
 

```matlab
diff_Matrix3 = diff(MatrixEquation, x,y,z)
```
diff_Matrix3 = 

  $$ \displaystyle \left(\begin{array}{ccc} 0 & 0 & 1\newline 0 & 0 & 0\newline 1 & 0 & 0 \end{array}\right) $$ 
 
## Reescribir ecuaciones

Podemos reescribir expresiones usando la toolbox simbólica: 

```matlab
Eq = (x + 1) * (x + y)
```
Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 

La función collect() devolverá una ecuación donde todas las expresiones se agrupan según la variable deseada y sus potencias idénticas 

```matlab
Eq_collect_x = collect(Eq, x)
```
Eq_collect_x = 
 $\displaystyle x^2 +{\left(y+1\right)}\,x+y$
 

La función simplify() nos permite factorizar una expresión y aplicar reglas de cancelación

```matlab
Simple_Eq = simplify(Eq_collect_x)
```
Simple_Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 
## Resolver ecuaciones

La toolbox simbólica también nos permite resolver variables: 

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


También podemos hacer que resuelva una variable que depende de otras: 

```matlab
parameter_solution_a = solve(Eq1, a)
```
parameter_solution_a = 
 $\displaystyle -\frac{b}{5}$
 