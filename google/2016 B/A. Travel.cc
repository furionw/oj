// Copyright 2016 Qi Wang
// Date: 2016-10-25
// Note that you should refer to other's solution after finish this problem on your own
#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using std::cin; using std::endl; using std::cout;
using std::vector;
using std::pair;
using std::list;

struct Node {
  Node(int dis, int idx) : dis(dis), idx(idx) {}
  inline bool operator <(const Node& rhs) const {
    return dis > rhs.dis;
  }
  int dis;
  int idx;
};

vector<int> dijkstraIter(const vector<list<pair<int, int>>>& roads, int t) {
  vector<bool> vi(roads.size(), false);
  vector<int> dis(roads.size(), INT_MAX);
  dis[24 + t] = 0;
  std::priority_queue<Node> q;
  q.emplace(0, 24 + t);
  while (!q.empty()) {
    auto u = q.top();
    q.pop();
    if (vi[u.idx]) continue;
    vi[u.idx] = true;
    for (auto& road : roads[u.idx]) {
      if (!vi[road.first] && dis[road.first] > dis[u.idx] + road.second) {
        dis[road.first] = dis[u.idx] + road.second;
        q.emplace(dis[road.first], road.first);
      }
    }
  }
  return dis;
}

vector<vector<int>> dijkstra(const vector<list<pair<int, int>>>& roads) {
  vector<vector<int>> res;
  for (int t = 0; t < 24; ++t)
    res.emplace_back(dijkstraIter(roads, t));
  return res;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<list<pair<int, int>>> roads((n + 1) * 24);
    while (m--) {
      int x, y;
      cin >> x >> y;
      for (int i = 0; i < 24; ++i) {
        int cost;
        cin >> cost;
        int arriveTime = (i + cost) % 24;
        roads[x * 24 + i].emplace_back(y * 24 + arriveTime, cost);
        roads[y * 24 + i].emplace_back(x * 24 + arriveTime, cost);
      }
    }
    auto disTable = dijkstra(roads);
    cout << "Case #" << tt << ":";
    while (k--) {
      int D, departT;
      cin >> D >> departT;
      int dis = *min_element(disTable[departT].begin() + D * 24,
          disTable[departT].begin() + (D + 1) * 24);
      cout << " " << (dis != INT_MAX ? dis : -1);
    }
    cout << endl;
  }
}
