cmake_minimum_required(VERSION 3.26)
project(Schedule C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

add_executable(Schedule src/main.c
        include/schedule.h
        include/utils.h
        include/io.h
        src/schedule.c
        src/io.c
        src/utils.c
        include/structures.h
)
