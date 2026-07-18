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

#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

namespace
{
constexpr float kStraightTolerance = 0.15F;
}  // namespace

class SteeringDecision final : public rclcpp::Node {
public:
  SteeringDecision()
  : Node("steering_decision")
  {
    subscription_ = create_subscription<std_msgs::msg::Float32>(
      "perception/lateral_error", 10,
      std::bind(
        &SteeringDecision::decide_steering, this, std::placeholders::_1));
  }

private:
  void decide_steering(const std_msgs::msg::Float32 & message)
  {
    RCLCPP_INFO(
      get_logger(), "Received error %.2f with tolerance %.2f",
      message.data, kStraightTolerance);
    std::string decision;
    if (message.data < -kStraightTolerance) {
      decision = "left";
    } else if (message.data > kStraightTolerance) {
      decision = "right";
    } else {
      decision = "straight";
    }
    RCLCPP_INFO(get_logger(), "Decision:%s", decision.c_str());

    // TODO(learner): Decide left/straight/right and log the decision.
  }

  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SteeringDecision>());
  rclcpp::shutdown();
  return 0;
}
