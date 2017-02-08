// Copyright 2017 Qi Wang
// Date: 2017-02-08
// Refer to: https://discuss.leetcode.com/topic/77918/c-without-paying-too-much-attention-on-direction-switch
// Slower than the first implementation
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return vector<int>();
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    for (int i = 0; i < m + n - 1; ++i) {
      int x = max(0, i - n + 1), y = min(i, n - 1);
      vector<int> nums(1, matrix[x][y]);
      while (true) {
        ++x, --y;
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
          break;
        nums.push_back(matrix[x][y]);
      }
      // odd
      if (i & 1) {
        result.insert(result.end(), nums.begin(), nums.end());
      // even
      } else {
        result.insert(result.end(), nums.rbegin(), nums.rend());
      }
    }
    return result;
  }
};

// Date: 2017-02-08
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return vector<int>();
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result;
    pair<int, int> pos = {0, 0};
    for (bool from_left = true; pos.first != -1; from_left = !from_left) {
      if (from_left) {
        start_from_left(matrix, pos, result);
      } else {
        start_from_top(matrix, pos, result);
      }
    }
    return result;
  }

 private:
  void start_from_top(const vector<vector<int>>& matrix,
      pair<int, int>& pos, vector<int>& result) const {
    result.push_back(matrix[pos.first][pos.second]);
    while (true) {
      int x = pos.first + 1;
      int y = pos.second - 1;
      if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
        break;
      result.push_back(matrix[x][y]);
      pos = {x, y};
    }
    // advance
    if (pos.first + 1 < matrix.size()) {
      ++pos.first;
    } else if (pos.second + 1 < matrix[0].size()) {
      ++pos.second;
    } else {
      pos = {-1, -1};
    }
  }

  void start_from_left(const vector<vector<int>>& matrix,
      pair<int, int>& pos, vector<int>& result) const {
    result.push_back(matrix[pos.first][pos.second]);
    while (true) {
      int x = pos.first - 1;
      int y = pos.second + 1;
      if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
        break;
      result.push_back(matrix[x][y]);
      pos = {x, y};
    }
    // advance
    if (pos.second + 1 < matrix[0].size()) {
      ++pos.second;
    } else if (pos.first + 1 < matrix.size()) {
      ++pos.first;
    } else {
      pos = {-1, -1};
    }
  }
};
