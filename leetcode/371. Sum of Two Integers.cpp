// Copyright 2016 Qi Wang
// Date: 2016-10-02
class Solution {
 public:
  int getSum(int a, int b) {
    int res = 0;
    bool carry = false;
    for (size_t mask = 1; mask != 0; mask <<= 1) {
      bool aBit = a & mask;
      bool bBit = b & mask;
      if (carry) {
        // with carry
        if (aBit && bBit) {
          res |= mask;
        } else if (!aBit && !bBit) {
          res |= mask;
          carry = false;
        }
      } else {
        // no carry
        if (aBit && bBit) {
          carry = true;
        } else if (aBit || bBit) {
          res |= mask;
        }
      }
    }
    return res;
  }
};
