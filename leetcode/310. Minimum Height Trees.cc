// Copyright 2016 Qi Wang
// Date: 2016-12-06
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (n == 1) return {0};
    vector<list<int>> m(n);
    int degrees[n] {0};
    for (auto& edge : edges) {
      m[edge.first].push_back(edge.second);
      m[edge.second].push_back(edge.first);
      ++degrees[edge.first];
      ++degrees[edge.second];
    }
    queue<int> q;
    for (int v = 0; v < n; ++v)
      if (degrees[v] == 1)
        q.push(v);
    while (n > 2) {
      queue<int> newQ;
      for (; !q.empty(); q.pop(), --n) {
        int u = q.front();
        for (int v : m[u])
          if (--degrees[v] == 1)
            newQ.push(v);
      }
      q = newQ;
    }
    vector<int> res;
    for (; !q.empty(); q.pop())
      res.push_back(q.front());
    return res;
  }
};
