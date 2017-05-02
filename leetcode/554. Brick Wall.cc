// Copyright 2017 Qi Wang
// Date: 2017-05-02
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> cnts;
    for (const auto& row : wall) {
      int acc = 0;
      for (size_t i = 0; i < row.size() - 1; ++i)
        ++cnts[acc += row[i]];
    }
    int max_edge = 0;
    for (const auto& p : cnts) max_edge = max(max_edge, p.second);
    return wall.size() - max_edge;
  }
};
