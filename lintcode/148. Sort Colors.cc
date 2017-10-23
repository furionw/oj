// Copyright 2017 Qi Wang
// Date: 2017-10-21
class Solution {
 public:
  void sortColors(vector<int> &nums) {
    if (nums.size() <= 1) return;
    int zero_idx = 0, two_idx = nums.size() - 1;
    for (int one_idx = 0; one_idx <= two_idx;) {
      if (nums[one_idx] == 0) {
        swap(nums[zero_idx++], nums[one_idx++]);
      } else if (nums[one_idx] == 2) {
        swap(nums[two_idx--], nums[one_idx]);
      } else {
        ++one_idx;
      }
    }
  }
};
