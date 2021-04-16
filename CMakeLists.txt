cmake_minimum_required(VERSION 3.15)
project(Cartwork)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Artwork)

add_executable(Cartwork main.cpp)
target_link_libraries(Cartwork Artwork)