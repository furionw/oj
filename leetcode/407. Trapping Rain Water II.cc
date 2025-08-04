// 2025-08-04
// Refer to the Editorial
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    int n = heightMap[0].size();

    if (m <= 2 || n <= 2) {
      return 0;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for (int i = 0; i < m; ++i) {
      pq.emplace(heightMap[i][0], i * n);
      visited[i][0] = true;
      pq.emplace(heightMap[i][n - 1], i * n + n - 1);
      visited[i][n - 1] = true;
    }
    for (int j = 1; j < n - 1; ++j) {
      pq.emplace(heightMap[0][j], j);
      visited[0][j] = true;
      pq.emplace(heightMap[m - 1][j], (m - 1) * n + j);
      visited[m - 1][j] = true;
    }

    int result = 0;
    while (!pq.empty()) {
      auto [h, idx] = pq.top();
      pq.pop();
      int i = idx / n;
      int j = idx % n;
      static vector<int> deltas {-1, 0, 1, 0, -1};
      for (int d = 0; d < 4; ++d) {
        int nextI = i + deltas[d];
        int nextJ = j + deltas[d + 1];
        if (nextI < 1 || nextI >= m - 1 || nextJ < 1 || nextJ >= n - 1
            || visited[nextI][nextJ]) {
          continue;
        }
        result += max(0, h - heightMap[nextI][nextJ]);
        pq.emplace(max(h, heightMap[nextI][nextJ]), nextI * n + nextJ);
        visited[nextI][nextJ] = true;
      }
    }

    return result;
  }
};

// 2025-08-04
// Same mistake as 2016-11-02
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    int n = heightMap[0].size();
    vector<vector<int>> leftmost(m, vector<int>(n, 0));
    auto rightmost = leftmost;
    auto upmost = leftmost;
    auto downmost = leftmost;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        leftmost[i][j] = max(leftmost[i][j - 1], heightMap[i][j - 1]);
      }
      for (int j = n - 2; j >= 0; --j) {
        rightmost[i][j] = max(rightmost[i][j + 1], heightMap[i][j + 1]);
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < m; ++i) {
        upmost[i][j] = max(upmost[i - 1][j], heightMap[i - 1][j]);
      }
      for (int i = m - 2; i >= 0; --i) {
        downmost[i][j] = max(downmost[i + 1][j], heightMap[i + 1][j]);
      }
    }

    int result = 0;
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        int bound = min(leftmost[i][j], rightmost[i][j]);
        bound = min(bound, upmost[i][j]);
        bound = min(bound, downmost[i][j]);
        result += max(0, bound - heightMap[i][j]);
      }
    }
    return result;
  }
};

// 2016-11-02
// Failed on
// [
// [12,13,1,12],
// [13,4,13,12],
// [13,8,10,12],
// [12,13,12,12],
// [13,13,13,13]
// ]
class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.size() <= 2 || heightMap[0].size() <= 2) return 0;
    size_t m = heightMap.size(), n = heightMap[0].size();
    int leftmost[m][n], rightmost[m][n], topmost[m][n], botmost[m][n];
    for (int i = 0; i < m; ++i)
      for (int j = 0, max = 0; j < n; ++j) {
        leftmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int i = 0; i < m; ++i)
      for (int j = n - 1, max = 0; j >= 0; --j) {
        rightmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int j = 0; j < n; ++j)
      for (int i = 0, max = 0; i < m; ++i) {
        topmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    for (int j = 0; j < n; ++j)
      for (int i = m - 1, max = 0; i >= 0; --i) {
        botmost[i][j] = max;
        max = ::max(max, heightMap[i][j]);
      }
    int res = 0;
    for (size_t i = 1; i < m; ++i)
      for (size_t j = 1; j < n; ++j) {
        int bound = ::min({leftmost[i][j], rightmost[i][j],
            topmost[i][j], botmost[i][j]});
        if (bound > heightMap[i][j]) res += bound - heightMap[i][j];
      }
    return res;
  }
};
