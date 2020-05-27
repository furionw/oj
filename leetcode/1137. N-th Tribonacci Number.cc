// Copyright 2019 Qi Wang
// Date: 2019-09-17
class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    } else if (n <= 2) {
      return 1;
    }
    int a = 0, b = 1, c = 1;
    for (n = n - 2; n > 0; --n) {
      int d = a + b + c;
      a = b;
      b = c;
      c = d;
    }
    return c;
  }
};
