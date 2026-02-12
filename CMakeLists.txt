cmake_minimum_required(VERSION 4.1)
project(c_observer_pattern)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(c_observer_pattern ${SOURCES})
