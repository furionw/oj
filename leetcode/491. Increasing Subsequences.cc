// Copyright 2017 Qi Wang
// Method 2
// Refer to: https://discuss.leetcode.com/topic/76274/c-dfs-solution-using-unordered_set
// My proof:
//   exists: Using this implementaion, we will be able to find all combinations
//   unique: For any combination, there is only one calling chain would yield
//     the corresponding result.
// Date: 2017-06-12
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    vector<vector<int>> result;
    F(nums, 0, seq, result);
    return result;
  }

 private:
  void F(const vector<int>& nums, size_t pos, vector<int>& seq,
      vector<vector<int>>& result) const {
    if (seq.size() > 1) result.push_back(seq);
    unordered_set<int> hash;
    for (size_t i = pos; i < nums.size(); ++i) {
      if ((seq.empty() || seq.back() <= nums[i]) && hash.count(nums[i]) == 0) {
        seq.push_back(nums[i]);
        F(nums, i + 1, seq, result);
        seq.pop_back();
        hash.insert(nums[i]);
      }
    }
  }
};

// Method 1
// Date: 2017-06-12
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    if (nums.size() <= 1) return vector<vector<int>>();
    vector<int> cur;
    vector<vector<int>> result;
    unordered_set<string> dict;
    F(nums, 0, cur, dict, result);
    return result;
  }
 
 private:
  void F(const vector<int>& nums, size_t idx, vector<int>& cur,
      unordered_set<string>& dict, vector<vector<int>>& result) const {
    if (nums.size() == idx) {
      if (cur.size() >= 2 && !Exist(cur, dict)) result.push_back(cur);
      return;
    }
    F(nums, idx + 1, cur, dict, result);
    if (cur.empty() || nums[idx] >= cur.back()) {
      cur.push_back(nums[idx]);
      F(nums, idx + 1, cur, dict, result);
      cur.pop_back();
    }
  }
 
  bool Exist(const vector<int>& cur, unordered_set<string>& dict) const {
    string str;
    for (int i : cur) str += to_string(i) + ",";
    if (1 == dict.count(str)) {
      return true;
    } else {
      dict.insert(str);
      return false;
    }
  }
};
