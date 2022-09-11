cmake_minimum_required(VERSION 3.8)
project(accio_task)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(accio_interfaces REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

include_directories(include)

add_executable(OrderGenNode src/OrderGenNode.cpp src/OrderGen.cpp)
ament_target_dependencies(OrderGenNode rclcpp accio_interfaces std_msgs )
target_compile_features(OrderGenNode PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

include_directories(include)

add_executable(spawn_graph_robots_totes src/spawn_graph_robots_totes.cpp src/colon.cpp src/eml_rand_mt19937ar_stateful.cpp src/find.cpp src/mod.cpp src/rand.cpp src/randperm.cpp src/rt_nonfinite.cpp src/rtGetInf.cpp src/rtGetNaN.cpp src/spawn_graph_robots_totes_new_data.cpp src/spawn_graph_robots_totes_new_initialize.cpp src/spawn_graph_robots_totes_new_terminate.cpp src/spawn_graph_robots_totes_new.cpp)
# include/spawn_graph_robots_totes_new.cpp include/spawn_graph_robots_totes_new_terminate.cpp include/coder_array.cpp include/rt_nonfinite.cpp
ament_target_dependencies(spawn_graph_robots_totes rclcpp accio_interfaces std_msgs )
target_compile_features(spawn_graph_robots_totes PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS 
  OrderGenNode
  spawn_graph_robots_totes
  DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY include/
  DESTINATION include
)

ament_package()
