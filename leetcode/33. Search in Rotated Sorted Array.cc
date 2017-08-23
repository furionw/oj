// Copyright 2017 Qi Wang
// Date: 2017-08-17
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (target < nums[mid]) {
        if (nums[l] <= nums[mid] && target < nums[l]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      // target > nums[mid]
      } else {
        if (nums[mid] <= nums[r] && target > nums[r]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }
    return -1;
  }
};

// Date: 2017-07-26
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    return Search(nums, 0, nums.size() - 1, target);
  }

 private:
  int Search(const vector<int>& nums, int l, int r, int target) const {
    if (l > r) return -1;
    int mid = (l + r) >> 1;
    if (nums[mid] < target) {
      if (nums[l] <= nums[mid]) {
        return Search(nums, mid + 1, r, target);
      } else {
        return target <= nums[r]
            ? Search(nums, mid + 1, r, target)
            : Search(nums, l, mid - 1, target);
      }
    } else if (nums[mid] == target) {
      return mid;
    // target < nums[mid]
    } else {
      if (nums[l] <= nums[mid]) {
        return target >= nums[l]
            ? Search(nums, l, mid - 1, target)
            : Search(nums, mid + 1, r, target);
      } else {
        return Search(nums, l, mid - 1, target);
      }
    }
  }
};

class Solution 
{
public:
    int search(int A[], int n, int target) 
    {
      return find(A, 0, n-1, target);
    }
private:
  int find(int a[], int l, int r, int target)
  {
    if (l > r)
    {
      return -1;
    }

    int index = -1, mid = (l+r)>>1;

    if (a[l] < a[r])
    {
      while (l <= r)
      {
        mid = (l+r) >> 1;
        if (a[mid] == target)
        {
          index = mid;
          break;
        } else if (a[mid] < target)
        {
          l = mid + 1;
        } else
        {
          r = mid - 1;
        }
      }
    } else
    {
      index = find(a, l, mid, target);
      index = index!=-1? index: find(a, mid+1, r, target);
    }

    return index;
  }
};