#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <accio_interfaces/msg/order.hpp>
#include <accio_interfaces/msg/robot.hpp>
#include "accio_task/spawn_graph_robots_totes_new.h"
#include "accio_task/main.h"
// #include "accio_task/rt_nonfinite.h"
// #include "accio_task/spawn_graph_robots_totes_new_terminate.h"
#include "accio_task/coder_array.h"
// #include <assert.h>
using std::placeholders::_1;

// Function Declarations
// static double argInit_real_T();

// static void main_spawn_graph_robots_totes_new();

double dimX{0.0}, dimY{0.0}, dimZ{0.0}, gridX{0.0}, gridY{0.0}, gridZ{0.0}, numRobots{0.0}, numTotes{20.0}, numOrders{10}, numStations{6.0};

// static double argInit_real_T()
// {
//     return 0.0;
// }

// static void main_spawn_graph_robots_totes_new()
// {
//     coder::array<double, 2U> delivery_stations;
//     coder::array<double, 2U> graph_info;
//     coder::array<double, 2U> robot_spots;
//     coder::array<double, 2U> robots;
//     coder::array<double, 2U> totes;
//     double columns;
//     double levels;
//     double rows;
//     double wh_x_tmp;
//     // Initialize function 'spawn_graph_robots_totes_new' input arguments.
//     wh_x_tmp = argInit_real_T();
//     // Call the entry-point 'spawn_graph_robots_totes_new'.
//     spawn_graph_robots_totes_new(wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp,
//                                  wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp,
//                                  robots, totes, robot_spots, delivery_stations,
//                                  graph_info, &columns, &rows, &levels);
// }

class OrdereHandler : public rclcpp::Node
{
public:
    OrdereHandler()
        : Node("order_subscriber")
    {
        subscription_ = this->create_subscription<accio_interfaces::msg::Order>(
            "order_list", 10, std::bind(&OrdereHandler::topic_callback, this, _1));
    }

private:
    void topic_callback(const accio_interfaces::msg::Order &msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%ld'", msg.orderid);

        coder::array<double, 2> robots, totes, graph, deliveryStations, parkingSpots;
        double cols, rows, levels;
        spawn_graph_robots_totes_new(dimX, dimY, dimZ, gridX, gridY, gridZ, numRobots, numTotes, numStations, 5.0, robots, totes, parkingSpots, deliveryStations, graph, &cols, &rows, &levels);

        RCLCPP_INFO(this->get_logger(), "I heard: '%ld'", msg.orderid);
    }
    rclcpp::Subscription<accio_interfaces::msg::Order>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<OrdereHandler>());

    // spawn_graph_robots_totes_new_terminate();

    rclcpp::shutdown();
    return 0;
}