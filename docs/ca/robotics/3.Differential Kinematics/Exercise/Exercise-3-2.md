```matlab
clear all; 
```
# Exercici 3.2 \- Algorisme de cinemàtica inversa

En aquest exercici configuraràs un algorisme de cinemàtica inversa fent servir la pseudoinversa del jacobià. 


Considera aquest robot UR3e: 


![image_0.png](Exercise-3-2_media/image_0.png)


Considera aquesta taula DH per a l’UR3e: 

||||||
| :-: | :-- | :-: | :-: | :-: |
| Enllaç  | a $begin:math:display$m$end:math:display$  | alpha  | d $begin:math:display$m$end:math:display$  | theta   |
| 1  | 0  | pi/2  | 0.15185  | q1   |
| 2  | \-0.24355  | 0  | 0  | q2   |
| 3  | \-0.2132  | 0  | 0  | q3   |
| 4  | 0  | pi/2  | 0.13105  | q4   |
| 5  | 0  | \-pi/2  | 0.08535  | q5   |
| 6  | 0  | 0  | 0.0921  | q6   |


L’esquema de control que has d’implementar és: 


![image_1.svg](Exercise-3-2_media/image_1.svg)


on $k\left(\cdot \right)$ és la cinemàtica directa de q. 

# Tasca 1

Escriu una funció que calculi una solució de la cinemàtica inversa fent servir la pseudoinversa del jacobià. La funció té les entrades següents: 

1.  els estats articulars inicials com a vector fila ( $q_0 \in {\mathbb{R}}^{6\textrm{x1}}$ )
2. vector de postura desitjada fent servir angles d’Euler (ZYZ) $x_{\textrm{desired}} =\left\lbrack \begin{array}{c} x\newline y\newline z\newline \phi \newline \theta \newline \psi  \end{array}\right\rbrack$
3. guany (k)
4. tolerància (tol)
5. iteracions màximes (Imax)

La funció ha de retornar els estats articulars requerits com a vector fila ( $q\in {\mathbb{R}}^{6\textrm{x1}}$ )


Per a aquesta tasca, considera $\dot{x_d } =\left\lbrack \begin{array}{c} 0\newline 0\newline 0\newline 0\newline 0\newline 0 \end{array}\right\rbrack$ i $\Delta t=0\ldotp 01\;s$ 


Fes servir el nom de funció següent per a la teva solució:

-   PseudoInverseAlgorithm(q0, x\_desired, k, tol, Imax) 

Pots fer servir la funció següent per calcular la transformació simbòlica des de la base fins a l’efector final. 

-  dh2tf() 

Resol aquest exercici sense fer servir la funció: 

-  inverseKinematics() 
```matlab
function q = PseudoInverseAlgorithm(q0, x_desired, k, tol, Imax)
syms q1 q2 q3 q4 q5 q6 real
DH=[
   %a       alpha       d       theta
   0        pi/2        0.15185  q1;
   -0.24355 0           0       q2;
   -0.2132  0           0       q3;
   0        pi/2        0.13105 q4;
   0        -pi/2       0.08535 q5;
   0        0           0.0921  q6;
    ];
```
DH = 

  $$ \displaystyle \left(\begin{array}{cccc} 0 & \frac{\pi }{2} & \frac{3037}{20000} & q_1 \newline -\frac{4871}{20000} & 0 & 0 & q_2 \newline -\frac{533}{2500} & 0 & 0 & q_3 \newline 0 & \frac{\pi }{2} & \frac{2621}{20000} & q_4 \newline 0 & -\frac{\pi }{2} & \frac{1707}{20000} & q_5 \newline 0 & 0 & \frac{921}{10000} & q_6  \end{array}\right) $$ 
 

