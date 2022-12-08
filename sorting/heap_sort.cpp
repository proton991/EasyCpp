// Heap Sort in C++

#include <iostream>
#include "heap_sort.hpp"
#include "../common/printer.hpp"

using namespace std;


// Driver code
int main() {
  int arr[] = {1, 12, 9, 5, 6, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  heap_sort(arr, n);

  cout << "Sorted array is \n";
  common::print_array(arr, n);
}