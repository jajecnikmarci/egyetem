cmake_minimum_required(VERSION 3.23)
project(jatek2 C)

set(CMAKE_C_STANDARD 99)

add_executable(jatek2 main.c beolvas.c beolvas.h jatek.c jatek.h dicsoseglista.c dicsoseglista.h)
