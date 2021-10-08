cmake_minimum_required(VERSION 3.16)

project(regular-to-graph VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(regular-to-graph main.cpp Operation.hpp RegExprParser.cpp RegExprParser.hpp Graph.cpp Graph.hpp)

target_include_directories(regular-to-graph PUBLIC "${PROJECT_BINARY_DIR}")
