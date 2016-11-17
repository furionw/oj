// Copyright 2016 Qi Wang
// Date: 2016-11-16
// The declaration is necessary here
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    size_t l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int ans = guess(mid);
      if (ans == 0) {
        return mid;
      } else if (ans == 1) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;  // comfort the compiler
  }
};
