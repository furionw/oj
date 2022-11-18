// Date: 2022-11-17
// Refer to https://leetcode.com/problems/most-profitable-path-in-a-tree/discuss/2807411/Python-One-DFS
class Solution {
 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = edges.size() + 1;
    vector<bool> seen(n + 1, false);
    vector<vector<int>> g(n + 1, vector<int>());
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return dfs(g, bob, amount, seen, 0 /*u*/, 0 /*depth*/).first;
  }

 private:
  // profit and depth
  std::pair<int, int> dfs(
      const vector<vector<int>>& g,
      int bob,
      const vector<int>& amount,
      vector<bool>& seen,
      int u,
      int depth
  ) {
    seen[u] = true;
    int biggestSubSum = numeric_limits<int>::min();
    int db = u == bob ? 0 : seen.size();
    for (int v : g[u]) {
      if (seen[v]) {
        continue;
      }
      auto [subSum, subDb] = dfs(g, bob, amount, seen, v, depth + 1);
      biggestSubSum = max(biggestSubSum, subSum);
      db = min(db, subDb);
    }
    if (biggestSubSum == numeric_limits<int>::min()) {
      biggestSubSum = 0;
    }
    if (depth == db) {
      biggestSubSum += amount[u] / 2;
    } else if (depth < db) {
      biggestSubSum += amount[u];
    }
    
    return {biggestSubSum, db + 1};
  }
};