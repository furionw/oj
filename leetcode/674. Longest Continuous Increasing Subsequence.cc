// Copyright 2017 Qi Wang
// Date: 2017-10-18
// Case 1: [0, 1, 4, 5, 6]
// Case 2: [1, 3, 5, 4, 7]
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int len = 1;
    int result = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] <= nums[i - 1]) {
        result = max(result, len);
        len = 1;
      } else {
        ++len;
      }
    }
    return max(result, len);
  }
};

// Date: 2017-09-09
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int result = !nums.empty();
    int cur = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        result = max(result, ++cur);
      } else {
        cur = 1;
      }
    }
    return result;
  }
};
