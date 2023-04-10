#ifndef EASYCPP_COUTING_SORT_HPP
#define EASYCPP_COUTING_SORT_HPP

#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& nums) {
  if (nums.size() == 0) return;
  int upper = *max_element(nums.begin(), nums.end());
  int lower = *min_element(nums.begin(), nums.end());
  int range = upper - lower + 1;
  vector<int> count(range);
  for (auto n : nums) {
    count[n-lower]++;
  }
  count[0]--;
  for (int i = 1; i < range; i++) {
    count[i] += count[i-1];
  }
  vector<int> result(nums.size());
  for (int i = nums.size() - 1; i >= 0; i--) {
    result[count[nums[i]-lower]] = nums[i];
    count[nums[i]-lower]--;
  }
  copy(result.begin(), result.end(), nums.begin());
}
#endif  //EASYCPP_COUTING_SORT_HPP
