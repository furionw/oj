// Copyright 2016 Qi Wang
// Method 1
// Reservoir sampling
// Time: somethings TLE, sometimes beats 88% cpp solutions with about 110ms
// Refer to: http://www.cnblogs.com/grandyang/p/5875509.html
// Date: 2016-11-27
class Solution {
 public:
  Solution(vector<int> nums) : nums_(move(nums)) {}
    
  int pick(int target) {
    int res = -1;
    for (size_t i = 0, cnt = 0; i < nums_.size(); ++i) {
      if (nums_[i] != target) continue;
      ++cnt;
      if (rand() % cnt == 0) res = i;
    }
    return res;
  }

 private:
  vector<int> nums_;
};

// Method 1
// Time: somethings 130ms, sometimes 218ms : P
// Date: 2016-11-26
class Solution {
 public:
  Solution(vector<int> nums) : nums_(move(nums)) {}
    
  int pick(int target) {
    vector<int> idxs;
    for (size_t i = 0; i < nums_.size(); ++i)
      if (nums_[i] == target) idxs.push_back(i);
    return idxs[rand() % idxs.size()];
  }

 private:
  vector<int> nums_;
};