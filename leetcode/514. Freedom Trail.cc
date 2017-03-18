// Copyright 2017 Qi Wang
// Date: 2017-03-18
class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int result = INT_MAX;
    f(ring, key, 0, result);
    return result;
  }

 private:
  void f(string ring, string key, int cur, int& result) const {
    if (cur > result) return;
    if (key.empty()) {
      result = min(cur, result);
      return;
    }
    for (size_t i = 1; i < ring.size(); ++i)
      if (ring[i] == key.front())
        f(ring.substr(i) + ring.substr(0, i), key.substr(1),
            cur + min(i, ring.size() - i), result);
  }
};
