// Copyright 2017 Qi Wang
// Date: 2017-09-04
// Case 1: [[1, 2], [3, 4]], 4
// Case 2: [[1, 2], [3, 4]], 5
// LC 240
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int x = 0, y = matrix[0].size() - 1;
    while (x < matrix.size() && y >= 0) {
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] > target) {
        --y;
      } else {
        ++x;
      }
    }
    return false;
  }
};