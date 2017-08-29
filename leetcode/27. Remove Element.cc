// Copyright 2016 Qi Wang
// Date: 2017-08-28
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int len = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[len++] = nums[i];
      }
    }
    return len;
  }
};

// Date: 2016-12-21
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    size_t len = 0;
    for (int& num : nums)
      if (num != val)
        nums[len++] = num;
    return len;
  }
};

// Date: 2014-06
class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
    {
      int ret = 0;

      for (int i = 0; i < n; ++ i)
      {
        if (A[i] != elem)
        {
          A[ret ++] = A[i];
        }
      }

      return ret;    
    }
};
