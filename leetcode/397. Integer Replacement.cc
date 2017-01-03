// Copyright 2017 Qi Wang
// Date: 2017-01-03
// Refer to: https://discuss.leetcode.com/topic/58334/a-couple-of-java-solutions-with-explanations
class Solution {
 public:
  int integerReplacement(int n) {
    if (n == INT_MAX) return 32;
    int cnt = 0;
    for (; n > 1; ++cnt) {
      if ((n & 1) == 0) {
        n >>= 1;
      } else if (n == 3 || (n & 3) == 1) {
        --n;
      } else {
        ++n;
      }
    }
    return cnt;
  }
};

// Date: 2016-11-16
class Solution {
 public:
  int integerReplacement(int n) {
    int res = INT_MAX;
    dfs(n, 0, res);
    return res;
  }

 private:
  // Use the size_t handle the case where n == INT_MAX
  // actually we can do better just use the if stmt, like the solution
  // presented on 2017-01-03.
  // Commented on 2017-01-03
  void dfs(size_t n, int cnt, int& res) {
    if (cnt >= res) {
      // prune
      return;
    } else if (n == 1) {
      res = cnt;
    } else {
      // even
      if ((n & 1) == 0) {
        dfs(n >> 1, cnt + 1, res);
      // odd
      } else {
        dfs(n - 1, cnt + 1, res);
        dfs(n + 1, cnt + 1, res);
      }
    }
  }
};
