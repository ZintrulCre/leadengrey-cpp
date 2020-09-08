cmake_minimum_required(VERSION 2.6)

project(LeadGrey)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIR_SOURCES)

add_executable(LeadGrey ${DIR_SOURCES})