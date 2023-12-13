cmake_minimum_required(VERSION 3.26)
project(Schedule C)

set(CMAKE_C_STANDARD 11)

add_executable(Schedule src/main.c
        include/schedule.h
        include/utils.h
        include/io.h
        src/schedule.c
        src/io.c
        src/utils.c
        include/structures.h
)
