project (RayTracerTests)  
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++17")

include_directories(../include
                    ./include)

ADD_LIBRARY(SourceProjectile
            ../src/tuple.cpp
            ../src/canvas.cpp
            ../src/color.cpp
            )

ADD_EXECUTABLE(Projectile ./src/projectile.cpp)
target_link_libraries(Projectile SourceProjectile)

ADD_LIBRARY(SourceClockHours
            ../src/tuple.cpp
            ../src/canvas.cpp
            ../src/color.cpp
            ../src/matrix.cpp
            ../src/transformations.cpp
            )

ADD_EXECUTABLE(ClockHours ./src/clock_hours.cpp)
target_link_libraries(ClockHours SourceClockHours)
