// Copyright 2017 Qi Wang
// Date: 2017-08-07
// Refer to the previous solution
class Solution {
 public:
  bool isPowerOfFour(int num) {
    return num > 0 && (log10(num) / log10(4) == int(log10(num) / log10(4)));
  }
};

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
