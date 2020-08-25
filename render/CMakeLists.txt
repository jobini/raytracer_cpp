project (RayTracerTests)  
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++17")

include_directories(../include
                    ./include)

ADD_LIBRARY(SourceTuple
            ../src/tuple.cpp)

ADD_EXECUTABLE(Projectile ./src/projectile.cpp)
target_link_libraries(Projectile SourceTuple)
