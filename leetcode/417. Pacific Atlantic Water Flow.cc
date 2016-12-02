// Copyright 2016 Qi Wang
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
