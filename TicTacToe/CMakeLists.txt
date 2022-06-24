cmake_minimum_required (VERSION 3.16)
project (ParkingLot)

set(CMAKE_CXX_STANDARD 17)

set(TicTacToeSource
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TicTacToe.cpp
)

add_library(TicTacToe_lib ${TicTacToeSource})

add_executable (TicTacToe src/main.cpp)

target_link_libraries(TicTacToe TicTacToe_lib)