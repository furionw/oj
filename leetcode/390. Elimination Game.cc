// Copyright 2016 Qi Wang
// Refer to: http://bookshadow.com/weblog/2016/08/28/leetcode-elimination-game/
// Date: 2016-11-25
class Solution {
 public:
  int lastRemaining(int n) {
    int res = 1;
    for (int interval = 1, flag = 1; n > 1; flag = !flag) {
      interval <<= 1;
      n >>= 1;
      // Left to right
      if (flag & 1) {
        res += (interval >> 1) + (n - 1) * interval;
      } else {
        res -= (interval >> 1) + (n - 1) * interval;
      }
    }
    return res;
  }
};
