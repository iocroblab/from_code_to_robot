# Algoritmo de cinemática inversa

Utilizar el jacobiano nos permite configurar un algoritmo para encontrar una solución numérica de cinemática inversa. Este enfoque puede usarse para manipuladores redundantes o manipuladores para los que no existe una solución en forma cerrada (solución analítica). 


La idea general es calcular la dirección desde el efector final actual hasta la pose deseada. Usando este vector de velocidad, te aproximas iterativamente a la pose deseada mediante una discretización de Euler. En cada paso discreto, consideras la nueva pose del efector final y el nuevo vector de velocidad hasta la convergencia. 


Estos algoritmos usan el jacobiano analítico, ya que codifica la orientación deseada en términos de, por ejemplo, ángulos de Euler.

# Inversa/pseudoinversa del jacobiano 

### Objetivo: 

Seleccionar $\dot{q}$ de modo que $\dot{e} =\dot{x_d } -\dot{x_{\textrm{ee}} } =\dot{x_d } -J_A \left(q\right)\cdot \dot{q} <0$ 

### Teoría: 

Si elegimos $\dot{q} =J_A^{-1} \left(q\right)\cdot \left(\dot{x_d } +K\cdot e\right)$, entonces la dinámica del error es lineal: 

 $$ \dot{e} +K\cdot e=0 $$ 

La convergencia a cero depende de los valores propios de K. Cuanto mayores sean los valores propios, más rápida será la convergencia. Sin embargo, ganancias muy grandes pueden romper las implementaciones en tiempo discreto (sobreoscilación) o violar los límites articulares.

### Algoritmo: 

Para cada paso de tiempo discreto k con $\Delta t$:

 $$ q\left(t_{k+1} \right)=q\left(t_k \right)+\dot{q} \left(t_k \right)\cdot \Delta t $$ 

hasta la convergencia. 


El jacobiano usado para los cálculos solo es válido para la configuración articular con la que se calculó. Elegir un paso de tiempo $\Delta t$ demasiado grande puede hacer que no haya convergencia. 

### Esquema de control: 

![image_0.svg](Inverse_Kinematic_Algorithm_media/image_0.svg)


donde $k\left(\cdot \right)$ es la cinemática directa de q. 

### Notas: 
-  Normalmente $\dot{x_d } =0$ y el error en régimen estacionario es 0, ya que hay un integrador en el bucle 
-  Para manipuladores redundantes, debe usarse la pseudoinversa, ya que J es una matriz no cuadrada. 
# Jacobiano transpuesto 

### Objetivo: 

Seleccionar $\dot{q}$ de modo que $\dot{e} =\dot{x_d } -\dot{x_{\textrm{ee}} } =\dot{x_d } -J_A \left(q\right)\cdot \dot{q} <0$ 

### Teoría: 

Usa el método directo de Lyapunov para asegurar la estabilidad asintótica:

 $$ V\left(e\right)=\frac{1}{2}\cdot e^T \cdot K\cdot e $$ 

 $$ \dot{V} \left(e\right)=e^T \cdot K\cdot \dot{x_d } -e^T \cdot K\cdot J_A \left(q\right)\cdot \dot{q} $$ 
### Pasos: 

Eligiendo $\dot{q} =J_A^T \left(q\right)\cdot K\cdot e$, entonces: 

 $$ \dot{V} \left(e\right)=e^T \cdot K\cdot \dot{x_d } -e^T \cdot K\cdot J_A^T \left(q\right)\cdot \dot{q} $$ 

si $\dot{x_d } =0$, entonces $\dot{V} <0$ cuando $J_A$ es de rango completo, asegurando la estabilidad asintótica. 

### Esquema: 

![image_1.svg](Inverse_Kinematic_Algorithm_media/image_1.svg)


donde $k\left(\cdot \right)$ es la cinemática directa del manipulador. 

### Notas: 
-  Solo se requiere el cálculo de $J_A^T \left(q\right)$ y $k\left(\cdot \right)$.  
-  El error de orientación debe tratarse con cuidado (el uso de ángulos de Euler no es la mejor opción)  