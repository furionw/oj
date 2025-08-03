// 2025-07-29
struct V {
  int dist;
  int k;
  int i;
  int j;
};

class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1 && n == 1) {
      return 0;
    }
    vector<vector<set<int>>> visited(m, vector<set<int>>(n));
    queue<V> q;
    q.push(V {
      .dist = 0,
      .k = k,
      .i = 0,
      .j = 0
    });
    visited[0][0].insert(k);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      vector<int> deltas {-1, 0, 1, 0, -1};
      for (int d = 0; d < 4; ++d) {
        int nextI = v.i + deltas[d];
        int nextJ = v.j + deltas[d + 1];
        if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) {
          continue;
        }
        if (nextI == m - 1 && nextJ == n - 1) {
          return v.dist + 1;
        }
        if (visited[nextI][nextJ].lower_bound(v.k - grid[nextI][nextJ]) !=
            visited[nextI][nextJ].end()
            || v.k - grid[nextI][nextJ] < 0
        ) {
          continue;
        } else {
          visited[nextI][nextJ].insert(v.k - grid[nextI][nextJ]);
          q.push(V {
            .dist = v.dist + 1,
            .k = v.k - grid[nextI][nextJ],
            .i = nextI,
            .j = nextJ
          });
        }
      }
    }
    return -1;
  }
};
