// Copyright 2016 Qi Wang
// Date: 2016-10-17
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;
using std::cin; using std::cout; using std::endl;

const int MAXN = 1e2 + 1;
int n, m;
int roads[MAXN][MAXN];

int main() {
  cin >> n >> m;
  // init
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      roads[i][j] = i == j ? 0 : INT_MAX;
  // input
  while (m--) {
    int u, v, len;
    cin >> u >> v >> len;
    roads[u][v] = roads[v][u] = min(roads[u][v], len);
  }
  // floyd
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (roads[i][k] != INT_MAX && roads[k][j] != INT_MAX)
          roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cout << roads[i][j] << " ";
    cout << endl;
  }
}
