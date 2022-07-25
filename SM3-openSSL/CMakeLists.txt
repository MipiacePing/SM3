cmake_minimum_required(VERSION 3.21)
project(opensslSM3)

set(CMAKE_CXX_STANDARD 14)
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_RELEASE -Ofast)
 
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2  -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2  -Wall")
add_executable(a.out main.cpp sm3/sm3.c)
