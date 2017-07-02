// Copyright 2017 Qi Wang
// Date: 2017-07-01
class Solution {
 public:
  bool judgeSquareSum(int c) {
    int bound = ceil(sqrt(ceil((c / 2.))));
    for (int i = 1; i <= bound; ++i) {
      int left = c - i * i;
      int num = sqrt(left);
      if (num * num == left) return true;
    }
    return false;
  }
};
