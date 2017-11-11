// Copyright 2017 Qi Wang
// Date: 2017-11-10
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
      for (int j = 0; j < rooms[0].size(); ++j) {
        if (rooms[i][j] == 0) {
          Dfs(&rooms, i, j, 0);
        }
      }
    }
  }
 
 private:
  void Dfs(vector<vector<int>>* rooms, int i, int j, int dist) const {
    (*rooms)[i][j] = dist;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + delta[d], y = j + delta[d + 1];
      if (0 <= x && x < rooms->size() && 0 <= y && y < (*rooms)[0].size() &&
          (*rooms)[x][y] > dist + 1) {
        Dfs(rooms, x, y, dist + 1);
      }
    }
  }
};

// Date: 2017-08-01
// BFS
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
      for (int j = 0; j < rooms[0].size(); ++j) {
        if (rooms[i][j] == 0) {
          Bfs(rooms, i, j);
        }
      }
    }
  }

 private:
  void Bfs(vector<vector<int>>& rooms, int x, int y) const {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    constexpr int delta[] = {0, 1, 0, -1, 0};
    while (!q.empty()) {
      x = q.front().first, y = q.front().second;
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int i = x + delta[d], j = y + delta[d + 1];
        if (i >= 0 && i < rooms.size() && j >= 0 && j < rooms[0].size()
            && rooms[i][j] > rooms[x][y] + 1) {
          rooms[i][j] = rooms[x][y] + 1;
          q.emplace(i, j);
        }
      }
    }
  }
};

// Date: 2017-08-01
// DFS
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i) {
      for (int j = 0; j < rooms[0].size(); ++j) {
        if (rooms[i][j] == 0) {
          Dfs(rooms, i, j);
        }
      }
    }
  }

 private:
  void Dfs(vector<vector<int>>& rooms, int x, int y) const {
    constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int i = x + delta[d], j = y + delta[d + 1];
      if (i >= 0 && i < rooms.size() && j >= 0 && j < rooms[0].size()
          && rooms[i][j] > rooms[x][y] + 1) {
        rooms[i][j] = rooms[x][y] + 1;
        Dfs(rooms, i, j);
      }
    }
  }
};

// Date: 2016-12-28
class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty() || rooms[0].empty()) return;
    int m = static_cast<int>(rooms.size()),
        n = static_cast<int>(rooms[0].size());
    for (int i = 0; i < m; ++i)
     for (int j = 0; j < n; ++j)
       if (rooms[i][j] == 0)  // This cell is a gate
         bfs(rooms, i, j);
  }

 private:
  void bfs(vector<vector<int>>& rooms, int i, int j) const {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    while (!q.empty()) {
      i = q.front().first, j = q.front().second;
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int x = i + DELTA[d], y = j + DELTA[d + 1];
        if (x < 0 || x >= rooms.size()
            || y < 0 || y >= rooms[0].size()) continue;
        if (rooms[i][j] + 1 < rooms[x][y]) {
          rooms[x][y] = rooms[i][j] + 1;
          q.emplace(x, y);
        }
      }
    }
  }
};

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
