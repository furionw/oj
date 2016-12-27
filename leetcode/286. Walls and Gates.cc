// Copyright 2016 Qi Wang
// Date: 2016-12-27
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty() || rooms[0].empty()) return;
    int m = static_cast<int>(rooms.size()),
        n = static_cast<int>(rooms[0].size());
    for (int i = 0; i < m; ++i)
     for (int j = 0; j < n; ++j)
       if (rooms[i][j] == 0)  // This cell is a gate
         dfs(rooms, i, j);
  }

 private:
  void dfs(vector<vector<int>>& rooms, int i, int j) const {
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + DELTA[d], y = j + DELTA[d + 1];
      if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size()) continue;
      if (rooms[i][j] + 1 < rooms[x][y]) {
        rooms[x][y] = rooms[i][j] + 1;
        dfs(rooms, x, y);
      }
    }
  }
};
