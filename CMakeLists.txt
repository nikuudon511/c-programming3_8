cmake_minimum_required(VERSION 3.15)
project(cpp_exam_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
add_executable(practice04 practice/04_battleship/game.cpp practice/04_battleship/test.cpp)
add_test(NAME practice04 COMMAND practice04)
add_executable(practice05 practice/05_code_lock/cell.cpp practice/05_code_lock/test.cpp)
add_test(NAME practice05 COMMAND practice05)
