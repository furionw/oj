// Copyright 2017 Qi Wang
// Date: 2017-01-02
class Solution {
 private:
  using P = pair<int, int>;
  using VP = vector<P>;

 public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    vector<VP> s(m, VP(n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        s[i][j] = {i, j};
    vector<int> res;
    for (auto& p : positions) {
      if (grid[p.first][p.second]) {
        res.push_back(res.back());
        continue;
      }
      // grid[p.first][p.second] is water before, now we turn it into land
      grid[p.first][p.second] = 1;
      static constexpr int DELTA[] = {0, 1, 0, -1, 0};
      VP lands;
      for (int d = 0; d < 4; ++d) {
        int x = p.first + DELTA[d], y = p.second + DELTA[d + 1];
        if (0 <= x && x < m && 0 <= y && y < n && grid[x][y])
          lands.emplace_back(x, y);
      }
      // No surrounding lands
      if (lands.empty()) {
        res.push_back(res.empty() ? 1 : res.back() + 1);
      } else {
        int islandCnt = res.back();
        auto root = find(s, lands.front());
        s[p.first][p.second] = root;
        for (size_t i = 1; i < lands.size(); ++i) {
          auto rhs = find(s, lands[i]);
          if (root != rhs) {
            s[rhs.first][rhs.second] = root;
            --islandCnt;
          }
        }
        res.push_back(islandCnt);
      }
    }
    return res;
  }

 private:
  P find(vector<VP>& s, const P& p) const {
    return s[p.first][p.second] != p
        ? s[p.first][p.second] = find(s, s[p.first][p.second])
        : p;
  }
};
