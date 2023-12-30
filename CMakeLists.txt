cmake_minimum_required(VERSION 3.10)
project(DDOS)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)
find_package(Boost REQUIRED)

add_executable(DDOS main.cpp)
add_executable(test test.cpp)
add_executable(asio asio.cpp)

target_link_libraries(DDOS ${CURL_LIBRARIES})
target_include_directories(DDOS PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(test ${CURL_LIBRARIES})
target_include_directories(test PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(asio ${CURL_LIBRARIES})
target_include_directories(asio PRIVATE ${Boost_INCLUDE_DIRS})