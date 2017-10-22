// Copyright 2017 Qi Wang
// Date: 2017-10-21
class Solution {
 public:
  int numIslands(vector<vector<bool>> &grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j]) {
          Dfs(&grid, i, j);
          ++result;
        }
      }
    }
    return result;
  }
 
 private:
  void Dfs(vector<vector<bool>>* grid, int x, int y) const {
    (*grid)[x][y] = false;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int i = x + delta[d], j = y + delta[d + 1];
      if (i >= 0 && i < grid->size() && j >= 0 && j < (*grid)[0].size() &&
          (*grid)[i][j]) {
        Dfs(grid, i, j);
      }
    }
  }
};
