// Copyright 2016 Qi Wang
// Date: 2016-12-22
class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = static_cast<int>(grid.size()),
        n = static_cast<int>(grid[0].size());
    int up[m][n], down[m][n], left[m][n], right[m][n];
    memset(up, 0, sizeof up);
    memset(down, 0, sizeof down);
    memset(left, 0, sizeof left);
    memset(right, 0, sizeof right);
    // top down
    for (int i = 1; i < m; ++i)
      for (int j = 0; j < n; ++j)
        up[i][j] = grid[i - 1][j] == 'W'
            ? 0 : up[i - 1][j] + (grid[i - 1][j] == 'E');
    // bottom up
    for (int i = m - 2; i >= 0; --i)
      for (int j = 0; j < n; ++j)
        down[i][j] = grid[i + 1][j] == 'W'
            ? 0 : down[i + 1][j] + (grid[i + 1][j] == 'E');
    // left to right
    for (int i = 0; i < m; ++i)
      for (int j = 1; j < n; ++j)
        left[i][j] = grid[i][j - 1] == 'W'
            ? 0 : left[i][j - 1] + (grid[i][j - 1] == 'E');
    // right to left
    for (int i = 0; i < m; ++i)
      for (int j = n - 2; j >= 0; --j)
        right[i][j] = grid[i][j + 1] == 'W'
            ? 0 : right[i][j + 1] + (grid[i][j + 1] == 'E');
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '0')
          res = max(res, up[i][j] + down[i][j] + left[i][j] + right[i][j]);
    return res;
  }
};

// Date: 2016-12-22
// Method 1: TLE
class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != '0') continue;
        int temp = 0;
        // upwards
        for (int k = i - 1; k >= 0 && grid[k][j] != 'W'; --k)
          temp += grid[k][j] == 'E';
        // downwards
        for (int k = i + 1; k < m && grid[k][j] != 'W'; ++k)
          temp += grid[k][j] == 'E';
        // backwards, from middle to left
        for (int k = j - 1; k >= 0 && grid[i][k] != 'W'; --k)
          temp += grid[i][k] == 'E';
        // towards, from middle to right
        for (int k = j + 1; k < n && grid[i][k] != 'W'; ++k)
          temp += grid[i][k] == 'E';
        res = max(res, temp);
      }
    return res;
  }
};
