// 2025-06-18
// Identical to "LC 542. 01 Matrix"
class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // water
        if (mat[i][j] == 1) {
          mat[i][j] = 0;
          q.emplace(i, j);
        } else {
          mat[i][j] = 1e9;
        }
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      int dis = mat[x][y];
      static constexpr int d[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; ++k) {
        int i = x + d[k];
        int j = y + d[k + 1];
        if (i < 0 || i >= m || j < 0 || j >= n
            || dis + 1 >= mat[i][j]) {
          continue;
        }
        mat[i][j] = mat[x][y] + 1;
        q.emplace(i, j);
      }
    }

    return mat;
  }
};