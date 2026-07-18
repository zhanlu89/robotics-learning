cmake_minimum_required(VERSION 3.16)
project(topic_flow_cpp LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(status_publisher src/status_publisher.cpp)
target_compile_features(status_publisher PRIVATE cxx_std_17)
ament_target_dependencies(status_publisher rclcpp std_msgs)

add_executable(status_subscriber src/status_subscriber.cpp)
target_compile_features(status_subscriber PRIVATE cxx_std_17)
ament_target_dependencies(status_subscriber rclcpp std_msgs)

add_executable(lateral_error_publisher src/lateral_error_publisher.cpp)
target_compile_features(lateral_error_publisher PRIVATE cxx_std_17)
ament_target_dependencies(lateral_error_publisher rclcpp std_msgs)

add_executable(steering_decision src/steering_decision.cpp)
target_compile_features(steering_decision PRIVATE cxx_std_17)
ament_target_dependencies(steering_decision rclcpp std_msgs)

install(TARGETS
  status_publisher
  status_subscriber
  lateral_error_publisher
  steering_decision
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
