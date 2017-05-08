// Copyright 2017 Qi Wang
// Date: 2017-05-08
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  vector<pair<int, int> > cows(n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &cows[i].first, &cows[i].second);
  sort(cows.begin(), cows.end());
  int shift = 1, result = 0;
  for (int i = 0; i < n && cows[i].first <= shift && shift <= t;) {
    int idx = i;
    for (; i < n && cows[i].first <= shift; ++i)
      if (cows[i].second > cows[idx].second)
        idx = i;
    shift = cows[idx].second + 1;
    while (i < n && cows[i].second < shift) ++i;
    ++result;
  }
  printf("%d\n", shift > t ? result : -1);
}
