// 2025-05-01
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    if (k == 0) {
      return longestOnes(nums);
    }

    int result = 0;
    int cnt = 0;
    int prev = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        ++cnt;
      } else {
        for (; k == 0 && prev < i; ++prev) {
          --cnt;
          if (nums[prev] == 0) {
            ++k;
          }
        }
        ++cnt;
        --k;
      }
      result = max(result, cnt);
    }

    return result;
  }

 private:
  int longestOnes(vector<int>& nums) {
    int result = 0;
    int cnt = 0;
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
