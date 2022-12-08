cmake_minimum_required(VERSION 3.22)
project(EasyCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(sorting)
add_subdirectory(leetcode)
add_subdirectory(tests)
#add_subdirectory(common)

file(GLOB common_lib_src
        common/generator.hpp
        common/printer.hpp)

add_library(common_lib INTERFACE)
target_include_directories(common_lib INTERFACE common)
set_target_properties(common_lib PROPERTIES LINKER_LANGUAGE CXX)