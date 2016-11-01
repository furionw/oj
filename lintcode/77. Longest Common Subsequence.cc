// Copyright 2016 Qi Wang
// Date: 2016-11-01
class Solution {
 public:
  int longestCommonSubsequence(string A, string B) {
    int dp[A.size() + 1][B.size() + 1];
    memset(dp, 0, sizeof dp);
    int res = 0;
    for (int i = 1; i <= A.size(); ++i)
      for (int j = 1; j <= B.size(); ++j) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]
            + (A[i - 1] == B[j - 1] ? 1 : 0));
        res = max(res, dp[i][j]);
      }
    return res;
  }
};
