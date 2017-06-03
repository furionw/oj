// Copyright 2017 Qi Wang
// Date: 2017-06-02
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
