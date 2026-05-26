```matlab
clear all; 
```
# Exercici 2.4 \- Planificació de trajectòries en l’espai articular

En aquest exercici desenvoluparàs funcions per calcular trajectòries articulars. 


Si us plau, desa les teves solucions a les variables predefinides!

# Descripció de la tasca:

Segueix les tasques i configura les funcions requerides per a diferents càlculs de trajectòries. 


Respon totes les preguntes i desa la teva solució a la variable correcta

# Tasca 1

Escriu una funció que calculi una trajectòria articular quíntica per a una sola articulació. Aquesta funció pren quatre entrades: 

1.  estat articular inicial (q0)
2. estat articular objectiu (qf)
3. temps per arribar a la postura (t)
4. estats articulars intermedis (N)
5. velocitat inicial (v0)
6. velocitat a l’estat articular objectiu (vf)
7. acceleració inicial (a0)
8. acceleració a l’estat articular objectiu (af)

i retorna la trajectòria articular com una on cada fila correspon a una configuració articular, la trajectòria de velocitat articular, la trajectòria d’acceleració articular i un vector que conté el temps a cada entrada de la trajectòria. 


Assumeix que tant la velocitat com l’acceleració a l’inici i al final de la trajectòria són 0. 


Fes servir el nom de funció següent per a la teva solució:

-  SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af) 

Resol aquest exercici sense fer servir les funcions: 

-  quinticpolytraj() 
```matlab
function [q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0, qf, T, N, v0, vf, a0, af)

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-4-1')
```

Pots representar gràficament la teva trajectòria: 

```matlab
 
q0 = 0; 
qf = pi;
v0 = 0; 
vf = 0; 
a0 = 0;
af = 0; 
T = 8; 
N = 100; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = SingleQuinticTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
```
# Tasca 2

Escriu una funció que prengui dues configuracions articulars i calculi la trajectòria quíntica per a cada articulació. Pots fer servir la funció definida prèviament


Fes servir les variables següents per desar la teva solució:

-  QuinticConfigurationTrajectory(q0, qt, t, N) 

Resol aquest exercici sense fer servir les funcions: 

-  quinticpolytraj() 
```matlab
function q_config_trajectory = QuinticConfigurationTrajectory(q0,qt,t,N)

end
```

Pots visualitzar la teva trajectòria a Rviz: 

```matlab
 
q0 = zeros(1,6); 
qf = [-pi/7,-pi/2,pi/5,-pi/3,pi/2,pi/4];
v0 = zeros(1,6); 
vf = zeros(1,6); 
a0 = zeros(1,6);
af = zeros(1,6); 
T = 8; 
N = 300; 
[q_trajectory, qd_trajectory, qdd_trajectory, timevec] = QuinticConfigurationTrajectory(q0,qf,T,N,v0,vf,a0,af);
plotTrajectory(q_trajectory, qd_trajectory, qdd_trajectory, timevec)
JointStatesToRviz(q_trajectory, [], T);

```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-4-2')
```

Observa que ara tens una restricció diferent en comparació amb el tutorial. Per tant, la teva funció ha de determinar l’acceleració constant requerida. 


La funció ha de tenir quatre sortides: 

1.  trajectòria d’estat articular q
2. trajectòria de velocitat articular qd
3. trajectòria d’acceleració articular qdd
4. vector de temps timevec

Fes servir el nom de funció següent per a la teva solució:

-  SingleTrapezoidalTrajectory(q0, qt, T, N, vc) 

Resol aquest exercici sense fer servir les funcions: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = SingleTrapezoidalTrajectory(q0, qt, T, N, vc)

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-4-3')
```
# Tasca 4

Amplia la funció de la Tasca 3. Aquesta funció pren sis entrades: 

1.  estat articular inicial (q0)
2. estat articular objectiu (qt)
3. temps per arribar a la postura (t)
4. nombre de passos per arribar a la postura (N)
5. velocitat de creuer (vc)
6. acceleració màxima (amax)

Aquesta funció ha de comprovar si la trajectòria articular calculada dona com a resultat una acceleració més gran que l’acceleració màxima permesa. Si aquest és el cas, la funció ha d’augmentar el temps per arribar a la postura en increments de 0.1 s fins que l’acceleració resultant estigui dins dels límits. 


Pots fer servir la funció de la Tasca 3


Fes servir el nom de funció següent per a la teva solució:

-  LimitedTrapezoidalTrajectory(q0, qt, t, N, vc, amax) 

La funció ha de tenir quatre sortides: 

1.  trajectòria d’estat articular q
2. trajectòria de velocitat articular qd
3. trajectòria d’acceleració articular qdd
4. vector de temps

Resol aquest exercici sense fer servir les funcions: 

-  solve() 
-  trapveltraj() 
```matlab
function [q, qd, qdd, timevec] = LimitTrapezoidalTrajectory(q0,qt,t,N,vc,amax)

end
```

Pots comprovar la teva feina fent clic a Run: 

```matlab
 
check_exercise('2-4-4')
```