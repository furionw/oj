// Copyright 2017 Qi Wang
// Date: 2017-07-04
// According to the result, the solution on 2017-02-18 is faster.
class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A,
      vector<vector<int>>& B) {
    if (A.empty() || A[0].empty()) return {};
    // A: m * n, B: p * q. n == p
    size_t m = A.size();
    size_t p = B.size(), q = B[0].size();
    vector<bool> a_row_non_zero(m, false), b_col_non_zero(q, false);
    for (size_t i = 0; i < m; ++i)
      a_row_non_zero[i] = any_of(A[i].begin(), A[i].end(), [](int num) {
        return num != 0;
      });
    for (size_t j = 0; j < q; ++j) {
      bool non_zero = false;
      for (size_t i = 0; i < p && !non_zero; ++i)
        non_zero = B[i][j] != 0;
      b_col_non_zero[j] = non_zero;
    }
    vector<vector<int>> result(m, vector<int>(q, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < q; ++j)
        if (a_row_non_zero[i] && b_col_non_zero[j]) {
          int64_t sum = 0;
          for (size_t k = 0; k < p; ++k)
            sum += A[i][k] * B[k][j];
          result[i][j] = sum;
        }
    return result;
  }
};

// Date: 2017-02-18
// Refer to: https://discuss.leetcode.com/topic/30625/easiest-java-solution
class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.empty() || A[0].empty()) return A;
    int n = A.size(), m = A[0].size(), k = B[0].size();
    vector<vector<int>> result(n, vector<int>(k, 0));
    for (int i = 0; i < n; ++i)
      for (int p = 0; p < m; ++p)
        if (A[i][p] != 0)
          for (int j = 0; j < k; ++j)
            result[i][j] += A[i][p] * B[p][j];
    return result;
  }
};

// Date: 2017-02-18
// TLE
class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.empty() || A[0].empty()) return A;
    int n = A.size(), m = A[0].size(), k = B[0].size();
    vector<vector<int>> result(n, vector<int>(k, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < k; ++j)
        for (int p = 0; p < m; ++p)
          result[i][j] += A[i][p] * B[p][j];
    return result;
  }
};
