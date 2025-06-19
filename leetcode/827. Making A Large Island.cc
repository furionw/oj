// 2025-06-18
struct Result {
  int area;
  set<pair<int, int>> water;
};

class Solution {
 public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> islands(
        n, vector<vector<int>>(n, vector<int>{}));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int result = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          auto temp = bfs(grid, visited, i, j);
          result = max(result, temp.area);
          for (const auto& [x, y] : temp.water) {
            islands[x][y].push_back(temp.area);
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (islands[i][j].empty()) {
          continue;
        }
        assert(islands[i][j].size() <= 4);
        result = max(
            result,
            accumulate(islands[i][j].begin(), islands[i][j].end(), 1));
      }
    }
    return result;
  }

 private:
  Result bfs(
      const vector<vector<int>>& grid,
      vector<vector<bool>>& visited,
      int x,
      int y
  ) const {
    int n = grid.size();
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;

    int area = 0;
    set<pair<int, int>> water;
    while (!q.empty()) {
      ++area;
      x = q.front().first;
      y = q.front().second;
      q.pop();
      static constexpr int d[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; ++k) {
        int i = x + d[k];
        int j = y + d[k + 1];
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j]) {
          continue;
        }
        if (grid[i][j] == 0) {
          water.emplace(i, j);
        } else {
          q.emplace(i, j);
          visited[i][j] = true;
        }
      }
    }
    
    return {
      .area = area,
      .water = move(water)
    };
  }
};
