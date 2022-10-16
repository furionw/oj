// Date: 2022-10-14
class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int maxx = accumulate(nums.begin() + 1, nums.end(), nums[0],
                          [](int acc, int cur){
                            return max(acc, cur);
                          });
    int result = 1;
    int cur = 0;
    for (int num : nums) {
      if (num == maxx) {
        ++cur;
      } else {
        result = max(result, cur);
        cur = 0;
      }
    }
    result = max(result, cur);
    return result;
  }
};
