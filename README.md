# Technical Task setup
We are using ROS 2 Galactic running on Ubuntu 20.04 so it might not work with some other ROS 2 version. You have been given a folder called Accio_task. This will help you in generating a graph for the warehouse and random order placement in certain time intervals. It has the following folders:
```
Accio_task
 ├── include
 │    ├── OrderGen.h
 │    └── spawn_graph_robots_totes_new
 ├── msg
 │   └── Order.msg
 ├── README.md
 └── src
     ├── OrderGen.cpp
     └── orderGenNode.cpp
```

## Order Generator
This file will generate and publish random orders at an interval specified by you. It will get published on a topic called **/order_list**.
#### Note
There are some variables which might be imported through a yaml file. You can either create one or just hard code these variables.
```
this->declare_parameter("numTotes");
this->declare_parameter("numOrders");

this->get_parameter("numTotes", numTotes);
this->get_parameter("numOrders", numOrders);
```
**Max number of totes is 1260**<br>
You can change the publishing time by changing this value
```
else if (duration.count() >= 28 and !first)
```
This publishes a new order every 28s

## Graph, Robot & Tote generation
We are using a boost graph from the BOOST library. You are free to use any library you want for storing Graph Data structure. Be sure to include **spawn_graph_robots_totes_new.h** when you want to use this.
#### Note
There are some variables which might be imported through a yaml file. You can either create one or just hard code these variables.
```
All these are of type double. Max number of totes is 1260

this->declare_parameter("dimX");
this->declare_parameter("dimY");
this->declare_parameter("dimZ");
this->declare_parameter("gridX");
this->declare_parameter("gridY");
this->declare_parameter("gridZ");
this->declare_parameter("numRobots");
this->declare_parameter("numTotes");
this->declare_parameter("numOrders");
this->declare_parameter("numStations");

this->get_parameter("dimX", dimX);
this->get_parameter("dimY", dimY);
this->get_parameter("dimZ", dimZ);
this->get_parameter("gridX", gridX);
this->get_parameter("gridY", gridY);
this->get_parameter("gridZ", gridZ);
this->get_parameter("numRobots", numRobots);
this->get_parameter("numTotes", numTotes);
this->get_parameter("numOrders", numOrders);
this->get_parameter("numStations", numStations);
```
Using the function below, you can generate the graph, number of robots, totes and delivery stations
```
coder::array<double, 2> robots, totes, graph, deliveryStations, parkingSpots;

spawn_graph_robots_totes_dist(dimX, dimY, dimZ, gridX, gridY, gridZ, numRobots, numTotes, numStations, 5.0, robots, totes, parkingSpots, deliveryStations, graph, &cols, &rows, &levels);
```
Graph is represented like this:
```
(uuid, x, y, z, node1, node2, node3, node4, node5, node6, weight1, weight2, weight3, weight4, weight5, weight6)
```
**uuid:** Main node number<br>
**x:** Its x position<br>
**y:** Its y position<br>
**z:** Its z position<br>
**node1:** node number uuid is connected to. 0 if no connection<br>
**node2:** node number uuid is connected to. 0 if no connection<br>
**node3:** node number uuid is connected to. 0 if no connection<br>
**node4:** node number uuid is connected to. 0 if no connection<br>
**node5:** node number uuid is connected to. 0 if no connection<br>
**node6:** node number uuid is connected to. 0 if no connection<br>
**weight1:** Weight of going from uuid->node1. 0 if no connection<br>
**weight2:** Weight of going from uuid->node2. 0 if no connection<br>
**weight3:** Weight of going from uuid->node3. 0 if no connection<br>
**weight4:** Weight of going from uuid->node4. 0 if no connection<br>
**weight5:** Weight of going from uuid->node5. 0 if no connection<br>
**weight6:** Weight of going from uuid->node6. 0 if no connection<br>

Now if you want to read **coder::array<double, 2> graph**, this is how you do it:
```
for (uint i = 0; i < graph.size(0); i++)
{
    uuid = graph[i];
    x = graph[i + graph.size(0)*1];
    y = graph[i + graph.size(0)*2];
    z = graph[i + graph.size(0)*3];
    for (int j = 4; j <= 9; ++j) {
        if (graph[i + graph.size(0)*j] != 0) {
            node = graph[i + graph.size(0)*j];
            weight = graph[i + graph.size(0)*(j + 6)];
        }
    }
}
```
Robot is represented like this:
```
[robotId, X, Y, Z, qw, qx, qy, qz, available, currentNode]
```
**robotId:** The id of the bot <br>
**x:** Its x position <br>
**y:** Its y position <br>
**z:** Its z position <br>
**qw:** Its orientation in quaternion<br>
**qx:** Its orientation in quaternion<br>
**qy:** Its orientation in quaternion<br>
**qz:** Its orientation in quaternion<br>
**available:** If the bot is available for an order 1/0<br>
**currentNode:** The node at which the robot is spawned<br>

Now if you want to read **coder::array<double, 2> robots** , this is how you do it:
```
for (uint i = 0; i < robots.size(0); ++i)
{
    robotId = robots[i];
    X = robots[i + robots.size(0)*1];
    Y = robots[i + robots.size(0)*2];
    Z = robots[i + robots.size(0)*3];
    qw = robots[i + robots.size(0)*4];
    qx = robots[i + robots.size(0)*5];
    qy = robots[i + robots.size(0)*6];
    qz = robots[i + robots.size(0)*7];
    available = robots[i + robots.size(0)*8];
    currentNode = robots[i + robots.size(0)*9];
}
```
Tote is represented like this:
```
[toteId, X, Y, Z, qw, qx, qy, qz, assigned, nodeNum]
```
**toteId:** The ID of the tote<br>
**X:** Its x position<br>
**y:** Its y position<br>
**z:** Its z position<br>
**qw:** Its orientation in quaternion<br>
**qx:** Its orientation in quaternion<br>
**qy:** Its orientation in quaternion<br>
**qz:** Its orientation in quaternion<br>
**assigned:** Robot it is assigned to. 0 otherwise<br>
**nodeNum:** The node in graph at which the robot has to come to pick this tote up<br>

Now if you want to read **coder::array<double, 2> totes** , this is how you do it:
```
for (uint i = 0; i < totes.size(0); ++i) {
    toteId = totes[i + totes.size(0) * 0];
    X = totes[i + totes.size(0) * 1];
    Y = totes[i + totes.size(0) * 2];
    Z = totes[i + totes.size(0) * 3] + gridZ;
    qw = totes[i + totes.size(0) * 4];
    qx = totes[i + totes.size(0) * 5];
    qy = totes[i + totes.size(0) * 6];
    qz = totes[i + totes.size(0) * 7];
    assigned = totes[i + totes.size(0) * 8];
    nodeNum = totes[i + totes.size(0) * 9];
}
```
