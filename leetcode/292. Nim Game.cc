// Copyright 2017 Qi Wang
// Date: 2017-07-31
class Solution {
 public:
  bool canWinNim(int n) {
      return n % 4 != 0;
  }
};

// Date: 2017-04-08
class Solution {
 public:
  bool canWinNim(int n) {
    return n & 3;
  }
};
