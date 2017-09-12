// Copyright 2017 Qi Wang
// Date: 2017-09-11
class Solution {
 public:
  vector<Point> outerTrees(vector<Point>& points) {
    // This check is added even 'points' is guaranteed to be non-empty
    // in the question.
    if (points.empty()) return {};
    vector<Point> result(points.size() * 2);
    int k = 0;
    sort(points.begin(), points.end(), Comp);
    for (auto& p : points) {
      while (k > 1 &&
             !CounterClockwise(result[k - 2], result[k - 1], p)) {
        --k;
      }
      result[k++] = p;
    }
    for (int i = points.size() - 1, t = k + 1; i >= 0; --i) {
      while (k >= t && !CounterClockwise(result[k - 2], result[k - 1],
                                         points[i])) {
        --k;
      }
      result[k++] = points[i];
    }
    result.resize(k);
    sort(result.begin(), result.end(), Comp);
    result.erase(unique(result.begin(), result.end(), Equal),
                 result.end());
    return result;
  }

  static bool Comp(const Point& p1, const Point& p2) {
    return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
  }

  static bool Equal(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
  }

 private:
  bool CounterClockwise(const Point& p1, const Point& p2,
                        const Point& p3) const {
    return float(p3.y - p2.y) * (p2.x - p1.x) >=
           float(p2.y - p1.y) * (p3.x - p2.x);
  }
};
