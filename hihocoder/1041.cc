// Copyright 2016 Qi Wang
// Date: 2016-10-15
#include <iostream>
#include <vector>
#include <list>
#include <bitset>

using std::list;
using std::vector;
using std::cin; using std::cout; using std::endl;
using std::bitset;

const int MAXN = 100;
vector<list<int>> roads;
list<int> orderList;
vector<vector<bool>> vi;
vector<bitset<MAXN>> reach;

void dfsReach(int cur, int pre) {
  reach[cur][cur] = 1;
  for (int next : roads[cur]) {
    if (next == pre) continue;
    dfsReach(next, cur);
    reach[cur] |= reach[next];
  }
}

void dfs(int cur, int pre) {
  if (cur == orderList.front()) orderList.pop_front();
  while (!orderList.empty()) {
    size_t preSz = orderList.size();
    for (int next : roads[cur]) {
      if (next == pre) continue;
      if (reach[next][orderList.front()] && !vi[cur][next]) {
        vi[cur][next] = true;
        dfs(next, cur);
      }
      if (orderList.empty()) break;
    }
    if (preSz == orderList.size()) break;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    roads = vector<list<int>>(n);
    vi = vector<vector<bool>>(n, vector<bool>(n, false));
    reach = vector<bitset<MAXN>>(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      roads[a - 1].push_back(b - 1);
      roads[b - 1].push_back(a - 1);
    }
    int m;
    cin >> m;
    orderList.clear();
    for (int i = 0; i < m; ++i) {
      int order;
      cin >> order;
      orderList.push_back(order - 1);
    }
    dfsReach(0, -1);
    dfs(0, -1);
    cout << (orderList.empty() ? "YES" : "NO") << endl;
  }
}
