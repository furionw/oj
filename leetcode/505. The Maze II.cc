// Copyright 2017 Qi Wang
// Date: 2017-02-06
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
      vector<int>& dest) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dist_tbl(m, vector<int>(n, INT_MAX));
    dist_tbl[start[0]][start[1]] = 0;
    while (true) {
      int u[] = {-1, -1}, min_dist = INT_MAX;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (!visited[i][j] && dist_tbl[i][j] < min_dist)
            u[0] = i, u[1] = j, min_dist = dist_tbl[i][j];
      if (u[0] == -1) break;
      visited[u[0]][u[1]] = true;
      if (u[0] == dest[0] && u[1] == dest[1]) break;
      static constexpr int DELTA[] = {0, -1, 0, 1, 0};
      for (int d = 0; d < 4; ++d) {
        int dist = 1;
        while (true) {
          int v[] = {u[0] + dist * DELTA[d], u[1] + dist * DELTA[d + 1]};
          if (v[0] < 0 || v[0] >= m || v[1] < 0 || v[1] >= n
              || maze[v[0]][v[1]] == 1) break;
          ++dist;
        }
        --dist;
        int v[] = {u[0] + dist * DELTA[d], u[1] + dist * DELTA[d + 1]};
        dist_tbl[v[0]][v[1]] = min(dist_tbl[v[0]][v[1]],
            dist_tbl[u[0]][u[1]] + dist);
      }
    }
    return visited[dest[0]][dest[1]] ? dist_tbl[dest[0]][dest[1]] : -1;
  }
};
