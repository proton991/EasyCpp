add_executable(sorting_tests catch.hpp sorting_tests.cpp unit_testing.cpp)
add_executable(leetcode_tests catch.hpp leetcode_tests.cpp unit_testing.cpp)

target_include_directories(sorting_tests PUBLIC ${CMAKE_SOURCE_DIR}/sorting)
target_include_directories(sorting_tests PUBLIC ${CMAKE_SOURCE_DIR}/common)
target_include_directories(leetcode_tests PUBLIC ${CMAKE_SOURCE_DIR}/leetcode)

enable_testing()
