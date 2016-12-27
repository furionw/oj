// Copyright 2016 Qi Wang
// Date: 2016-12-27
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int n = static_cast<int>(nums.size());
    for (int i = n - 2; i >= 0; --i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] > nums[i]) {
          swap(nums[j], nums[i]);
          reverse(nums.begin() + i + 1, nums.end());
          return;
        }
      }
    }
    reverse(nums.begin(), nums.end());
  }
};

// Method 2
// Refer to my submission in 2014-07
// Date: 2016-12-06
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    for (int i = nums.size() - 2; i >= 0; --i)
      // [i + 1, ..., nums.size()] are in decending order
      for (int j = nums.size() - 1; j > i; --j)
        if (nums[j] > nums[i]) {
          swap(nums[i], nums[j]);
          sort(nums.begin() + i + 1, nums.end());
          return;
        }
    sort(nums.begin(), nums.end());
  }
};

// Method 1
// Date: 2016-12-06
// Copyright 2016 Qi Wang
// Date: 2016-12-06
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    for (int i = nums.size() - 2; i >= 0; --i) {
      int largerMin = INT_MAX, idx = -1;
      for (int j = i + 1; j < nums.size(); ++j)
        if (nums[j] > nums[i] && nums[j] < largerMin) {
          largerMin = nums[j];
          idx = j;
        }
      // Found
      if (idx != -1) {
        swap(nums[i], nums[idx]);
        sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    sort(nums.begin(), nums.end());
  }
};

// Date: 2014-07
class Solution 
{
public:
    void nextPermutation(vector<int> &num) 
    {
    for (int i = num.size()-2; i >= 0; -- i)
    {
      for (int j = num.size()-1; j > i; -- j)
      {
        if (num[j] > num[i])
        {
          int tmp = num[j];
          num[j] = num[i];
          num[i] = tmp;
          sort(num.begin()+i+1, num.end()); 
          return ;
        }
      }
    }
    sort(num.begin(), num.end());
    }
};