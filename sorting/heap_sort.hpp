#ifndef LEARNCPP_HEAP_SORT_HPP
#define LEARNCPP_HEAP_SORT_HPP
#include <iostream>
using std::swap;
using std::cout;

void heap_sort(int arr[], int n);
void max_heapify(int arr[], int n, int i);
void min_heapify(int arr[], int n, int i);

void min_heapify(int arr[], int n, int i) {
  // Find smallest among root, left child and right child
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] < arr[smallest])
    smallest = left;

  if (right < n && arr[right] < arr[smallest])
    smallest = right;

  // Swap and continue heapifying if root is not largest
  if (smallest != i) {
    swap(arr[i], arr[smallest]);
    min_heapify(arr, n, smallest);
  }
}

void max_heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(arr[i], arr[largest]);
    max_heapify(arr, n, largest);
  }
}

// main function to do heap sort
void heap_sort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    max_heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    max_heapify(arr, i, 0);
  }
}

// main function to do heap sort
void heap_sort_desc(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    min_heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    min_heapify(arr, i, 0);
  }
}


#endif //LEARNCPP_HEAP_SORT_HPP
