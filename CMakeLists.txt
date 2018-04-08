cmake_minimum_required(VERSION 3.5.1)
set (CMAKE_CXX_STANDARD 11)

project(solutions)

add_subdirectory(leetcode)

enable_testing()
add_subdirectory(test)