// Copyright 2016 Qi Wang
// Date: 2016-10-17
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using std::min;
using std::cin; using std::cout; using std::endl;

const int MAXN = 1e3 + 1;
int n, m, s, t;
int roads[MAXN][MAXN];
bool vi[MAXN];
int dis[MAXN];

int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; ++i) {
    dis[i] = INT_MAX;
    for (int j = 1; j <= n; ++j)
      roads[i][j] = INT_MAX;
  }
  memset(vi, 0, sizeof(vi));
  while (m--) {
    int u, v, len;
    cin >> u >> v >> len;
    roads[u][v] = roads[v][u] = min(roads[u][v], len);
  }
  dis[s] = 0;
  for (int u = s; u != t; ) {
    vi[u] = true;
    for (int v = 1; v <= n; ++v)
      if (roads[u][v] != INT_MAX)
        dis[v] = min(dis[v], dis[u] + roads[u][v]);
    int minn = INT_MAX;
    for (int v = 1; v <= n; ++v)
      if (!vi[v] && dis[v] < minn) {
        u = v;
        minn = dis[v];
      }
  }
  cout << dis[t] << endl;
}
