// Copyright 2016 Qi Wang
// Date: 2016-11-11
class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    } else {
      int pre = 9, res = 1;
      for (int i = 9; n--; --i) {
        res += pre;
        pre *= i;
      }
      return res;
    }
  }
};
