// 2025-08-01
class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    vector<vector<pair<int, int>>> E(n);
    for (const auto& e : edges) {
      E[e[0]].emplace_back(e[1], e[2] + 1);
      E[e[1]].emplace_back(e[0], e[2] + 1);
    }
    vector<bool> visited(n, false);
    vector<int> dist(n, maxMoves + 1);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    int result = 0;
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (visited[u]) {
        continue;
      }
      visited[u] = true;
      dist[u] = d;
      ++result;
      for (auto [v, w] : E[u]) {
        if (d + w <= dist[v] && d + w <= maxMoves) {
          pq.emplace(d + w, v);
        }
        int inc = min(w - 1, maxMoves - d);
        int sub = 0;
        if (visited[v]) {
          if (d + w <= maxMoves) {
            sub = min(w - 1, maxMoves - dist[v]);
          } else if (dist[v] + w <= maxMoves) {
            sub = inc;
          } else {
            int inc2 = maxMoves - dist[v];
            sub = max(0, inc + inc2 - (w - 1));
          }
        }
        result += inc - sub;
      }
    }
    return result;
  }
};
