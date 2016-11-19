// Copyright 2016 Qi Wang
// Date: 2016-11-19
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (int num : nums) {
      if (num > second) {
        return true;
      } else if (num > first) {
        second = min(second, num);
      } else {
        first = min(first, num);
      }
    }
    return false;
  }
};
