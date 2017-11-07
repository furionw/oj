// Copyright 2017 Qi Wang
// Date: 2017-11-07
// Case 1: ["0011", "1100", "0001"] -> 8
// The solution on 2017-02-19 is more space efficient
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    vector<int> cnts(32, 0);
    int n = nums.size();
    for (int num : nums) {
      for (int i = 0; num; ++i, num >>= 1) {
        cnts[i] += num & 1;
      }
    }
    int result = 0;
    for (int cnt : cnts) {
      result += (n - cnt) * cnt;
    }
    return result;
  }
};

// Date: 2017-08-04
// The solution on 2017-02-19 is more space efficient
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int cnts[32][2];
    memset(cnts, 0, sizeof cnts);
    for (int num : nums) {
      for (int i = 0; i < 32; ++i) {
        ++cnts[i][num & 1];
        num >>= 1;
      }
    }
    int result = 0;
    for (int i = 0; i < 32; ++i) {
      result += cnts[i][0] * cnts[i][1];
    }
    return result;
  }
};

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
