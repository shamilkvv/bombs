cmake_minimum_required(VERSION 3.10)
project(project)
add_executable(project main.cpp)
target_link_libraries(project gtest)