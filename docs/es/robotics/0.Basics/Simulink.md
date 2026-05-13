
# Simulink 
# How to add Blocks 

In Simulink double click on an empty field and search for the block you want to insert in your plant.  


![image_0.png](Simulink_media/image_0.png)


Alternatively you can brows the block library. Navigate to the Simulation tab and click Library Browser. 


![image_1.png](Simulink_media/image_1.png)


The browser will open from where you can drag the desired blocks into your plant. 

![image_2.png](Simulink_media/image_2.png)
# Connect Blocks

To connect Blocks simply select the signal wire or block output and the desired block input. 


![image_3.gif](Simulink_media/image_3.gif)

# Format Blocks

You can change the appearance of blocks by formatting them. 

-  Right click on a block and expand the Format tab. From here you are able to rotate or flip the block.  
-  You can change the size of a block by dragging one of its corners.  

# Format Plant

You can select a section of your model and drag it to create more space, the signal lines will stay intact and extend/retract. 


You can drag the signal lines to make the plant easier to read. 


![image_4.gif](Simulink_media/image_4.gif)

# Tools and Blocks to use

In Simulink you can use a variety of differnt blocks to achieve your desired behaviour. Below we will introduce a few blocks that you can use to solve the exercises of this Curriculum. (Alternative solutions are not wrong!)

### Constant

Constant lets you insert a numeric scalar or array, which you can also load from your workspace. 


![image_5.gif](Simulink_media/image_5.gif)

### Sum

The Sum block lets you add or subtract signals from one another. By changing the settings inside the block you can increase the amount of signals to be processed. By adding a | you can change the positions of inputs. 


![image_6.gif](Simulink_media/image_6.gif)

### Scope

The scope block lets you visualize your signal trajectories. Click above or below an input to create an additional signal input. You can delete it by selecting the input and pressing "del"


![image_7.gif](Simulink_media/image_7.gif)

### Matrix Multiply

To multiply matrices (matrix as an input). Can also be used to multiply a matrix with a vector. 


![image_8.png](Simulink_media/image_8.png)

### Gain

Has a static gain. Can be loaded from the workspace via a variable name. 


Allows scalar valus and matrices as gain. 


Select a desired Multiplication option for your application. 


![image_9.png](Simulink_media/image_9.png)

### MatlabFunction

Allows to use code inside of simulink. Define inputs and outputs in the function declaration. 


![image_10.png](Simulink_media/image_10.png)

### Saturation

This block is used to limit a signal. Define the upper and lower allowed limit. 


Can take a vector as the limits (corresponding to the input vector size) 


![image_11.png](Simulink_media/image_11.png)

### Mux/Demux

Mux and Demux blocks can be used to seperate or combine signals into a vector. 


![image_12.png](Simulink_media/image_12.png)

# Run a Simulation 

Navigate to the Simulation section. You will see under the tab SIMULATE. 


![image_13.png](Simulink_media/image_13.png)


To run a simulation you must first set the desired simulation length. 


![image_14.png](Simulink_media/image_14.png)


Set a positive number or inf for a continious execution. 


To start the Simulation press Run 


![image_15.png](Simulink_media/image_15.png)


You can also simulate step by step by pressing the Step Forward button. However this is more useful in offline applications. 


![image_16.png](Simulink_media/image_16.png)


Once running you can pause or stop the simulation by pressing: 


![image_17.png](Simulink_media/image_17.png)


