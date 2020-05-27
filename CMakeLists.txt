cmake_minimum_required(VERSION 3.15)
project(netPbmRender)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(NetPBMRenderer)

add_executable(netPbmRender main.cpp)
target_link_libraries(netPbmRender NetPBMRenderer)