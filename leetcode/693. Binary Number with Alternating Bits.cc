// Copyright 2017 Qi Wang
// Date: 2017-10-12
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int prev = n & 1;
    for (n >>= 1; n; n >>= 1) {
      if ((n & 1) == prev) return false;
      prev = n & 1;
    }
    return true;
  }
};
