// 2025-07-22
class Solution {
 public:
  int maximizeGreatness(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto it = upper_bound(nums.begin(), nums.end(), nums[0]);
    int result = 0;
    for (int num : nums) {
      while (it != nums.end() && *it <= num) {
        ++it;
      }
      if (it == nums.end()) {
        break;
      } else {
        ++result;
        ++it;
      }
    }
    return result;
  }
};
