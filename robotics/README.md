# From Code to Robot: A hands-on curriculum for robotics, computer vision, and AI using MATLAB and Company robots

## Description
“From Code to Robot” is a hands-on curriculum that equips students with practical skills in robotics, computer vision, and artificial intelligence (AI) using MATLAB and Universal Robots (UR) robotic arms. Targeted at students in industrial engineering, computer science, and technology, this curriculum provides a software and hardware framework together with teaching material to supplement theoretical concepts with practical applications, preparing learners for careers in automation, robotics, and intelligent systems. The curriculum is built around three core pillars – Robotics, Computer Vision, and AI – each offering focused, hands-on teaching materials and exercises that deepen students' technical skills. Separating the curriculum into these three pillars adds flexibility for both instructors and students. In many bachelor’s and master’s programs, courses focus exclusively on one domain – robotics, vision, or AI – and only recently are programs beginning to integrate topics across two or even all three fields. By maintaining a modular design, the curriculum supports two main objectives: (1) encouraging faculty to design elective courses that integrate multiple pillars for a more interdisciplinary, project-based learning experience, and (2) allowing individual modules to be used in courses that concentrate on one or two pillars, where the remaining content can be “fixed” or “preset” for instructors looking to focus primarily on robotics, vision, or AI. In particular, the objectives regarding each one of the three pillars are:

- Robotics: This module covers essential robotic concepts related to modeling, kinematics, differential kinematics, dynamics, and control for serial manipulators. It will include topics such as DH
parameter computation, forward and inverse kinematics (both closed-form and iterative), trajectory planning, geometric and analytic Jacobians, singularities, redundancy, and dynamic modeling using
Lagrange and Newton-Euler methods, as well as decentralized motion control. All concepts will be illustrated in simulation on a UR3 robotic arm using MATLAB, utilizing the Symbolic Math Toolbox
and Simulink, and some exercises will be prepared to run on physical UR3 robots, utilizing the Universal Robots UR Series Manipulators Support from the Robotics System Toolbox.

- Computer Vision: This module focuses on object detection and recognition using pretrained models, specifically YOLOv8. Key concepts include creating datasets for training, applying data
augmentation, transfer learning, and the training and validation of deep learning models. The goal is to use MATLAB's current transfer learning framework within the Deep Learning Toolbox,
integrating it with the YOLOv8 architecture (already implemented in MATLAB; refer to this git repository). Students will work with the developed teaching materials, mainly MATLAB live or .m
scripts, to annotate objects in images by defining bounding boxes, apply data augmentation techniques, such as geometric transformations (rotations, translations, and dilations), and train and
validate new objects via transfer learning (YOLOv8 is already pretrained on the COCO dataset). These curriculum materials enable students to train YOLO on new objects and obtain their bounding
boxes, facilitating object manipulation by the Universal Robots robots. In addition, a calibration script will be developed to convert detected object positions in images into spatial coordinates based on the lab’s existing cameras, ensuring smooth communication between the computer vision and robotics modules within MATLAB. 

- Artificial Intelligence: This module focuses on robotic task planning using Q-learning and Deep Q-learning, two UPC - BarcelonaTech model-free algorithms in Reinforcement Learning (RL). Key
concepts covered include the STRIPS language (modeling pre- and post-conditions of robotic actions), task planning, and Q-learning algorithms. The goal is to create curricular materials in the
form of MATLAB live or .m scripts, utilizing the existing implementation of these reinforcement learning algorithms in MATLAB’s Reinforcement Learning Toolbox. The current implementation of
these algorithms is expected to support robotic task planning directly. However, if the algorithms do not account for action preconditions to reduce the number of possible actions in a given state,
modifications may be necessary. In such a case, a customized version of the algorithm will be developed with minor adjustments to enable action pruning for each state. The developed materials
will take as input a primary robotic task, defined by the user and based on objects detected by the computer vision module, and output a sequence of ordered primitive tasks. When executed by the
robot, these tasks achieve the main objective. The sequence is then sent to the robotics module, which designs and executes the required trajectories to complete each task. This enables students
to apply advanced techniques to optimize task sequencing and decision-making in robotics.


## Goals
- Develop curriculum materials in the form of MATLAB live scripts or .m scripts (the latest version of .m scripts includes new features that make them more similar to live scripts), and Simulink models for programming, simulating and controlling UR3 robotic arms, covering kinematics, dynamics, and motion control using the Symbolic Math Toolbox, Simulink, the Universal Robots UR Series
Manipulators Support from the Robotics System Toolbox. These curriculum materials will be developed in English, Spanish, and Catalan to accommodate the different course languages.
- Integrate YOLOv8 into the MATLAB’s transfer learning framework of the Deep Learning Toolbox for customizable object detection, enabling a smooth communication with the robotics module.
- Implement Q-learning and Deep Q-learning for task planning using the Reinforcement Learning Toolbox, generating optimized task sequences for robotic execution. 
- Develop a modular set of demos and tutorials to equip students with skills in robotics, computer vision, and/or AI. 5. Publish a teaching innovation journal or conference paper, create repository
documentation, and develop supporting materials for course adoption, as well as other promotional material such as YouTube videos.