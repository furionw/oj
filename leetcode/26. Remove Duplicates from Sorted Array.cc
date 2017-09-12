// Copyright 2017 Qi Wang
// Date: 2017-09-11
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
  }
};

// Date: 2017-08-16
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int idx = 1;
    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] != nums[i - 1])
        nums[idx++] = nums[i];
    return idx;
  }
};

// Date: 2017-08-05
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int result = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        nums[result++] = nums[i];
      }
    }
    return result;
  }
};
 
// Date: 2016-12-21
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    size_t i = 1, pre = 0;
    while (true) {
      while (i < nums.size() && nums[i] == nums[pre]) ++i;
      if (i < nums.size()) {
        nums[++pre] = nums[i++];
      } else {
        break;
      }
    }
    // return the length of the new array
    return pre + 1;
  }
};

// Date: 2014-06
class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
      int ret = 0;

      for (int i = 0; i < n; ++ i)
      {
        if (i!=0 && A[i]==A[i-1])
        {
          continue;
        } else
        {
          A[ret ++] = A[i];
        }
      }

      return ret;    
    }
};