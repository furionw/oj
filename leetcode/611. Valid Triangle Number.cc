// Copyright 2017 Qi Wang
// Date: 2017-06-11
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        auto lb = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
        result += distance(nums.begin() + j + 1, lb);
      }
    }
    return result;
  }
};
