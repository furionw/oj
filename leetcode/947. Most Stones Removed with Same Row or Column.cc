// 2025-07-29
class Solution {
 public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }

    unordered_map<int, optional<int>> xToS;
    unordered_map<int, optional<int>> yToS;
    for (int i = 0; i < n; ++i) {
      const auto& s = stones[i];

      int x = s[0];
      if (xToS[x].has_value()) {
        merge(i, *xToS[x], p);
      }
      xToS[x] = i;

      int y = s[1];
      if (yToS[y].has_value()) {
        merge(i, *yToS[y], p);
      }
      yToS[y] = i;
    }

    unordered_set<int> roots;
    for (int i = 0; i < n; ++i) {
      roots.insert(find(i, p));
    }
    return n - roots.size();
  }

 private:
  void merge(int u, int v, vector<int>& p) const {
    int pu = find(u, p);
    int pv = find(v, p);
    p[pv] = pu;
  }

  int find(int u, vector<int>& p) const {
    return u == p[u]
        ? u
        : p[u] = find(p[u], p);
  }
};
