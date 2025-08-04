// 2025-08-03
class Solution {
 public:
  int minimumCost(int n, vector<vector<int>>& connections) {
    // min-heap for shortest edge
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    for (int i = 0; i < connections.size(); ++i) {
      pq.emplace(connections[i][2], i);
    }

    // parents
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      p[i] = i;
    }

    int cost = 0;
    int edgeCount = 0;
    while (!pq.empty()) {
      auto [w, idx] = pq.top();
      pq.pop();
      int u = connections[idx][0];
      int v = connections[idx][1];
      int pu = find(u, p);
      int pv = find(v, p);
      if (pu == pv) {
        continue;
      }
      p[pv] = pu;
      cost += w;
      if (++edgeCount == n - 1) {
        return cost;
      }
    }

    return -1;
  }

 private:
  int find(int u, vector<int>& p) {
    int pu = p[u];
    return pu == u
        ? pu
        : p[u] = find(pu, p);
  }
};
