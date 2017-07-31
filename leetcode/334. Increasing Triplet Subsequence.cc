// Copyright 2017 Qi Wang
// Date: 2017-07-30
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int a1 = nums.front(), a2 = INT_MAX, b = INT_MAX;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] > a2) {
        return true;
      } else if (a1 < nums[i] && nums[i] < a2) {
        a2 = nums[i];
      } else if (nums[i] < a1) {
        if (a2 == INT_MAX) {
          a1 = nums[i];
        } else if (nums[i] > b) {
          a1 = b;
          a2 = nums[i];
        } else {
          b = nums[i];
        }
      }
    }
    return false;
  }
};

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
