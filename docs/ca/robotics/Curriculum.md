# Currículum

A continuació trobaràs l’ordre proposat de tutorials i exercicis per a la secció de robòtica del projecte From\-Code\-to\-Robot. 

# 0. Conceptes bàsics 

Aquest paquet conté alguns tutorials que expliquen com fer servir funcions bàsiques de Matlab. Entendre aquests conceptes és crucial per a les parts següents del tutorial de Robòtica. 

## [Manipulació de matrius](./0.Basics/Matrix_manipulation.md) 

Aquest tutorial explica com configurar i fer servir matrius a MATLAB. 

## [Symbolic Math Toolbox](./0.Basics/Symbolic_Math_toolbox.md)

Aquest tutorial explica com fer servir variables simbòliques a MATLAB. 

## [Estructures](./0.Basics/Structures.md)

Aquest tutorial il·lustra com accedir a diferents elements d’una estructura i com treballar-hi. 

## [Cel·les](./0.Basics/Cells.md)

Aquest tutorial il·lustra com accedir a diferents elements d’una cel·la i com treballar-hi. 

## [Simulink](./0.Basics/Simulink.md)

Aquest tutorial explica els conceptes bàsics de Simulink 

# 1. Modelatge 

Aquest paquet explica els conceptes bàsics per modelar un robot amb el Robotic System Toolbox. Conté tutorials per entendre els conceptes fent servir el Symbolic Toolbox. 

## [Transformacions](./1.Modelling/Tutorial/Transforms.md)

Aquest tutorial explica què són una translació i una rotació, com es poden expressar en vectors i matrius i la seva combinació com a matriu de transformació homogènia. A més, s’expliquen diferents representacions de rotació. 

### [Exercici 1.1 \- Troba les transformacions](./1.Modelling/Exercise/Exercise-1-1.md)

En aquest exercici hauràs de trobar diferents transformacions per descriure la postura relativa de dos marcs. 

## [Modelatge amb el Robotic System Toolbox](./1.Modelling/Tutorial/Modelling_with_RS_toolbox.md)

Aquest tutorial explica com configurar un robot fent servir el Robotic System Toolbox. 

### [Exercici 1.2 \- Modelatge d’un robot ](./1.Modelling/Exercise/Exercise-1-2.md)

En aquest exercici configuraràs un Universal Robot fent servir el Robotic System Toolbox.

### [Exercici 1.3 \- Troba els paràmetres DH](./1.Modelling/Exercise/Exercise-1-3.md)

En aquest exercici calcularàs els paràmetres DH per a un manipulador robòtic arbitrari i el configuraràs fent servir el Robotic System Toolbox

# 2. Cinemàtica

Aquest paquet explica les relacions entre els angles articulars i la postura resultant dels efectors finals. Fent servir aquest coneixement calcularàs els angles articulars requerits per a una postura desitjada i trajectòries per moure les articulacions de manera controlada. 

## [Cinemàtica directa](./2.Kinematics/Tutorial/Forward_Kinematics.md)

Aquest tutorial explica com calcular la transformació resultant d’un manipulador donada una configuració articular amb l’exemple d’un Universal UR3. 

### [Exercici 2.1 \- Cinemàtica directa](./2.Kinematics/Exercises/Exercise-2-1.md)

En aquest exercici calcularàs la transformació resultant per a una configuració donada fent servir el Symbolic Toolbox i el Robotic System Toolbox. 

## [Cinemàtica inversa](./2.Kinematics/Tutorial/Inverse_Kinematics.md)

Aquest tutorial explica com calcular una o múltiples solucions a la pregunta de quins angles articulars són necessaris per aconseguir una transformació desitjada. 

### [Exercici 2.2 \- Cinemàtica inversa de braços planars](./2.Kinematics/Exercises/Exercise-2-2.md)

En aquest exercici calcularàs les solucions de cinemàtica inversa per a robots planars simples. 

### [Exercici 2.3 \- Cinemàtica inversa d’un braç antropomòrfic amb canell esfèric](./2.Kinematics/Exercises/Exercise-2-3.md)

En aquest exercici calcularàs les solucions analítiques de cinemàtica inversa per a un braç antropomòrfic amb canell esfèric fent servir les tècniques explicades al tutorial. 

## [Planificació de trajectòries en l’espai articular](./2.Kinematics/Tutorial/Joint_Space_Trajectory_Planning.md)

Aquest tutorial explica com calcular una trajectòria d’un estat articular a un altre fent servir perfils de velocitat específics. 

### [Exercici 2.4 \- Planificació de trajectòries en l’espai articular](./2.Kinematics/Exercises/Exercise-2-4.md)

En aquest tutorial configuraràs diferents funcions per calcular trajectòries per a una sola articulació i per a manipuladors complets. Ajustaràs les funcions per complir requisits específics. 

# 3. Cinemàtica diferencial

Aquest paquet explica la relació entre velocitats articulars i velocitats cartesianes de l’efector final. A partir d’aquest coneixement aprendràs com configurar un algorisme numèric de cinemàtica inversa i aprendràs sobre la manipulabilitat dels robots i quins reptes apareixen. 

## [Jacobians](<./3.Differential Kinematics/Tutorial/Jacobians.md>)

Aquest tutorial explica els càlculs de la matriu jacobiana geomètrica i analítica fent servir el Symbolic Toolbox. A més, aprendràs com utilitzar el Robotic System Toolbox per als càlculs. 

