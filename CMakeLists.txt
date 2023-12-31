cmake_minimum_required(VERSION 3.10)
project(compiler)

set(CMAKE_C_STANDARD 99)

add_executable(compiler main.c)
add_executable(DDOS main.c)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.65.1 REQUIRED COMPONENTS system)

add_executable(DDOS main.cpp)

target_link_libraries(DDOS Boost::system)