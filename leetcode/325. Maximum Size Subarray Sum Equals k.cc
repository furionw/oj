// Copyright 2017 Qi Wang
// Date: 2017-07-03
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int64_t, int> sum_to_idx;
    sum_to_idx[0] = -1;
    int64_t sum = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum_to_idx.count(sum - k) > 0)
        result = max(result, i - sum_to_idx[sum - k]);
      if (0 == sum_to_idx.count(sum))
        sum_to_idx[sum] = i;
    }
    return result;
  }
};

// Date: 2017-02-14
// Refer to: https://discuss.leetcode.com/topic/33255/o-n-c-solution-using-unordered_map
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> sums;
    int result = 0, cur_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cur_sum += nums[i];
      if (cur_sum == k) {
        result = i + 1;
      // I think count() runs faster than find()
      } else if (sums.count(cur_sum - k) > 0) {
        result = max(result, i - sums[cur_sum - k]);
      }
      if (sums.count(cur_sum) == 0)
        sums[cur_sum] = i;
    }
    return result;
  }
};

// Date: 2017-02-10
// 1600ms, Almost TLE
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    for (int result = nums.size(); result != 0; --result) {
      int sum = accumulate(nums.begin(), nums.begin() + result, 0);
      if (sum == k) return result;
      for (int i = result; i < nums.size(); ++i)
        if ((sum += nums[i] - nums[i - result]) == k)
          return result;
    }
    return 0;
  }
};
