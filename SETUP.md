# Packages and their versions
## ROS2:

* Ros2 version: galactic-geochelone
* rosbridge-server using ` sudo apt install ros-galactic-rosbridge-server `

```bash
#orderGenerator
colcon build
source install/setup.bash
ros2 run accio_task OrderGenNode
```

```bash
#spawner
colcon build
source install/setup.bash
ros2 run accio_task_python spawn
```

It makes me sad to not even have launch files here.
## Node:

**NOTE: Build and source ROS2 before installing react package dependencies**

```bash
#backend
cd accio_web_interface
npm start
```

```bash
#frontend
cd accio_web_interface/client
npm start
```