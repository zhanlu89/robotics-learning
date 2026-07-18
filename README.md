# Robotics Learning

这是一个用于记录机器人技术学习过程的综合仓库。不同主题以独立子目录组织，便于逐步扩展、单独运行和回顾实验结果。

## 学习项目

| 项目 | 内容 | 状态 |
| --- | --- | --- |
| [opencv-basics](opencv-basics/) | 使用 Python 和 C++/CMake 验证 OpenCV 图像绘制、保存与读取 | 已完成基础测试 |
| [topic_flow_cpp](ros2_ws/src/topic_flow_cpp/) | 使用 ROS 2 C++ 验证 Topic 数据流，并将模拟视觉偏移转换为离散转向决策 | 已完成基础数据流验证 |

## 目录结构

```text
robotics-learning/
├── README.md
├── opencv-basics/
│   ├── README.md
│   ├── python_smoke_test.py
│   └── cpp_smoke_test/
│       ├── CMakeLists.txt
│       └── main.cpp
└── ros2_ws/
    └── src/
        └── topic_flow_cpp/
            ├── CMakeLists.txt
            ├── package.xml
            └── src/
```

## 开始学习

当前可以从 [OpenCV 基础项目](opencv-basics/README.md) 开始，其中包含：

- 项目用途与环境说明
- Python 测试运行方式
- C++ 和 CMake 构建方式
- OpenCV 版本及生成图片位置

后续的机器人学、计算机视觉、传感器和控制相关练习将继续作为新的子项目加入本仓库。

## ROS 2 Topic 数据流

`topic_flow_cpp` 当前包含两组学习节点：

- `status_publisher` / `status_subscriber`：验证 String 消息的发布、订阅和回调；
- `lateral_error_publisher` / `steering_decision`：循环发布模拟横向偏移，并根据容差区输出左转、直行或右转决策。

构建工作区：

```bash
cd ros2_ws
source /opt/ros/jazzy/setup.bash
colcon build --packages-select topic_flow_cpp
source install/setup.bash
```

分别在两个已加载系统 ROS 2 和当前工作区环境的终端运行：

```bash
ros2 run topic_flow_cpp lateral_error_publisher
ros2 run topic_flow_cpp steering_decision
```

运行静态检查：

```bash
colcon test --packages-select topic_flow_cpp
colcon test-result --verbose
```

当前验证结果为 24 项测试、0 errors、0 failures；详细的动态学习状态记录在 [学习进度.md](学习进度.md)。
