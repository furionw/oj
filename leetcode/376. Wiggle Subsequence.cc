// Copyright 2016 Qi Wang
// Greedy with O(n) time
// Method 2
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;
    int lessCnt = 1, less = nums[0];
    int greaterCnt = 1, greater = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] < greater && lessCnt < greaterCnt + 1) {
        lessCnt = greaterCnt + 1;
        less = nums[i];
      }
      if (nums[i] > less && greaterCnt < lessCnt + 1) {
        greaterCnt = lessCnt + 1;
        greater = nums[i];
      }
      less = min(less, nums[i]);
      greater = max(greater, nums[i]);
    }
    return max(lessCnt, greaterCnt);
  }
};

// Method 1
// DP with O(n^2) time
// Date: 2016-12-17
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.empty()) return 0;
    int less[nums.size()], greater[nums.size()];
    fill(less, less + nums.size(), 1);
    fill(greater, greater + nums.size(), 1);
    for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j]) {
          greater[i] = max(greater[i], less[j] + 1);
        } else if (nums[i] < nums[j]) {
          less[i] = max(less[i], greater[j] + 1);
        }
        // do nothing when nums[i] == nums[j]
      }
    }
    return max(*max_element(less, less + nums.size()),
        *max_element(greater, greater + nums.size()));
  }
};
