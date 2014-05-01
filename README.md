SimulatorPrototype
==================

Install Prototype:

1.) At the moment the easiest way is to use Ubuntu 12.04. Install a corresponding version

2.) Make sure that Apache and PHP5 are installed correctly

3.) Install ROS Hydro. Follow the instructions here: http://wiki.ros.org/hydro/Installation/Ubuntu

4.) Install NEST. Follow the instructions here: http://www.nest-initiative.org/Software:Installation

5.) Install Cython: sudo apt-get install cython

5.) In order to upload files > 2MB Apache settings have to be changed
      - Edit the file /etc/php5/apache2/php.ini 
      - Change the parameters upload_max_filesize and post_max_size to a big value e.g. 500000
      
7.) Restart the Apache server

8.) Check put the prototype from github: git clone https://github.com/ozweigle/SimulatorPrototype.git

9.) Create a symbolic link /var/www/SimulatorPrototype to GIT_INSTALL_DIR/SimulatorPrototype/webinterface

10.) Test the Apache server. Go to http://SERVER_IP/SimulatorPrototype/

11.) You should see the SimulatorPrototype Page now

12.) Install rosbridge and rosapi:
      - sudo apt-get install ros-hydro-rosbridge-server
      - sudo apt-get install ros-hydro-rosbridge-suite
      - sudo apt-get install ros-hydro-rosapi
      
13.) add the following lines to your .bashrc:
      - source /GIT_INSTALL_DIR/SimulatorPrototype/ros_ws/devel/setup.bash
      - export PYTHONPATH=/GIT_INSTALL_DIR/SimulatorPrototype/nest_extensions/py_modules:$PYTHONPATH
      
14.) Build the rosnodes. Go to /GIT_INSTALL_DIR/SimulatorPrototype/ros_ws/ and run catkin_make

15.) Run the following launch file to start the system: roslaunch system_starter system_starter.launch

16.) The system can now be used...


System Usage:

1.) Go to http://YOUR_MACHINE_IP/SimulatorPrototype

2.) Type YOUR_MACHINE_IP in the field SERVER and press connect

3.) If everything is running properly the message "Connected to ROS YOUR_MACHINE_IP" must be visible

4.) In the directory data, some example models can be found 

5.) Upload a Brain Model from data/nest_models

6.) Upload an Environment Model from data/env_models

7.) Upload a Transfer Function from data/trans_funcs

8.) Press the Simulate Button

9.) A window with the Simulator stage should show up and the robot should move
