# From Code To Robot

<span style="font-size:24px;"><strong><em>A hands-on curriculum for robotics, computer vision, and AI using MATLAB and UR robots</em></strong></span>

![](images/logos.svg)

**Code**: [https://github.com/iocroblab/from_code_to_robot.git](https://github.com/iocroblab/from_code_to_robot.git)

## Contents

- [Overview](#overview)
    - [General Objective](#general-objective)
    - [Project Goals](#project-goals)
    - [Target Audience](#target-audience)
    - [Key Features](#key-features)
    - [Educational Flexibility](#educational-flexibility)
- [Main Learning Outcomes](#main-learning-outcomes)
- [Curriculum Structure](#curriculum-structure)
    - [Robotics](#robotics)
    - [Computer Vision](#computer-vision)
    - [Artificial Intelligence](#artificial-intelligence)
- [Software Requirements](#software-requirements)
- [Credits](#credits)
- [About](#about)


# Overview

**From Code to Robot** is an open, modular, and hands-on curriculum designed to teach the foundations of:

- 🤖 Robotics  
- 👁️ Computer Vision  
- 🧠 Artificial Intelligence  

using **MATLAB** and **Universal Robots (UR)** manipulators.

The project combines theory with practical experimentation through simulation, real robotic platforms, and executable MATLAB scripts. It is intended for undergraduate and graduate courses in:

- Industrial Engineering  
- Robotics  
- Computer Science  
- Automation and Control  
- Artificial Intelligence  

The curriculum is organized as a flexible collection of tutorials, demos, exercises, and projects that instructors can easily adapt to different courses and academic levels.


## General Objective

Provide students with a practical and interdisciplinary framework to design, simulate, perceive, plan, and execute robotic tasks using modern tools in robotics, computer vision, and artificial intelligence.

The curriculum bridges the gap between theory and real robotic applications through reproducible hands-on exercises using MATLAB and UR robots.

## Project Goals

- Develop open teaching materials for robotics education
- Promote interdisciplinary learning across robotics, vision, and AI
- Facilitate adoption of practical robotics courses
- Support experimentation with industrial robotic platforms
- Publish teaching innovation and educational research outcomes
- Provide reusable tutorials, demos, and documentation

## Target Audience

- Engineering students
- Robotics researchers
- Educators and instructors
- AI and computer vision practitioners
- Laboratories introducing hands-on robotics education


## Key Features

✅ Hands-on and project-based learning  
✅ Modular curriculum adaptable to many courses  
✅ Integration of Robotics + Vision + AI  
✅ MATLAB-centered workflow  
✅ Simulation and real robot execution  
✅ Open educational resources  
✅ Materials available in:
    - English
    - Spanish
    - Catalan

## Educational Flexibility

The curriculum is intentionally modular.

It can be used:

- As a complete interdisciplinary robotics course
- As independent modules in robotics, vision, or AI courses
- In undergraduate or master-level programs
- In laboratory sessions, projects, or tutorials

This flexibility allows instructors to adapt the materials to their own teaching objectives and course structures.


---


# Main Learning Outcomes

After completing the curriculum, students will be able to:

- Model and control robotic manipulators
- Solve forward and inverse kinematics problems
- Plan trajectories and analyze robot motion
- Understand robot dynamics and decentralized control
- Train and validate object detection models using YOLOv8
- Build datasets and apply data augmentation techniques
- Integrate perception with robotic manipulation
- Implement robotic task planning using Reinforcement Learning
- Design intelligent robotic behaviors using Q-learning and Deep Q-learning
- Connect AI decision-making with robot execution
- Develop complete robotics pipelines from perception to action

---

# Curriculum Structure

The curriculum is organized into three interconnected pillars.

---

## Robotics

This module introduces the foundations of robotic manipulators through MATLAB simulations and experiments with UR robots.

### Topics Covered

- DH parameter modeling
- Forward and inverse kinematics
- Differential kinematics and Jacobians
- Singularities and redundancy
- Trajectory planning
- Dynamic modeling
- Motion control
- Simulation with Simulink

### Practical Components

- MATLAB live scripts 
- Symbolic Math Toolbox
- Robotics System Toolbox
- Simulink models
- UR3 simulations using:
    - docker-based reproducible ROS 2 Jazzy environment.
- Real robot experiments using:
    - Universal Robots Support Package

### Learning Outcomes

Students learn how to mathematically model, simulate, and control industrial robotic manipulators in realistic scenarios.

---

## Computer Vision

This module focuses on object detection and robotic perception using deep learning techniques.

### Topics Covered

- YOLOv8 object detection
- Dataset generation and annotation
- Bounding box labeling
- Data augmentation
- Transfer learning
- Model training and validation
- Camera calibration
- Vision-to-robot coordinate transformation

### Practical Components

- MATLAB Deep Learning Toolbox
- Transfer learning with pretrained YOLOv8 models
- Integration with robotic manipulation tasks
- Detection of custom objects for robot interaction

### Learning Outcomes

Students learn how to train vision systems capable of detecting objects and providing spatial information for robotic manipulation.

---

## Artificial Intelligence

This module introduces robotic task planning using Reinforcement Learning techniques.

### Topics Covered

- STRIPS representations
- Task planning
- Q-learning
- Deep Q-learning
- Sequential decision-making
- Action pruning
- Intelligent robotic behaviors

### Practical Components

- MATLAB Reinforcement Learning Toolbox
- Planning pipelines connected to robot execution
- AI-driven task sequencing
- Integration with robotics and computer vision modules

### Learning Outcomes

Students learn how robots can autonomously make decisions, optimize task execution, and plan complex behaviors.

---

# Software Requirements 

The curriculum is based on MATLAB and several MathWorks toolboxes for robotics, computer vision, and artificial intelligence.

## Recommended Software

- MATLAB (recommended version: R2025a or R2025b)
- Simulink

## MATLAB Toolboxes

- Robotics System Toolbox
- Symbolic Math Toolbox
- Deep Learning Toolbox
- Reinforcement Learning Toolbox
- Computer Vision Toolbox
- Image Processing Toolbox

## Suggested Hardware

- Universal Robots UR3 / UR5 manipulators
- RGB camera



---

# Credits

**From Code to Robot** is a project developed at the Universitat Politècnica de Catalunya and funded by MathWorks and Universal Robots.

## Developers

1. **Robotics**

    - Constantin Sul (Universitat Politècnica de Catalunya)
    - Prof. Jan Rosell (Universitat Politècnica de Catalunya)

2. **Computer Vision and Artificial Intelligence**

    - Noel Nathan Planell (Universitat Politècnica de Catalunya)
    - Prof. Isiah Zaplana (Universitat Politècnica de Catalunya)

## Advisors

- Jennifer Gago (MathWorks)
- Carlos Pérez (Universal Robots)

---

# About

**Current Version**: 0.0.1

# Examples

Manipulability ellipsoid

<!--  ![image_0.gif](robotics/Videos_media/image_0.gif) -->

<div style="text-align:center;">
  <img src="robotics/Videos_media/image_0.gif"
       style="width:100%; max-width:600px;">
</div>


Torque control

<!-- ![image_1.gif](robotics/Videos_media/image_1.gif) -->

<div style="text-align:center;">
  <img src="robotics/Videos_media/image_1.gif"
       style="width:100%; max-width:600px;">
</div>


