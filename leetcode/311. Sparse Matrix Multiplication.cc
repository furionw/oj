// Copyright 2017 Qi Wang
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
