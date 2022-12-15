#ifndef EASYCPP_FIND_CLOSEST_LCCI_HPP
#define EASYCPP_FIND_CLOSEST_LCCI_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace lc {
class FindClosestSolution {
public:
  int findClosest(vector<string> &words, string word1, string word2) {
    vector<int> indices1 = {};
    vector<int> indices2 = {};
    for (auto i = 0; i < words.size(); ++i) {
      auto w = words[i];
      if (w == word1) {
        indices1.push_back(i);
      }
      if (w == word2) {
        indices2.push_back(i);
      }
    }
    int closest = words.size() + 1;
    for (const auto &index1: indices1) {
      for (const auto &index2: indices2) {
        auto dist = index1 - index2;
        if (dist < 0) dist *= -1;
        if (dist == 1) return 1;
        if (dist < closest) closest = dist;
      }
    }
    return closest;
  }
};
}
#endif //EASYCPP_FIND_CLOSEST_LCCI_HPP
