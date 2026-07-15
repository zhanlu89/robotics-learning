# 项目协作说明

## 项目范围

- `python_smoke_test.py` 是 Python OpenCV 冒烟测试。
- `cpp_smoke_test/` 是基于 CMake 的 C++ OpenCV 冒烟测试。
- 修改测试后，应同时检查控制台输出和生成图片路径是否符合 `README.md` 的说明。

## 验证命令

```bash
.venv/bin/python python_smoke_test.py
cmake -S cpp_smoke_test -B cpp_smoke_test/build
cmake --build cpp_smoke_test/build
(cd cpp_smoke_test && ./build/opencv_smoke_test)
```

## 提交规则

- 修改文件前先运行 `git status`。
- 提交前运行适用于变更范围的测试，并检查 `git status` 和 `git diff --stat`。
- 提交前检查变更中不包含密钥、密码、订阅链接、`.env` 文件、数据集、模型权重、虚拟环境或构建产物。
- 未经用户确认，不执行 `git add` 或 `git commit`。
- 未经用户明确确认，不执行 `git push`。
