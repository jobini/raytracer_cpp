project (RayTracerTests)  
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++17")

include_directories(../include)

ADD_LIBRARY(SourceTuple
    ../src/tuple.cpp
    ../src/color.cpp
)

ADD_LIBRARY(SourceCanvas
    ../src/tuple.cpp
    ../src/color.cpp
    ../src/canvas.cpp
)

ADD_LIBRARY(SourceMatrix
    ../src/matrix.cpp
    ../src/tuple.cpp
)

ADD_EXECUTABLE(TestsTuple tuple_tests.cpp)
target_link_libraries(TestsTuple SourceTuple)

ADD_EXECUTABLE(TestsCanvas canvas_tests.cpp)
target_link_libraries(TestsCanvas SourceCanvas)

ADD_EXECUTABLE(TestsMatrix matrix_tests.cpp)
target_link_libraries(TestsMatrix SourceMatrix)


