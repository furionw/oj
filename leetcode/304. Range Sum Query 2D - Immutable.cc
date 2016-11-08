// Copyright 2016 Qi Wang
// Dynamic programming
// Refer to: other's blog
// Date: 2016-11-08
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty()) return;
    size_t n = matrix.size() + 1, m = matrix[0].size() + 1;
    sum = vector<vector<int>>(n, vector<int>(m, 0));
    for (size_t i = 1; i < n; ++i)
      for (size_t j = 1; j < m; ++j)
        sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1]
            - sum[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (sum.empty()) return 0;
    return sum[row2 + 1][col2 + 1] + sum[row1][col1]
        - sum[row2 + 1][col1] - sum[row1][col2 + 1];
  }

  vector<vector<int>> sum;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
