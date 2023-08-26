cmake_minimum_required(VERSION 3.23)
project(GraphLib)

set(CMAKE_CXX_STANDARD 14)

add_library(GraphLib graph.cpp mainTest.cpp)