## [Manipulabilitat](<./3.Differential Kinematics/Tutorial/Manipulability.md>) 

Aquest tutorial explica si un robot pot moure’s en configuracions específiques i amb quin esforç. Explicarà el concepte de singularitats i redundància i mostrarà alguns exemples a Rviz. 

### [Exercici 3.1 \- Jacobià](<./3.Differential Kinematics/Exercise/Exercise-3-1.md>) 

En aquest exercici configuraràs funcions per calcular simbòlicament els jacobians geomètric i analític i calcular les velocitats articulars requerides per aconseguir un moviment específic. Visualitzaràs aquest moviment a Rviz i analitzaràs com canvien la manipulabilitat i les velocitats articulars quan s’està prop d’una configuració singular.

## [Algorisme de cinemàtica inversa](<./3.Differential Kinematics/Tutorial/Inverse_Kinematic_Algorithm.md>)

Aquest tutorial explica dos enfocaments sobre com utilitzar els jacobians per configurar un algorisme numèric de cinemàtica inversa.

### [Exercici 3.2 \- Algorisme de cinemàtica inversa](<./3.Differential Kinematics/Exercise/Exercise-3-2.md>)

En aquest exercici configuraràs l’algorisme de cinemàtica inversa amb pseudoinversa i analitzaràs la convergència i l’error que produeix. Faràs servir quaternions per calcular l’error d’orientació fent servir el jacobià analític. 

### [Exercici 3.3 \- Teleoperació per velocitat](<./3.Differential Kinematics/Exercise/Exercise-3-3.md>)

En aquest exercici simularàs un robot i controlaràs l’efector final amb el teu teclat calculant les velocitats articulars requerides. 

# 4. Dinàmica

Aquest paquet explica la relació entre estats articulars, velocitats i parells fent servir la formulació de Lagrange. També aprendràs com estimar paràmetres del teu robot donades dades de prova suficients; això et permet aproximar, per exemple, el pes o les matrius d’inèrcia del teu manipulador robòtic. 

## [Formulació de Lagrange de la dinàmica](./4.Dynamics/Tutorial/Dynamics_Lagrange_Formulation.md)

 Aquest tutorial explicarà què són els diferents termes de la formulació de Lagrange i com es calculen fent servir el Symbolic Toolbox i el Robotic System Toolbox. A més, es presenta una tècnica per a la identificació de paràmetres dinàmics lineals. 

### [Exercici 4.1 \- Càlcul de termes dinàmics](./4.Dynamics/Exercise/Exercise-4-1.md)

En aquest exercici configuraràs funcions per calcular els diferents termes de la formulació de Lagrange per a un manipulador arbitrari fent servir el toolbox simbòlic. 

### [Exercici 4.2 \- Control basat en esforç fent servir el model dinàmic ](./4.Dynamics/Exercise/Exercise-4-2.md)

En aquest exercici controlaràs un robot ur3e perquè sostingui un pes en diferents configuracions fent servir el motor de simulació física gazebo. Calcularàs els parells articulars requerits per sostenir un pes fent servir la formulació de Lagrange. 

# 5. Control 

Aquest paquet explica diferents enfocaments d’algorismes de control robòtic. Per exemple, esquemes de control centralitzats i descentralitzats.

## [Esquemes de control](<./5.Control/Tutorial/Control Schemes.md>)

Aquest tutorial explica les idees bàsiques darrere de diferents esquemes de control. 

### [Exercici 5.1 \- Control d’esforç del manipulador de tres enllaços fent servir matrius simbòliques](./5.Control/Exercises/Exercise1/Exercise-5-1.md)

En aquest exercici controlaràs un manipulador de tres enllaços fent servir un algorisme de dinàmica inversa. Configuraràs un esquema de control a simulink fent servir les matrius simbòliques que has calculat a l’Exercici 4.1 i calcularàs matrius més eficients per reduir la càrrega computacional. 

### [Exercici 5.2 \- Control d’esforç del manipulador de tres enllaços fent servir control PD i extensions](./5.Control/Exercises/Exercise2/Exercise-5-2.md)

En aquest exercici controlaràs un manipulador de tres enllaços fent servir control de parell i configuraràs un esquema de control PD que s’augmenta amb termes addicionals al llarg de l’exercici. El resultat és un PID + compensació de gravetat

### [Exercici 5.3 \- Control d’esforç d’un UR fent servir Robotic System Toolbox](./5.Control/Exercises/Exercise3/Exercise-5-3.md)

En aquest exercici controlaràs un robot UR de la teva elecció, fent servir un esquema de control de dinàmica inversa mitjançant els blocs de simulink del Robotic System Toolbox. 

### [Exercici 5.4 \- Universal Robots en l’espai de tasca fent servir control de velocitat](./5.Control/Exercises/Exercise4/Exercise-5-4.md)

En aquest exercici controlaràs un robot UR en l’espai de tasca fent servir un esquema de jacobià invers. 

### [Exercici 5.5 \- Universal Robots en l’espai de tasca fent servir control d’esforç](./5.Control/Exercises/Exercse5/Exercise-5-5.md)

En aquest exercici controlaràs un robot UR en l’espai de tasca fent servir un esquema centralitzat i descentralitzat. 

# 6. Projecte final

Ara combinaràs el teu treball de Visió per Computador i IA amb els teus coneixements de robòtica, per detectar i seguir una fruita i fer-la servir per teleoperar el robot. 