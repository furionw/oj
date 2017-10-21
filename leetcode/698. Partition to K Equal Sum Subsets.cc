// Copyright 2017 Qi Wang
// Date: 2017-10-18
// Case 1: [-1, -1, -1, 1], 2
// Case 2: [4, 3, 2, 3, 5, 2, 1], 4
// Refer to: https://discuss.leetcode.com/topic/107111/cpp-solution-with-explanation-in-details
class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k == 1) return true;
    int acc = accumulate(nums.begin(), nums.end(), 0);
    if (acc % k != 0) return false;
    vector<bool> taken(nums.size(), false);
    return CanPartitionKSubsets(nums, &taken, 0, 0, acc / k, 1, k);
  }
 
 private:
  bool CanPartitionKSubsets(const vector<int>& nums, vector<bool>* taken,
      int idx, int cur_sum, int target_sum, int subset_cnt, int k) const {
    if (cur_sum == target_sum) {
      if (subset_cnt == k - 1) return true;
      return CanPartitionKSubsets(nums, taken, 0, 0, target_sum,
                                  ++subset_cnt, k);
    }
    for (int i = idx; i < nums.size(); ++i) {
      if ((*taken)[i]) continue;
      cur_sum += nums[i];
      (*taken)[i] = true;
      if (CanPartitionKSubsets(nums, taken, i + 1, cur_sum, target_sum,
                               subset_cnt, k))
        return true;
      (*taken)[i] = false;
      cur_sum -= nums[i];
    }
    return false;
  }
};
