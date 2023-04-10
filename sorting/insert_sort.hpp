#ifndef EASYCPP_INSERT_SORT_HPP
#define EASYCPP_INSERT_SORT_HPP

#include <vector>
using namespace std;
void insert_sort(vector<int>& nums) {
  for (int i = 1; i < nums.size(); ++i) {
    int current_num = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > current_num) {
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = current_num;
  }
}
#endif  //EASYCPP_INSERT_SORT_HPP
