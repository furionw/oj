// Date: 2022-11-12
class Solution {
public:
  int subarrayLCM(vector<int>& nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int cur_lcm = nums[i];
      if (cur_lcm == k) {
        ++res;
      }
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] > k) {
          break;
        }
        cur_lcm = lcm(cur_lcm, nums[j]);
        if (cur_lcm == k) {
          ++res;
        } else if (cur_lcm > k) {
          break;
        }
      }
    }
    
    return res;
  }
};
