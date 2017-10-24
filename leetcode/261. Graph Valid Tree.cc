// Copyright 2017 Qi Wang
// Date: 2017-10-23
class Solution {
 public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n - 1) return false;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
    for (const auto& edge : edges) {
      int u = Find(&p, edge.first), v = Find(&p, edge.second);
      if (u != v) {
        p[v] = u;
      } else {
        return false;
      }
    }
    return true;
  }
 
 private:
  int Find(vector<int>* p, int v) const {
    if ((*p)[v] == v) {
      return v;
    } else {
      return (*p)[v] = Find(p, (*p)[v]);
    }
  }
};

// Date: 2017-07-20
class Solution {
 public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if (n <= 0 || n - 1 != edges.size()) return false;
    if (1 == n) return true;
    vector<vector<int>> graph(n);
    for (const auto& p : edges) {
      graph[p.first].push_back(p.second);
      graph[p.second].push_back(p.first);
    }
    // BFS
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(edges.front().first);
    visited[edges.front().first] = true;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : graph[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    return count(visited.begin(), visited.end(), true) == n;
  }
};

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
