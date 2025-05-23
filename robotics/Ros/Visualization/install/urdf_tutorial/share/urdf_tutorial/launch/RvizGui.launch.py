from launch import LaunchDescription
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (
    LogInfo,
    Shutdown,
)


def generate_launch_description():

    prefix = LaunchConfiguration('prefix', default='')


    launch_rviz = LaunchConfiguration('launch_rviz', default='true')



    joint_state_publisher_gui = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        name="joint_state_publisher_gui",
        output="screen",
        on_exit=Shutdown(), #???
    )



    # Description
    ld =  LaunchDescription()

    ld.add_action(joint_state_publisher_gui)

    return ld
