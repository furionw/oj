// Copyright 2016 Qi Wang
// Reference: https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap
// Date: 2016-10-22
class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
      unordered_set<int> s;
      mask |= (1 << i);
      for (int num : nums) s.insert(num & mask);
      int temp = res | (1 << i);
      for (int num : s)
        if (s.find(temp ^ num) != s.end()) {
          res = temp;
          break;
        }
    }
    return res;
  }
};
