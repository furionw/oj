// Copyright 2016 Qi Wang
// Method 2
// Refer to: http://bookshadow.com/weblog/2016/11/01/leetcode-find-all-numbers-disappeared-in-an-array/
// Date: 2016-11-16
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int num : nums)
      nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
    vector<int> res;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      if (nums[i] > 0)
        res.push_back(i + 1);
    return res;
  }
};

// Method 1
// Date: 2016-11-16
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < static_cast<int>(nums.size());)
      if (nums[i] != -1 && nums[i] != i + 1) {
        if (nums[i] == nums[nums[i] - 1]) {
          nums[i] = -1;
          ++i;
        } else {
          swap(nums[i], nums[nums[i] - 1]);
        }
      } else {
        ++i;
      }
    vector<int> res;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
      if (nums[i] == -1)
        res.push_back(i + 1);
    return res;
  }
};
