# Technical Task Report

## My Approach

### 1. ROS2

* **accio_task:** This package contains two nodes -
  * *OrderGenNode* starts or stops periodic publishing of order lists to `/order_list` topic based on the bool value on `/start_simulation` topic from a button on web interface.
  * *spawn_graph_robots_totes* -
    * **Assumption:** We use parts-to-picker based order processing system, where mobile robots hoist racks and bring them directly to stationary pickers.
    * For every tote ID in the order's pick list, we get a **Boost** graph data with tote's current node as the main node, look for and assign to, an available robot parked at a parkingSpot with the highest weightage to travel to the main node and then to the processing station, then mark the robot unavailable.
    * Continuously publish robots' id, position, orientation, and availability to `/robot` topic.
    * Once there are no available robots, any new orders are pushed to a FIFO queue and an updated queue instance is published to `/orders_queued`
    * Fulfilled orders' list is published to `/orders_fulfilled`
* **accio_interfaces:** This package contains all the required message files.

### 2. Node.js backend

* Uses **socket.io** to connect to the **React** hooks at the frontend.
* Sets up an event listener to listen to `sim:start` events on button press and a ROS2 publisher using **rclnodejs** to publish to bool to `/start_simulation` topic.
* Subscribes to `/robot`, `/orders_queued`, and `/orders_fulfilled` topics and sets up emitters for them all.
* Assuming top-left corner of the map as the origin, map the length of the warehouse to the length of the map image and execute change in position and orientation of the robot using **CSS** `transform` property with a transition of low 0.3s.

### 3. React frontend

* Creates visual components for order queue, robot list, robot plotter, fulfilled order list, simulation start button, and socket.io server connection status.
* Each socket.io listener on frontend uses hooks to update it's respective component state.
* start simulation event emitter emits to the backend on button press.

## Difficulties faced

1. Matlab generated code was quite confusing. I made use of OrderGen part of the code and had to write some myself to assist with web interface demo.
2. Took me some time to understand the problem statement.
3. I could only partially implement my plans due to the my current work schedule but I have given it my best.

### Whats functional
* OrderGen node
* Bi-directional communication between ROS2 and Node.js via rclnodejs
* Bi-directionl communication between Node.js and React via socket.io
web interface UI with robot status, simulation start/stop button, server connection status, pending orders, and fulfilled orders 

---
Thank you for such an interesting task! I had a good time doing it.
> **NOTE:**  I think there might be a typo in Readme.md that suggests using `spawn_graph_robots_totes_dist()` which does not exist.
