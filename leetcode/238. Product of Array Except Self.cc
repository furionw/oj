// Copyright 2016 Qi Wang
// Date: 2016-11-26
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for (int i = 1, left = 1; i < static_cast<int>(nums.size()); ++i) {
      left *= nums[i - 1];
      res[i] *= left;
    }
    for (int i = static_cast<int>(nums.size()) - 2, right = 1; i >= 0; --i) {
      right *= nums[i + 1];
      res[i] *= right;
    }
    return res;
  }
};
