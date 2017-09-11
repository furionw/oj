// Copyright 2017 Qi Wang
// Date: 2017-09-09
class Solution {
 public:
  int cutOffTree(vector<vector<int>>& forest) {
    if (forest.empty() || forest[0].empty()) return 0;
    m = forest.size(), n = forest[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (forest[i][j] > 1) {
          trees_[forest[i][j]] = make_pair(i, j);
        }
    forest_ = forest;
    visited_ = vector<vector<bool>>(m, vector<bool>(n, false));
    return F(0, 0, 0);
  }

 private:
  struct Pos {
    int x, y, dist;
    Pos(int x, int y, int dist) : x(x), y(y), dist(dist) {}
  };

  int F(int x, int y, int steps) {
    if (trees_.empty()) return steps;
    for (int i = 0; i < m; ++i) {
      fill(visited_[i].begin(), visited_[i].end(), false);
    }
    queue<Pos> q;
    q.emplace(x, y, 0);
    visited_[x][y] = true;
    auto target = trees_.begin()->second;
    do {
      auto now = q.front(); q.pop();
      if (now.x == target.first && now.y == target.second) {
        trees_.erase(trees_.begin());
        return F(now.x, now.y, steps += now.dist);
      }
      static int delta[] = {0, 1, 0, -1, 0};
      for (int d = 0; d < 4; ++d) {
        int i = now.x + delta[d], j = now.y + delta[d + 1];
        if (0 <= i && i < m && 0 <= j && j < n && forest_[i][j] != 0 && !visited_[i][j]) {
          visited_[i][j] = true;
          q.emplace(i, j, now.dist + 1);
        }
      }
    } while (!q.empty());
    return -1;
  }

  vector<vector<int>> forest_;
  vector<vector<bool>> visited_;
  map<int, pair<int, int>> trees_;
  int m, n;
};
