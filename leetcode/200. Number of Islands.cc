// Copyright 2017 Qi Wang
// Date: 2017-08-31
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++result;
          Dfs(&grid, i, j);
        }
      }
    }
    return result;
  }

 private:
  void Dfs(vector<vector<char>>* grid, int i, int j) const {
    (*grid)[i][j] = '2';
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + delta[d], y = j + delta[d + 1];
      if (0 <= x && x < grid->size() && 0 <= y && y < (*grid)[0].size()
          && (*grid)[x][y] == '1') Dfs(grid, x, y);
    }
  }
};

// Date: 2017-07-10
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int result = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '1') {
          Dfs(grid, i, j);
          ++result;
        }
    return result;
  }

 private:
  void Dfs(vector<vector<char>>& grid, int i, int j) const {
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    grid[i][j] = '0';
    for (int d = 0; d < 4; ++d) {
      int x = i + delta[d], y = j + delta[d + 1];
      if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() &&
          '1' == grid[x][y]) {
        Dfs(grid, x, y);
      }
    }
  }
};

// Date: 2017-01-01
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int cnt = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '1') {
          ++cnt;
          dfs(grid, i, j);
        }
    return cnt;
  }

 private:
  void dfs(vector<vector<char>>& grid, int i, int j) const {
    ++grid[i][j];  // mark it as visited
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + DELTA[d], y = j + DELTA[d + 1];
      if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()
          && grid[x][y] == '1') dfs(grid, x, y);
    }
  }
};

// Date: 2015-06
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
      if (grid.size() == 0)
      {
        return 0;
      }

      int cnt = 0;      
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));

      for (int i = 0; i < grid.size(); ++ i)
      {
        for (int j = 0; j < grid[0].size(); ++ j)
        {
          if (grid[i][j] == '1' && vi[i][j] == false)
          {
            ++ cnt;
            dfs(i, j, grid, vi, dir);
          }
        }
      }

      return cnt;
    }

private:
  void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vi, int dir[][2])
  {
    vi[x][y] = true;
    for (int i = 0; i < 4; ++ i)
    {
      int new_x = x+dir[i][0], new_y = y+dir[i][1];
      if (new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size()
        && grid[new_x][new_y]=='1' && vi[new_x][new_y]==false)
      {
          dfs(new_x, new_y, grid, vi, dir);
      }
    }
  }
};

// 2015-04
class Solution 
{
public:
    int numIslands(vector<vector<char>> &grid) 
    {
      if (grid.size() == 0)
      {
        return 0;
      }

      int cnt = 0;
      vector<vector<bool>> vi(grid.size(), vector<bool>(grid[0].size(), false));   

      for (size_t i = 0; i < grid.size(); ++ i)
      {
        for (size_t j = 0; j < grid[0].size(); ++ j)
        {
          if (grid[i][j] == '1' && vi[i][j] == false)
          {
            ++ cnt;
            bfs(static_cast<int>(i), static_cast<int>(j), grid, vi);
          }
        }
      }

      return cnt;
    }
private:
  void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vi)
  {
    vi[x][y] = true;

    int offset[] = {-1, 0, 1};
    for (int i = 0; i < 3; ++ i)
    {
      for (int j = 0; j < 3; ++ j)
      {
        // offset constrains
        if (i == j || i+j == 2)
        {
          continue;
        }
        int xx = x+offset[i], yy = y+offset[j];
        if (xx >= 0 && xx < grid.size()
          && yy >=0 && yy < grid[0].size())
        {
          if (grid[xx][yy] == '1' && vi[xx][yy] == false)
          {
            vi[xx][yy] = true;
            bfs(xx, yy, grid, vi);
          }
        }
      }
    }
  }
};