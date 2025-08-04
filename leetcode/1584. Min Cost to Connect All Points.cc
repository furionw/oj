// 2025-08-03
// Prim algorithm. Proved with cut property
class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    auto dist = [&](int u, int v) {
      return abs(points[u][0] - points[v][0])
          + abs(points[u][1] - points[v][1]);
    };

    vector<bool> inMst(n, false);
    inMst[0] = 0;
    
    // weight, index
    using PII = pair<int, int>;
    // min heap
    priority_queue<PII, vector<PII>, greater<>> pq;
    pq.emplace(0, 0);

    int cost = 0;
    while (!pq.empty()) {
      auto [w, u] = pq.top();
      pq.pop();
      if (inMst[u]) {
        continue;
      }
      inMst[u] = true;
      cost += w;
      for (int v = 0; v < n; ++v) {
        if (inMst[v]) {
          continue;
        }
        pq.emplace(dist(u, v), v);
      }
    }
    return cost;
  }
};
