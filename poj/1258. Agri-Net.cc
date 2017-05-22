// Copyright 2017 Qi Wang
// Prim
// Date: 2017-05-21
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

int main() {
  int n;
  int dist[100];
  int tbl[100][100];
  bool vi[100];
  while (cin >> n) {
    memset(vi, 0, sizeof vi);
    for (int i = 0; i < n; ++i) {    
      dist[i] = INT_MAX;
      for (int j = 0; j < n; ++j)
        cin >> tbl[i][j];
    }
    dist[0] = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      int minn = INT_MAX, u = -1;
      for (int v = 0; v < n; ++v)
        if (!vi[v] && dist[v] < minn) {
          u = v;
          minn = dist[v];
        }
      assert(u != -1);
      vi[u] = true;
      result += dist[u];
      for (int v = 0; v < n; ++v)
        dist[v] = min(dist[v], tbl[u][v]);
    }
    cout << result << endl;
  }
}
