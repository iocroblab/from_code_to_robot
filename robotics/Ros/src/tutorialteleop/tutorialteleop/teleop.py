#!/usr/bin/env python3
import sys
import threading
import shutil
import termios
import tty
import time
from typing import Dict, List, Optional

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from geometry_msgs.msg import Twist
from std_msgs.msg import String

# ---------- terminal helpers (fixed-width panel) ----------
CSI = "\x1b["
PANEL_WIDTH = 50  # fixed; ensure your terminal is >= this

def _cursor_hide(): sys.stdout.write(CSI + "?25l"); sys.stdout.flush()
def _cursor_show(): sys.stdout.write(CSI + "?25h"); sys.stdout.flush()
def _move_to(row: int, col: int = 1): sys.stdout.write(f"{CSI}{row};{col}H")
def _clear_line(): sys.stdout.write(CSI + "2K")
def _save(): sys.stdout.write("\x1b7")
def _restore(): sys.stdout.write("\x1b8")

class BottomPanel:
    def __init__(self):
        self.rows, self.cols = shutil.get_terminal_size((24, 80))
        self.enabled = sys.stdout.isatty()
        if self.enabled: _cursor_hide()
        self.mode = "Linear"
        self.frame = "Base"

    def _header(self) -> List[str]:
        bar = "-" * PANEL_WIDTH
        line1 = " Teleoperation | Q/ESC: quit "
        line2 = f" Mode: {self.mode} | Frame: {self.frame}"
        return [bar, line1[:PANEL_WIDTH].ljust(PANEL_WIDTH),
                line2[:PANEL_WIDTH].ljust(PANEL_WIDTH), bar]

    def _map_block(self) -> List[str]:
        if self.mode == "Linear":
            w, s, a, d, sp, mn = "+X", "-X", "-Y", "+Y", "+Z", "-Z"
        else:
            w, s, a, d, sp, mn = "+RotX", "-RotX", "-RotY", "+RotY", "+RotZ", "-RotZ"
        body = [
            "",
            "                [ W ]           -> " + w,
            "         [ A ]         [ D ]    -> " + f"{a} / {d}",
            "                [ S ]           -> " + s,
            "",
            "    [ SPACE ]  -> " + f"{sp:<6}",
            "    [  -  ]    -> " + mn,
            "",
            "   Keys:  TAB toggle mode (Linear >-> Rotation)",
            "          M toggle ref frame (Base <-> EndEffector)",
            "          SHIFT x2 speed (uppercase WASD; '+' fast +Z, '_' fast -Z)",
        ]
        return [ln[:PANEL_WIDTH].ljust(PANEL_WIDTH) for ln in body]

    def draw(self):
        if not self.enabled: return
        block = self._header() + self._map_block() + ["-" * PANEL_WIDTH]
        self.rows, _ = shutil.get_terminal_size((24, 80))
        top_row = max(1, self.rows - len(block) + 1)
        _save()
        row = top_row
        for ln in block:
            _move_to(row, 1); _clear_line(); sys.stdout.write(ln + "\n"); row += 1
        sys.stdout.flush()
        _restore()

    def restore(self):
        if self.enabled: _cursor_show()

# ---------- raw TTY helpers ----------
def _save_tty():
    if sys.platform == 'win32': return None
    return termios.tcgetattr(sys.stdin)

def _restore_tty(settings):
    if sys.platform != 'win32' and settings is not None:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

def _read_key(settings) -> str:
    tty.setraw(sys.stdin.fileno())
    try:
        ch = sys.stdin.read(1)  # returns a single-character string
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return ch

