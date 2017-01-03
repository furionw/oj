// Copyright 2017 Qi Wang
// Date: 2017-01-03
// Time: about 90 ms. This BFS impl probably is slower than DFS on 2016-12-02
class Solution {
  using VP = vector<pair<int, int>>;
  using VVB = vector<vector<bool>>;

 public:
  VP pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return VP();
    VP res;
    // mark them as unvisited
    int m = matrix.size(), n = matrix[0].size();
    VVB pacific(m, vector<bool>(n, 0));
    foo(0, 0, matrix, pacific);
    VVB atlantic(m, vector<bool>(n, 0));
    foo(m - 1, n - 1, matrix, atlantic);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (pacific[i][j] && atlantic[i][j]) res.emplace_back(i, j);
    return res;
  }

 private:
  void foo(int x, int y, const vector<vector<int>>& matrix, VVB& ocean) const {
    for (int i = 0; i < matrix.size(); ++i)
      if (!ocean[i][y]) bfs(i, y, matrix, ocean);
    for (int j = 0; j < matrix[0].size(); ++j)
      if (!ocean[x][j]) bfs(x, j, matrix, ocean);
  }

  void bfs(int x, int y, const vector<vector<int>>& matrix, VVB& ocean) const {
    ocean[x][y] = true;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    while (!q.empty()) {
      auto& p = q.front();
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int new_x = p.first + DELTA[d], new_y = p.second + DELTA[d + 1];
        if (0 <= new_x && new_x < matrix.size()
            && 0 <= new_y && new_y < matrix[0].size()
            && matrix[new_x][new_y] >= matrix[p.first][p.second]
            && !ocean[new_x][new_y]) {
          ocean[new_x][new_y] = true;
          q.emplace(new_x, new_y);
        }
      }
    }
  }
};

// Date: 2016-12-02
// Time: about 72 - 79 ms
// Method 2
class Solution {
 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> res;
    // trivial case
    if (matrix.empty() || matrix[0].empty()) return res;
    // Here we assume m, n is in the range of [1, INT_MAX)
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    foo(0, 0, matrix, pacific);
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    foo(m - 1, n - 1, matrix, atlantic);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (pacific[i][j] && atlantic[i][j]) res.emplace_back(i, j);
    return res;
  }

 private:
  inline void foo(int x, int y, vector<vector<int>>& matrix,
      vector<vector<bool>>& vi) const {
    for (int i = 0; i < vi.size(); ++i)
      bar(i, y, matrix, vi);
    for (int j = 0; j < vi[0].size(); ++j)
      bar(x, j, matrix, vi);
  }

  inline void bar(int i, int j, vector<vector<int>>& matrix,
      vector<vector<bool>>& vi) const {
    // We just simply return when this vertex is visited before
    if (vi[i][j]) return;
    vi[i][j] = true;
    if (i - 1 >= 0 && matrix[i][j] <= matrix[i - 1][j])
      bar(i - 1, j, matrix, vi);
    if (i + 1 < vi.size() && matrix[i][j] <= matrix[i + 1][j])
      bar(i + 1, j, matrix, vi);
    if (j - 1 >= 0 && matrix[i][j] <= matrix[i][j - 1])
      bar(i, j - 1, matrix, vi);
    if (j + 1 < vi[0].size() && matrix[i][j] <= matrix[i][j + 1])
      bar(i, j + 1, matrix, vi);
  }
};

// Method 1
// Time: about 700 ms
// Date: 2016-12-02
class Solution {
 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> res;
    // trivial case
    if (matrix.empty() || matrix[0].empty()) return res;
    // Here we assume m, n is in the range of [1, INT_MAX)
    for (int i = 0; i < static_cast<int>(matrix.size()); ++i)
      for (int j = 0; j < static_cast<int>(matrix[0].size()); ++j)
        if (reach(i, j, matrix)) res.emplace_back(i, j);
    return res;
  }

 private:
  inline bool reach(int i, int j, const vector<vector<int>>& matrix) const {
    int m = matrix.size(), n = matrix[0].size();
    bool vi[m][n];
    memset(vi, 0, sizeof vi);
    queue<pair<int, int>> q;
    q.emplace(i, j);
    vi[i][j] = true;
    bool pacific = false, atlantic = false;
    while (!q.empty() && (!pacific || !atlantic)) {
      auto cur = q.front();
      q.pop();
      i = cur.first, j = cur.second;
      pacific = pacific || i == 0 || j == 0;
      atlantic = atlantic || i == m - 1 || j == n - 1;
      if (i - 1 >= 0 && matrix[i][j] >= matrix[i - 1][j] && !vi[i - 1][j]) {
        q.emplace(i - 1, j);
        vi[i - 1][j] = true;
      }
      if (i + 1 < m && matrix[i][j] >= matrix[i + 1][j] && !vi[i + 1][j]) {
        q.emplace(i + 1, j);
        vi[i + 1][j] = true;
      }
      if (j - 1 >= 0 && matrix[i][j] >= matrix[i][j - 1] && !vi[i][j - 1]) {
        q.emplace(i, j - 1);
        vi[i][j - 1] = true;
      }
      if (j + 1 < n && matrix[i][j] >= matrix[i][j + 1] && !vi[i][j + 1]) {
        q.emplace(i, j + 1);
        vi[i][j + 1] = true;
      }
    }
    return pacific && atlantic;
  }
};
