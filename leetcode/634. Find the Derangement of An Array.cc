// Copyright 2017 Qi Wang
// Date: 2017-07-01
class Solution {
 public:
  int findDerangement(int n) {
    if (n <= 2) return n == 2;
    size_t first = 0, second = 1;
    size_t result;
    for (size_t i = 3; i <= n; ++i) {
      result = (i - 1) * (first + second) % MOD;
      first = second;
      second = result;
    }
    return result;
  }

 private:
  static constexpr int MOD = 1e9 + 7;
};
