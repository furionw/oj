// 2025-07-29
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 1) {
      return grid[0][0];
    }

    int total = n * n;
    vector<bool> visited(total, false);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    pq.emplace(grid[0][0], 0);
    int t = 0;

    while (!pq.empty()) {
      auto [dist, idx] = pq.top();
      pq.pop();

      if (visited[idx]) {
        continue;
      }
      visited[idx] = true;

      t = max(t, dist);
      auto [i, j] = index(idx, n);
      vector<int> deltas = {-1, 0, 1, 0, -1};
      for (int d = 0; d < 4; ++d) {
        int i2 = i + deltas[d];
        int j2 = j + deltas[d + 1];
        if (i2 == n - 1 && j2 == n - 1) {
          return max(t, grid[i2][j2]);
        }
        if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= n) {
          continue;
        }
        int idx2 = index(i2, j2, n);
        if (!visited[idx2]) {
          pq.emplace(grid[i2][j2], idx2);
        }
      }
    }

    return -1;
  }

 private:
  int index(int i, int j, int n) {
    return i * n + j;
  }

  pair<int, int> index(int idx, int n) {
    return {idx / n, idx % n};
  }
};
