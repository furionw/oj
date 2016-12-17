// Copyright 2016 Qi Wang
// Solved by my own!!!
// Date: 2016-12-16
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;
    vector<int> res;
    list<int> descL;
    for (int i = 0; i < k - 1; ++i) {
      while (!descL.empty() && descL.back() < nums[i]) descL.pop_back();
      descL.push_back(nums[i]);
    }
    for (size_t i = k - 1; i < nums.size(); ++i) {
      if (descL.front() == nums[i - k]) descL.pop_front();
      while (!descL.empty() && descL.back() < nums[i]) descL.pop_back();
      descL.push_back(nums[i]);
      res.push_back(descL.front());
    }
    return res;
  }
};

// Refer to: http://blog.csdn.net/xudli/article/details/46955257
// Time complexity: O(n)
// Date: 2016-11-12
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 0) return vector<int>();
    vector<int> res;
    list<size_t> window;
    for (size_t i = 0; i < nums.size(); ++i) {
      while (!window.empty() && nums[window.back()] <= nums[i])
        window.pop_back();
      window.push_back(i);
      if (i - window.front() >= k) window.pop_front();
      if (i + 1 >= k) res.push_back(nums[window.front()]);
    }
    return res;
  }
};

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
