// Copyright 2016 Qi Wang
// Date: 2016-12-25
class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) return 0;
    int res = 0;
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] < target) {
          res += r - l;
          ++l;
        } else {
          --r;
        }
      }
    }
    return res;
  }
};