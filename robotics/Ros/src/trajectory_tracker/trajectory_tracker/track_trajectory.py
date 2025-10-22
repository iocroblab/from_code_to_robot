#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from sensor_msgs.msg import PointCloud2, PointField
import tf2_ros
import struct
from rclpy.qos import QoSProfile, QoSDurabilityPolicy

class TrajectoryPublisher(Node):
    def __init__(self):
        super().__init__('trajectory_publisher')
        
        # Parameters
        self.declare_parameter('tracked_frame', 'tool0')
        self.declare_parameter('world_frame', 'world')
        self.declare_parameter('publish_rate', 30.0)
        self.max_points = 200
        
        self.tracked_frame = self.get_parameter('tracked_frame').get_parameter_value().string_value
        self.world_frame = self.get_parameter('world_frame').get_parameter_value().string_value
        self.publish_rate = self.get_parameter('publish_rate').get_parameter_value().double_value
        
        # TF buffer and listener
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # Publisher for PointCloud2
        qos = QoSProfile(depth=1)
        qos.durability = QoSDurabilityPolicy.TRANSIENT_LOCAL  # So RViz sees last cloud
        self.pc_pub = self.create_publisher(PointCloud2, '/trajectory_path_live', qos)
        
        # Storage for positions
        self.positions = []
        
        # Timer
        self.timer = self.create_timer(1.0/self.publish_rate, self.timer_callback)
        self.get_logger().info(f'Trajectory publisher started for frame "{self.tracked_frame}" w.r.t "{self.world_frame}"')
    
    def timer_callback(self):
        try:
            trans: TransformStamped = self.tf_buffer.lookup_transform(
                self.world_frame,
                self.tracked_frame,
                rclpy.time.Time()
            )
            
            # Append new position
            pos = [trans.transform.translation.x,
                   trans.transform.translation.y,
                   trans.transform.translation.z]
            self.positions.append(pos)
            
            # Keep only the last max_points
            if len(self.positions) > self.max_points:
                self.positions.pop(0)
            
            # Publish PointCloud2
            pc_msg = self.create_pointcloud2(self.positions)
            self.pc_pub.publish(pc_msg)
            
        except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
            pass
    
    def create_pointcloud2(self, points):
        """
        Create a PointCloud2 message from a Nx3 list of points.
        Points will be yellow (RGB = 0xFFFF00)
        """
        msg = PointCloud2()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.world_frame
        msg.height = 1
        msg.width = len(points)
        
        msg.fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name='rgb', offset=12, datatype=PointField.UINT32, count=1)
        ]
        msg.is_bigendian = False
        msg.point_step = 16  # 4 floats = 16 bytes
        msg.row_step = msg.point_step * msg.width
        msg.is_dense = True
        
        # Pack data
        data = bytearray()
        yellow_rgb = struct.unpack('I', struct.pack('BBBB', 0, 255, 255, 0))[0]  # RGB = yellow
        for p in points:
            data.extend(struct.pack('fffI', p[0], p[1], p[2], yellow_rgb))
        
        msg.data = data
        return msg


def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
