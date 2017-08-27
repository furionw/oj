// Copyright 2017 Qi Wang
// Date: 2017-08-26
class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> nums(n);
    for (int i = 1; i <= k; ++i) {
      if (i & 1) {
        // odd
        nums[i - 1] = (i + 1) / 2;
      } else {
        nums[i - 1] = n + 1 - nums[i - 2];
      }
    }
    if (k & 1) {
      int num = (k + 1) / 2 + 1;
      for (int i = k; i < n; ++i) {
        nums[i] = num++;
      }      
    } else {
      for (int i = k; i < n; ++i) {
        nums[i] = nums[i - 1] - 1;
      }
    }
    return nums;
  }
};
