// Date: 2020-08-02
// Method 1: use "l < r"
class Solution {
  public int[] searchRange(int[] nums, int target) {
    int firstIdx = first(nums, target);
    if (firstIdx == -1) {
      return new int[] { -1, -1 };
    } else {
      return new int[] { firstIdx, last(nums, target) };
    }
  }

  // loop invariant: 答案存在于 nums[l: r] 或者 result 中
  // nums[l: r] -- Python 的写法，也就是 nums[l] 至 nums[r - 1] 中
  static private int first(int[] nums, int target) {
    int l = 0;
    int r = nums.length;
    int result = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        // 找到了潜在的答案，进一步缩小搜索范围寻找更准确的答案
        result = mid;
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return (l < nums.length && nums[l] == target) ? l : result;
  }

  static private int last(int[] nums, int target) {
    int l = 0;
    int r = nums.length;
    int result = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        // 找到了潜在的答案，进一步缩小搜索范围寻找更准确的答案
        result = mid;
        l = mid + 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return (l < nums.length && nums[l] == target) ? l : result;
  }
}

// Date: 2020-08-02
// Method 2: use "l < r"
class Solution {
  public int[] searchRange(int[] nums, int target) {
    if (nums.length == 0) {
      return new int[] { -1, -1 };
    }
    int firstIdx = first(nums, target);
    if (firstIdx == -1) {
      return new int[] { -1, -1 };
    } else {
      return new int[] { firstIdx, last(nums, target) };
    }
  }
   
  // assumption: nums is non-empty
  static private int first(int[] nums, int target) {
    int l = 0;
    int r = nums.length - 1;
    int result = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        // 找到了潜在的答案，进一步缩小搜索范围寻找更准确的答案
        result = mid;
        r = mid - 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return nums[l] == target ? l : result;
  }

  // assumption: nums is non-empty
  static private int last(int[] nums, int target) {
    int l = 0;
    int r = nums.length - 1;
    int result = -1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        // 找到了潜在的答案，进一步缩小搜索范围寻找更准确的答案
        result = mid;
        l = mid + 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return nums[l] == target ? l : result;
  }
}

// Date: 2020-08-02
// Method 3: Use "l <= r"
class Solution {
  public int[] searchRange(int[] nums, int target) {
    int firstIdx = first(nums, target);
    if (firstIdx == -1) {
      return new int[] { -1, -1 };
    } else {
      return new int[] { firstIdx, last(nums, target) };
    }
  }

  static private int first(int[] nums, int target) {
    int l = 0;
    int r = nums.length - 1;
    int result = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        result = mid;
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return result;
  }

  static private int last(int[] nums, int target) {
    int l = 0;
    int r = nums.length - 1;
    int result = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        result = mid;
        l = mid + 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return result;
  }
}
