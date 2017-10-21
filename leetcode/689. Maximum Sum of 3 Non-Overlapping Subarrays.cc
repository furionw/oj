// Copyright 2017 Qi Wang
// Date: 2017-10-19
// Refer to: https://discuss.leetcode.com/topic/105577/c-java-dp-with-explanation-o-n
// Case 1: [5, 3, 2, 7], 1
class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i < sums.size(); ++i) {
      sums[i] = sums[i - 1] + nums[i - 1];
    }
    // left_pos[i] = x, where i >= k - 1.
    //   sub-array nums[x], nums[x + 1], …, nums[x + k - 1] has the maximal sum
    vector<int> left_pos(nums.size() + 1, 0);
    for (int i = k, sum = sums[k]; i < nums.size(); ++i) {
      if (sums[i + 1] - sums[i + 1 - k] > sum) {
        sum = sums[i + 1] - sums[i + 1 - k];
        left_pos[i] = i - k + 1;
      } else {
        left_pos[i] = left_pos[i - 1];
      }
      // printf("left_pos[%d] = %d\n", i, left_pos[i]);
    }
    vector<int> right_pos(nums.size() + 1, nums.size() - k);
    for (int i = nums.size() - k - 1, sum = sums.back() - sums[nums.size() - k];
         i >= 2 * k; --i) {
      if (sums[i + k] - sums[i] > sum) {
        sum = sums[i + k] - sums[i];
        right_pos[i] = i;
      } else {
        right_pos[i] = right_pos[i + 1];
      }
      // printf("right_pos[%d] = %d\n", i, right_pos[i]);
    }
    vector<int> result;
    for (int i = k, sum = 0; i <= nums.size() - 2 * k; ++i) {
      int l = left_pos[i - 1], r = right_pos[i + k];
      int val = (sums[l + k] - sums[l]) + (sums[i + k] - sums[i]) +
                (sums[r + k] - sums[r]);
      if (val > sum) {
        sum = val;
        result = {l, i, r};
      }
    }
    return result;
  }
};
