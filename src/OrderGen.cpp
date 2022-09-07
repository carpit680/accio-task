#include <OrderGen.h>

OrderGen::OrderGen() : Node("order_gen_node") {
    // Publisher
    orderGenPub = this->create_publisher<fleet_msgs::msg::Order>("/order_list", 1);
    startSimSub = this->create_subscription<std_msgs::msg::Bool>("/start_simulation", 100, std::bind(&OrderGen::startSimulation, this, _1));
    // declare parameters you want to use
    this->declare_parameter("numTotes");
    this->declare_parameter("numOrders");
    // use the parameters set from warehouse_params.yaml
    this->get_parameter("numTotes", numTotes);
    this->get_parameter("numOrders", numOrders);
    rclcpp::sleep_for(1000000000ns);
    orderGeneration();
    timer_ = this->create_wall_timer(1s, std::bind(&OrderGen::orderPublisher, this));

}

void OrderGen::orderGeneration() {
    Order orders;
    int randPick, randTotes, max{7}, min{5};
    for (uint i = 1; i <= numOrders; ++i) {
        randPick = rand()%(max - min + 1) + min;
        orders.orderId = i;
        for (uint j = 0; j < randPick; ++j) {
            randTotes = 1 + (rand() % int(numTotes));
            while (std::find(orders.pickList.begin(), orders.pickList.end(), randTotes) != orders.pickList.end())
            {
                randTotes = 1 + (rand() % int(numTotes));
            }
            orders.pickList.emplace_back(randTotes);
        }
        orders.lastPick = orders.pickList[randPick - 1];
        orderList.emplace_back(orders);
        orders.pickList.clear();
    }
}

void OrderGen::orderPublisher() {
    if (startSim) {
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
        fleet_msgs::msg::Order orders;
        if (first)
        {
            startTime = std::chrono::high_resolution_clock::now();
            orders.orderid = orderList[0].orderId;
            for (auto &i : orderList[0].pickList)
            {
                orders.picklist.emplace_back(i);
            }
            orderGenPub->publish(orders);
            orderList.erase(orderList.begin());
            first = false;
        }
        else if (duration.count() >= 28 and !first) {
            startTime = std::chrono::high_resolution_clock::now();
            if (!orderList.empty()) {
                orders.orderid = orderList[0].orderId;
                for (auto &i : orderList[0].pickList) {
                    orders.picklist.emplace_back(i);
                }
                orderGenPub->publish(orders);
                orderList.erase(orderList.begin());
            }

        }
        stopTime = std::chrono::high_resolution_clock::now();
    }
}

void OrderGen::startSimulation(const std_msgs::msg::Bool &msg) {
    startSim = msg.data;
}
