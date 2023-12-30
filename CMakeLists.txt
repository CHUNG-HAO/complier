cmake_minimum_required(VERSION 3.10)
project(DDOS)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)

add_executable(DDOS main.cpp)

target_link_libraries(DDOS ${CURL_LIBRARIES})