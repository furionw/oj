// Copyright 2017 Qi Wang
// Date: 2017-02-18
// Note that the solution presented on 2016-11-26 is better
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    // init left
    vector<int> left(n);
    left.front() = nums.front();
    for (int i = 1; i < n; ++i)
      left[i] = nums[i] * left[i - 1];
    // init right
    vector<int> right(nums.size(), 1);
    right.back() = nums.back();
    for (int i = n - 2; i >= 0; --i)
      right[i] = nums[i] * right[i + 1];
    // calculate the result
    vector<int> result(n);
    result.front() = right[1];
    result.back() = left[n - 2];
    for (int i = 1; i < n - 1; ++i)
      result[i] = left[i - 1] * right[i + 1];
    return result;
  }
};

// Date: 2016-11-26
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for (int i = 1, left = 1; i < static_cast<int>(nums.size()); ++i) {
      left *= nums[i - 1];
      res[i] *= left;
    }
    for (int i = static_cast<int>(nums.size()) - 2, right = 1; i >= 0; --i) {
      right *= nums[i + 1];
      res[i] *= right;
    }
    return res;
  }
};
