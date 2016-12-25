// Copyright 2016 Qi Wang
// Date: 2016-12-25
// Method 2: refer to the Top Solutions
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int m = grid.size(), n = static_cast<int>(grid[0].size());
    auto tot = grid;
    int walk = 0, minDist;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1) continue;
        // start from the building to find the connected empty lands
        minDist = -1;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        auto dist = grid;
        while (!q.empty()) {
          auto p = q.front();
          q.pop();
          int delta[] = {0, 1, 0, -1, 0};
          for (int d = 0; d < 4; ++d) {
            int x = p.first + delta[d], y = p.second + delta[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == walk) {
              q.emplace(x, y);
              --grid[x][y];
              dist[x][y] = dist[p.first][p.second] + 1;
              tot[x][y] += dist[x][y] - 1;
              if (minDist == -1 || minDist > tot[x][y]) minDist = tot[x][y];
            }
          }
        }
        --walk;
      }
    }
    return minDist;
  }
};

// Date: 2016-12-25
// Method 1
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int res = INT_MAX;
    int houseCnt = 0;
    for (auto& row : grid)
      for (int elem : row)
        houseCnt += elem == 1;
    bool found = false;
    for (int i = 0; i < static_cast<int>(grid.size()); ++i)
      for (int j = 0; j < static_cast<int>(grid[0].size()); ++j)
        if (grid[i][j] == 0) {
          int dis = bfs(grid, i, j, houseCnt);
          if (dis != -1) {
            found = true;
            res = min(res, dis);
          }
          found = found || dis != -1;
        }
    return found ? res : -1;
  }

 private:
  struct Cell {
    Cell() {}
    Cell(int i, int j, int d) : i(i), j(j), dis(d) {}
    int i, j, dis;
  };

  int bfs(const vector<vector<int>>& grid, int i, int j, int houseCnt) const {
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    bool vi[m][n];
    memset(vi, 0, sizeof vi);
    queue<Cell> q;
    q.emplace(i, j, 0);
    int res = 0;
    while (!q.empty()) {
      auto cell = q.front();
      q.pop();
      // top
      i = cell.i - 1, j = cell.j;
      if (i >= 0 && !vi[i][j]) {
        vi[i][j] = true;
        f(grid, i, j, cell, q, res, houseCnt);
      }
      // bot
      i = cell.i + 1, j = cell.j;
      if (i < m  && !vi[i][j]) {
        vi[i][j] = true;
        f(grid, i, j, cell, q, res, houseCnt);
      }
      // left
      i = cell.i, j = cell.j - 1;
      if (j >= 0 && !vi[i][j]) {
        vi[i][j] = true;
        f(grid, i, j, cell, q, res, houseCnt);
      }
      // right
      i = cell.i, j = cell.j + 1;
      if (j < n && !vi[i][j]) {
        vi[i][j] = true;
        f(grid, i, j, cell, q, res, houseCnt);
      }
    }
    return houseCnt == 0 ? res : -1;
  }

  void f(const vector<vector<int>>& grid, int i, int j, const Cell& cell,
      queue<Cell>& q, int& res, int& houseCnt) const {
    if (grid[i][j] == 0) {
      q.emplace(i, j, cell.dis + 1);
    } else if (grid[i][j] == 1) {
      res += cell.dis + 1;
      --houseCnt;
    }
  }
};
