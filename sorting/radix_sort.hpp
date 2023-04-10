#ifndef EASYCPP_RADIX_SORT_HPP
#define EASYCPP_RADIX_SORT_HPP

#include <vector>
#include <algorithm>

using namespace std;
void radix_sort(vector<int>& nums) {
  int n = nums.size();
  if (n < 2)  return;
  int exp = 1;
  vector<int> buf(n);
  int upper = *max_element(nums.begin(), nums.end());

  while (upper >= exp) {
    vector<int> cnt(10);
    for (int i = 0; i < n; ++i) {
      int digit = (nums[i] / exp) % 10;
      cnt[digit]++;
    }
    for (int i = 1; i < 10; ++i) {
      cnt[i]+=cnt[i-1];
    }
    for (int i = n - 1; i >= 0; i--) {
      int digit = (nums[i] / exp) % 10;
      buf[--cnt[digit]] = nums[i];
    }
    copy(buf.begin(), buf.end(), nums.begin());
    exp *= 10;
  }
}
#endif  //EASYCPP_RADIX_SORT_HPP
