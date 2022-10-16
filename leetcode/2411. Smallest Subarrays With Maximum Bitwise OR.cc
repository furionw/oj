// Date: 2022-10-14
// Method 2
// Refer to: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/discuss/2588015/JavaC%2B%2BPython-Bit-Solution-with-Explanation
class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int last[30] = {};
    vector<int> res(nums.size(), 1);
    // for (int num : nums) {
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = 0; i < 30; ++j) {
        if ((1 << j) & num) {
          last[j] = i;
        }
        res[i] = max(res[i], j - i + 1);
      }
    }
  }
};

// Method 1
class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    unordered_set<int> bitPos;
    int bitCnts[31] = {0};
    
    vector<int> maxBits(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; --i) {
      int num = nums[i];
      for (int j = 0; j < 31; ++j) {
        if (((1 << j) & num) != 0) {
          bitPos.insert(j);
        }
      }
      maxBits[i] = bitPos.size();
    }
    
    
    vector<int> result(nums.size(), 1);
    
    for (int i = 0, cur = 0, j = 0; i < nums.size(); ++i) {
      if (i > 0) {
        cur = update(nums[i - 1], bitCnts, false /*inc*/, cur);        
      }
      for (; j < nums.size() && cur < maxBits[i]; ++j) {
        cur = update(nums[j], bitCnts, true /*inc*/, cur);        
      }
      if (j == i) {
        ++j;
      }
      result[i] = j - i;
    }
    return result;
  }
  
 private:
  int update(int num, int* bitCnts, bool inc, int cur) const {
    for (int i = 0; i < 31; ++i) {
      if (((1 << i) & num) == 0) {
        continue;
      }
      if (inc && bitCnts[i]++ == 0) {
        ++cur;
      } else if (!inc && --bitCnts[i] == 0) {
        --cur;
      }
    }
    return cur;
  }
};
