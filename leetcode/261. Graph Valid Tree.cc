// Copyright 2016 Qi Wang
// Difficulty: Medium
// Date: 2016-12-21
class Solution {
 public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n - 1) return false;
    // e : adjacent table
    list<int> e[n];
    for (auto& p : edges) {
      e[p.first].push_back(p.second);
      e[p.second].push_back(p.first);
    }
    bool vi[n];
    memset(vi, 0, sizeof vi);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      // Mark vertex u as visited
      vi[u] = true;
      // Iterate all the adjacent edges connected to u
      for (int v : e[u])
        if (!vi[v])
          q.push(v);
    }
    // all bits should be set if edges forms a valid tree
    return all_of(vi, vi + n, [](bool visited) { return visited; });
  }
};
