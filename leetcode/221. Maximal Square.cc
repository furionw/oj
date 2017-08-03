// Copyright 2017 Qi Wang
// Date: 2017-08-02
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int>> hor(m, vector<int>(n, 0));
    vector<vector<int>> ver(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        hor[i][j] = ver[i][j] = matrix[i][j] - '0';
        if (j > 0 && matrix[i][j] == '1') hor[i][j] += hor[i][j - 1];
        if (i > 0 && matrix[i][j] == '1') ver[i][j] += ver[i - 1][j];
      }
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = matrix[i][j] - '0';
        if (i > 0 && j > 0 && matrix[i][j] == '1')
          dp[i][j] = min(dp[i - 1][j - 1] + 1, min(hor[i][j], ver[i][j]));
        result = max(result, dp[i][j]);
      }
    }
    return result * result;
  }
};

// Date: 2016-11-07
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    // Note that we only handle some matrixs with limited size by 2^31
    int n = static_cast<int>(matrix.size()),
        m = static_cast<int>(matrix[0].size());
    // dp
    vector<vector<int>> dp(2, vector<int>(m, 0));
    int res = 0;
    // init
    for (int j = 0; j < m; ++j) {
      dp[0][j] = matrix[n - 1][j] == '1';
      res = max(res, dp[0][j]);
    }
    // deduct
    for (int i = n - 2; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        if (j == m - 1) {
          dp[1][j] = matrix[i][j] == '1';
        } else {
          if (matrix[i][j] == '1') {
            int hLen = 1, vLen = 1;
            for (; j + hLen < m && matrix[i][j + hLen] == '1'; ++hLen) {}
            for (; i + vLen < n && matrix[i + vLen][j] == '1'; ++vLen) {}
            dp[1][j] = min(hLen, min(vLen, dp[0][j + 1] + 1));
          } else {
            dp[1][j] = 0;
          }
        }
        res = max(res, dp[1][j]);
      }
      swap(dp[0], dp[1]);
    }
    return res * res;
  }
};
