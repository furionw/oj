// Copyright 2017 Qi Wang
// Date: 2017-10-11
// Case 1: 2, INT_MIN -> 
// Case 2: 2, 0
class Solution {
 public:
  double myPow(double x, int n) {
    if (n == INT_MIN) {
      double sqrt = myPow(x, n / 2);
      return sqrt * sqrt;
    } else if (n < 0) {
      return 1 / myPow(x, -n);
    } else if (n == 0) {
      return 1;
    } else {
      double sqrt = myPow(x, n / 2);
      return sqrt * sqrt * (n % 2 == 1 ? x : 1);
    }
  }
};
