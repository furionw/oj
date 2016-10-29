// Copyright 2016 Qi Wang
// Date: 2016-10-29
class Solution {
 public:
  int findNthDigit(int n) {
    int len = 1, start = 1;
    for (size_t sz = 9; n > sz * len; sz *= 10) {
      n -= sz * len++;
      start *= 10;
    }
    return to_string(start + (n - 1) / len)[(n - 1) % len] - '0';
  }
};
