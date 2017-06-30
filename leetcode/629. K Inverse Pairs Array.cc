// Copyright 2017 Qi Wang
// Date: 2017-06-30
// Refer to: https://discuss.leetcode.com/topic/93765/shared-my-c-o-n-k-solution-with-explanation
class Solution {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    int flag = 0;
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[flag][j] = (dp[!flag][j] + dp[flag][j - 1]) % MOD;
        if (i <= j)
          dp[flag][j] = (dp[flag][j] - dp[!flag][j - i] + MOD) % MOD;
      }
      flag = !flag;
    }
    return dp[!flag][k];
  }
 
 private:
  static constexpr int MOD = 1e9 + 7;
};
