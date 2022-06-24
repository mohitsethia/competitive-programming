cmake_minimum_required (VERSION 3.16)
project (ParkingLot)

set(CMAKE_CXX_STANDARD 17)

set(SnakeAndLadderSource
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SnakeAndLadder.cpp
)

add_library(SnakeAndLadder_lib ${SnakeAndLadderSource})

add_executable (SnakeAndLadder src/main.cpp)

target_link_libraries(SnakeAndLadder SnakeAndLadder_lib)
