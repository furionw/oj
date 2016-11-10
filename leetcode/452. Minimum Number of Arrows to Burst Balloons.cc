// Copyright 2016 Qi Wang
// Date: 2016-11-09
class Solution {
 public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end());
    int res = 1, pre = points.back().first;
    for (int i = points.size() - 1; i >= 0; --i)
      if (points[i].second < pre) {
        pre = points[i].first;
        ++res;
      }
    return res;
  }
};
