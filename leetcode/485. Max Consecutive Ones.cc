// Copyright 2017 Qi Wang
// Date: 2017-01-17
// Difficulty: Easy
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    for (int cnt = 0, i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        result = max(result, ++cnt);
      } else {
        cnt = 0;
      }
    }
    return result;
  }
};
