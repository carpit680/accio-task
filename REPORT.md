# Accio Technical Task Report

## Task specifications as per my uderstanding from the question:

* Web Interface frontend for warehouse monitoring
* Update latency: real-time
* Information on Web Interface:
  * 2D map of warehouse
  * Locations of robots
  * Robot availability
  * Assigned OrderIDs
  * Completed OrderIDs

## Assumptions:
TODO
## My approach:

### 1. Web Interface

* Create a **React** app with a 2D map of the warehouse, a list of robots, and a list of completed orders.
* The data will be updated using a websocket connection established using **rclnodejs** library.
* The map will be a static image with a plot of realtime locations of the robots.
* The list of robots can then expand when clicked to show the robot's ID, availability, and assigned order ID.
* A button to start the simulation by publishing to `/start_simulation` topic.

### 2. ROS2

A ROS2 package that will contain nodes publishing:

* Order to `/order_list` (containing order ID and a list of totes in that order)
* Graph to `/graph` (containing main node, its position, Nodes associated with UUIDs, weights of going to 6 nodes)
* Robot to `/robot` (containing robot ID, position, orientation, availability, and current node)
* Tote to `/tote` (containing tote ID, position, orientation, availability, and current node)

## Difficulties:

* Unfamiliarity to rclnodejs library
* Understanding the working of given code