// Date: 2022-11-18
class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (size_t i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] <<= 1;
        nums[i + 1] = 0;
      }
    }
    for (size_t i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] != 0) {
        continue;
      }
      size_t j = i + 1;
      for (; j < nums.size() && nums[j] == 0; ++j) {}
      if (j == nums.size()) {
        break;
      }
      swap(nums[i], nums[j]);
    }
    return nums;
  }
};
