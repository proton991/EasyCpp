add_executable(sorting_tests catch.hpp sorting_tests.cpp unit_testing.cpp)
add_executable(leetcode_tests catch.hpp leetcode_tests.cpp unit_testing.cpp)
add_executable(datastructure_tests catch.hpp datastructure_tests.cpp unit_testing.cpp)

target_include_directories(sorting_tests PUBLIC ${CMAKE_SOURCE_DIR}/sorting)
target_link_libraries(sorting_tests common_lib)
target_include_directories(sorting_tests PUBLIC ${CMAKE_SOURCE_DIR}/profile)

target_include_directories(leetcode_tests PUBLIC ${CMAKE_SOURCE_DIR}/leetcode)
target_include_directories(datastructure_tests PUBLIC ${CMAKE_SOURCE_DIR}/datastructures)

enable_testing()
