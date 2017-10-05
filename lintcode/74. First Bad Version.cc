// Copyright 2017 Qi Wang
// Date: 2017-10-05
class Solution {
 public:
  int findFirstBadVersion(int n) {
    int64_t l = 1, result = 0;
    while (l <= n) {
      int mid = (l + n) >> 1;
      if (SVNRepo::isBadVersion(mid)) {
        n = mid - 1;
        result = mid;
      } else {
        l = mid + 1;
      }
    }
    return result;
  }
};
