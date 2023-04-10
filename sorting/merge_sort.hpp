#ifndef EASYCPP_MERGE_SORT_HPP
#define EASYCPP_MERGE_SORT_HPP

#include <vector>
using namespace std;

void merge_sort(vector<int>& nums, vector<int>& tmp, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  merge_sort(nums, tmp, l, mid);
  merge_sort(nums, tmp, mid+1, r);
  int i = l, j = mid + 1;
  int k = 0;
  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= r) {
    tmp[k++] = nums[j++];
  }
  for (i = 0; i <= r - l; i++) {
    nums[l+i] = tmp[i];
  }
}

void merge_sort(vector<int>& nums) {
  vector<int> tmp(nums.size());
  merge_sort(nums, tmp, 0, nums.size() - 1);
}
#endif  //EASYCPP_MERGE_SORT_HPP
