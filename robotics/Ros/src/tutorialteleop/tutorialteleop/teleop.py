#!/usr/bin/env python3
import sys
import threading
import shutil
import termios
from typing import Set, List, Optional

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from geometry_msgs.msg import Twist
from std_msgs.msg import String

from pynput import keyboard
from pynput.keyboard import Key, KeyCode

# ---------- terminal helpers (fixed-width panel) ----------
CSI = "\x1b["

PANEL_WIDTH = 80  # fixed; ensure your terminal is >= 80 cols

def _cursor_hide(): sys.stdout.write(CSI + "?25l"); sys.stdout.flush()
def _cursor_show(): sys.stdout.write(CSI + "?25h"); sys.stdout.flush()
def _move_to(row: int, col: int = 1): sys.stdout.write(f"{CSI}{row};{col}H")
def _clear_line(): sys.stdout.write(CSI + "2K")
def _save(): sys.stdout.write("\x1b7")
def _restore(): sys.stdout.write("\x1b8")

class _NoEcho:
    """Disable echo locally in this TTY (like teleop_twist_keyboard)."""
    def __init__(self):
        self.fd = None
        self.old = None
        try:
            self.fd = sys.stdin.fileno()
            self.old = termios.tcgetattr(self.fd)
            new = termios.tcgetattr(self.fd)
            new[3] &= ~termios.ECHO
            termios.tcsetattr(self.fd, termios.TCSADRAIN, new)
        except Exception:
            self.fd = None
            self.old = None
    def restore(self):
        if self.fd is not None and self.old is not None:
            try:
                termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old)
            except Exception:
                pass

class BottomPanel:
    """Always draw the same 80-col mapping at the bottom; no adaptive layout."""
    def __init__(self):
        self.rows, self.cols = shutil.get_terminal_size((24, 80))
        self.last_mode = None
        self.last_frame = None
        self.enabled = sys.stdout.isatty()
        if self.enabled:
            _cursor_hide()

    def _header(self, mode: str, frame: str) -> List[str]:
        bar = "-" * PANEL_WIDTH
        line = f" Teleoperation | Mode: {mode} | Frame: {frame} | Q/ESC: quit "
        return [bar, line[:PANEL_WIDTH].ljust(PANEL_WIDTH), bar]

    def _map_block(self, mode: str) -> List[str]:
        # Current action labels
        if mode == "Linear":
            w, s, a, d, sp, ct = "+X", "-X", "-Y", "+Y", "+Z", "-Z"
        else:
            w, s, a, d, sp, ct = "+RotX", "-RotX", "-RotY", "+RotY", "+RotZ", "-RotZ"

        body = [
            "",
            "                [ W ]           -> " + f"{w}",
            "         [ A ]         [ D ]    -> " + f"{a} / {d}",
            "                [ S ]           -> " +  f"{s} ",
            "",
            "    [ SPACE ]  -> " + f"{sp:<6}",
            "    [ CTRL ]   -> " + f"{ct}",
            "",
            "   Keys:  TAB toggle mode (Linear >-> Rotation)",
            "          M toggle ref frame (Base <-> EndEffector)",
            "          SHIFT hold: x2 speed",
        ]
        # pad/truncate to panel width
        return [ln[:PANEL_WIDTH].ljust(PANEL_WIDTH) for ln in body]

    def _compose(self, mode: str, frame: str) -> List[str]:
        lines = self._header(mode, frame) + self._map_block(mode) + ["-" * PANEL_WIDTH]
        return lines

    def draw(self, mode: str, frame: str):
        if not self.enabled:
            return
        self.last_mode, self.last_frame = mode, frame
        block = self._compose(mode, frame)

        # place the block at the bottom
        self.rows, _ = shutil.get_terminal_size((24, 80))
        top_row = max(1, self.rows - len(block) + 1)

        _save()
        row = top_row
        for ln in block:
            _move_to(row, 1)
            _clear_line()
            sys.stdout.write(ln + "\n")
            row += 1
        sys.stdout.flush()
        _restore()

    def restore(self):
        if self.enabled:
            _cursor_show()

# ---------- key canonicalization ----------
SHIFT_KEYS = {k for k in (getattr(Key, n, None) for n in ('shift', 'shift_l', 'shift_r')) if k}
CTRL_KEYS  = {k for k in (getattr(Key, n, None) for n in ('ctrl', 'ctrl_l', 'ctrl_r')) if k}

