// Copyright 2017 Qi Wang
// Date: 2017-02-19
// Refer to: https://discuss.leetcode.com/topic/72092/java-o-n-time-o-1-space
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int result = 0;
    for (int mask = 1 << 30; mask; mask >>= 1) {
      int one_cnt = count_if(nums.begin(), nums.end(), [mask](int num) {
        return num & mask;
      });
      result += (nums.size() - one_cnt) * one_cnt;
    }
    return result;
  }
};

// Date: 2017-02-19
// TLE
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        result += hammingDistance(nums[i], nums[j]);
    return result;
  }

 private:
  int hammingDistance(int x, int y) {
    int cnt = 0;
    for (x ^= y; x != 0; x &= x - 1)
      ++cnt;
    return cnt;
  }
};
