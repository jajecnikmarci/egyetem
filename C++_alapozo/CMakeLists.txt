cmake_minimum_required(VERSION 3.24)
project(C___alapozo)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/libpcap)


add_executable(C___alapozo
        halozat.cpp)
