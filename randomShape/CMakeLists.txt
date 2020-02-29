cmake_minimum_required(VERSION 3.7)
project(randomShape C CXX)

set(OpenCV_DIR /home/ctankep/programming/opensources/opencv/build)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(main main.cpp draw.cpp shapes.cpp)
set_target_properties(main PROPERTIES CXX_STANDARD 17)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT} ${OpenCV_LIBS})