// Copyright 2017 Qi Wang
// Date: 2017-10-12
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          max_area = max(max_area, Dfs(&grid, i, j));
        }
      }
    }
    return max_area;
  }
 
 private:
  int Dfs(vector<vector<int>>* grid, int x, int y) const {
    (*grid)[x][y] = 0;
    int area = 1;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int i = x + delta[d], j = y + delta[d + 1];
      if (0 <= i && i < grid->size() && 0 <= j && j < (*grid)[0].size() &&
          (*grid)[i][j] == 1) {
        area += Dfs(grid, i, j);
      }
    }
    return area;
  }
};
