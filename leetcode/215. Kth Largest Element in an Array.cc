// Copyright 2016 Qi Wang
// Method 2
// Date: 2016-12-05
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    for (int begin = 0, end = nums.size() - 1; begin < end; ) {
      int left = begin, right = end;
      int pivot = nums[left];
      while (left < right) {
        for (; left < right && nums[right] <= pivot; --right) {}
        nums[left] = nums[right];
        for (; left < right && nums[left] > pivot; ++left) {}
        nums[right] = nums[left];
      }
      nums[left] = pivot;
      if (left == k - 1) {
        return nums[k - 1];
      } else if (left < k - 1) {
        begin = left + 1;
      } else {
        end = left - 1;
      }
    }
    return nums[k - 1];
  }
};

// Date: 2016-12-05
// Method 1: std::nth_element
// Beats 90% cpp solutions
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.end() - k, nums.end());
    return nums[nums.size() - k];
  }
};

// Date: 2015-09
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int begin = 0, end = nums.size() - 1;

        while (begin < end)
        {
          int left = begin, right = end;
          int pivot = nums[left];
          while (left < right)
          {
            for (; left < right && nums[right] < pivot; -- right) {}
            nums[left] = nums[right];            
            for (; left < right && nums[left] >= pivot; ++ left) {}
            nums[right] = nums[left];
          }
          nums[left] = pivot;
          if (left == k - 1)
          {
            return nums[left];
          } else if (left > k - 1)
          {
            end = left - 1;
          } else 
          {
            begin = left + 1;
          }
        }

        return nums[k-1];
    }
};