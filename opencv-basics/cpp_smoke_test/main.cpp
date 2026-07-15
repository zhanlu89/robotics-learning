#include <filesystem>
#include <iostream>
#include <stdexcept>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace {
constexpr int kWidth = 320;
constexpr int kHeight = 240;
const std::filesystem::path kOutputPath{"output/cpp_smoke_test.png"};
}  // namespace

int main() {
  std::filesystem::create_directories(kOutputPath.parent_path());

  cv::Mat image(kHeight, kWidth, CV_8UC3, cv::Scalar(32, 32, 32));
  cv::rectangle(image, cv::Point(40, 45), cv::Point(280, 195),
                cv::Scalar(255, 180, 0), 4);
  cv::putText(image, "OpenCV C++", cv::Point(68, 128),
              cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 255, 255), 2,
              cv::LINE_AA);

  if (!cv::imwrite(kOutputPath.string(), image)) {
    throw std::runtime_error("Failed to write " + kOutputPath.string());
  }

  const cv::Mat loaded = cv::imread(kOutputPath.string(), cv::IMREAD_COLOR);
  if (loaded.empty()) {
    throw std::runtime_error("Failed to read " + kOutputPath.string());
  }
  if (loaded.cols != kWidth || loaded.rows != kHeight || loaded.channels() != 3) {
    throw std::runtime_error("Unexpected dimensions or channel count");
  }

  std::cout << "OpenCV version: " << CV_VERSION << '\n';
  std::cout << "Output: " << std::filesystem::absolute(kOutputPath) << '\n';
  std::cout << "Verified: " << loaded.cols << 'x' << loaded.rows << ", "
            << loaded.channels() << " channels\n";
  return 0;
}
