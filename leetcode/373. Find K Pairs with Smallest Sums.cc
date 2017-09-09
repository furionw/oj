// Copyright 2017 Qi Wang
// Date: 2017-09-08
// Refer to: https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation
struct Tuple3 {
  int num1, num2, num2_idx;
};
 
struct Comp {
  bool operator()(const Tuple3& lhs, const Tuple3& rhs) {
    return lhs.num1 + lhs.num2 > rhs.num1 + rhs.num2;
  }
};
 
class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1,
                                        vector<int>& nums2, int k) {
    vector<pair<int, int>> result;
    if (nums1.size() * nums2.size() <= k) {
      for (int num1 : nums1)
        for (int num2 : nums2)
          result.emplace_back(num1, num2);
      return result;
    }
    priority_queue<Tuple3, vector<Tuple3>, Comp> pq;
    for (int i = 0; i < nums1.size() && i < k; ++i) {
      pq.push({nums1[i], nums2[0], 0});
    }
    result.resize(k);
    for (int i = 0; i < k; ++i) {
      auto tuple3 = pq.top(); pq.pop();
      result[i] = {tuple3.num1, tuple3.num2};
      if (tuple3.num2_idx + 1 < nums2.size()) {
        pq.push({tuple3.num1, nums2[tuple3.num2_idx + 1],
                   tuple3.num2_idx + 1});
      }
    }
    return result;
  }
};

// Date: 2017-09-08
class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1,
                                        vector<int>& nums2, int k) {
    vector<pair<int, int>> candidates;
    for (int num1 : nums1)
      for (int num2 : nums2)
        candidates.emplace_back(num1, num2);
    if (candidates.size() < k) return candidates;
    nth_element(
        candidates.begin(), candidates.begin() + k, candidates.end(),
        [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.first + lhs.second < rhs.first + rhs.second;
        });
    candidates.resize(k);
    return candidates;
  }
};
