// 2025-07-25
class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> ps(n);
    for (int i = 0; i < n; ++i) {
      ps[i] = i;
    }
    for (const auto& c: connections) {
      unionFind(c[0], c[1], ps);
    }
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      s.insert(find(i, ps));
    }
    return connections.size() < n - 1
        ? -1
        : s.size() - 1;
  }

 private:
  void unionFind(int u, int v, vector<int>& ps) {
    int pu = find(u, ps);
    int pv = find(v, ps);
    ps[pu] = pv;
  }

  int find(int v, vector<int>& ps) {
    return ps[v] == v
        ? v
        : ps[v] = find(ps[v], ps);
  }
};
