// Copyright 2016 Qi Wang
// Date: 2016-12-25
class Solution {
 public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int res = 0;
    for (size_t i = 0; i < points.size(); ++i) {
      unordered_map<int, int> cnts;
      for (size_t j = 0; j < points.size(); ++j) {
        if (i == j) continue;
        int xDelta = points[j].first - points[i].first,
            yDelta = points[j].second - points[i].second;
        ++cnts[xDelta * xDelta + yDelta * yDelta];
      }
      for (auto& p : cnts)
        res += p.second * (p.second - 1);
    }
    return res;
  }
};

// Date: 2016-11-08
class Solution {
 public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    if (points.empty()) return 0;
    int res = 0;
    for (size_t i = 0; i < points.size(); ++i) {
      // Define only one RB-tree inside the loop, instead of allocating
      // n RB-tree array at the beginning
      map<int, int> dis;
      for (size_t j = 0; j < points.size(); ++j)
        ++dis[calDis(points[i], points[j])];      
      for (const auto& p : dis)
        if (p.second >= 2) res += p.second * (p.second - 1);
    }
    return res;
  }

 private:
  inline int calDis(const pair<int, int>& a, const pair<int, int>& b) const {
    // We do not use pow() here, avoiding floating point multiplication
    return (a.first - b.first) * (a.first - b.first)
        + (a.second - b.second) * (a.second - b.second);
  }
};
