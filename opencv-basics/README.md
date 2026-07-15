# OpenCV Basics

这是一个独立的 OpenCV 基础学习项目，用于验证 Python 和 C++ 开发环境是否能够正确加载 OpenCV、绘制图形、写入图片并重新读取结果。

当前测试使用的 OpenCV 版本为 **4.6.0**。

## Python 测试

项目使用仓库根目录下的 `.venv` 虚拟环境。激活环境后运行测试：

```bash
source .venv/bin/activate
python python_smoke_test.py
```

测试成功时会输出 OpenCV 版本、模块路径、生成图片路径和读取到的图片尺寸。

## C++ 测试

C++ 测试使用 CMake 构建，要求系统已安装 C++17 编译器、CMake 和 OpenCV 开发库：

```bash
cd cpp_smoke_test
cmake -S . -B build
cmake --build build
./build/opencv_smoke_test
```

CMake 配置阶段会显示找到的 OpenCV 版本；测试程序会输出生成图片的绝对路径和验证后的图片尺寸及通道数。

## 生成图片

- Python 测试：`output/python_smoke_test.png`
- C++ 测试：`cpp_smoke_test/output/cpp_smoke_test.png`

两个测试都会创建一张 320 × 240 的三通道 PNG 图片，并在写入后重新读取，以验证基本的图像编解码功能。
