// Copyright 2017 Qi Wang
// Date: 2017-05-11
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Stop {
  Stop() {}
  Stop(int pos, int fuel) : pos(pos), fuel(fuel) {}
  int pos, fuel;
};

bool comp(const Stop& lhs, const Stop& rhs) {
  return lhs.pos != rhs.pos ? lhs.pos < rhs.pos : lhs.fuel < rhs.fuel;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<Stop> stops(n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &stops[i].pos, &stops[i].fuel);
  int l, p;
  scanf("%d%d", &l, &p);
  for (int i = 0; i < n; ++i)
    stops[i].pos = l - stops[i].pos;
  sort(stops.begin(), stops.end(), comp);
  stops.push_back(Stop(l, 0));
  int pos = 0, result = 0;
  priority_queue<int> q;
  for (int i = 0; i <= n && p >= 0; ++i) {
    int dist = stops[i].pos - pos;
    // lack of fuel
    while (!q.empty() && p < dist) {
      p += q.top();
      q.pop();
      ++result;
    }
    // If stops[i] is unreachable, p would become negative, resulting in loop
    // termination.
    p -= dist;
    q.push(stops[i].fuel);
    pos = stops[i].pos;
  }
  printf("%d\n", p >= 0 ? result : -1);
}
