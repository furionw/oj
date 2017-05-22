// Copyright 2017 Qi Wang
// Date: 2017-05-22
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    int result = 0;
    unordered_map<int, int> cnts;
    for (int num : nums) {
      ++cnts[num];
      if (cnts[num - 1] > 0)
        result = max(result, cnts[num - 1] + cnts[num]);
      if (cnts[num + 1] > 0)
        result = max(result, cnts[num] + cnts[num + 1]);
    }
    return result;
  }
};
