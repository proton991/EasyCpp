#ifndef LEARNCPP_PRINTER_HPP
#define LEARNCPP_PRINTER_HPP

#include <iostream>

namespace common {
// Print an array
void print_array(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}
}
#endif //LEARNCPP_PRINTER_HPP
