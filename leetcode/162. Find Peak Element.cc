// Copyright 2017 Qi Wang
// Date: 2017-09-07
// Refer to: https://discuss.leetcode.com/topic/5848/o-logn-solution-javacode
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.empty()) return -1;
    int n = nums.size();
    if (n == 1 || nums[0] > nums[1]) return 0;
    if (nums[n - 2] < nums[n - 1]) return n - 1;
    int l = 1, r = n - 2;
    while (l <= r) {
      int mid = l + r >> 1;
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid - 1] < nums[mid] &&
                 nums[mid] < nums[mid + 1]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
};

// Date: 2017-09-07
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.empty()) return -1;
    int n = nums.size();
    if (n == 1 || nums[0] > nums[1]) return 0;
    if (nums[n - 2] < nums[n - 1]) return n - 1;
    for (int i = 1; i < n - 1; ++i)
      if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) return i;
    return -1;
  }
};

class Solution 
{
public:
    int findPeakElement(const vector<int> &num) 
    {
      if (num.size() == 1)
      {
        return 0;
      }
        for (int i = 0; i < num.size(); ++ i)
        {
          if ((i - 1 >= 0 && i + 1 < num.size() && num[i] > num[i-1] && num[i] > num[i+1])
            || (i == 0 && i + 1 < num.size() && num[i] > num[i+1])
            || (i + 1 == num.size() && i - 1 >= 0 && num[i] > num[i-1]))
          {
            return i;
          }
        }
        return INT_MAX;
    }
};