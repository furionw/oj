// Copyright 2016 Qi Wang
// Date: 2016-11-17
class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    int res[n];
    res[0] = 1;
    int multiplicators[] = {2, 3, 5};
    int idxs[] = {0, 0, 0};
    for (int i = 1; i < n; ++i) {
      res[i] = INT_MAX;
      for (int j = 0; j < 3; ++j)
        res[i] = min(res[i], multiplicators[j] * res[idxs[j]]);
      for (int j = 0; j < 3; ++j)
        idxs[j] += multiplicators[j] * res[idxs[j]] == res[i];
    }
    return res[n - 1];
  }
};

// Date: 2015-09
class Solution 
{
public:
  int nthUglyNumber(int n) 
  {
    vector<int> nums(n, 1);
    int idx2 = 0; 
    int idx3 = 0;
    int idx5 = 0;
    
    for (int i = 1; i < n; ++ i)
    {
      nums[i] = min(2*nums[idx2], min(3*nums[idx3], 5*nums[idx5]));
      for (; 2 * nums[idx2] <= nums[i]; ++ idx2) {}
      for (; 3 * nums[idx3] <= nums[i]; ++ idx3) {}
      for (; 5 * nums[idx5] <= nums[i]; ++ idx5) {}
    }
      
    return nums[n-1];
  }
};
