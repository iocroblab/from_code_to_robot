# Control 

En este tutorial, estudiaremos dos estrategias de control importantes para manipuladores robóticos: **control centralizado** y **control descentralizado**.

El objetivo es entender cuándo es adecuado cada enfoque, en qué supuestos se basan y cómo afectan al rendimiento.

# Motivación

Los manipuladores robóticos son sistemas no lineales y altamente acoplados.

Esto significa que el movimiento de una articulación a menudo influye en las fuerzas y los pares que actúan sobre las demás. Por ejemplo, mover el hombro de un brazo robótico cambia el par requerido en el codo, incluso si el propio codo no se mueve.

La tarea del controlador es garantizar que el manipulador siga una trayectoria deseada a pesar de estos acoplamientos y efectos no lineales. Hay dos filosofías generales para abordar este problema:

-  En el **control descentralizado**, cada articulación se controla por separado, casi como si fuera un sistema independiente. Los acoplamientos dinámicos con las otras articulaciones no se modelan explícitamente, sino que se tratan como perturbaciones. Esto hace que el controlador sea más simple, pero el rendimiento puede degradarse si los acoplamientos son fuertes. 
-  En el **control centralizado**, se tienen en cuenta las dinámicas completas del manipulador. La matriz de inercia, los términos de Coriolis y centrífugos, y la gravedad se incluyen explícitamente en la ley de control, de modo que los acoplamientos se compensan activamente. Esto generalmente conduce a un seguimiento de trayectoria más preciso, a costa de requerir un modelo preciso y más cálculo. 

# Control descentralizado

En un esquema de control descentralizado, cada articulación del manipulador se trata como un sistema independiente. La idea es diseñar un controlador simple, como un controlador PD, para cada articulación por separado. Las interacciones entre articulaciones, que en realidad existen debido a la dinámica acoplada, no se modelan explícitamente. En cambio, se consideran perturbaciones externas que el controlador local debe rechazar lo mejor posible.

Este enfoque tiene la ventaja de la simplicidad: requiere únicamente mediciones locales de las articulaciones y un modelado básico de cada actuador. Además, el control descentralizado es robusto en el sentido de que no depende de un conocimiento preciso de la dinámica completa del robot. Sin embargo, también tiene una clara desventaja: cuando el manipulador ejecuta movimientos rápidos o complejos, los efectos de acoplamiento se vuelven significativos y el rendimiento del control puramente descentralizado se degrada.

Una mejora común es incluir **términos feedforward** basados en un conocimiento aproximado de la dinámica. Por ejemplo, añadir compensación de gravedad o predicciones parciales de par ayuda a reducir el efecto de los acoplamientos. De esta manera, los controladores descentralizados pueden lograr un buen rendimiento sin volverse excesivamente complejos.

![image_0.svg](Control_Schemes_media/image_0.svg)

## Control PD compensado por gravedad

Una de las formas más simples de mejorar el control descentralizado es añadir **compensación de gravedad**. La idea es que, sin compensación, el controlador debe luchar contra los pares gravitacionales constantes que actúan sobre las articulaciones. Esto puede conducir a grandes errores en régimen permanente.

Al incluir explícitamente un término feedforward igual al vector de gravedad g(q), podemos cancelar el efecto gravitacional estático.

La ley de control:

 $$ u=g\left(q\right)+k_p \cdot \left(q_d -q\right)-k_d \cdot \left(\dot{q_d } -\dot{q} \right) $$ 

se simplifica a 

 $$ u=g\left(q\right)+k_p \cdot \left(q_d -q\right)-k_d \cdot \dot{\;q} $$ 

para $\dot{q_d } =0$ 

Dando lugar al esquema de control: ![image_1.svg](Control_Schemes_media/image_1.svg)

# Control PID

Otra forma de mejorar el control descentralizado y eliminar el error en régimen permanente consiste en introducir un término de integración. Es importante añadir algún mecanismo anti-windup para impedir que el término de integración siga acumulándose cuando la posición está muy alejada. La idea es mover las articulaciones lo más cerca posible de la posición deseada usando un esquema feedforward PD + compensación de gravedad. El término integral eliminará cualquier error en régimen permanente. 

# Control centralizado

En cambio, el control centralizado incorpora explícitamente la dinámica acoplada del robot en la ley de control. En lugar de tratar las interacciones entre articulaciones como perturbaciones, se modelan y se compensan usando las ecuaciones dinámicas completas del manipulador.

La dinámica del robot puede escribirse en la forma estándar:

 $$ B\left(q\right)\cdot \;\ddot{\;q} +C\left(q,\dot{q} \right)\cdot \dot{q} +F\cdot \dot{q} +g\left(q\right)=\tau $$ 

En un esquema centralizado, el controlador usa este modelo para calcular pares que cancelan los términos no lineales. Esto da como resultado un comportamiento en lazo cerrado más simple, a menudo lineal. La ventaja es una precisión de seguimiento mucho mejor, especialmente en tareas que implican el movimiento simultáneo de múltiples articulaciones. La desventaja es que el control centralizado requiere un modelo razonablemente preciso del robot. Si los parámetros son inciertos o cambian con el tiempo, el rendimiento puede deteriorarse.