cmake_minimum_required(VERSION 3.20)

project(main_project)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER g++)

add_executable(my_programm main.cpp main_1.cpp)

target_sources(my_programm PRIVATE main.cpp main_1.cpp)
