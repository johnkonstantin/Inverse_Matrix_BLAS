cmake_minimum_required(VERSION 3.22)
project(pract4_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(pract4_3 main.cpp matrix_op.cpp matrix_op.h)
find_package(OpenBLAS REQUIRED)
include_directories(${OpenBLAS_INCLUDE_DIRS})
target_link_libraries(pract4_3 ${OpenBLAS_LIBRARY})