from launch import LaunchDescription
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution, TextSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import (
    LogInfo,
    Shutdown,
)

def generate_launch_description():

    # General arguments
    description_package = LaunchConfiguration("description_package", default='urdf_tutorial')
    description_file = LaunchConfiguration("description_file", default='pan_tilt.xacro')
    
    launch_rviz = LaunchConfiguration("launch_rviz", default='true')
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("urdf_tutorial"), "rviz", "display_urdf.rviz"]
    )

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [FindPackageShare(description_package), "urdf", description_file]
            )
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[{"use_sim_time": False}, robot_description],
    )

    joint_state_publisher_gui = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        name="joint_state_publisher_gui",
        output="screen",
        #on_exit=Shutdown(), #???
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        condition=IfCondition(launch_rviz),
        on_exit=Shutdown(),
    )

    log_robot_description = LogInfo(
            msg=robot_description.get("robot_description"),
    )

    # Description
    ld =  LaunchDescription()

    ld.add_action(robot_state_publisher_node)
    ld.add_action(joint_state_publisher_gui)
    ld.add_action(rviz_node)
    ld.add_action(log_robot_description)    

    return ld