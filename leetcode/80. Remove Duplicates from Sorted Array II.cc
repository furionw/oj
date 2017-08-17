// Copyright 2017 Qi Wang
// Date: 2017-08-16
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int idx = 1;
    int cnt = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        if (++cnt > 2) continue;
        nums[idx++] = nums[i];
      } else {
        nums[idx++] = nums[i];
        cnt = 1;
      }
    }
    return idx;
  }
};

// Date: 2017-08-05
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size();) {
      int pos = i;
      for (++i; i < nums.size() && nums[i] == nums[i - 1]; ++i) {}
      for (int k = 1; k <= i - pos && k <= 2; ++k) {
        nums[result++] = nums[pos];
      }
    }
    return result;
  }
};

class Solution 
{
public:
  int removeDuplicates(int A[], int n) 
  {
    int length = 0;

    for (int i=0; i < n; )
    {
      A[length ++] = A[i ++];
      if (i<n && A[i-1]==A[i])
      {
        A[length ++] = A[i ++];
      }
      for ( ; i<n && A[i]==A[i-1]; ++ i) {}
    }

    return length;
  }
};