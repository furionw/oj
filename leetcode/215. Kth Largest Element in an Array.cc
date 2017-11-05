// Copyright 2017 Qi Wang
// Date: 2017-11-05
// Case 1: [5, 2, 4, 1, 3, 6, 0], 4
// Please note that the solution on 2017-09-11 is a little bit more concise.
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size();
    while (l < r) {
      int pivot_idx = Partition(&nums, l, r);
      if (pivot_idx == k - 1) {
        return nums[k - 1];
      } else if (pivot_idx < k - 1) {
        l = pivot_idx + 1;
      } else {
        r = pivot_idx;
      }
    }
    return nums[k - 1];
  }
 
 private:
  int Partition(vector<int>* nums, int l, int r) const {
    int pivot_idx = l + rand() % (r - l);
    int pivot = (*nums)[pivot_idx];
    swap((*nums)[l], (*nums)[pivot_idx]);
    int last_greater_elem_idx = l;
    for (int i = l + 1; i < r; ++i) {
      if ((*nums)[i] > pivot) {
        swap((*nums)[++last_greater_elem_idx], (*nums)[i]);
      }
    }
    swap((*nums)[l], (*nums)[last_greater_elem_idx]);
    return last_greater_elem_idx;
  }
};

// Date: 2017-09-11
// Refer to: 剑指Offer Q30
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty() || k > nums.size()) return INT_MIN;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int idx = Partition(&nums, l, r);
      if (idx == k - 1) {
        return nums[k - 1];
      } else if (idx < k - 1) {
        l = idx + 1;
      } else {
        r = idx - 1;
      }
    }
    return INT_MIN;
  }
 
 private:
  int Partition(vector<int>* nums, int l, int r) {
    swap((*nums)[RandomInRange(l, r)], (*nums)[r]);
    int big = l - 1;
    for (int i = l; i <= r; ++i) {
      if ((*nums)[i] > (*nums)[r]) {
        swap((*nums)[++big], (*nums)[i]);
      }
    }
    swap((*nums)[++big], (*nums)[r]);
    return big;
  }
 
  int RandomInRange(int l, int r) {
    return l + rand() % (r - l + 1);
  }
};

// Date: 2017-08-17
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
        return nums[ll];
      } else if (ll < k - 1) {
        l = ll + 1;
      } else {
        r = ll - 1;
      }
    }
    return nums[k - 1];;
  }
};
 
// Date: 2017-08-14
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) return INT_MIN;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int ll = l, rr = r;
      int pivot = nums[ll];
      while (ll < rr) {
        for (; ll < rr && pivot >= nums[rr]; --rr) {}
        nums[ll] = nums[rr];
        for (; ll < rr && nums[ll] > pivot; ++ll) {}
        nums[rr] = nums[ll];
      }
      nums[ll] = pivot;
      if (ll == k - 1) {
        return nums[k - 1];
      } else if (ll < k - 1) {
        l = ll + 1;
      } else {
        r = ll - 1;
      }
    }
    return nums[k - 1];
  }
};

// Date: 2017-08-14
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
        greater<int>());
    return nums[k - 1];
  }
};

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