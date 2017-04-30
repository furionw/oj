// Copyright 2017 Qi Wang
// Date: 2017-04-30
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.empty()) return nums;
    int m = nums.size(), n = nums[0].size();
    if (m * n != r * c) return nums;
    int cnt = 0;
    vector<vector<int>> result(1);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (++cnt <= c) {
          result.back().push_back(nums[i][j]);
        } else {
          cnt = 1;
          result.emplace_back(1, nums[i][j]);
        }
      }
    return result;
  }
};
