// Copyright 2017 Qi Wang
// Date: 2017-06-03
// Refer to: https://discuss.leetcode.com/topic/88492/c-6-lines-dp-o-n-m-n-6-ms
class Solution {
 public:
  int findPaths(int m, int n, int N, int l, int k) {
    uint32_t dp[2][50][50];
    memset(dp, 0, sizeof dp);
    bool flag = false;
    while (N-- > 0) {
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          dp[flag][i][j] = ((i == 0 ? 1 : dp[!flag][i - 1][j]) +
              (i == m - 1 ? 1 : dp[!flag][i + 1][j]) +
              (j == 0 ? 1 : dp[!flag][i][j - 1]) +
              (j == n - 1 ? 1 : dp[!flag][i][j + 1])) % 1000000007;
      flag = !flag;
    }
    return dp[!flag][l][k];
  }
};
