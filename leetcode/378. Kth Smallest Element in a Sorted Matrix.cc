// Copyright 2017 Qi Wang
// Date: 2017-08-10
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || matrix[0].empty()) return INT_MIN;
    int64_t l = matrix[0][0], r = matrix.back().back() + 1;
    while (l < r) {
      int64_t mid = l + r >> 1;
      int cnt = 0;
      int j = matrix[0].size() - 1;
      for (int i = 0; i < matrix.size(); ++i) {
        for (; j >= 0 && matrix[i][j] > mid; --j) {}
        cnt += j + 1;
      }
      if (cnt < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};
