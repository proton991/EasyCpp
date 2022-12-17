#ifndef EASYCPP_BUBBLE_SORT_HPP
#define EASYCPP_BUBBLE_SORT_HPP
#include <algorithm>
void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}
#endif  //EASYCPP_BUBBLE_SORT_HPP
