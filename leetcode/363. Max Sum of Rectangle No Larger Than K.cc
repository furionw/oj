// Copyright 2017 Qi Wang
// Date: 2017-04-17
// Refer to: https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references/44
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    size_t rows = matrix.size(), cols = matrix[0].size();
    int result = INT_MIN;
    for (int l = 0; l < cols; ++l) {
      vector<int> sums(rows, 0);
      for (int r = l; r < cols; ++r) {
        // update sums
        for (int i = 0; i < rows; ++i) sums[i] += matrix[i][r];
        set<int> s;
        s.insert(0);
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
          sum += sums[i];
          auto it = s.lower_bound(sum - k);
          if (it != s.end()) result = max(result, sum - *it);
          s.insert(sum);
        }
      }
    }
    return result;
  }
};

// Date: 2016-12-22
class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    size_t m = matrix.size(), n = matrix[0].size();
    for (size_t i = 1; i < m; ++i)
      matrix[i][0] += matrix[i - 1][0];
    for (size_t j = 1; j < n; ++j)
      matrix[0][j] += matrix[0][j - 1];
    for (size_t i = 1; i < m; ++i)
      for (size_t j = 1; j < n; ++j)
        matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1]
            - matrix[i - 1][j - 1];
    int res = INT_MIN;
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j) {
        updateOrRemain(res, matrix[i][j], k);
        for (size_t p = 0; p < i; ++p)
          updateOrRemain(res, matrix[i][j] - matrix[p][j], k);
        for (size_t q = 0; q < j; ++q)
          updateOrRemain(res, matrix[i][j] - matrix[i][q], k);
        for (size_t p = 0; p < i; ++p)
          for (size_t q = 0; q < j; ++q)
            updateOrRemain(res, matrix[i][j] - matrix[p][j] - matrix[i][q]
                + matrix[p][q], k);
      }
    return res;
  }

 private:
  void updateOrRemain(int& res, int temp, int k) const {
    res = temp > res && temp <= k ? temp : res;  // update or remain
  }
};
