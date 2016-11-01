// Copyright 2016 Qi Wang
// Date: 2016-11-01
// Use state compression technique introduced in CLRS 15.4
// Actually the space could be only "slightly" more than one row.
class Solution {
 public:
  int longestCommonSubsequence(string A, string B) {
    vector<vector<int>> dp(2, vector<int>(B.size() + 1, 0));
    int res = 0;
    for (int i = 1; i <= A.size(); ++i) {
      for (int j = 1; j <= B.size(); ++j) {
        dp[1][j] = max(dp[0][j], dp[1][j - 1]);
        dp[1][j] = max(dp[1][j], dp[0][j - 1]
            + (A[i - 1] == B[j - 1] ? 1 : 0));
        res = max(res, dp[1][j]);
      }
      swap(dp[0], dp[1]);
    }
    return res;
  }
};
