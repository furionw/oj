// Copyright 2016 Qi Wang
// Date: 2016-11-11
struct cmp {
  bool operator ()(const pair<int, size_t>& lhs, const pair<int, size_t>& rhs) {
    return lhs.first != rhs.first
        ? lhs.first < rhs.first
        : lhs.second > rhs.second;
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 0) return vector<int>();
    vector<int> res;
    priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, cmp> q;
    for (size_t i = 0; i < k; ++i)
      q.emplace(nums[i], i);
    res.push_back(q.top().first);
    for (size_t i = k; i < nums.size(); ++i) {
      q.emplace(nums[i], i);
      while (i - q.top().second >= k)
        q.pop();
      res.push_back(q.top().first);
    }
    return res;
  }
};
