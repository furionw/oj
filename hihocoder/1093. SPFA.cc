// Copyright 2016 Qi Wang
// Date: 2016-10-17
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <list>
#include <map>

using std::min;
using std::cin; using std::cout; using std::endl;
using std::queue;
using std::list;
using std::map;

const int MAXN = 1e5 + 1;
int n, m, s, t;
// We have to use adjacent list instead of 2-d array int[MAXN][MAXN] here,
// or we will run out of memory
map<int, int> roads[MAXN];
int dis[MAXN];
bool inQ[MAXN];
queue<int> q;

int main() {
  cin >> n >> m >> s >> t;
  // init
  for (int i = 1; i <= n; ++i) dis[i] = INT_MAX;
  memset(inQ, 0, sizeof(inQ));
  // input
  while (m--) {
    int u, v, len;
    cin >> u >> v >> len;
    roads[u][v] = roads[v][u] = roads[u][v] == 0 ? len : min(roads[u][v], len);
  }
  q.push(s);
  dis[s] = 0;
  inQ[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inQ[u] = false;
    for (auto& road : roads[u]) {
      int v = road.first, len = road.second;
      if (dis[v] > dis[u] + len) {
        dis[v] = dis[u] + len;
        if (!inQ[v]) {
          inQ[v] = true;
          q.push(v);
        }
      }
    }
  }
  cout << dis[t] << endl;
}
