#include <iostream>
#include "catch.hpp"
#include "generator.hpp"
#include "heap_sort.hpp"
#include "bubble_sort.hpp"
#include "printer.hpp"
#include "simple_timer.hpp"

TEST_CASE("Test random vector generation") {
  std::vector<int> randomVector = common::generate_random_int_vector(10);
  common::print_array(randomVector.data(), randomVector.size());
}

TEST_CASE("Test heap sort asc") {
  std::vector<int> randomVector = common::generate_random_int_vector(10);
  common::print_array(randomVector.data(), randomVector.size());
  heap_sort(randomVector.data(), randomVector.size());
  common::print_array(randomVector.data(), randomVector.size());
}

TEST_CASE("Test bubble sort asc") {
  std::vector<int> randomVector = common::generate_random_int_vector(10);
  common::print_array(randomVector.data(), randomVector.size());
  bubble_sort(randomVector.data(), randomVector.size());
  common::print_array(randomVector.data(), randomVector.size());
}

TEST_CASE("Test simple timer") {
  std::vector<int> randomVector = common::generate_random_int_vector(1000);
  SimpleTimer timer;
  heap_sort(randomVector.data(), randomVector.size());
  std::cout << "heap sort time used: " << timer.TimeStep() << "ms\n";

  std::vector<int> randomVector2 = common::generate_random_int_vector(1000);
  bubble_sort(randomVector2.data(), randomVector2.size());
  std::cout << "bubble sort time used: " << timer.TimeStep() << "ms\n";
}
