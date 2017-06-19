// Copyright 2017 Qi Wang
// Date: 2017-06-19
// Refer to https://discuss.leetcode.com/topic/92858/c-o-n
class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int left = arrays[0].front(), right = arrays[0].back();
    int result = 0;
    for (size_t i = 1; i < arrays.size(); ++i) {
      const auto& elem = arrays[i];
      result = max(result, max(abs(elem.back() - left), abs(elem.front() - right)));
      left = min(left, elem.front());
      right = max(right, elem.back());
    }
    return result;
  }
};

// Date: 2017-06-18
class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int maxx = INT_MIN, max_idx = -1;
    priority_queue<int> q;
    for (int i = 0; i < arrays.size(); ++i) {
      if (arrays[i].back() > maxx) {
        maxx = arrays[i].back();
        max_idx = i;
      }
      q.push(arrays[i].back());
    }
    int result = 0;
    for (int i = 0; i < arrays.size(); ++i)
      if (max_idx != i)
        result = max(result, abs(maxx - arrays[i].front()));
    q.pop();
    result = max(result, abs(q.top() - arrays[max_idx].front()));
    return result;
  }
};
