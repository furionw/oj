// Copyright 2017 Qi Wang
// Date: 2017-05-09
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

inline int solve(vector<pair<double, double> >& intervals) {
  sort(intervals.begin(), intervals.end());
  double pre = intervals.back().first;
  int result = 1;
  for (int i = intervals.size() - 1; i >= 0; --i)
    if (intervals[i].second < pre) {
      pre = intervals[i].first;
      ++result;
    }
  return result;
}

int main() {
  for (double n, d, id = 1; cin >> n >> d, n != 0 && d != 0; ++id) {
    // Use double to represent positions
    vector<pair<double, double> > intervals;
    bool valid = true;
    for (double x, y; 0 != n; --n) {
      cin >> x >> y;
      valid = valid && y <= d;
      double dist = sqrt(d * d - y * y);
      intervals.push_back(make_pair(x - dist, x + dist));
    }
    cout << "Case " << id << ": " << (valid ? solve(intervals) : -1) << endl;
  }
}
