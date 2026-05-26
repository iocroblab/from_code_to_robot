# From Code to Robot: AI 

This module focuses on robotic task planning using Q-learning and Deep Q-learning, two UPC - BarcelonaTech model-free algorithms in Reinforcement Learning (RL). Key
concepts covered include the STRIPS language (modeling pre- and post-conditions of robotic actions), task planning, and Q-learning algorithms. The goal is to create curricular materials in the
form of MATLAB live or .m scripts, utilizing the existing implementation of these reinforcement learning algorithms in MATLAB’s Reinforcement Learning Toolbox. The current implementation of
these algorithms is expected to support robotic task planning directly. However, if the algorithms do not account for action preconditions to reduce the number of possible actions in a given state,
modifications may be necessary. In such a case, a customized version of the algorithm will be developed with minor adjustments to enable action pruning for each state. The developed materials
will take as input a primary robotic task, defined by the user and based on objects detected by the computer vision module, and output a sequence of ordered primitive tasks. When executed by the
robot, these tasks achieve the main objective. The sequence is then sent to the robotics module, which designs and executes the required trajectories to complete each task. This enables students
to apply advanced techniques to optimize task sequencing and decision-making in robotics.
