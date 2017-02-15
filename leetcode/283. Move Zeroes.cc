// Copyright 2017 Qi Wang
// Date: 2017-02-09
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    while (true) {
      bool has_swap = false;
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] == 0 && nums[i + 1] != 0) {
          swap(nums[i], nums[i + 1]);
          has_swap = true;
        }
      }
      if (!has_swap) break;
    }
  }
};

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
