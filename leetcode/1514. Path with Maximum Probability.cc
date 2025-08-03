// 2025-07-29
class Solution {
 public:
  double maxProbability(int n,
      vector<vector<int>>& edges, vector<double>& succProb, int startNode, int endNode) {
    if (startNode == endNode) {
      return 1;
    }

    vector<vector<pair<int, double>>> e(n);
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      e[u].emplace_back(v, succProb[i]);
      e[v].emplace_back(u, succProb[i]);
    }
    priority_queue<pair<double, int>> pq;
    vector<bool> visited(n, false);
    pq.emplace(1, startNode);
    while (!pq.empty()) {
      auto [w1, u] = pq.top();
      if (u == endNode) {
        return w1;
      }
      visited[u] = true;
      pq.pop();
      for (auto [v, w2]: e[u]) {
        if (!visited[v]) {
          pq.emplace(w1 * w2, v);
        }
      }
    }

    return 0;
  }
};
