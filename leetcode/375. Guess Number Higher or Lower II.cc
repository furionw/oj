// Copyright 2016 Qi Wang
// Refer to: https://www.hrwhisper.me/leetcode-guess-number-higher-lower-ii/
// Date: 2016-11-25
class Solution {
 public:
  // No that the return value could be wrong when the n is large enough
  int getMoneyAmount(int n) {
    int dp[n + 1][n + 1];
    // init
    for (int i = 1; i <= n ; ++i)
      dp[i][i] = 0;
    // deduct
    for (int tot = 2; tot <= n; ++tot) {
      for (int l = 1, r = tot; r <= n; ++l, ++r) {
        dp[l][r] = l + dp[l + 1][r];
        for (int mid = l + 1; mid < r; ++mid)
          dp[l][r] = min(dp[l][r], mid + max(dp[l][mid - 1], dp[mid + 1][r]));
      }
    }
    return dp[1][n];
  }
};
