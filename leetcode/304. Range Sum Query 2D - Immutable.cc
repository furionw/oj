// Copyright 2016 Qi Wang
// Date: 2016-12-22
// Method 3: refer to the solution on 2016-11-08
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty()) return;
    // m and n are assigned as (sz + 1)
    size_t m = matrix.size() + 1, n = matrix[0].size() + 1;
    sums_ = vector<vector<int>>(m, vector<int>(n, 0));
    for (size_t i = 1; i < m; ++i)
      for (size_t j = 1; j < n; ++j)
        sums_[i][j] = matrix[i - 1][j - 1] + sums_[i - 1][j]
            + sums_[i][j - 1] - sums_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (!(!sums_.empty() && !sums_[0].empty()
        && validRowIdx(row1) && validColIdx(col1) && validRowIdx(row2)
        && validColIdx(col2) && row1 <= row2 && col1 <= col2)) {
      cerr << "Invalid input\n";
      return INT_MIN;
    }
    return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1]
        - sums_[row1][col2 + 1] + sums_[row1][col1];
  }

 private:
  bool validRowIdx(int row) const { return 0 <= row && row + 1 < sums_.size(); }
  bool validColIdx(int col) const { return 0 <= col && col + 1 < sums_[0].size(); }
  vector<vector<int>> sums_;
};

// Copyright 2016 Qi Wang
// Date: 2016-12-22
// Method 2: 20 ms
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty()) return;
    size_t m = matrix.size(), n = matrix[0].size();
    sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 1; i <= m; ++i)
      sums_[i][0] = matrix[i - 1][0] + sums_[i - 1][0];
    for (size_t j = 1; j <= n; ++j)
      sums_[0][j] = matrix[0][j - 1] + sums_[0][j - 1];
    for (size_t i = 1; i <= m; ++i)
      for (size_t j = 1; j <= n; ++j)
        sums_[i][j] = matrix[i - 1][j - 1] + sums_[i - 1][j]
            + sums_[i][j - 1] - sums_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (!(!sums_.empty() && !sums_[0].empty()
        && validRowIdx(row1) && validColIdx(col1) && validRowIdx(row2)
        && validColIdx(col2) && row1 <= row2 && col1 <= col2)) {
      cerr << "Invalid input\n";
      return INT_MIN;
    }
    return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1]
        - sums_[row1][col2 + 1] + sums_[row1][col1];
  }

 private:
  bool validRowIdx(int row) const { return 0 <= row && row + 1 < sums_.size(); }
  bool validColIdx(int col) const { return 0 <= col && col + 1 < sums_[0].size(); }
  vector<vector<int>> sums_;
};

// Date: 2016-12-22
// Method 1: 100 ms, the processing turns slow due to "if-else" in the sumRegion()
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>> &matrix) : sums_(move(matrix)) {
    if (sums_.empty()) return;
    size_t m = sums_.size(), n = sums_[0].size();
    for (size_t i = 1; i < m; ++i)
      sums_[i][0] += sums_[i - 1][0];
    for (size_t j = 1; j < n; ++j)
      sums_[0][j] += sums_[0][j - 1];
    for (size_t i = 1; i < m; ++i)
      for (size_t j = 1; j < n; ++j)
        sums_[i][j] += sums_[i - 1][j] + sums_[i][j - 1] - sums_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (!(!sums_.empty() && !sums_[0].empty()
        && validRowIdx(row1) && validColIdx(col1) && validRowIdx(row2)
        && validColIdx(col2) && row1 <= row2 && col1 <= col2)) {
      cerr << "Invalid input\n";
      return 1;
    }
    if (row1 == 0 && col1 == 0) {
      return sums_[row2][col2];
    } else if (row1 == 0) {
      return sums_[row2][col2] - sums_[row2][col1 - 1];
    } else if (col1 == 0) {
      return sums_[row2][col2] - sums_[row1 - 1][col2];
    } else {
      return sums_[row2][col2] - sums_[row2][col1 - 1]
          - sums_[row1 - 1][col2] + sums_[row1 - 1][col1 - 1];
    }
  }

 private:
  bool validRowIdx(int row) const { return 0 <= row && row < sums_.size(); }
  bool validColIdx(int col) const { return 0 <= col && col < sums_[0].size(); }
  vector<vector<int>> sums_;
};

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
