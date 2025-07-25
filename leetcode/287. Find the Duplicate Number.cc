// 2025-07-23
// Method 2: Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (true) {
      fast = nums[nums[fast]];
      slow = nums[slow];
      if (slow == fast) {
        break;
      }
    }
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

// Method 1: sum of set bits
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    // log2(3) = 1. Need 2 bits
    // log2(4) = 2. Need 3 bits
    // log2(5) = 2. Need 3 bits
    int bits = log2(n) + 1;

    vector<int> baseCounts(bits, 0);
    for (int i = 1; i <= n; ++i) {
      int idx = 0;
      for (int mask = 1; mask <= i; mask <<= 1) {
        if (i & mask) {
          ++baseCounts[idx];
        }
        ++idx;
      }
    }

    vector<int> numsCounts(bits, 0);
    for (int num : nums) {
      int idx = 0;
      for (int mask = 1; mask <= num; mask <<= 1) {
        if (num & mask) {
          ++numsCounts[idx];
        }
        ++idx;
      }
    }

    int result = 0;
    for (int i = 0; i < bits; ++i) {
      if (numsCounts[i] > baseCounts[i]) {
        result += (1 << i);
      }
    }
    return result;
  }
};

// Date: 2017-08-10
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    const int N = nums.size() - 1;
    int l = 1, r = N;
    while (l <= r) {
      int mid = l + r >> 1;
      int greater_cnt = 0, less_cnt = 0;
      for (int num : nums) {
        if (num > mid) {
          ++greater_cnt;
        } else if (num < mid) {
          ++less_cnt;
        }
      }
      if (greater_cnt > N - mid) {
        l = mid + 1;
      } else  if (less_cnt > mid - 1) {
        r = mid - 1;
      } else {
        return mid;
      }
    }
    return INT_MIN;
  }
};
