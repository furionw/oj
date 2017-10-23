// Copyright 2017 Qi Wang
// Date: 2017-10-22
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    if (s1.empty()) {
      return accumulate(s2.begin(), s2.end(), int(0));
    } else if (s2.empty()) {
      return accumulate(s1.begin(), s1.end(), int(0));      
    } else {
      int m = s1.size(), n = s2.size();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      for (int i = 1; i <= m; ++i) {
        dp[i][0] = s1[i - 1];
      }
      for (int j = 1; j <= n; ++j) {
        dp[0][j] = s2[j - 1];
      }
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
          }
        }
      }
      return dp[m][n];
    }
  }
};
