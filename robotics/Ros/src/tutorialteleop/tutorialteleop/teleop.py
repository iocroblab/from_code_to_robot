#!/usr/bin/env python3
import threading
from typing import Set

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

from pynput import keyboard
from pynput.keyboard import Key

HELP = """
TutorialTeleop

Keys (work in both modes; TAB toggles the target: Linear ↔ Rotation)
  W:  +X        (Linear: linear.x  | Rotation: angular.x)
  S:  -X
  A:  -Y        (Linear: linear.y  | Rotation: angular.y)
  D:  +Y
  SPACE: +Z     (Linear: linear.z  | Rotation: angular.z)
  CTRL:  -Z

Controls
  TAB: toggle mode (Linear ↔ Rotation)
  H/?: show this help
  Q/ESC: quit

Parameters
  linear_speed (m/s)      default 0.2
  angular_speed (rad/s)   default 1.0
  publish_rate_hz         default 50
  topic                   default "cmd_vel"
  show_help_on_start      default true
"""

def key_char(k):
    return k.char.lower() if isinstance(k, keyboard.KeyCode) and k.char else None

def is_ctrl(k):
    names = ('ctrl', 'ctrl_l', 'ctrl_r')
    return k in {getattr(Key, n) for n in names if hasattr(Key, n)}

class TutorialTeleop(Node):
    def __init__(self):
        super().__init__('tutorial_teleop')

        # Parameters
        self.declare_parameter('linear_speed', 0.2)
        self.declare_parameter('angular_speed', 1.0)
        self.declare_parameter('publish_rate_hz', 50.0)
        self.declare_parameter('topic', 'cmd_vel')
        self.declare_parameter('show_help_on_start', True)

        self.linear_speed = float(self.get_parameter('linear_speed').value)
        self.angular_speed = float(self.get_parameter('angular_speed').value)
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)
        topic = str(self.get_parameter('topic').value)
        show_help = bool(self.get_parameter('show_help_on_start').value)

        self.pub = self.create_publisher(Twist, topic, 10)
        self.mode_rotation = False  # False=Linear, True=Rotation

        self._pressed: Set[object] = set()
        self._lock = threading.Lock()
        self._should_quit = False

        # suppress=True prevents keys from appearing in the terminal
        self._listener = keyboard.Listener(
            on_press=self._on_press,
            on_release=self._on_release,
            suppress=True
        )
        self._listener.start()

        self.get_logger().info(f"Publishing on: {topic}")
        self.get_logger().info("TAB toggles Linear/Rotation. Q/ESC quits.")
        if show_help:
            self.get_logger().info(HELP)

        self.timer = self.create_timer(1.0 / self.publish_rate_hz, self._tick)

    # --- keyboard callbacks ---
    def _on_press(self, key):
        try:
            with self._lock:
                self._pressed.add(key)

            ch = key_char(key)
            if key == Key.tab:
                self.mode_rotation = not self.mode_rotation
                self.get_logger().info(f"[Mode] {'Rotation' if self.mode_rotation else 'Linear'}")
            elif key == Key.esc or ch == 'q':
                self._should_quit = True
            elif ch in ('h', '?'):
                self.get_logger().info(HELP)
        except Exception as e:
            self.get_logger().warn(f"press error: {e}")

    def _on_release(self, key):
        try:
            with self._lock:
                self._pressed.discard(key)
        except Exception as e:
            self.get_logger().warn(f"release error: {e}")

    # --- main loop ---
    def _tick(self):
        if self._should_quit:
            rclpy.shutdown()
            return

        with self._lock:
            keys = set(self._pressed)

        chars = {c for c in (key_char(k) for k in keys) if c}
        w = 'w' in chars
        a = 'a' in chars
        s = 's' in chars
        d = 'd' in chars
        space = Key.space in keys
        ctrl = any(is_ctrl(k) for k in keys)

        twist = Twist()
        lin, ang = self.linear_speed, self.angular_speed

        if not self.mode_rotation:
            twist.linear.x = (+lin if w else 0.0) + (-lin if s else 0.0)
            twist.linear.y = (-lin if a else 0.0) + (+lin if d else 0.0)
            twist.linear.z = (+lin if space else 0.0) + (-lin if ctrl else 0.0)
        else:
            twist.angular.x = (+ang if w else 0.0) + (-ang if s else 0.0)
            twist.angular.y = (-ang if a else 0.0) + (+ang if d else 0.0)
            twist.angular.z = (+ang if space else 0.0) + (-ang if ctrl else 0.0)

        self.pub.publish(twist)

    def destroy_node(self):
        try:
            if self._listener:
                self._listener.stop()
        except Exception:
            pass
        return super().destroy_node()


def main():
    rclpy.init()
    node = TutorialTeleop()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
