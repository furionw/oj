// Copyright 2017 Qi Wang
// Date: 2017-05-24
class Solution {
 public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1,
        vector<int>(word2.size() + 1, 0));
    for (size_t i = 1; i <= word1.size(); ++i)
      for (size_t j = 1; j <= word2.size(); ++j)
        dp[i][j] = max(dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1]),
            max(dp[i][j - 1], dp[i - 1][j]));
    return word1.size() + word2.size() - dp.back().back() * 2;
  }
};
