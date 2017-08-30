// Copyright 2017 Qi Wang
// Date: 2017-08-29
class Solution {
 public:
  int firstBadVersion(int n) {
    int64_t l = 1, r = int64_t(n) + 1;
    while (l < r) {
      int64_t mid = l + r >> 1;
      if (isBadVersion(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};

// Date: 2017-08-17 
class Solution {
 public:
  int firstBadVersion(int n) {
    // "int64_t(n)" matters. Or the function will fail when n = INT_MAX
    int64_t left = 1, right = int64_t(n) + 1;
    while (left < right) {
      int mid = left + right >> 1;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
 
// Date: 2017-08-17
class Solution {
 public:
  int firstBadVersion(int n) {
    uint64_t l = 1, r = n;
    int last_bad_version = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (isBadVersion(mid)) {
        r = mid - 1;
        last_bad_version = mid;
      } else {
        l = mid + 1;
      }
    }
    return last_bad_version;
  }
};

// Date: 2017-07-04 
class Solution {
 public:
  int firstBadVersion(int n) {
    // my bug: the type of l and r should be size_t !!!
    size_t l = 1, r = n, mid;
    while (l <= r) {
      mid = l + r >> 1;
      if (isBadVersion(mid)) {
        // You'd better not call isBadVersion here.
        // Please refer to the solution on 2017-08-12
        if (1 == mid || !isBadVersion(mid - 1)) return mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return mid;
  }
};

// Date: 2017-03-04
class Solution {
 public:
  int firstBadVersion(int n) {
    for (size_t l = 1, r = n; l <= r; ) {
      int mid = (l + r) >> 1;
      if (isBadVersion(mid)) {
        if (mid - 1 == 0 || !isBadVersion(mid - 1)) return mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;  // comfort the compiler
  }
};

// Date: 2016-11-26
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
