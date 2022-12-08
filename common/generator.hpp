#ifndef LEARNCPP_GENERATOR_HPP
#define LEARNCPP_GENERATOR_HPP
#include <random>
#include <vector>
namespace common {

int* generate_random_array(int length) {
  int* array = new int[length];
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<int> distribution(1, 100);
  for (int i = 0; i < length; ++i) {
    array[i] = distribution(rng);
  }
  return array;
}

std::vector<int> generate_random_int_vector(int length) {
  std::vector<int> v(length);
  std::random_device device;
  std::mt19937 rng(device());
  std::uniform_int_distribution<int> distribution(1, 100);
  for (int i = 0; i < length; ++i) {
    v[i] = distribution(rng);
  }
  return v;
}


}
#endif //LEARNCPP_GENERATOR_HPP