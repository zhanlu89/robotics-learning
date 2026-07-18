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

#include <array>
#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

namespace
{
constexpr std::array<float, 5> kLateralErrors{
  -0.80F, -0.10F, 0.00F, 0.20F, 0.75F};
}  // namespace

class LateralErrorPublisher final : public rclcpp::Node {
public:
  LateralErrorPublisher()
  : Node("lateral_error_publisher")
  {
    publisher_ = create_publisher<std_msgs::msg::Float32>(
      "perception/lateral_error", 10);
    timer_ = create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&LateralErrorPublisher::publish_next_error, this));
  }

private:
  void publish_next_error()
  {
    std_msgs::msg::Float32 message;
    message.data = kLateralErrors[next_error_index_];
    publisher_->publish(message);
    RCLCPP_INFO(get_logger(), "Published lateral error: %.2f", message.data);

    next_error_index_ = (next_error_index_ + 1) % kLateralErrors.size();
  }

  std::size_t next_error_index_{0};
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LateralErrorPublisher>());
  rclcpp::shutdown();
  return 0;
}
