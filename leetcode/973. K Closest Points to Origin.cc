// Copyright 2019 Qi Wang
// Date: 2019-01-13
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    nth_element(points.begin(), points.begin() + K, points.end(),
        [](const vector<int>& lhs, const vector<int>& rhs) {
          return (lhs[0] * lhs[0] + lhs[1] * lhs[1]) <
              (rhs[0] * rhs[0] + rhs[1] * rhs[1]);
        });
    return vector<vector<int>>(points.begin(), points.begin() + K);
  }
};
