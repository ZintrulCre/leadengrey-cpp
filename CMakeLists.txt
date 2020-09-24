cmake_minimum_required(VERSION 3.16.3)

project(leadgrey)


# compile
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g -Wall -Wextra -Werror)
# lib
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)
# sanitizer
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})


# dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
message(STATUS "source dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "output dir: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


# header
include_directories(./)
# source
aux_source_directory(. DIR_SOURCES)
aux_source_directory(design-pattern/ DESIGN_PATTERN_SOURCES)
aux_source_directory(online-judge/leetcode/ LEETCODE_SOURCES)


add_executable(leadgrey ${DIR_SOURCES} ${DESIGN_PATTERN_SOURCES} ${LEETCODE_SOURCES})