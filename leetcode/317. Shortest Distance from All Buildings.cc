// 2025-06-17
// Method 2 -- start from buildings

// Method 1
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int buildingCount = 0;
    for (auto& row : grid) {
      for (int& num : row) {
        if (num == 1) {
          num = kBuilding;
          ++buildingCount;
        } else if (num == 2) {
          num = kObstacle;
        }
      }
    }
    int result = numeric_limits<int>::max();
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == kLand) {
          result = min(result, bfs(grid, i, j, buildingCount));
        }
      }
    }
    return result == numeric_limits<int>::max() ? -1 : result;
  }

 private:
  int bfs(vector<vector<int>> grid, int x, int y, int buildingCount) {
    int result = 0;
    int actualBuildingCount = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;
    while (!q.empty()) {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      static constexpr int d[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; ++k) {
        int i = x + d[k];
        int j = y + d[k + 1];
        if (i < 0 || i >= m || j < 0 || j >= n 
            || visited[i][j]
            || grid[i][j] == kObstacle) {
          continue;
        }
        visited[i][j] = true;
        if (grid[i][j] == kBuilding) {
          ++actualBuildingCount;
          result += grid[x][y] + 1;
        } else if (grid[i][j] == kLand) {
          grid[i][j] = grid[x][y] + 1;
          q.emplace(i, j);
        }
      }
    }
    return actualBuildingCount == buildingCount
        ? result
        : numeric_limits<int>::max();
  }

  static constexpr int kLand = 0;
  static constexpr int kBuilding = -1;
  static constexpr int kObstacle = -2;
};

// Date: 2017-10-24
// Refer to the solution on 2016-12-25
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    int m =  grid.size(), n = grid[0].size();
    int stage = 0;
    auto tot = grid;
    int min_dist;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1) continue;
        static constexpr int delta[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.emplace(i, j);
        auto dist = grid;
        min_dist = -1;
        while (!q.empty()) {
          auto p = q.front(); q.pop();
          for (int d = 0; d < 4; ++d) {
            int x = p.first + delta[d], y = p.second + delta[d + 1];
            if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == stage) {
              // This empty land is still valid in the next stage.
              --grid[x][y];
              // Place this position in the queue.
              q.emplace(x, y);
              // Records its distance so that it could be used when it's fetched
              // from the queue.
              dist[x][y] = dist[p.first][p.second] + 1;
              tot[x][y] += dist[x][y] - 1;
              // Updates the result.
              if (min_dist == -1 || min_dist > tot[x][y]) min_dist = tot[x][y];
            }
          }
        }
        --stage;
      }
    }
    return min_dist;
  }
};

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
