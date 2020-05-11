cmake_minimum_required(VERSION 3.16)
project(regular-to-graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(regular-to-graph main.cpp Operation.h RegExprParser.cpp RegExprParser.h Graph.cpp Graph.h)