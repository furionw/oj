// Copyright 2017 Qi Wang
// Date: 2016-11-11
// Revisited: 2017-01-03
// Refer to: https://discuss.leetcode.com/topic/48236/share-my-0ms-c-solution-with-proof-and-explanation
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
