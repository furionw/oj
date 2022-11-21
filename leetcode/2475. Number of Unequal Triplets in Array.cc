// Date: 2022-11-20
class Solution {
 public:
  int unequalTriplets(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] == nums[i]) {
          continue;
        }
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[k] == nums[i] || nums[k] == nums[j]) {
            continue;
          }
          ++res;
        }
      }
    }
    return res;
  }
};