```matlab

A06 = dh2tf(DH); 
```
ans = 

  $$ \displaystyle \begin{array}{l} \left(\begin{array}{cccc} \cos \left(q_6 \right)\,\sigma_3 -\sigma_1 \,\cos \left(q_1 \right)\,\sin \left(q_6 \right) & -\sin \left(q_6 \right)\,\sigma_3 -\sigma_1 \,\cos \left(q_1 \right)\,\cos \left(q_6 \right) & \cos \left(q_5 \right)\,\sin \left(q_1 \right)-\sigma_4 \,\cos \left(q_1 \right)\,\sin \left(q_5 \right) & \frac{2621\,\sin \left(q_1 \right)}{20000}-\frac{4871\,\cos \left(q_1 \right)\,\cos \left(q_2 \right)}{20000}+\frac{921\,\cos \left(q_5 \right)\,\sin \left(q_1 \right)}{10000}-\frac{921\,\sigma_4 \,\cos \left(q_1 \right)\,\sin \left(q_5 \right)}{10000}+\frac{1707\,\cos \left(q_2 +q_3 \right)\,\cos \left(q_1 \right)\,\sin \left(q_4 \right)}{20000}+\frac{1707\,\sin \left(q_2 +q_3 \right)\,\cos \left(q_1 \right)\,\cos \left(q_4 \right)}{20000}-\frac{533\,\cos \left(q_1 \right)\,\cos \left(q_2 \right)\,\cos \left(q_3 \right)}{2500}+\frac{533\,\cos \left(q_1 \right)\,\sin \left(q_2 \right)\,\sin \left(q_3 \right)}{2500}\newline -\cos \left(q_6 \right)\,\sigma_2 -\sigma_1 \,\sin \left(q_1 \right)\,\sin \left(q_6 \right) & \sin \left(q_6 \right)\,\sigma_2 -\sigma_1 \,\cos \left(q_6 \right)\,\sin \left(q_1 \right) & -\cos \left(q_1 \right)\,\cos \left(q_5 \right)-\sigma_4 \,\sin \left(q_1 \right)\,\sin \left(q_5 \right) & \frac{533\,\sin \left(q_1 \right)\,\sin \left(q_2 \right)\,\sin \left(q_3 \right)}{2500}-\frac{921\,\cos \left(q_1 \right)\,\cos \left(q_5 \right)}{10000}-\frac{4871\,\cos \left(q_2 \right)\,\sin \left(q_1 \right)}{20000}-\frac{2621\,\cos \left(q_1 \right)}{20000}-\frac{921\,\sigma_4 \,\sin \left(q_1 \right)\,\sin \left(q_5 \right)}{10000}+\frac{1707\,\cos \left(q_2 +q_3 \right)\,\sin \left(q_1 \right)\,\sin \left(q_4 \right)}{20000}+\frac{1707\,\sin \left(q_2 +q_3 \right)\,\cos \left(q_4 \right)\,\sin \left(q_1 \right)}{20000}-\frac{533\,\cos \left(q_2 \right)\,\cos \left(q_3 \right)\,\sin \left(q_1 \right)}{2500}\newline \sigma_4 \,\sin \left(q_6 \right)+\sigma_1 \,\cos \left(q_5 \right)\,\cos \left(q_6 \right) & \sigma_4 \,\cos \left(q_6 \right)-\sigma_1 \,\cos \left(q_5 \right)\,\sin \left(q_6 \right) & -\sigma_1 \,\sin \left(q_5 \right) & \frac{1707\,\sin \left(q_2 +q_3 \right)\,\sin \left(q_4 \right)}{20000}-\frac{4871\,\sin \left(q_2 \right)}{20000}-\sin \left(q_5 \right)\,{\left(\frac{921\,\cos \left(q_2 +q_3 \right)\,\sin \left(q_4 \right)}{10000}+\frac{921\,\sin \left(q_2 +q_3 \right)\,\cos \left(q_4 \right)}{10000}\right)}-\frac{1707\,\cos \left(q_2 +q_3 \right)\,\cos \left(q_4 \right)}{20000}-\frac{533\,\sin \left(q_2 +q_3 \right)}{2500}+\frac{3037}{20000}\newline 0 & 0 & 0 & 1 \end{array}\right)\\\mathrm{}\\\textrm{where}\\\mathrm{}\\\;\;\sigma_1 =\sin \left(q_2 +q_3 +q_4 \right)\\\mathrm{}\\\;\;\sigma_2 =\cos \left(q_1 \right)\,\sin \left(q_5 \right)-\sigma_4 \,\cos \left(q_5 \right)\,\sin \left(q_1 \right)\\\mathrm{}\\\;\;\sigma_3 =\sin \left(q_1 \right)\,\sin \left(q_5 \right)+\sigma_4 \,\cos \left(q_1 \right)\,\cos \left(q_5 \right)\\\mathrm{}\\\;\;\sigma_4 =\cos \left(q_2 +q_3 +q_4 \right)\end{array} $$ 
 

```matlab

q=[]; 

end

```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('3-2-1')
```
# Tasca 2

Amplia la funció anterior. 


Afegeix l’entrada: 

-  dt (temps per al pas discret de l’algorisme) 

Afegeix les sortides: 

-  total\_time (temps que triga l’algorisme a trobar una solució) 
-  total\_iterations (iteracions fins que s’ha trobat la solució) 
-  solution\_error (error quadràtic de la postura per a la configuració solució $\left({\textrm{error}}_{\textrm{solution}} \left(q\right)={e\left(q\right)}^T \cdot e\left(q\right)\right)$ ) 

Fes servir "tic" i "toc" per mesurar el temps computacional. 


Fes servir el nom de funció següent per a la teva solució:

-   ExtendedPseudoInverseAlgorithm(t\_desired, k, dt, tol, Imax) 

Resol aquest exercici sense fer servir la funció: 

-  inverseKinematics() 
```matlab
function [q,total_time,total_iterations,solution_error] = ExtendedPseudoInverseAlgorithm(t_desired, k, dt, tol, Imax)

q=[]; 
total_time = []; 
total_iterations=[]; 
solution_error = []; 

end
```

Analitza com es comporta el teu algorisme quan canvies la tolerància, el guany o el pas temporal. 