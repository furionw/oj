// Copyright 2016 Qi Wang
// Date: 2016-10-05
class Solution {
 public:
  bool isPowerOfThree(int n) {
    return n > 0 && (log10(n) / log10(3) - int(log10(n) / log10(3)) == 0);
  }
};
