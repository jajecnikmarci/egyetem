cmake_minimum_required(VERSION 3.25)
project(skeleton)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_definitions(MEMTRACE)

add_executable(skeleton Test.cpp clients.h clients.cpp myvektor.hpp date.h date.cpp MVM.h MVM.cpp contracts.h contracts.cpp)






