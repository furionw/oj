// Copyright 2016 Qi Wang
// Date: 2016-10-22
#include <list>
#include <vector>
#include <map>
#include <bitset>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <queue>

int n;
constexpr int MAXN = 1e5 + 1;
std::list<std::pair<int, int>> edges[MAXN];
std::vector<int> dis(MAXN, INT_MAX);
struct Pos { int idx, x, y; };
Pos pos[MAXN];

struct Node {
  Node(int i, long long d) : idx(i), dis(d) {}
  bool operator <(const Node& rhs) const {
    return dis > rhs.dis;
  }
  int idx;
  long long dis;
};

long long dijkstra() {
  std::bitset<MAXN> vi;
  std::priority_queue<Node> q;
  q.emplace(1, 0);
  dis[1] = 0;
  while (!q.empty()) {
    Node u = q.top();
    q.pop();
    if (vi[u.idx]) continue;
    vi[u.idx] = true;
    for (auto& edge : edges[u.idx]) {
      if (dis[edge.first] > dis[u.idx] + edge.second) {
        dis[edge.first] = dis[u.idx] + edge.second;
        q.emplace(edge.first, dis[edge.first]);
      }
    }
  }
  return dis[n];
}

int main() {
  // input
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    pos[i].idx = i;
    scanf("%d%d", &pos[i].x, &pos[i].y);
  }
  // sort x
  std::sort(pos + 1, pos + 1 + n, [](const Pos& lhs, const Pos& rhs) {
    return lhs.x < rhs.x; 
  });
  for (int i = 2; i <= n; ++i) {
    int weight = pos[i].x - pos[i - 1].x;
    edges[pos[i - 1].idx].emplace_back(pos[i].idx, weight);
    edges[pos[i].idx].emplace_back(pos[i - 1].idx, weight);
  }
  // sort y
  std::sort(pos + 1, pos + 1 + n, [](const Pos& lhs, const Pos& rhs) {
    return lhs.y < rhs.y;
  });
  for (int i = 2; i <= n; ++i) {
    int weight = pos[i].y - pos[i - 1].y;
    edges[pos[i - 1].idx].emplace_back(pos[i].idx, weight);
    edges[pos[i].idx].emplace_back(pos[i - 1].idx, weight);
  }
  printf("%lld\n", dijkstra());
}
