// Copyright 2017 Qi Wang
// Date: 2017-08-23
class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return {};
    vector<vector<int>> result = M;
    int m = M.size(), n = M[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = 0, acc = 0;
        int dir[] = {-1, 0, 1};
        for (int p = 0; p < 3; ++p) {
          for (int q = 0; q < 3; ++q) {
            int x = i + dir[p], y = j + dir[q];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            ++cnt;
            acc += M[x][y];
          }
        }
        result[i][j] = acc / cnt;
      }
    }
    return result;
  }
};
