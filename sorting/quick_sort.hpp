#ifndef EASYCPP_QUICK_SORT_HPP
#define EASYCPP_QUICK_SORT_HPP

#include <vector>
#include <chrono>
#include <random>
using namespace std;

void quick_sort(vector<int>& nums, int left, int right);
int random_partition(vector<int>& nums, int left, int right);

void quick_sort(vector<int>& nums, int left, int right) {
  if (left < right) {
    int pos = random_partition(nums, left, right);
    quick_sort(nums, left, pos - 1);
    quick_sort(nums, pos+1, right);
  }
}

//int random_partition(vector<int>& nums, int left, int right) {
//  std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
//  std::uniform_int_distribution<int> dis(left, right);
//  int random_index = dis(gen);
//  swap(nums[right], nums[random_index]);
//  int pivot = nums[right];
//  int i = left - 1;
//  for (int j = left; j < right; j++) {
//    if (nums[j] <= pivot) {
//      i = i + 1;
//      swap(nums[i], nums[j]);
//    }
//  }
//  swap(nums[i+1], nums[right]);
//  return i + 1;
//}

int random_partition(vector<int>& nums, int left, int right) {
  std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> dis(left, right);
  int random_index = dis(gen);
  swap(nums[right], nums[random_index]);
  int pivot = nums[right];
  int i = left;
  for (int j = left; j < right; j++) {
    if (nums[j] <= pivot) {
      swap(nums[i], nums[j]);
      i++;
    }
  }
  swap(nums[i], nums[right]);
  return i;
}


void quick_sort(vector<int>& nums) {
  quick_sort(nums, 0, nums.size() - 1);
}
#endif  //EASYCPP_QUICK_SORT_HPP
