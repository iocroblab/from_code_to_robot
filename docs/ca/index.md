# De Codi a Robot

![](images/logos.svg)

De Codi a Robot: un currículum pràctic de robòtica, visió per computador i intel·ligència artificial utilitzant MATLAB i robots de l'empresa

**Codi**: https://github.com/iocroblab/from_code_to_robot.git

## Continguts

- [Descripció](#descripció)
    - [Robòtica](#robòtica)
    - [Visió per Computador](#visió-per-computador)
    - [Intel·ligència Artificial](#intel·ligència-artificial)
- [Objectius](#objectius)
- [Sobre el projecte](#sobre-el-projecte)
- [Crèdits](#crèdits)

## Descripció
"De Codi a Robot" és un currículum pràctic que proporciona a l'estudiantat competències aplicades en robòtica, visió per computador i intel·ligència artificial (IA) mitjançant MATLAB i braços robòtics Universal Robots (UR). Adreçat a estudiants d'enginyeria industrial, informàtica i tecnologies afins, aquest currículum ofereix un marc de programari i maquinari juntament amb material docent que complementa els conceptes teòrics amb aplicacions pràctiques, preparant els estudiants per a carreres en automatització, robòtica i sistemes intel·ligents.

El currículum s'articula al voltant de tres pilars principals - Robòtica, Visió per Computador i IA - cadascun amb materials docents i exercicis pràctics específics que aprofundeixen en les competències tècniques de l'estudiantat. La separació del currículum en aquests tres pilars aporta flexibilitat tant al professorat com a l'estudiantat. En molts programes de grau i màster, les assignatures se centren exclusivament en un únic domini -robòtica, visió o IA- i només recentment s'han començat a integrar continguts de dos o fins i tot dels tres àmbits. Mitjançant un disseny modular, el currículum dona suport a dos objectius principals: (1) incentivar el professorat a dissenyar assignatures optatives que integrin diversos pilars per oferir una experiència d'aprenentatge més interdisciplinària i basada en projectes, i (2) permetre que mòduls individuals s'utilitzin en assignatures centrades en un o dos pilars, mentre que el contingut restant pot quedar "fixat" o "preconfigurat" per al professorat que vulgui focalitzar-se principalment en robòtica, visió o IA. En particular, els objectius associats a cadascun dels tres pilars són:

### [Robòtica](robotics/index.md)

Aquest mòdul cobreix conceptes fonamentals de robòtica relacionats amb el modelatge, la cinemàtica, la cinemàtica diferencial, la dinàmica i el control de manipuladors sèrie. Inclou temes com el càlcul de paràmetres DH, la cinemàtica directa i inversa (tant en forma tancada com iterativa), la planificació de trajectòries, els jacobians geomètrics i analítics, les singularitats, la redundància i el modelatge dinàmic mitjançant els mètodes de Lagrange i Newton-Euler, així com el control de moviment descentralitzat. Tots els conceptes s'il·lustraran mitjançant simulació d'un braç robòtic UR3 a MATLAB, utilitzant el Symbolic Math Toolbox i Simulink, i alguns exercicis estaran preparats per executar-se en robots UR3 físics, emprant el Universal Robots UR Series Manipulators Support del Robotics System Toolbox.

### [Visió per Computador](Computer Vision/Curriculum.md)

Aquest mòdul se centra en la detecció i el reconeixement d'objectes utilitzant models preentrenats, concretament YOLOv8. Els conceptes clau inclouen la creació de conjunts de dades per a l'entrenament, l'aplicació d'augment de dades, l'aprenentatge per transferència i l'entrenament i validació de models d'aprenentatge profund. L'objectiu és utilitzar el marc actual d'aprenentatge per transferència de MATLAB dins del Deep Learning Toolbox, integrant-lo amb l'arquitectura YOLOv8 (ja implementada a MATLAB; vegeu aquest repositori git).

L'estudiantat treballarà amb els materials docents desenvolupats, principalment scripts MATLAB live o fitxers .m, per anotar objectes en imatges mitjançant la definició de capses delimitadores, aplicar tècniques d'augment de dades com transformacions geomètriques (rotacions, translacions i dilatacions) i entrenar i validar nous objectes mitjançant aprenentatge per transferència (YOLOv8 ja està preentrenat amb el conjunt de dades COCO). Aquests materials permeten entrenar YOLO amb nous objectes i obtenir-ne les capses delimitadores, facilitant la manipulació d'objectes amb robots Universal Robots. A més, es desenvoluparà un script de calibratge per convertir les posicions dels objectes detectats a les imatges en coordenades espacials a partir de les càmeres existents al laboratori, assegurant una comunicació fluida entre els mòduls de visió per computador i robòtica dins de MATLAB.

### [Intel·ligència Artificial](ai/Curriculum.md)

Aquest mòdul se centra en la planificació de tasques robòtiques mitjançant Q-learning i Deep Q-learning, dos algoritmes sense model de l'àmbit de l'aprenentatge per reforç (RL) desenvolupats a la UPC - BarcelonaTech. Els conceptes clau inclouen el llenguatge STRIPS (modelatge de les precondicions i postcondicions de les accions robòtiques), la planificació de tasques i els algoritmes de Q-learning. L'objectiu és crear materials curriculars en forma de scripts MATLAB live o fitxers .m, utilitzant les implementacions existents d'aquests algoritmes al Reinforcement Learning Toolbox de MATLAB. Es preveu que la implementació actual d'aquests algoritmes doni suport directament a la planificació de tasques robòtiques. No obstant això, si els algoritmes no tenen en compte les precondicions de les accions per reduir el nombre d'accions possibles en un estat determinat, pot ser necessari introduir modificacions. En aquest cas, es desenvoluparà una versió personalitzada de l'algoritme amb ajustos menors per permetre la poda d'accions a cada estat. Els materials desenvolupats rebran com a entrada una tasca robòtica principal, definida per l'usuari i basada en els objectes detectats pel mòdul de visió per computador, i produiran com a sortida una seqüència ordenada de tasques primitives. Quan s'executen al robot, aquestes tasques permeten assolir l'objectiu principal. La seqüència s'envia posteriorment al mòdul de robòtica, que dissenya i executa les trajectòries necessàries per completar cada tasca. Això permet a l'estudiantat aplicar tècniques avançades per optimitzar la seqüenciació de tasques i la presa de decisions en robòtica.

## Objectius
- Desenvolupar materials curriculars en forma de scripts MATLAB live o fitxers .m (les versions més recents dels fitxers .m inclouen noves funcionalitats que els fan més similars als live scripts) i models de Simulink per programar, simular i controlar braços robòtics UR3, cobrint cinemàtica, dinàmica i control del moviment mitjançant el Symbolic Math Toolbox, Simulink i el Universal Robots UR Series Manipulators Support del Robotics System Toolbox. Aquests materials curriculars es desenvoluparan en anglès, castellà i català per adaptar-se a les diferents llengües docents.
- Integrar YOLOv8 dins del marc d'aprenentatge per transferència de MATLAB del Deep Learning Toolbox per a la detecció d'objectes personalitzable, permetent una comunicació fluida amb el mòdul de robòtica.
- Implementar Q-learning i Deep Q-learning per a la planificació de tasques utilitzant el Reinforcement Learning Toolbox, generant seqüències de tasques optimitzades per a l'execució robòtica.
- Desenvolupar un conjunt modular de demostracions i tutorials per dotar l'estudiantat de competències en robòtica, visió per computador i/o IA. 5. Publicar un article en una revista o conferència d'innovació docent, crear documentació del repositori i desenvolupar materials de suport per a l'adopció en cursos, així com altres materials promocionals com vídeos a YouTube.

## Sobre el projecte

**Versió actual**: 0.0.1

---

## Crèdits

**De Codi a Robot** és un projecte desenvolupat a la Universitat Politècnica de Catalunya i finançat per MathWorks i Universal Robots.

### Desenvolupadors

1. **Robòtica**

    - Constantin Sul (Universitat Politècnica de Catalunya)
    - Prof. Jan Rosell (Universitat Politècnica de Catalunya)

2. **Visió per Computador i Intel·ligència Artificial**

    - Noel Nathan Planell (Universitat Politècnica de Catalunya)
    - Prof. Isiah Zaplana (Universitat Politècnica de Catalunya)

### Assessors

- Jennifer Gago (MathWorks)
- Carlos Pérez (Universal Robots)
