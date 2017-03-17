// Copyright 2017 Qi Wang
// Date: 2017-03-11
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); ++i)
      dp[i][i] = 1;
    int result = 1;
    for (int offset = 1; offset < s.size(); ++offset) {
      for (int i = 0; i + offset < s.size(); ++i) {
        int j = i + offset;
        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        if (s[i] == s[j]) dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
      }
    }
    return dp[0][s.size() - 1];
  }
};

// Copyright 2017 Qi Wang
// Date: 2017-03-11
// Refer to: https://discuss.leetcode.com/topic/78603/straight-forward-java-dp-solution
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < s.size(); ++j) {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        if (s[i] == s[j]) dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
      }
    }
    return dp[0][s.size() - 1];
  }
};
