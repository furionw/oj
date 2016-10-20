// Copyright 2016 Qi Wang
// More space efficient
// Date: 2016-10-09
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int mask = 1; mask; mask <<= 1) {
      int bitCnt = 0;
      for (int num : nums) bitCnt += (num & mask) != 0 ? 1 : 0;
      res |= bitCnt % 3 == 1 ? mask : 0;
    }
    return res;
  }
};

// Date: 2014-08
class Solution {
 public:
  int singleNumber(int A[], int n) {
  	int cnt[32] = {0};
  	int ret = 0;
  	for (int i = 0; i < n; ++ i)
  	  for (int j = 0; j < 32; ++ j) {
  		  unsigned int bit = 1 << j;
  		  cnt[j] += (A[i]&bit)!=0? 1: 0;
      }
  	for (int i = 0; i < 32; ++ i)
  	  ret |= (cnt[i]%3)!=0? 1<<i: 0;
    return ret;
  }
};
