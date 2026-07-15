cmake_minimum_required(VERSION 3.16)
project(opencv_smoke_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

add_executable(opencv_smoke_test main.cpp)
target_include_directories(opencv_smoke_test PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencv_smoke_test PRIVATE ${OpenCV_LIBS})
