#ifndef EASYCPP_SUBSETS_HPP
#define EASYCPP_SUBSETS_HPP

#include <vector>

using namespace std;
class SubsetsSolution {
public:
  void helper(int i, vector<int>& nums, vector<int>& current, vector<vector<int>>& res) {
    if (i >= nums.size()) {
      res.push_back(current);
      return;
    }
    current.push_back(nums[i]);
    helper(i+1, nums, current, res);
    current.pop_back();
    helper(i+1, nums, current, res);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current;
    helper(0, nums, current, res);
    return res;
  }

};
#endif  //EASYCPP_SUBSETS_HPP
