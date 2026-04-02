# De Código a Robot

![](images/logos.svg)

De Código a Robot: un currículo práctico de robótica, visión por computador e inteligencia artificial utilizando MATLAB y robots de la empresa

**Código**: https://github.com/iocroblab/from_code_to_robot.git

## Contenidos

- [Descripción](#descripción)
    - [Robótica](#robótica)
    - [Visión por Computador](#visión-por-computador)
    - [Inteligencia Artificial](#inteligencia-artificial)
- [Objetivos](#objetivos)
- [Acerca del proyecto](#acerca-del-proyecto)
- [Créditos](#créditos)

## Descripción
"De Código a Robot" es un currículo práctico que proporciona al estudiantado competencias aplicadas en robótica, visión por computador e inteligencia artificial (IA) mediante MATLAB y brazos robóticos Universal Robots (UR). Dirigido a estudiantes de ingeniería industrial, informática y tecnologías afines, este currículo ofrece un marco de software y hardware junto con material docente que complementa los conceptos teóricos con aplicaciones prácticas, preparando a los estudiantes para carreras en automatización, robótica y sistemas inteligentes.

El currículo se articula en torno a tres pilares fundamentales -Robótica, Visión por Computador e IA- cada uno de los cuales ofrece materiales docentes y ejercicios prácticos específicos que profundizan en las competencias técnicas del estudiantado. La separación del currículo en estos tres pilares aporta flexibilidad tanto al profesorado como al estudiantado. En muchos programas de grado y máster, las asignaturas se centran exclusivamente en un único dominio -robótica, visión o IA- y solo recientemente se han empezado a integrar contenidos de dos o incluso de los tres ámbitos. Mediante un diseño modular, el currículo apoya dos objetivos principales: (1) incentivar al profesorado a diseñar asignaturas optativas que integren varios pilares para ofrecer una experiencia de aprendizaje más interdisciplinar y basada en proyectos, y (2) permitir que módulos individuales se utilicen en asignaturas centradas en uno o dos pilares, mientras que el contenido restante puede quedar "fijado" o "preconfigurado" para el profesorado que desee centrarse principalmente en robótica, visión o IA. En particular, los objetivos asociados a cada uno de los tres pilares son:

### [Robótica](robotics/index.md)

Este módulo cubre conceptos fundamentales de robótica relacionados con el modelado, la cinemática, la cinemática diferencial, la dinámica y el control de manipuladores seriales. Incluye temas como el cálculo de parámetros DH, la cinemática directa e inversa (tanto en forma cerrada como iterativa), la planificación de trayectorias, los jacobianos geométricos y analíticos, las singularidades, la redundancia y el modelado dinámico mediante los métodos de Lagrange y Newton-Euler, así como el control de movimiento descentralizado. Todos los conceptos se ilustrarán mediante simulación de un brazo robótico UR3 en MATLAB, utilizando el Symbolic Math Toolbox y Simulink, y algunos ejercicios estarán preparados para ejecutarse en robots UR3 físicos, empleando el Universal Robots UR Series Manipulators Support del Robotics System Toolbox.

### [Visión por Computador](Computer Vision/Curriculum.md)

Este módulo se centra en la detección y el reconocimiento de objetos utilizando modelos preentrenados, concretamente YOLOv8. Los conceptos clave incluyen la creación de conjuntos de datos para el entrenamiento, la aplicación de aumento de datos, el aprendizaje por transferencia y el entrenamiento y validación de modelos de aprendizaje profundo. El objetivo es utilizar el marco actual de aprendizaje por transferencia de MATLAB dentro del Deep Learning Toolbox, integrándolo con la arquitectura YOLOv8 (ya implementada en MATLAB; véase este repositorio git).

El estudiantado trabajará con los materiales docentes desarrollados, principalmente scripts MATLAB live o archivos .m, para anotar objetos en imágenes mediante la definición de cajas delimitadoras, aplicar técnicas de aumento de datos como transformaciones geométricas (rotaciones, translaciones y dilataciones) y entrenar y validar nuevos objetos mediante aprendizaje por transferencia (YOLOv8 ya está preentrenado con el conjunto de datos COCO). Estos materiales permiten entrenar YOLO con nuevos objetos y obtener sus cajas delimitadoras, facilitando la manipulación de objetos por parte de los robots Universal Robots. Además, se desarrollará un script de calibración para convertir las posiciones de los objetos detectados en imágenes en coordenadas espaciales a partir de las cámaras existentes en el laboratorio, asegurando una comunicación fluida entre los módulos de visión por computador y robótica dentro de MATLAB.

### [Inteligencia Artificial](ai/Curriculum.md)

Este módulo se centra en la planificación de tareas robóticas mediante Q-learning y Deep Q-learning, dos algoritmos sin modelo del ámbito del aprendizaje por refuerzo (RL) desarrollados en la UPC - BarcelonaTech. Los conceptos clave incluyen el lenguaje STRIPS (modelado de las precondiciones y postcondiciones de las acciones robóticas), la planificación de tareas y los algoritmos de Q-learning. El objetivo es crear materiales curriculares en forma de scripts MATLAB live o archivos .m, utilizando las implementaciones existentes de estos algoritmos en el Reinforcement Learning Toolbox de MATLAB. Se espera que la implementación actual de estos algoritmos admita directamente la planificación de tareas robóticas. No obstante, si los algoritmos no tienen en cuenta las precondiciones de las acciones para reducir el número de acciones posibles en un estado determinado, puede ser necesario introducir modificaciones. En tal caso, se desarrollará una versión personalizada del algoritmo con ajustes menores para permitir la poda de acciones en cada estado. Los materiales desarrollados recibirán como entrada una tarea robótica principal, definida por el usuario y basada en los objetos detectados por el módulo de visión por computador, y producirán como salida una secuencia ordenada de tareas primitivas. Cuando se ejecutan en el robot, estas tareas permiten alcanzar el objetivo principal. La secuencia se envía posteriormente al módulo de robótica, que diseña y ejecuta las trayectorias necesarias para completar cada tarea. Esto permite al estudiantado aplicar técnicas avanzadas para optimizar la secuenciación de tareas y la toma de decisiones en robótica.

## Objetivos
- Desarrollar materiales curriculares en forma de scripts MATLAB live o archivos .m (las versiones más recientes de los archivos .m incluyen nuevas funcionalidades que los hacen más similares a los live scripts) y modelos de Simulink para programar, simular y controlar brazos robóticos UR3, cubriendo cinemática, dinámica y control del movimiento mediante el Symbolic Math Toolbox, Simulink y el Universal Robots UR Series Manipulators Support del Robotics System Toolbox. Estos materiales curriculares se desarrollarán en inglés, español y catalán para adaptarse a los distintos idiomas docentes.
- Integrar YOLOv8 dentro del marco de aprendizaje por transferencia de MATLAB del Deep Learning Toolbox para la detección de objetos personalizable, permitiendo una comunicación fluida con el módulo de robótica.
- Implementar Q-learning y Deep Q-learning para la planificación de tareas utilizando el Reinforcement Learning Toolbox, generando secuencias de tareas optimizadas para su ejecución robótica.
- Desarrollar un conjunto modular de demostraciones y tutoriales para dotar al estudiantado de competencias en robótica, visión por computador y/o IA. 5. Publicar un artículo en una revista o conferencia de innovación docente, crear documentación del repositorio y desarrollar materiales de apoyo para la adopción en cursos, así como otros materiales promocionales como vídeos en YouTube.

## Acerca del proyecto

**Versión actual**: 0.0.1

---

## Créditos

**De Código a Robot** es un proyecto desarrollado en la Universitat Politècnica de Catalunya y financiado por MathWorks y Universal Robots.

### Desarrolladores

1. **Robótica**

    - Constantin Sul (Universitat Politècnica de Catalunya)
    - Prof. Jan Rosell (Universitat Politècnica de Catalunya)

2. **Visión por Computador e Inteligencia Artificial**

    - Noel Nathan Planell (Universitat Politècnica de Catalunya)
    - Prof. Isiah Zaplana (Universitat Politècnica de Catalunya)

### Asesores

- Jennifer Gago (MathWorks)
- Carlos Pérez (Universal Robots)
