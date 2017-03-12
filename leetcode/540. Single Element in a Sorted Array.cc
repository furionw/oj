// Copyright 2017 Qi Wang
// Date: 2017-03-12
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    for (int l = 0, r = nums.size() - 1; l <= r; ) {
      if (l == r) return nums[l];
      int mid = (l + r) >> 1;
      if (nums[mid] == nums[mid - 1]) {
        // odd number
        if ((mid - 1 - l) & 1) {
          r = mid - 2;
        // even
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] == nums[mid + 1]) {
        // odd
        if ((r - mid - 1) & 1) {
          l = mid + 2;
        // even
        } else {
          r = mid - 1;
        }
      } else {
        return nums[mid];
      }
    }
    return -1;  // comfort the compiler
  }
};
