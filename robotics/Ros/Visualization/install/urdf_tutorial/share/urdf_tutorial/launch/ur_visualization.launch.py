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

    # UR description
    # Type/series of used UR robot.
    # choices=["ur3", "ur3e", "ur5", "ur5e", "ur10", "ur10e", "ur16e"]
    ur_type = LaunchConfiguration('ur_type', default='ur3')
    description_package = LaunchConfiguration('description_package', default='ur_description')
    description_file = LaunchConfiguration('description_file', default='ur.urdf.xacro')

    launch_rviz = LaunchConfiguration('launch_rviz', default='true')
    rviz_config_file = PathJoinSubstitution(
        [FindPackageShare("urdf_tutorial"), "rviz", "ur_visualization.rviz"]
    )

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [FindPackageShare(description_package), "urdf", description_file]
            ),
            " ",
            "name:=",
            "ur",
            " ",
            "ur_type:=",
            ur_type,
            " ",
            "prefix:=",
            prefix,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[{"use_sim_time": False}, robot_description],
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
    #ld.add_action(joint_state_publisher_gui)
    ld.add_action(rviz_node)
    ld.add_action(log_robot_description)    

    return ld
