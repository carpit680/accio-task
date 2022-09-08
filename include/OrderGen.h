#ifndef INCLUDE_ORDERGEN_H
#define INCLUDE_ORDERGEN_H

#include <memory>
#include <vector>
#include <fleet_msgs/msg/order.hpp> // TODO: pkg to be renamed
#include <algorithm>
#include <random>
#include <std_msgs/msg/bool.hpp>
#include <rclcpp/rclcpp.hpp>
#include <map>
#include <fstream>

using std::placeholders::_1;
using namespace std::chrono_literals;

struct Order {
    int orderId;
    std::vector<int> pickList;
    int lastPick;
    int priority;
};

class OrderGen : public rclcpp::Node {
public:
    OrderGen();

    void orderGeneration();

    void startSimulation(const std_msgs::msg::Bool &msg);

    void orderPublisher();

private:
    std::vector<Order> orderList;
    int numTotes, numOrders;
    bool startSim, first{true};
    std::chrono::high_resolution_clock::time_point startTime, stopTime;
    rclcpp::Publisher<fleet_msgs::msg::Order>::SharedPtr orderGenPub;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr startSimSub;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif //INCLUDE_CONTROL_H
