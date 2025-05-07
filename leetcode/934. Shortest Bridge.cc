// 2025-05-06
// Method 1
class Solution {
 public:
  int shortestBridge(vector<vector<int>>& _grid) {
    grid = _grid;
    n = grid.size();
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<vector<int>> island1, island2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] && !visited[i][j]) {
          bfs(i, j, island1.empty() ? island1 : island2);
        }
      }
    }

    int result = numeric_limits<int>::max();
    for (const auto& p1 : island1) {
      for (const auto& p2: island2) {
        assert(p1 != p2);
        int dist = abs(p1[0] - p2[0])
            + abs(p1[1] - p2[1])
            - (p1[0] != p2[0] || p1[1] != p2[1] ? 1 : 0);
        result = min(result, dist);
      }
    }
    return result;
  }

 private:
  void bfs(int i, int j, vector<vector<int>>& island) {
    queue<vector<int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty()) {
      i = q.front()[0];
      j = q.front()[1];
      island.push_back({i, j});
      q.pop();
      static vector<vector<int>> delta {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
      };
      for (const auto& d : delta) {
        int x = i + d[0];
        int y = j + d[1];
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || grid[x][y] == 0) {
          continue;
        }
        q.push({x, y});
        visited[x][y] = true;
      }
    }
  }

  int n;
  vector<vector<int>> grid;
  vector<vector<bool>> visited;
};

// Method 2
class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          x = i;
          y = j;
          break;
        }
      }
      if (x != -1) {
        break;
      }
    }

    queue<pair<int, int>> q, q2;
    q.push({x, y});
    q2.push({x, y});
    grid[x][y] = 2;
    while (!q.empty()) {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      vector<pair<int, int>> nexts {
        {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}
      };
      for (const auto& next : nexts) {
        x = next.first, y = next.second;
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) {
          continue;
        }
        grid[x][y] = 2;
        q.push({x, y});
        q2.push({x, y});
      }
    }

    int dist = 0;
    q.swap(q2);
    while (!q.empty()) {
      while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        vector<pair<int, int>> nexts {
          {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}
        };
        for (const auto& next : nexts) {
          x = next.first, y = next.second;
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          if (grid[x][y] == 1) {
            return dist;
          }
          if (grid[x][y] != 0) {
            continue;
          }
          grid[x][y] = -1;
          q2.push({x, y});
        }
      }
      ++dist;
      q.swap(q2);
    }
    return dist;
  }
};
