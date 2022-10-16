// Date: 2022-10-15
class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> sums;
    for (size_t i = 1; i < nums.size(); ++i) {
      int sum = nums[i - 1] + nums[i];
      if (sums.count(sum)) {
        return true;
      }
      sums.insert(sum);
    }
    return false;
  }
};
