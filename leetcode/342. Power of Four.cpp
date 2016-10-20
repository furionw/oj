// Copyright 2016 Qi Wang
// Date: 2016-10-05
class Solution {
 public:
  bool isPowerOfFour(int num) {
    return num > 0 && (log10(num) / log10(4) == int(log10(num) / log10(4)));
  }
};

class Solution {
 public:
  bool isPowerOfFour(int n) {
    return n > 0 && (log10(n) / log10(4) - int(log10(n) / log10(4)) == 0);
  }
};
