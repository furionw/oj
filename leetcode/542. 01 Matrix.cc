// Copyright 2017 Qi Wang
// Date: 2017-06-07
// Refer to: https://discuss.leetcode.com/topic/83453/java-solution-bfs
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return matrix;
    int m = matrix.size(), n = matrix[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (0 == matrix[i][j]) {
          q.emplace(i, j);
        } else {
          matrix[i][j] = INT_MAX;
        }
    while (!q.empty()) {
      auto pos = q.front(); q.pop();
      static constexpr int delta[] = {0, 1, 0, -1, 0};
      for (int d = 0; d < 4; ++d) {
        int i = pos.first + delta[d], j = pos.second + delta[d + 1];
        if (i < 0 || i >= m || j < 0 || j >= n
            || matrix[i][j] <= matrix[pos.first][pos.second] + 1)
          continue;
        matrix[i][j] = matrix[pos.first][pos.second] + 1;
        q.emplace(i, j);
      }
    }
    return matrix;
  }
};

// Date: 2017-06-07
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return matrix;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (0 == matrix[i][j] && INT_MAX == result[i][j])
          Dfs(matrix, i, j, 0, result);
    return result;
  }
 
 private:
  void Dfs(const vector<vector<int>>& matrix, int x, int y, int depth,
      vector<vector<int>>& result) const {
    if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
        || depth > result[x][y]) return;
    result[x][y] = depth = 0 == matrix[x][y] ? 0 : depth;
    static constexpr int delta[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d)
      Dfs(matrix, x + delta[d], y + delta[d + 1], depth + 1, result);
  }
};
