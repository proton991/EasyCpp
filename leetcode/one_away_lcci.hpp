#ifndef LEARNCPP_ONE_AWAY_LCCI_HPP
#define LEARNCPP_ONE_AWAY_LCCI_HPP
#include <string>
using namespace std;
class OneEditAwaySolution {
public:
  bool oneEditAway(string first, string second) {
    if (first == second) {
      return true;
    }
    if (abs(static_cast<int>(first.size() - second.size())) >= 2) {
      return false;
    }
    // edit
    if (first.size() == second.size()) {
      auto diffs = 0U;
      for (auto i = 0U; i < first.size(); i++) {
        if (first[i] != second[i]) {
          diffs++;
        }
        if (diffs > 1) {
          return false;
        }
      }
      return true;
    }
    // remove or insert
    if (first.size() > second.size()) {
      first.swap(second);
    }
    int edit = 0;
    int p1 = 0, p2 = 0;
    while (p1 < first.size()) {
      if (first[p1] != second[p2]) {
        char tmp = first[p1];
        auto pos = second.find(tmp);
        if (pos == string::npos || pos != p1 + 1) {
          return false;
        } else {
          p2++;
        }
      } else {
        p1++;
        p2++;
      }
    }
    return true;
  }
};
#endif //LEARNCPP_ONE_AWAY_LCCI_HPP
