// Copyright 2017 Qi Wang
// Date: 2017-10-18
// Case 1: ""
// Case 2: "010"
// Case 3: "001100"
class Solution {
 public:
  int countBinarySubstrings(string s) {
    if (s.size() <= 1) return 0;
    vector<vector<int>> dp(s.size(), vector<int>(2, 0));
    dp[0][s[0] - '0'] = 1;
    for (int i = 1; i < s.size(); ++i) {
      dp[i][s[i] - '0'] = dp[i - 1][s[i] - '0'] + 1;
    }
    int result = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (i + 1 >= 2 * dp[i][s[i] - '0'] &&
          dp[i][s[i] - '0'] <= dp[i - dp[i][s[i] - '0']][!(s[i] - '0')]) {
        ++result;
      }
    }
    return result;
  }
};