def _to_token(key: object) -> Optional[str]:
    """Map pynput Key/KeyCode to stable tokens so press/release always match."""
    if key in SHIFT_KEYS:
        return "shift"
    if key in CTRL_KEYS:
        return "ctrl"
    if key == Key.space:
        return "space"
    if key == Key.tab:
        return "tab"
    if key == Key.esc:
        return "esc"
    if isinstance(key, KeyCode) and key.char:
        return key.char.lower()
    return None

# ---------- teleop logic ----------
class TutorialTeleop(Node):
    def __init__(self):
        super().__init__('tutorial_teleop')

        # Params
        self.declare_parameter('linear_speed', 0.2)
        self.declare_parameter('angular_speed', 1.0)
        self.declare_parameter('publish_rate_hz', 50.0)
        self.declare_parameter('topic', 'cmd_vel')

        self.linear_speed = float(self.get_parameter('linear_speed').value)
        self.angular_speed = float(self.get_parameter('angular_speed').value)
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)
        topic = str(self.get_parameter('topic').value)

        # Pubs
        self.cmd_pub = self.create_publisher(Twist, topic, 10)
        mode_qos = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL
        )
        self.mode_pub = self.create_publisher(String, 'teleop_mode', mode_qos)

        # State
        self.mode_rotation = False       # False=Linear, True=Rotation
        self.ref_frame_is_ee = False     # False=Base, True=EndEffector

        # Terminal behavior (local only)
        self._noecho = _NoEcho()
        self._panel = BottomPanel()
        self._panel.draw(self._mode_str(), self._frame_str())

        # Input handling (canonical token set)
        self._pressed: Set[str] = set()
        self._lock = threading.Lock()
        self._quit = False

        # Do NOT suppress globally; don't block other panes
        self._listener = keyboard.Listener(
            on_press=self._on_press,
            on_release=self._on_release,
            suppress=False
        )
        self._listener.start()

        # Timer loop
        self.timer = self.create_timer(1.0 / self.publish_rate_hz, self._tick)

        # Initial teleop_mode (latched)
        self._publish_ref_frame()

    # --- helpers ---
    def _mode_str(self) -> str:
        return "Rotation" if self.mode_rotation else "Linear"
    def _frame_str(self) -> str:
        return "EndEffector" if self.ref_frame_is_ee else "Base"
    def _publish_ref_frame(self):
        self.mode_pub.publish(String(data=self._frame_str()))

    # --- keyboard callbacks ---
    def _on_press(self, key):
        tok = _to_token(key)
        if tok is None:
            return
        try:
            with self._lock:
                self._pressed.add(tok)

            if tok == 'tab':
                self.mode_rotation = not self.mode_rotation
                self._panel.draw(self._mode_str(), self._frame_str())  # full redraw
            elif tok == 'm':
                self.ref_frame_is_ee = not self.ref_frame_is_ee
                self._publish_ref_frame()
                self._panel.draw(self._mode_str(), self._frame_str())  # full redraw
            elif tok == 'esc' or tok == 'q':
                self._quit = True
            elif tok in ('h', '?'):
                self._panel.draw(self._mode_str(), self._frame_str())  # redraw on demand
        except Exception:
            pass

    def _on_release(self, key):
        tok = _to_token(key)
        if tok is None:
            return
        try:
            with self._lock:
                self._pressed.discard(tok)
        except Exception:
            pass

    # --- main loop ---
    def _tick(self):
        if self._quit:
            rclpy.shutdown()
            return

        with self._lock:
            keys = set(self._pressed)

        # Direction keys
        w = 'w' in keys; a = 'a' in keys; s = 's' in keys; d = 'd' in keys
        space = 'space' in keys
        ctrl = 'ctrl' in keys
        shift = 'shift' in keys

        # speed multiplier with SHIFT
        mult = 2.0 if shift else 1.0
        lin = self.linear_speed * mult
        ang = self.angular_speed * mult

        twist = Twist()
        if not self.mode_rotation:
            twist.linear.x = (+lin if w else 0.0) + (-lin if s else 0.0)
            twist.linear.y = (-lin if a else 0.0) + (+lin if d else 0.0)
            twist.linear.z = (+lin if space else 0.0) + (-lin if ctrl else 0.0)
        else:
            twist.angular.x = (+ang if w else 0.0) + (-ang if s else 0.0)
            twist.angular.y = (-ang if a else 0.0) + (+ang if d else 0.0)
            twist.angular.z = (+ang if space else 0.0) + (-ang if ctrl else 0.0)

        self.cmd_pub.publish(twist)

    def destroy_node(self):
        try:
            if self._listener: self._listener.stop()
        except Exception:
            pass
        self._panel.restore()
        self._noecho.restore()
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
