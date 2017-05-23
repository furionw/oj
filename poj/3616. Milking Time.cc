// Copyright 2017 Qi Wang
// Date: 2017-05-23
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
  Interval() {}
  bool operator <(const Interval& other) const {
    if (end != other.end) {
      return end < other.end;
    } else {
      return start != other.start
          ? start > other.start : efficiency > other.efficiency;
    }
  }
  int start, end, efficiency;
};

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> dp(n + 1, 0);
  vector<Interval> intervals(m);
  for (int i = 0; i < m; ++i) {
    cin >> intervals[i].start >> intervals[i].end >> intervals[i].efficiency;
    intervals[i].end = min(n, intervals[i].end + r);
  }
  sort(intervals.begin(), intervals.end());
  int t = 0;
  for (int i = 0; i < m;) {
    for (++t; t < intervals[i].end; ++t)
      dp[t] = dp[t - 1];
    dp[t] = dp[t - 1];
    for (; i < m && t == intervals[i].end; ++i)
      dp[t] = max(dp[t], dp[intervals[i].start] + intervals[i].efficiency);
  }
  cout << dp[t] << endl;
}
