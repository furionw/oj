// Copyright 2016 Stephen Wong
// Date: 2016-09-25
class Solution {
 public:
  int countDigitOne(int n) {
    int cnt = 0;
    for (int i = 0; n >= pow(10, i); ++i) {
      int divisor = pow(10, i);
      cnt += (n / divisor + 8) / 10 * divisor
          + (n / divisor % 10 == 1? 1: 0) * (n % divisor + 1);
    }
    return cnt;
  }
};
