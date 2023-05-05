cmake_minimum_required(VERSION 3.24)
project(hetero)

set(CMAKE_CXX_STANDARD 17)

add_executable(hetero memtrace.cpp hetero_test.cpp)
