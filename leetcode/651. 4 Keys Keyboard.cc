// Copyright 2017 Qi Wang
// Date: 2017-07-29
// Refer to: 1st place, cchao's solution
class Solution {
 public:
  int maxA(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      dp[i] = i;
    for (int i = 1; i < n; ++i) {
      for (int j = i + 3, k = dp[i]; j <= n; ++j, k += dp[i]) {
        dp[j] = max(dp[j], dp[i] + k);
      }
    }
    return dp[n];
  }
};
