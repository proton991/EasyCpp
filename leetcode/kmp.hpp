#pragma once
#include <string>
using namespace std;

namespace lc {
void get_next(const string& s, vector<int>& next) {
  next[0] = -1;
  int i = 0, j = -1;
  while (i < (int)s.size() - 1) {
    if (j == -1 || s[i] == s[j]) {
      i++;
      j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}

int kmp(string s, string p) {
  vector<int> next(p.size());
  get_next(p, next);
  int i = 0, j = 0;
  while (i < (int)s.size() && j < (int)p.size()) {
    if (j == -1 || s[i] == p[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j == p.size()) {
    return i - j;
  } else {
    return -1;
  }
}
}  // namespace lc