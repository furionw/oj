// Copyright 2016 Qi Wang
// Date: 2016-11-26

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    // the type of l and r should be size_t !!!
    size_t l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (isBadVersion(mid)) {
        if (mid == 1 || !isBadVersion(mid - 1)) {
          return mid;
        } else {
          r = mid - 1;
        }
      } else {
        l = mid + 1;
      }
    }
    return -1;  // comfort the compiler
  }
};