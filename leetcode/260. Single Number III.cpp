// Copyright 2016 Qi Wang
// Date: 2016-10-09
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int pivot = 0;
    for (int num : nums) pivot ^= num;
    int mask = 1;
    // Note that the EQUAL's precendence is higher than AND's
    while ((mask & pivot) == 0) mask <<= 1;
    vector<int> res(2, 0);
    for (int num : nums) res[(mask & num) == 0] ^= num;
    return res;
  }
};

// Taught by Ming Lin
// Date: 2016-09-26
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int xorRes = 0;
    for (int num : nums) xorRes ^= num;
    int filterBit = 1;
    while ((filterBit & xorRes) == 0) filterBit <<= 1;
    vector<int> res(2, 0);
    for (int num : nums) res[(filterBit & num) == 0] ^= num;
    return xorRes;
  }
};
