// Copyright 2026 Lingyi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class StatusPublisher final : public rclcpp::Node {
public:
  StatusPublisher()
  : Node("status_publisher")
  {
    publisher_ = create_publisher<std_msgs::msg::String>("learning/status", 10);
    timer_ = create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&StatusPublisher::publish_status, this));
  }

private:
  void publish_status()
  {
    std_msgs::msg::String message;
    message.data = "好困好想睡觉";
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<StatusPublisher>());
  rclcpp::shutdown();
  return 0;
}
