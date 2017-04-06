// Copyright 2017 Qi Wang
// Date: 2017-04-06
// Refer to: LC 264
class Solution {
 public:
  int GetUglyNumber_Solution(int index) {
    if (index <= 0) return 0;
    vector<int> nums(index);
    nums[0] = 1;
    int idx2 = 0, idx3 = 0, idx5 = 0;
    for (int i = 1; i < index; ++i) {
      nums[i] = min(2 * nums[idx2], 3 * nums[idx3]);
      nums[i] = min(nums[i], 5 * nums[idx5]);
      for (; 2 * nums[idx2] <= nums[i]; ++idx2) {}
      for (; 3 * nums[idx3] <= nums[i]; ++idx3) {}
      for (; 5 * nums[idx5] <= nums[i]; ++idx5) {}
    }
    return nums.back();
  }
};
