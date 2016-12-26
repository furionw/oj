// Copyright 2016 Qi Wang
// Date: 2016-12-26
// Method 2: refer to the Top Solutions
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = static_cast<int>(matrix.size()),
        n = static_cast<int>(matrix[0].size());
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        res = max(res, dfs(matrix, i, j, dp));
    return res;
  }

 private:
  int dfs(const vector<vector<int>>& matrix, int i, int j,
      vector<vector<int>>& dp) const {
    if (dp[i][j]) return dp[i][j];
    int max = 1;
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++ d) {
      int x = i + DELTA[d], y = j + DELTA[d + 1];
      if (0 <= x && x < matrix.size() && 0 <= y && y < matrix[0].size()
          && matrix[i][j] < matrix[x][y])
        max = std::max(max, dfs(matrix, x, y, dp) + 1);
    }
    return dp[i][j] = max;
  }
};

// Date: 2016-12-26
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = static_cast<int>(matrix.size()),
        n = static_cast<int>(matrix[0].size());
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dfs(matrix, i, j, dp);
    int res = 1;
    for (auto& row : dp)
      for (auto& elem : row)
        res = max(res, elem);
    return res;
  }

 private:
  void dfs(const vector<vector<int>>& matrix, int i, int j,
      vector<vector<int>>& dp) const {
    static int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++ d) {
      int x = i + delta[d], y = j + delta[d + 1];
      if (0 <= x && x < matrix.size() && 0 <= y && y < matrix[0].size()
          && matrix[i][j] < matrix[x][y] && dp[i][j] + 1 > dp[x][y]) {
        dp[x][y] = dp[i][j] + 1;
        dfs(matrix, x, y, dp);
      }
    }
  }
};
