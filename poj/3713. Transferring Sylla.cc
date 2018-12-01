// Copyright 2017 Qi Wang
// Date: 2017-05-27
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  Edge() {}
  Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
  int to, cap, rev;
};

#define N_MAX 500

bool vi[N_MAX];
vector<vector<Edge> > origin_g, g;

inline void AddEdge(int a, int b) {
  // a -> b
  origin_g[a].push_back(Edge(b, 1, origin_g[b].size()));
  origin_g[b].push_back(Edge(a, 0, origin_g[a].size() - 1));
  // b -> a
  origin_g[b].push_back(Edge(a, 1, origin_g[a].size()));
  origin_g[a].push_back(Edge(b, 0, origin_g[b].size() - 1));
}

bool Dfs(int v, int t) {
  if (v == t) return 1;
  vi[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i) {
    Edge& e = g[v][i];
    if (!vi[e.to] && e.cap > 0 && Dfs(e.to, t)) {
      --e.cap;
      ++g[e.to][e.rev].cap;
      return true;
    }
  }
  return false;
}

inline bool MaxFlow(int s, int t) {
  g = origin_g;
  int flow = 0;
  while (flow < 3) {
    memset(vi, 0, sizeof vi);
    if(Dfs(s, t)) {
      ++flow;
    } else {
      break;
    }
  }
  return flow >= 3;
}

int main() {
  for (int n, m; cin >> n >> m, n != 0 && m != 0;) {
    origin_g = vector<vector<Edge> >(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      AddEdge(a, b);
    }
    bool safe = true;
    for (int s = 0; s < n && safe; ++s)
      for (int t = s + 1; t < n && safe; ++t)
        safe = MaxFlow(s, t);
    cout << (safe ? "YES" : "NO") << endl;
  }
}
