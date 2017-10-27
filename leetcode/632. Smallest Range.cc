// Copyright 2017 Qi Wang
// Date: 2017-10-26
class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    if (nums.empty()) return {INT_MIN, INT_MIN};
    priority_queue<Elem, vector<Elem>, comp> pq;
    int max_elem = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i].empty()) {
        return {INT_MIN, INT_MIN};
      }
      pq.emplace(nums[i][0], i, 0);
      max_elem = max(max_elem, nums[i][0]);
    }
    vector<int> result {pq.top().val, max_elem};
    while (true) {
      auto top = pq.top(); pq.pop();
      if (top.idx + 1 < nums[top.row].size()) {
        int val = nums[top.row][top.idx + 1];
        pq.emplace(val, top.row, top.idx + 1);
        max_elem = max(max_elem, val);
        if (max_elem - pq.top().val < result[1] - result[0]) {
          result = {pq.top().val, max_elem};
        }
      } else {
        break;
      }
    }
    return result;
  }
 
 private:
  struct Elem {
    Elem() {}
    Elem(int v, int r, int i) : val(v), row(r), idx(i) {}
    int val, row, idx;
  };
 
  struct comp {
    bool operator()(const Elem& lhs, const Elem& rhs) const {
      return lhs.val > rhs.val;
    }
  };
};

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
