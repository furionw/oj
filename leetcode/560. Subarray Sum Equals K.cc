// 2025-05-06
// Method 2: refer to solution in 2017
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> cnts {{0, 1}};
    int acc = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      acc += nums[i];
      result += cnts[acc - k];
      ++cnts[acc];
    }
    return result;
  }
};

// Method 1
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> cnts;
    int acc = 0;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      acc += nums[i];
      if (acc == k) {
        ++result;
      }
      result += cnts[acc - k];
      ++cnts[acc];
    }
    return result;
  }
};

// 2017-05-01
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> accCnts;
    accCnts[0] = 1;
    int acc = 0, result = 0;
    for (int num : nums) {
      acc += num;
      if (0 != accCnts.count(acc - k))
        result += accCnts[acc - k];
      ++accCnts[acc];
    }
    return result;
  }
};
