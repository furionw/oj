// Copyright 2017 Qi Wang
// Date: 2017-11-08
// Please note that this impl won't pass the LeetCode OJ, while it can achieve
// the minimal number of the write operations.
// Mentioned in https://instant.1point3acres.com/thread/290474
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.empty()) return;
    int zero_idx = 0, non_zero_idx = nums.size() - 1;
    while (zero_idx < non_zero_idx) {
      for (; zero_idx < non_zero_idx && nums[zero_idx] != 0; ++zero_idx) {}
      for (; zero_idx < non_zero_idx && nums[non_zero_idx] == 0;
           --non_zero_idx) {}
      if (zero_idx < non_zero_idx) {
        swap(nums[zero_idx++], nums[non_zero_idx--]);
      }
    }
  }
};

// Date: 2017-10-21
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int non_zero_idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[non_zero_idx++] = nums[i];
      }
    }
    for (; non_zero_idx < nums.size(); ++non_zero_idx) {
      nums[non_zero_idx] = 0;
    }
  }
};

// Date: 2017-08-28
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    for (int i = 0, begin = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        swap(nums[i], nums[begin++]);
      }
    }
  }
};

// Date: 2017-07-03
// The solution on 2017-02-09 is a more propriate answer.
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int zero_cnt = count(nums.begin(), nums.end(), 0);
    for (size_t i = 0; i < nums.size(); ++i)
      while (0 == nums[i] && zero_cnt > 0) {
        --zero_cnt;
        for (size_t j = i; j + 1 < nums.size(); ++j)
          swap(nums[j], nums[j + 1]);
      }
  }
};

// Date: 2017-02-09
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    while (true) {
      bool has_swap = false;
      for (int i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] == 0 && nums[i + 1] != 0) {
          swap(nums[i], nums[i + 1]);
          has_swap = true;
        }
      }
      if (!has_swap) break;
    }
  }
};

// Date: 2016-10-03
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int nonZeroIdx = 0;
    for (size_t i = 0; i < nums.size(); ++i)
      if (nums[i] != 0) swap(nums[nonZeroIdx++], nums[i]);
    memset(nums.data() + nonZeroIdx, 0,
        sizeof(int) * (nums.size() - nonZeroIdx));
  }
};
