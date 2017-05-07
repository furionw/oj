// Copyright 2017 Qi Wang
// Date: 2017-05-07
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int r, n;
  while (cin >> r >> n, r != -1 && n != -1) {
    vector<int> points(n);
    for (int i = 0; i < n; ++i) cin >> points[i];
    sort(points.begin(), points.end());
    int result = 0;
    for (int i = 0; i < n; ++i) {
      ++result;
      int center_idx = i;
      while (center_idx + 1 < n && points[center_idx + 1] - r <= points[i])
        ++center_idx;      
      int end_idx = center_idx;
      while (end_idx + 1 < n && points[end_idx + 1] - r <= points[center_idx])
        ++end_idx;
      i = end_idx;
    }
    cout << result << endl;
  }
}
