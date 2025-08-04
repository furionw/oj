// 2025-08-03
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // bellman-ford
    int kInf = 1e9;
    vector<int> dist(n + 1, kInf);
    vector<int> next;
    dist[k] = 0;
    for (int i = 1; i < n; ++i) {
      next = dist;
      for (const auto& e : times) {
        next[e[1]] = min(next[e[1]], dist[e[0]] + e[2]);
      }
      dist = next;
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
      if (dist[i] == kInf) {
        return -1;
      }
      result = max(result, dist[i]);
    }
    return result;
  }
};
