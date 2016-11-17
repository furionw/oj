// Copyright 2016 Qi Wang
// Date: 2016-11-16
class Solution {
 public:
  int integerReplacement(int n) {
    int res = INT_MAX;
    dfs(n, 0, res);
    return res;
  }

 private:
  void dfs(size_t n, int cnt, int& res) {
    if (cnt >= res) {
      // prune
      return;
    } else if (n == 1) {
      res = cnt;
    } else {
      if ((n & 1) == 0) {
        // even
        dfs(n >> 1, cnt + 1, res);
      } else {
        // odd
        dfs(n - 1, cnt + 1, res);
        dfs(n + 1, cnt + 1, res);
      }
    }
  }
};
