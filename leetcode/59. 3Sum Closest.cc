// Copyright 2017 Qi Wang
// Date: 2017-10-24
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) return INT_MIN;
    sort(nums.begin(), nums.end());
    int result = accumulate(nums.begin(), nums.begin() + 3, 0);
    for (int i = 0; i < nums.size() - 2;) {
      for (int l = i + 1, r = nums.size() - 1; l < r;) {
        int sum = nums[i] + nums[l] + nums[r];
        result = abs(result - target) < abs(sum - target) ? result : sum;
        if (sum == target) {
          return target;
        } else if (sum < target) {
          Advance(nums, &l);
        } else {
          --r;
        }
      }
      Advance(nums, &i);
    }
    return result;
  }

 private:
  void Advance(const vector<int>& nums, int* idx) const {
    for (++*idx; *idx < nums.size() && nums[*idx] == nums[*idx - 1]; ++*idx) {}
  }
};
