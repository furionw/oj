// Copyright 2017 Qi Wang
// Date: 2017-10-11
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[len - 1]) {
        swap(nums[i], nums[len++]);
      }
    }
    return len;
  }
};
