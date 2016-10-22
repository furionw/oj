// Copyright 2016 Qi Wang
// Proof of correctness ???
// Date: 2016-10-11
class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    if (z > x + y) return false;
    if (x == 0 && y == 0) return z == 0;
    return z % gcd(x, y) == 0;
  }

 private:
  int gcd(int a, int b) const {
    return b == 0 ? a : gcd(b, a % b);
  }
};
