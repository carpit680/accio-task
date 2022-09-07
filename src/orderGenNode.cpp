#include <OrderGen.h>

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OrderGen>());
    rclcpp::shutdown();
    return 0;
}