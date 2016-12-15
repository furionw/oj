// Copyright 2016 Qi Wang
// Date: 2016-12-15
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (const string& str : strs) {
      int cnts[] = {0, 0};
      for (char c : str) ++cnts[c - '0'];
      for (int zeroCnt = m; zeroCnt - cnts[0] >= 0; --zeroCnt)
        for (int oneCnt = n; oneCnt - cnts[1] >= 0; --oneCnt)
          dp[zeroCnt][oneCnt] = max(dp[zeroCnt][oneCnt],
              dp[zeroCnt - cnts[0]][oneCnt - cnts[1]] + 1);
    }
    return dp[m][n];
  }
};
