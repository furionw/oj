// Copyright 2017 Qi Wang
// Date: 2017-01-03
class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    unordered_set<string> points;
    int area = 0;
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    for (const auto& rect : rectangles) {
      x1 = min(x1, rect[0]);
      y1 = min(y1, rect[1]);
      x2 = max(x2, rect[2]);
      y2 = max(y2, rect[3]);
      area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
      // top-left
      updatePointSet(points, to_string(rect[0]) + ',' + to_string(rect[1]));
      // top-right
      updatePointSet(points, to_string(rect[0]) + ',' + to_string(rect[3]));
      // bottom-left
      updatePointSet(points, to_string(rect[2]) + ',' + to_string(rect[1]));
      // bottom-right
      updatePointSet(points, to_string(rect[2]) + ',' + to_string(rect[3]));
    }
    return points.size() == 4 && points.count(to_string(x1) + ',' + to_string(y1))
        && points.count(to_string(x1) + ',' + to_string(y2))
        && points.count(to_string(x2) + ',' + to_string(y1))
        && points.count(to_string(x2) + ',' + to_string(y2))
        && (x2 - x1) * (y2 - y1) == area;
  }

 private:
  void updatePointSet(unordered_set<string>& points, const string& point) const {
    // non exists
    if (!points.count(point)) {
      points.insert(point);
    // exist
    } else {
      points.erase(point);
    }
  }
};
