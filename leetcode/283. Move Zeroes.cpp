// Copyright 2016 Qi Wang
// Date: 2016-10-03
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int nonZeroIdx = 0;
    for (size_t i = 0; i < nums.size(); ++i)
      if (nums[i] != 0) swap(nums[nonZeroIdx++], nums[i]);
    memset(nums.data() + nonZeroIdx, 0,
        sizeof(int) * (nums.size() - nonZeroIdx));
  }
};
