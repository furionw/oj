// 2025-08-03
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, 1e9);
    vector<int> next = dist;
    dist[src] = 0;
    // k + 1 times
    for (int i = 0; i <= k; ++i) {
      next = dist;
      for (const auto& e : flights) {
        next[e[1]] = min(next[e[1]], dist[e[0]] + e[2]);
      }
      dist = next;
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
  }
};
