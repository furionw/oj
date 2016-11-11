// Copyright 2016 Qi Wang
// Date: 2016-11-11
class Solution {
 public:
  int integerBreak(int n) {
    if (n < 7) {
      int nums[] = {0, 0, 1, 2, 4, 6, 9};
      return nums[n];
    } else {
      int nums[n + 1] = {0, 0, 1, 2, 4, 6, 9};
      for (int i = 7; i <= n; ++i)
        nums[i] = max(nums[i - 1] / 3 * 4, nums[i - 3] * 3);
      return nums[n];
    }
  }
};