# ---------- teleop logic ----------
class TutorialTeleop(Node):
    def __init__(self):
        super().__init__('tutorial_teleop')

        # Params
        self.declare_parameter('linear_speed', 0.2)
        self.declare_parameter('angular_speed', 1.0)
        self.declare_parameter('publish_rate_hz', 50.0)
        self.declare_parameter('topic', 'cmd_vel')
        # Window to keep a key "active" between OS repeats (prevents mid-hold zeros)
        self.declare_parameter('hold_window_sec', 0.25)

        self.linear_speed = float(self.get_parameter('linear_speed').value)
        self.angular_speed = float(self.get_parameter('angular_speed').value)
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)
        self.hold_window = float(self.get_parameter('hold_window_sec').value)
        topic = str(self.get_parameter('topic').value)

        # Publishers
        self.cmd_pub = self.create_publisher(Twist, topic, 10)
        mode_qos = QoSProfile(depth=1,
                              reliability=ReliabilityPolicy.RELIABLE,
                              durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.mode_pub = self.create_publisher(String, 'teleop_mode', mode_qos)

        # State
        self.mode_rotation = False     # False=Linear, True=Rotation
        self.ref_frame_is_ee = False   # False=Base, True=EndEffector

        # Active directions with expiry timestamps (now + hold_window)
        # tokens: 'x+','x-','y+','y-','z+','z-'
        self._active: Dict[str, float] = {}
        self._boost_until = 0.0  # time until which boost (shift) is active
        self._quit = False
        self._lock = threading.Lock()

        # Panel
        self._panel = BottomPanel()
        self._panel.draw()

        # TTY reader thread
        self._tty_settings = _save_tty()
        self._reader = threading.Thread(target=self._reader_loop, daemon=True)
        self._reader.start()

        # Timer publish loop
        self.timer = self.create_timer(1.0 / self.publish_rate_hz, self._tick)

        # Initial teleop_mode
        self._publish_ref_frame()

    # ---- helpers ----
    def _mode_str(self) -> str:
        return "Rotation" if self.mode_rotation else "Linear"
    def _frame_str(self) -> str:
        return "EndEffector" if self.ref_frame_is_ee else "Base"
    def _publish_ref_frame(self):
        self.mode_pub.publish(String(data=self._frame_str()))

    # ---- key reader ----
    def _reader_loop(self):
        try:
            while not self._quit and rclpy.ok():
                ch = _read_key(self._tty_settings)
                if not ch: continue
                self._handle_key(ch)
        except Exception:
            self._quit = True

    def _handle_key(self, ch: str):
        now = time.monotonic()
        # Toggles
        if ch == '\t':  # TAB
            self.mode_rotation = not self.mode_rotation
            self._panel.mode = self._mode_str()
            self._panel.draw()
            return
        if ch.lower() == 'm':
            self.ref_frame_is_ee = not self.ref_frame_is_ee
            self._panel.frame = self._frame_str()
            self._publish_ref_frame()
            self._panel.draw()
            return
        if ch in ('\x1b', 'q'):  # ESC or q
            self._quit = True
            return

        # Movement keys -> set/refresh active tokens with expiry
        boost_here = False
        token: Optional[str] = None

        # WASD (uppercase implies boost)
        if ch.lower() in ('w','a','s','d'):
            token = {'w':'x+','s':'x-','a':'y-','d':'y+'}[ch.lower()]
            boost_here = ch.isupper()

        # Z axis:
        if ch == ' ':
            token = 'z+'            # space = +Z (normal speed)
        elif ch == '-':
            token = 'z-'            # minus = -Z (normal speed)
        elif ch == '+':
            token = 'z+'; boost_here = True  # SHIFT+'=' -> '+': fast +Z
        elif ch == '_':
            token = 'z-'; boost_here = True  # SHIFT+'-' -> '_': fast -Z

        if token:
            with self._lock:
                self._active[token] = now + self.hold_window
                if boost_here:
                    self._boost_until = max(self._boost_until, now + self.hold_window)
            return

        # Any other key clears all (optional; comment out to ignore)
        # with self._lock:
        #     self._active.clear()
        #     self._boost_until = 0.0

    # ---- publish loop ----
    def _tick(self):
        if self._quit:
            rclpy.shutdown()
            return

        now = time.monotonic()
        with self._lock:
            # drop expired directions
            expired = [k for k, t in self._active.items() if t < now]
            for k in expired:
                self._active.pop(k, None)
            boost_active = now < self._boost_until
            active = set(self._active.keys())

        # speed selection
        mult = 2.0 if boost_active else 1.0
        lin = self.linear_speed * mult
        ang = self.angular_speed * mult

        # build twist from active tokens (simultaneous supported)
        lx = ly = lz = rx = ry = rz = 0.0
        if not self.mode_rotation:
            if 'x+' in active: lx += lin
            if 'x-' in active: lx -= lin
            if 'y+' in active: ly += lin
            if 'y-' in active: ly -= lin
            if 'z+' in active: lz += lin
            if 'z-' in active: lz -= lin
        else:
            if 'x+' in active: rx += ang
            if 'x-' in active: rx -= ang
            if 'y+' in active: ry += ang
            if 'y-' in active: ry -= ang
            if 'z+' in active: rz += ang
            if 'z-' in active: rz -= ang

        twist = Twist()
        twist.linear.x, twist.linear.y, twist.linear.z = lx, ly, lz
        twist.angular.x, twist.angular.y, twist.angular.z = rx, ry, rz

        # publish
        self.cmd_pub.publish(twist)
        self._publish_ref_frame()

    def destroy_node(self):
        try:
            self._quit = True
        except Exception:
            pass
        _restore_tty(_save_tty())  # best-effort restore
        self._panel.restore()
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
