// Copyright 2017 Qi Wang
// Date: 2017-05-27
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main() {
  int c, l;
  cin >> c >> l;
  vector<pair<int, int> > cows(c), lotions(l);
  for (int i = 0; i < c; ++i)
    cin >> cows[i].first >> cows[i].second;
  for (int i = 0; i < l; ++i)
    cin >> lotions[i].first >> lotions[i].second;
  sort(cows.begin(), cows.end());
  sort(lotions.begin(), lotions.end());
  int result = 0;
  // minimal heap
  priority_queue<int, vector<int>, greater<int> > q;
  for (size_t cow_idx = 0, lotion_idx = 0; lotion_idx < l; ++lotion_idx) {
    while (cow_idx < c && cows[cow_idx].first <= lotions[lotion_idx].first)
      q.push(cows[cow_idx++].second);
    while (!q.empty() && lotions[lotion_idx].second > 0) {
      int cow_max_spf = q.top(); q.pop();
      if (lotions[lotion_idx].first <= cow_max_spf) {
        --lotions[lotion_idx].second;
        ++result;
      }
    }
  }
  cout << result << endl;
}
