// Copyright 2017 Qi Wang
// Date: 2017-04-16
class Solution {
 public:
  int checkRecord(int n) {
    int dp[2][2][3];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    // dp init
    for (int i = 1; i <= n; ++i) {
      // dp deduct
      dp[1][0][0] = accumulate(dp[0][0], dp[0][0] + 3, uint64_t(0)) % DIVISOR;
      dp[1][0][1] = dp[0][0][0];
      dp[1][0][2] = dp[0][0][1];
      dp[1][1][0] = (accumulate(dp[0][0], dp[0][0] + 3, uint64_t(0))
          + accumulate(dp[0][1], dp[0][1] + 3, uint64_t(0))) % DIVISOR;
      dp[1][1][1] = dp[0][1][0];
      dp[1][1][2] = dp[0][1][1];
      // copy
      copy(dp[1][0], dp[1][0] + 3, dp[0][0]);
      copy(dp[1][1], dp[1][1] + 3, dp[0][1]);
    }
    return (accumulate(dp[1][0], dp[1][0] + 3, uint64_t(0))
          + accumulate(dp[1][1], dp[1][1] + 3, uint64_t(0))) % DIVISOR;
  }

 private:
  static constexpr int DIVISOR = 1e9 + 7;
};
