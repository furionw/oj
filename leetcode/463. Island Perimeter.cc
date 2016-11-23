// Copyright 2016 Qi Wang
// Date: 2016-11-23
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j]) {
          // up
          if (i == 0 || !grid[i - 1][j]) ++res;
          // bottom
          if (i == grid.size() - 1 || !grid[i + 1][j]) ++res;
          // left
          if (j == 0 || !grid[i][j - 1]) ++ res;
          // right
          if (j == grid[0].size() - 1 || !grid[i][j + 1]) ++res;
        }
    return res;
  }
};
