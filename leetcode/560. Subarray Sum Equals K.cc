// Copyright 2017 Qi Wang
// Date: 2017-05-01
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
