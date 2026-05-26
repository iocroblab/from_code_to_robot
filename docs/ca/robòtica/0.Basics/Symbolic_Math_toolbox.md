```matlab
clear all; 
```
# Symbolic Math Toolbox

Aquest tutorial utilitzarà la Symbolic Math Toolbox. Aquest breu tutorial explicarà algunes de les funcionalitats bàsiques que s’utilitzaran en tutorials futurs.


La Symbolic Math Toolbox és una eina potent per fer càlculs, ja que ens permet utilitzar variables en lloc de nombres. Això pot ser útil per reutilitzar matrius o equacions complexes i substituir valors quan sigui necessari. 


Activeu "Output inline" a la dreta de la barra de desplaçament. 


 ![image_0.png](Symbolic_Math_toolbox_media/image_0.png)

# Crear una variable simbòlica 

Per crear una variable simbòlica, pots utilitzar l’ordre syms seguida de les variables desitjades. 

```matlab
syms var
```

Si només treballes amb nombres reals, com serà el cas en aquest tutorial, afegeix real a syms per reduir els càlculs simbòlics amb nombres imaginaris. 

```matlab
syms var real
```

Pots crear múltiples variables alhora; si hi afegeixes un número, es mostrarà com un índex en la visualització.

```matlab
syms var1 var2 var3 real real
MyVars = [var1 var2 var3]
```
MyVars = 

  $$ \displaystyle \left(\begin{array}{ccc} {\textrm{var}}_1  & {\textrm{var}}_2  & {\textrm{var}}_3  \end{array}\right) $$ 
 

Quan escrius lletres gregues com a variables, es converteixen en els seus símbols en la visualització: 

```matlab
syms alpha beta gamma Delta delta 
MyVars = [alpha, beta, gamma, Delta, delta]
```
MyVars = 

  $$ \displaystyle \left(\begin{array}{ccccc} \alpha  & \beta  & \gamma  & \Delta  & \delta  \end{array}\right) $$ 
 
# Substituir variables

Utilitzant la funció subs(), podem substituir variables simbòliques per valors, fent que sigui fàcil reutilitzar, per exemple, equacions:

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
 

Podem combinar funcions com: 

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
 

També pots substituir vectors per variables, obtenint una sortida vectorial en què cada fila correspon a la fila d’entrada corresponent. 

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

  $$ \displaystyle \left(\begin{array}{c} 0\newline \frac{25\,y}{4}+\frac{125}{4}\newline 25\,y+250\newline \frac{225\,y}{4}+\frac{3375}{4}\newline 100\,y+2000 \end{array}\right) $$ 
 
# Convertir variables simbòliques

De vegades apareixen missatges d’error quan s’intenta combinar variables numèriques i simbòliques. Evita-ho convertint-ne una:


Després de substituir, la variable del Workspace encara es considera una variable simbòlica. Encara que la nova variable només contingui nombres, MATLAB la considerarà una variable simbòlica, cosa que pot causar dificultats. La pots convertir a numèrica així: 

```matlab
ValueDouble = double(Value2)
```

```matlabTextOutput
ValueDouble = 7
```


Si intentes inserir variables simbòliques dins de variables numèriques, cal convertir la matriu numèrica en una matriu simbòlica: 

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
 
# Treballar amb variables simbòliques 

La Symbolic Math Toolbox ens dona eines potents per fer càlcul diferencial. 

## Derivar amb variables simbòliques 

Podem derivar una expressió com: 

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
 

També pots derivar respecte de múltiples variables alhora: 

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
 

Això també es pot utilitzar en una matriu, on cada element 

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
 
## Reescriure equacions

Podem reescriure expressions utilitzant la toolbox simbòlica: 

```matlab
Eq = (x + 1) * (x + y)
```
Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 

La funció collect() retorna una equació on totes les expressions s’agrupen segons la variable desitjada i les seves potències idèntiques. 

```matlab
Eq_collect_x = collect(Eq, x)
```
Eq_collect_x = 
 $\displaystyle x^2 +{\left(y+1\right)}\,x+y$
 

La funció simplify() ens permet factoritzar una expressió i aplicar regles de cancel·lació.

```matlab
Simple_Eq = simplify(Eq_collect_x)
```
Simple_Eq = 
 $\displaystyle {\left(x+y\right)}\,{\left(x+1\right)}$
 
## Resoldre equacions

La toolbox simbòlica també ens permet resoldre variables: 

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


També podem fer que resolgui una variable que depèn d’altres: 

```matlab
parameter_solution_a = solve(Eq1, a)
```
parameter_solution_a = 
 $\displaystyle -\frac{b}{5}$
 