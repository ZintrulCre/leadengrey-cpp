cmake_minimum_required(VERSION 3.17.2)

project(leadgrey)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g -Werror -pthread)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
message(STATUS "source dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "output dir: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include_directories(./)

aux_source_directory(. DIR_SOURCES)
aux_source_directory(design-pattern/ DESIGN_PATTERN_SOURCES)
aux_source_directory(online-judge/leetcode/ LEETCODE_SOURCES)

add_executable(leadgrey ${DIR_SOURCES} ${DESIGN_PATTERN_SOURCES} ${LEETCODE_SOURCES})