// Copyright 2016 Qi Wang
// Date: 2016-10-17
#include <iostream>
#include <climits>
#include <cassert>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::min;

const int MAXN = 1e3;
int n;
int m[MAXN][MAXN];
bool vi[MAXN];
int dis[MAXN];

int prim() {
  int res = 0;
  dis[0] = 0;
  for (int i = 0; i < n; ++i) {
    int u = -1, min_dis = INT_MAX;
    for (int v = 0; v < n; ++v)
      if (!vi[v] && dis[v] < min_dis) {
        u = v;
        min_dis = dis[v];
      }
    assert(u != -1);
    vi[u] = true;
    for (int v = 0; v < n; ++v)
      if (!vi[v]) dis[v] = min(m[u][v], dis[v]);
    res += min_dis;
  }
  return res;
}

int main() {
  // input
  cin >> n;
  for (int i = 0; i < n; ++i) {
    dis[i] = INT_MAX;
    for (int j = 0; j < n; ++j)
      cin >> m[i][j];
  }
  cout << prim() << endl;
}
