// 2025-05-17
class Solution {
 public:
  int minMoves(vector<string>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_map<char, vector<pair<int, int>>> ports;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char c = matrix[i][j];
        if (letter(c)) {
          ports[c].push_back({i, j});
        }
      }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    for (int dist = 0; !q.empty(); ++dist) {
      queue<pair<int, int>> next;
      for (; !q.empty(); q.pop()) {
        auto p = q.front();
        int i = p.first;
        int j = p.second;
        if (i == m - 1 && j == n - 1) {
          // test m != n case
          return dist;
        }
        char c = matrix[i][j];
        if (letter(c)) {
          for (auto [x, y] : ports[c]) {
            if (!visited[x][y]) {
              visited[x][y] = true;
              q.push({x, y});
            }
          }
          ports.erase(c);
        }
        vector<pair<int, int>> neighbors = {
          {i, j - 1}, {i, j + 1},
          {i - 1, j}, {i + 1, j}
        };
        for (auto [x, y] : neighbors) {
          if (x < 0 || x >= m || y < 0 || y >= n) {
            continue;
          }
          char n = matrix[x][y];
          if (n != '#' && !visited[x][y]) {
            visited[x][y] = true;
            next.push({x, y});
            if (letter(n)) {
              for (auto [xx, yy] : ports[n]) {
                if (!visited[xx][yy]) {
                  visited[xx][yy] = true;
                  next.push({xx, yy});
                }
              }
              ports.erase(n);
            }
          }
        }
      }
      q = std::move(next);
    }
    return -1;
  }
  
 private:
  bool letter(int c) {
    return c >= 'A' && c <= 'Z';
  }
};

// ["A#", "#A"]
// ["..C.","C.A."]
// [".#...",".#.#.",".#.#.","...#."]
// ["A..",".A.","..."]
