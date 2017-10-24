// Copyright 2017 Qi Wang
// Date: 2017-10-23
class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> cur;
    Subsets(nums, 0, &cur, &result);
    return result;
  }
 
 private:
  void Subsets(const vector<int>& nums, int idx, vector<int>* cur,
               vector<vector<int>>* result) const {
    if (idx == nums.size()) {
      result->push_back(*cur);
      return;
    }
    Subsets(nums, idx + 1, cur, result);
    cur->push_back(nums[idx]);
    Subsets(nums, idx + 1, cur, result);
    cur->pop_back();
  }
};
