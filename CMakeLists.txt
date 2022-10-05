cmake_minimum_required(VERSION 3.24.1)

project(bu_macros VERSION 1.0)

set(CMAKE_C_STANDARD 90)

add_library(bu_macros INTERFACE)

target_include_directories(bu_macros INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
