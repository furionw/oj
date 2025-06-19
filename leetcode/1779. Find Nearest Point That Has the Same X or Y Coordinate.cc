// 2025-06-18
class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int dis = 1e9;
    int result = -1;
    for (int i = 0; i < points.size(); ++i) {
      const auto& p = points[i];
      if (x == p[0] || y == p[1]) {
        int candidateDis = abs(x - p[0]) + abs(y - p[1]);
        if (candidateDis < dis) {
          dis = candidateDis;
          result = i;
        }
      }
    }
    return result;
  }
};
