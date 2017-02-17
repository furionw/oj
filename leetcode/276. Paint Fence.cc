// Copyright 2017 Qi Wang
// Date: 2017-02-17
class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 0 || k == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = k;
    for (size_t i = 1; i < n; ++i) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1);
      dp[i][1] = dp[i - 1][0];
    }
    return dp.back()[0] + dp.back()[1];
  }
};
