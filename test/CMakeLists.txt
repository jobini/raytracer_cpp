project (RayTracerTests)  
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++17")

include_directories(../include)

ADD_LIBRARY(SourceTuple
    ../src/tuple.cpp
    ../src/color.cpp
)

ADD_EXECUTABLE(TestsTuple tuple_tests.cpp)
target_link_libraries(TestsTuple SourceTuple)