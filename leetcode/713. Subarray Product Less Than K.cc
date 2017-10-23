// Copyright 2017 Qi Wang
// Date: 2017-10-22
// Refer to: artemztk's solution
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int prod = 1, cnt = 0;
    for (int l = 0, r = 0; l < nums.size(); ++l) {
      if (r <= l) r = l;
      while (r < nums.size() && prod * nums[r] < k) {
        prod *= nums[r++];
      }
      cnt += r - l;
      if (prod > 1) prod /= nums[l];
    }
    return cnt;
  }
};
