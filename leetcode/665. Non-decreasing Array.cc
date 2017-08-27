// Copyright 2017 Qi Wang
// Date: 2017-08-26
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    int max_elem = nums.front();
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] >= max_elem) {
        max_elem = nums[i];
      } else {
        if (cnt++ == 1) return false;
        if (i == 1 || nums[i] > nums[i - 2]) {
          max_elem = nums[i];
        }
      }
    }
    return true;
  }
};