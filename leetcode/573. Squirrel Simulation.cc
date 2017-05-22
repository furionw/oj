// Copyright 2017 Qi Wang
// Refer to: https://discuss.leetcode.com/topic/88504/c-clean-code-with-explanation
// Date: 2017-05-22
class Solution {
 public:
  int minDistance(int height, int width, vector<int>& tree,
      vector<int>& squirrel, vector<vector<int>>& nuts) {
    int result = 0;
    int min_extra = INT_MAX;
    for (const auto& nut : nuts) {
      result += dist(nut, tree) << 1;
      min_extra = min(min_extra, dist(nut, squirrel) - dist(nut, tree));
    }
    return result + min_extra;
  }

 private:
  int dist(const vector<int>& from, const vector<int>& to) const {
    return abs(from[0] - to[0]) + abs(from[1] - to[1]);
  }
};
