// Copyright 2017 Qi Wang
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
