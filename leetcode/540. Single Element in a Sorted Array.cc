// 2025-07-23
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    // n distinct numbers.
    // e.g. size = 9, n = 5
    //      size = 5, n = 3
    int n = nums.size() / 2 + 1;
    int l = 1, r = n;
    int begin = 0, end = nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      // e.g. mid = 3, the index of the first 3rd number should be 0,1,2,3,"4"
      // e.g. mid = 4, the index of the first 4rd number should be 0,1,2,3,4,5,"6"
      int idx = (mid - 1) * 2;
      if (nums[idx] == nums[idx + 1]) {
        l = mid + 1;
      } else if (idx > 0 && nums[idx - 1] == nums[idx]) {
        r = mid - 1;
      } else {
        return nums[idx];
      }
    }
    return nums[(l - 1) * 2];
  }
};

// Date: 2017-03-12
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    for (int l = 0, r = nums.size() - 1; l <= r; ) {
      if (l == r) return nums[l];
      int mid = (l + r) >> 1;
      if (nums[mid] == nums[mid - 1]) {
        // odd number
        if ((mid - 1 - l) & 1) {
          r = mid - 2;
        // even
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] == nums[mid + 1]) {
        // odd
        if ((r - mid - 1) & 1) {
          l = mid + 2;
        // even
        } else {
          r = mid - 1;
        }
      } else {
        return nums[mid];
      }
    }
    return -1;  // comfort the compiler
  }
};
