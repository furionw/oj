// Copyright 2017 Qi Wang
// Date: 2017-10-11
// Method 2
class Solution {
 public:
  int search(vector<int> &A, int target) {
    if (A.empty()) return -1;
    return Search(A, 0, A.size() - 1, target);
  }

 private:
  int Search(const vector<int>& nums, int l, int r, int target) const {
    while (l <= r) {
      int mid = l + r >> 1;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[l] > nums[mid]) {
        if (target < nums[mid] || target > nums[r]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target || target < nums[l]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return -1;
  }
};

// Date: 2017-10-11
// Method 1
class Solution {
 public:
  int search(vector<int> &A, int target) {
    if (A.empty()) return -1;
    return Search(A, 0, A.size() - 1, target);
  }
 
 private:
  int Search(const vector<int>& nums, int l, int r, int target) const {
    if (l > r) return -1;
    if (nums[l] <= nums[r]) {
      while (l <= r) {
        int mid = l + r >> 1;
        if (nums[mid] == target) {
          return mid;
        } else if (nums[mid] < target) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return -1;
    // nums[l] > nums[r]
    } else {
      int mid = l + r >> 1;
      if (nums[mid] == target) return mid;
      if (nums[l] > nums[mid]) {
        if (nums[mid] < target) {
          return target >= nums[l] ? Search(nums, l, mid - 1, target)
                                   : Search(nums, mid + 1, r, target);
        } else {
          return Search(nums, l, mid - 1, target);
        }
      } else {
        if (nums[mid] < target) {
          return Search(nums, mid + 1, r, target);
        } else {
          return nums[l] <= target ? Search(nums, l, mid - 1, target)
                                   : Search(nums, mid + 1, r, target);
        }
      }
    }
  }
};
