cmake_minimum_required(VERSION 3.13.4)

set(project_name leadengrey-cpp)
project(${project_name})

# compile
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS -Wall -Wextra -Werror -Wno-error=sign-compare)
# set(CMAKE_CXX_FLAGS -Wall)
# disable Vla
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Wvla)
# optimization
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -O0)
# pthread
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)
# libcurl
# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -lcurl)
# gdb
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
# # sanitizer
# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer)
# diagnostics
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fdiagnostics-color)

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
aux_source_directory(smart-pointer/ SMARTPOINTER_SOURCES)
file(GLOB_RECURSE ONLINE_JUDGE_SOURCES "online-judge/*.cpp")
file(GLOB_RECURSE DESIGN_PATTERN_SOURCES "design-pattern/*.cpp")
file(GLOB_RECURSE SMARTPOINTER_SOURCES "smart-pointer/*.cpp")
file(GLOB_RECURSE SORT_SOURCES "sort/*.cpp")
# message(STATUS "ONLINE_JUDGE_SOURCES: " ${ONLINE_JUDGE_SOURCES})

add_executable(${project_name} ${DIR_SOURCES} ${DESIGN_PATTERN_SOURCES} ${ONLINE_JUDGE_SOURCES} ${SMARTPOINTER_SOURCES})
