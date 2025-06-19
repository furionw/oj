// 2025-06-18
// Method 3
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
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

// Method 2
struct Point {
  int dis;
  int x;
  int y;
  bool operator<(const Point& other) const {
    return dis > other.dis;
  }
};

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    priority_queue<Point> pq;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          pq.push({
            .dis = 0,
            .x = i,
            .y = j
          });
        } else {
          mat[i][j] = 1e9;
        }
      }
    }

    while (!pq.empty()) {
      int x = pq.top().x;
      int y = pq.top().y;
      int dis = pq.top().dis;
      pq.pop();
      static constexpr int d[] = {-1, 0, 1, 0, -1};
      for (int k = 0; k < 4; ++k) {
        int i = x + d[k];
        int j = y + d[k + 1];
        if (i < 0 || i >= m || j < 0 || j >= n
            || dis + 1 >= mat[i][j]) {
          continue;
        }
        mat[i][j] = mat[x][y] + 1;
        pq.push({
          .dis = dis + 1,
          .x = i,
          .y = j
        });
      }
    }

    return mat;
  }
};

// 2025-06-18
// Method 1
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, 1e9));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          result[i][j] = 0;
        }
      }
    }
    for (bool found = true; found;) {
      found = false;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (mat[i][j] == 0) {
            continue;
          }
          static constexpr int d[] = {-1, 0, 1, 0, -1};
          for (int k = 0; k < 4; ++k) {
            int x = i + d[k];
            int y = j + d[k + 1];
            if (x < 0 || x >= m || y < 0 || y >= n
                || result[x][y] + 1 >= result[i][j]) {
              continue;
            }
            result[i][j] = result[x][y] + 1;
            found = true;
          }
        }
      }
    }
    return result;
  }
};

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
