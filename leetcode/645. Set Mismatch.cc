// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    // 2
    vector<int> record(nums.size() + 1, 0);
    for (int num : nums)
      ++record[num];
    vector<int> result;
    for (size_t i = 1; i < record.size(); ++i)
      if (record[i] == 2)
        result.push_back(i);
    for (size_t i = 1; i < record.size(); ++i)
      if (record[i] == 0)
        result.push_back(i);
    return result;
  }
};