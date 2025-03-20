# From Code to Robot: Computer vision

This module focuses on object detection and recognition using pretrained models, specifically YOLOv8. Key concepts include creating datasets for training, applying data
augmentation, transfer learning, and the training and validation of deep learning models. The goal is to use MATLAB's current transfer learning framework within the Deep Learning Toolbox,
integrating it with the YOLOv8 architecture (already implemented in MATLAB; refer to this git repository). Students will work with the developed teaching materials, mainly MATLAB live or .m
scripts, to annotate objects in images by defining bounding boxes, apply data augmentation techniques, such as geometric transformations (rotations, translations, and dilations), and train and
validate new objects via transfer learning (YOLOv8 is already pretrained on the COCO dataset). These curriculum materials enable students to train YOLO on new objects and obtain their bounding
boxes, facilitating object manipulation by the Universal Robots robots. In addition, a calibration script will be developed to convert detected object positions in images into spatial coordinates based on the lab’s existing cameras, ensuring smooth communication between the computer vision and robotics modules within MATLAB. 
