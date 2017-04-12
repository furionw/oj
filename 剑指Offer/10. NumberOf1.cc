// Copyright 2017 Qi Wang
// Date: 2017-04-11
class Solution {
 public:
  int NumberOf1(int n) {
    int cnt = 0;
    for (; n; n = (n - 1) & n)
      ++cnt;
    return cnt;
  }
};
