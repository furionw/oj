// 2025-05-18
// Method 3
struct V {
  int i;
  int j;
  int dist;

  bool operator<(const V& other) const {
    return dist > other.dist;
  }
};

struct E {
  int x;
  int y;
  int w;
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dists(m, vector<int>(n, numeric_limits<int>::max()));
    priority_queue<V> pq;
    pq.push({0, 0, 0});
    dists[0][0] = 0;
    while (!pq.empty()) {
      auto [i, j, dist] = pq.top();
      pq.pop();
      if (i == m - 1 && j == n - 1) {
        return dist;
      }
      if (visited[i][j]) {
        continue;
      }
      visited[i][j] = true;

      static vector<vector<int>> deltas {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
      };
      for (const auto& d : deltas) {
        int x = i + d[0], y = j + d[1];
        if (x < 0 || x >= m || y < 0 || y >= n) {
          continue;
        }
        int w = abs(heights[i][j] - heights[x][y]);
        if (max(dist, w) < dists[x][y]) {
          dists[x][y] = max(dist, w);
          pq.push({x, y, dists[x][y]});
        }
      }
    }

    throw std::runtime_error("Should not be executed");
  }
};



// Method 2
struct V {
  int u;
  int dist;

  bool operator<(const V& other) const {
    return dist != other.dist
        ? dist > other.dist
        : u < other.u;
  }
};

struct E {
  int v;
  int w;
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    cout << "minimumEffortPath\n";
    int m = heights.size();
    cout << "m = " << m << endl;
    int n = heights[0].size();
    int o = m * n;
    cout << o << endl;
    vector<bool> visited(o, false);
    vector<int> dists(o, numeric_limits<int>::max());

    vector<vector<E>> edges(o, vector<E>{});
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int u = i * n + j;
        vector<vector<int>> nexts {
          {i, j - 1}, {i, j + 1}, {i - 1, j}, {i + 1, j}
        };
        for (const auto& next : nexts) {
          int x = next[0], y = next[1];
          if (x < 0 || x >= m || y < 0 || y >= n) {
            continue;
          }
          int v = x * n + y;
          int w = abs(heights[i][j] - heights[x][y]);
          edges[u].push_back({v, w});
          edges[v].push_back({u, w});
        }
      }
    }

    dists[0] = 0;
    priority_queue<V> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
      auto [u, dist] = pq.top();
      pq.pop();
      if (u == o - 1) {
        return dist;
      }
      if (visited[u]) {
        continue;
      }
      visited[u] = true;

      for (const auto& [v, w] : edges[u]) {
        if (max(dist, w) < dists[v]) {
          dists[v] = max(dist, w);
          pq.push({v, dists[v]});
        }
      }
    }
    
    throw std::runtime_error("Should not be executed");
  }
};

// Method 1: TLE
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& hs) {
    heights = std::move(hs);
    m = heights.size();
    n = heights[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    f(0, 0, 0);
    return result;
  }
  
 private:
  void f(int x, int y, int effort) {
    if (x == m - 1 && y == n - 1) {
      result = min(result, effort);
      return;
    }
    visited[x][y] = true;
    vector<vector<int>> neighbors {
      {x + 1, y},
      {x, y + 1},
      {x, y - 1},
      {x - 1, y}
    };
    for (const auto& neighbor : neighbors) {
      int i = neighbor[0], j = neighbor[1];
      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
        continue;
      }
      int requiredE = abs(heights[i][j] - heights[x][y]);
      if (requiredE > result) {
        continue;
      }
      f(i, j, max(effort, requiredE));
    }
    visited[x][y] = false;
  }

  int m;
  int n;
  int result = numeric_limits<int>::max();
  vector<vector<int>> heights;
  vector<vector<bool>> visited;
};
