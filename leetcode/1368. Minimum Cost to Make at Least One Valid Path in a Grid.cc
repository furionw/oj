// 2025-08-02
class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    static vector<int> x {0, 0, 0, 1, -1};
    static vector<int> y {0, 1, -1, 0, 0};
    int m = grid.size();
    int n = grid[0].size();
    int tot = m * n;
    vector<bool> visited(tot, false);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
      auto [dist, idx] = pq.top();
      pq.pop();
      if (idx == tot - 1) {
        return dist;
      }
      if (visited[idx]) {
        continue;
      }
      visited[idx] = true;
      auto i = idx / n;
      int j = idx % n;
      for (int d = 1; d <= 4; ++d) {
        int nextI = i + x[d];
        int nextJ = j + y[d];
        int nextIdx = nextI * n + nextJ;
        if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n
            || visited[nextIdx]) {
          continue;
        }
        pq.emplace(dist + (grid[i][j] != d), nextIdx);
      }
    }
    return -1;
  } 
};
