// Copyright 2017 Qi Wang
// Date: 2017-10-26
// Refer to the solution on 2017-08-17
// Case 1: [2, 3, 4], 2
class Solution {
 public:
  int64_t splitArray(vector<int>& nums, int m) {
    if (nums.empty() || nums.size() < m) return INT_MIN;
    int l = nums.front();
    int64_t r = 1;
    for (int num : nums) {
      r += num;
      l = max(l, num);
    }
    while (l < r) {
      int64_t mid = l + r >> 1;
      if (Valid(nums, mid, m)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;  // l == r now
  }
 
 private:
  bool Valid(const vector<int>& nums, int64_t candidate_sum, int m) const {
    int64_t acc = 0;
    int cnt = 0;
    for (int num : nums) {
      if (acc + num > candidate_sum) {
        acc = num;
        if (++cnt == m) return false;
      } else {
        acc += num;
      }
    }
    return true;
  }
};

// Date: 2017-08-17
// Refer to: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    int64_t acc = 0;
    int max_num = INT_MIN;
    for (int num : nums) {
      acc += num;
      max_num = max(max_num, num);
    }
    if (m == 1) return acc;
    int64_t l = max_num, r = acc + 1;
    while (l < r) {
      int64_t mid = l + r >> 1;
      if (Valid(nums, m, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
 
 private:
  bool Valid(const vector<int>& nums, int m, int64_t sum) const {
    int cnt = 1;
    int64_t acc = 0;
    for (int num : nums) {
      acc += num;
      if (acc > sum) {
        acc = num;
        if (++cnt > m) return false;
      }
    }
    return true;
  }
};
