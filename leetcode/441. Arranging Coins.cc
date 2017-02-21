// Copyright 2017 Qi Wang
// Date: 2017-02-19
class Solution {
 public:
  int arrangeCoins(int n) {
    return floor((-1 + sqrt(1 + 8l * n)) / 2);
  }
};
