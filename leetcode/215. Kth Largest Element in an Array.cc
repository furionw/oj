// Copyright 2017 Qi Wang
// Date: 2017-07-27
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int ll = l, rr = r;
      int pivot = nums[ll];
      while (ll < rr) {
        for (; ll < rr && nums[rr] <= pivot; --rr) {}
        nums[ll] = nums[rr];
        for (; ll < rr && nums[ll] > pivot; ++ll) {}
        nums[rr] = nums[ll];
      }
      nums[ll] = pivot;
      if (ll == k - 1) {
        return nums[k - 1];
      } else if (ll > k - 1) {
        r = ll - 1;
      } else {
        l = ll + 1;
      }
    }
    // Return nums[k - 1] here to handle the case where k == 1
    return nums[k - 1];
  }
};

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