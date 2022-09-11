cmake_minimum_required(VERSION 3.8)
project(accio_interfaces)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)

set(msg_files
  "msg/Position.msg"
  "msg/Orientation.msg"
  "msg/Robot.msg"
  "msg/Order.msg"
  "msg/Orders.msg"
  )

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}  
  DEPENDENCIES builtin_interfaces
)

install(DIRECTORY msg
    DESTINATION share/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
