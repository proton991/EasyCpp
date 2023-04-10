#ifndef EASYCPP_SHELL_SORT_HPP
#define EASYCPP_SHELL_SORT_HPP
#include <vector>
using namespace std;

void shell_sort(vector<int>& nums) {
  for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < nums.size(); ++i) {
      int curr_num = nums[i];
      int pre_index = i - gap;
      while (pre_index >= 0 && nums[pre_index] > curr_num) {
        nums[pre_index + gap] = nums[pre_index];
        pre_index -= gap;
      }
      nums[pre_index + gap] = curr_num;
    }
  }
}
#endif  //EASYCPP_SHELL_SORT_HPP
