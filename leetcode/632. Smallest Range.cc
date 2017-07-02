// Copyright 2017 Qi Wang
// Date: 2017-07-01
struct Node {
  Node() {}
  Node(int val, int nums_idx, int next)
      : val(val), nums_idx(nums_idx), next(next) {}
  int val;
  int nums_idx;
  int next;
  bool operator <(const Node& other) const {
    return val > other.val;
  }
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<Node> pq;
    int start = INT_MAX, maxx = INT_MIN;
    for (size_t i = 0; i < nums.size(); ++i) {
      pq.emplace(nums[i].front(), i, 1);
      maxx = max(maxx, nums[i].front());
    }
    int range = INT_MAX;
    while (true) {
      auto node = pq.top(); pq.pop();
      if (range > maxx - node.val) {
        range = maxx - node.val;
        start = node.val;
      } else if (range == maxx - node.val && node.val < start) {
        start = node.val;
      }
      if (node.next < nums[node.nums_idx].size()) {
        pq.emplace(nums[node.nums_idx][node.next], node.nums_idx, node.next + 1);
        maxx = max(maxx, nums[node.nums_idx][node.next]);
      } else {
        break;
      }
    }
    return {start, start + range};
  }
};
