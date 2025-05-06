// 2025-05-05
class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    set<vector<int>> s;
    for (const auto& p : points) {
      s.insert(p);
    }
    int result = 0;
    for (const auto& p1 : s) {
      for (const auto& p2 : s) {
        if (p1[0] >= p2[0] || p1[1] >= p2[1]) {
          continue;
        }
        // only consider when p1 is the bottom-left and p2 is the top-right
        if (!s.contains({p1[0], p2[1]}) || !s.contains({p2[0], p1[1]})) {
          continue;
        }
        int area = (p2[0] - p1[0]) * (p2[1] - p1[1]);
        if (result == 0) {
          result = area;
        } else {
          result = min(result, area);
        }
      }
    }
    return result;
  }
};
