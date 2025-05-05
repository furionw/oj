// 2025-05-01
// Refer to: https://leetcode.com/problems/zero-array-transformation-i/solutions/6053820/very-easy-intuitive-solution-beginner-friendly-prefix-sum/?envType=company&envId=google&favoriteSlug=google-thirty-days
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int result = 0;
    for (int num : nums) {
      if (num == 0) {
        cnt = 0;
      } else {
        result = max(result, ++cnt);
      }
    }
    return result;
  }
};

// Date: 2017-01-17
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    for (int cnt = 0, i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        result = max(result, ++cnt);
      } else {
        cnt = 0;
      }
    }
    return result;
  }
};
