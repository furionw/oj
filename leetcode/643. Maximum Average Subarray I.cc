// Copyright 2017 Qi Wang
// Date: 2017-07-15
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int result = accumulate(nums.begin(), nums.begin() + k, 0);
    int cur = result;
    for (size_t i = k; i < nums.size(); ++i) {
      result = max(result, cur += nums[i] - nums[i - k]);
    }
    return result * 1. / k;
  }
};
