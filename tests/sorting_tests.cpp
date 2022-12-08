#include "catch.hpp"
#include "generator.hpp"
#include "heap_sort.hpp"
#include "printer.hpp"
#include <iostream>

TEST_CASE("Test random vector generation") {
  std::vector<int> randomVector = common::generate_random_int_vector(10);
  for (int i = 0; i < randomVector.size(); ++i) {
    std::cout << randomVector[i] << " ";
  }
}

TEST_CASE("Test heap sort asc") {
  int arr[] = {1, 12, 9, 5, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  heap_sort(arr, n);
  REQUIRE(arr[0] == 1);
  common::print_array(arr, n);
}
