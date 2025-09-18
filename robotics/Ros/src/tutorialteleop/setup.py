from setuptools import setup

package_name = 'tutorialteleop'
module_name = 'tutorialteleop'

setup(
    name=package_name,
    version='0.1.0',
    packages=[module_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pynput>=1.7'],
    zip_safe=True,
    author='Your Name',
    author_email='you@example.com',
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='Keyboard teleop node with linear/rotation mode toggle for cmd_vel.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'tutorial_teleop = tutorialteleop.teleop:main',
        ],
    },
)
