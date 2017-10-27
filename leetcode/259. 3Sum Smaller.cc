// Copyright 2017 Qi Wang
// Date: 2017-10-26
// Refer to the solution on 2016-12-25
// Case 1: [1, 2, 3], 3
// Case 2: [1, 2, 3, 4], 10
class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] < target) {
          result += r - l++;
        } else {
          --r;
        }
      }
    }
    return result;
  }
};

// Date: 2016-12-25
class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) return 0;
    int res = 0;
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] < target) {
          res += r - l;
          ++l;
        } else {
          --r;
        }
      }
    }
    return res;
  }
};