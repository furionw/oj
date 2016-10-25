// Copyright 2016 Qi Wang
// Date: 2016-10-23
#include <cstdio>
#include <list>
#include <vector>
#include <bitset>

constexpr int MAXN = 1e5 + 1;
std::vector<std::list<int>> graph(MAXN);
std::vector<int> flow(MAXN, 1);
std::bitset<MAXN> vi;
std::vector<int> viruses(MAXN, 0);

void dfs(int u) {
  if (vi[u]) return;
  vi[u] = true;
  for (int v : graph[u]) {
    dfs(v);
    // % 142857 is necessary here
    flow[u] = (flow[u] + flow[v]) % 142857;
  }
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int idx;
    scanf("%d", &idx);
    viruses[idx] = 1;
  }
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i)
    dfs(i);
  int res = 0;
  for (int i = 1; i <= n; ++i)
    res = (res + flow[i] * viruses[i]) % 142857;
  printf("%d\n", res);
}
