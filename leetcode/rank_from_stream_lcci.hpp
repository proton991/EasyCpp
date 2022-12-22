#ifndef RANK_FROM_STREAM_LCCI_HPP
#define RANK_FROM_STREAM_LCCI_HPP
#include <vector>
class StreamRank {
public:
  StreamRank() {

  }

  void track(int x) {
    if (data.empty()) {
      data.push_back(x);
      return;
    }
    auto it = lower_bound(data.begin(), data.end(), x);
    data.insert(it, x);
  }

  int getRankOfNumber(int x) {
    if (data.empty() || x < data[0])
      return 0;
    auto it = upper_bound(data.begin(), data.end(), x);
    int index = it - data.begin();
    return index;
  }

private:
  std::vector<int> data;
};
#endif  //RANK_FROM_STREAM_LCCI_HPP
