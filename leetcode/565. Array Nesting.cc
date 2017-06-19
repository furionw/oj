// Copyright 2017 Qi Wang
// Date: 2017-06-20
// Method 2
// Refer to the solution on 2017-06-03
class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i)
      if (result[i] == -1)
        F(nums, i, result, 1);
    return *max_element(result.begin(), result.end());
  }
 
 private:
  void F(const vector<int>& nums, int idx, vector<int>& result,
      int depth) const {
    result[idx] = 0;
    // cyclic visit will happen if call F() on nums[idx]
    if (result[nums[idx]] != -1) {
      result[idx] = depth;
    // idx, nums[idx] are on the same cycle
    } else {
      F(nums, nums[idx], result, ++depth);
      result[idx] = result[nums[idx]];  // same cycle
    }
  }
};

// Date: 2017-06-20
// Method 1
class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i)
      if (result[i] == -1)
        F(nums, i, result, 1);
    return *max_element(result.begin(), result.end());
  }
 
 private:
  int F(const vector<int>& nums, int idx, vector<int>& result,
      int depth) const {
    if (nums[idx] == idx) {
      return result[idx] = depth;
    } else if (result[nums[idx]] != -1) {
      return result[idx] = depth;
    } else {
      result[idx] = 0;
      return result[idx] = F(nums, nums[idx], result, ++depth);
    }
  }
};

// Date: 2017-06-03
class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    vector<bool> vi(nums.size(), false);
    vector<int> cnt(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      if (!vi[i]) {
        DFS(i, 1, nums, vi, cnt);
      }
    }
    return *max_element(cnt.begin(), cnt.end());
  }
 
 private:
  void DFS(int idx, int depth, const vector<int>& nums, vector<bool>& vi,
      vector<int>& cnt) const {
    vi[idx] = true;
    if (vi[nums[idx]]) {
      cnt[idx] = depth;
    } else {
      DFS(nums[idx], ++depth, nums, vi, cnt);
      cnt[idx] = cnt[nums[idx]];
    }
  }
};
