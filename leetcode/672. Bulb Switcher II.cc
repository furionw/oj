// Copyright 2017 Qi Wang
// Date: 2017-09-03
class Solution {
 public:
  int flipLights(int n, int m) {
    if (m == 0) return 1;
    if (n == 1) {
      return 2;
    } else if (n == 2) {
      return m == 1 ? 3 : 4; 
    // n > 2
    } else {
      if (m == 1) {
        return 4;
      } else if (m == 2) {
        return 7;
      // m >= 3
      } else {
        return 8;
      }
    }
  }
};
