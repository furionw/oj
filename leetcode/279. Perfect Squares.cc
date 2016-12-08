// Copyright 2016 Qi Wang
// Math: Lagrange's four-square theorem
// Refer to: https://www.cnblogs.com/grandyang/p/4800552.html
//   - lack of proof
// Date: 2016-12-08
class Solution {
 public:
  int numSquares(int n) {

  }
};

// DP
// Date: 2016-12-08
class Solution {
 public:
  int numSquares(int n) {
    int dp[n + 1];
    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
      for (int sqrt = std::sqrt(i); sqrt >= 1; --sqrt)
        dp[i] = min(dp[i], dp[i - sqrt * sqrt] + 1);
    return dp[n];
  }
};
