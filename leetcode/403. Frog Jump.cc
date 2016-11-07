// Copyright 2016 Qi Wang
// Date: 2016-11-06
class Solution {
 public:
  bool canCross(vector<int>& stones) {
    unordered_set<int> jumps[stones.size()];
    jumps[0].insert(1);
    for (size_t i = 0; i < stones.size() - 1; ++i) {
      for (int jump : jumps[i]) {
        size_t idx = find(stones, stones[i] + jump, i + 1, stones.size() - 1);
        if (idx != 0) {
          if (jump > 1) jumps[idx].insert(jump - 1);
          jumps[idx].insert(jump);
          jumps[idx].insert(jump + 1);
        }
      }
    }
    return !jumps[stones.size() - 1].empty();
  }

 private:
  size_t find(const vector<int>& stones, int pos, size_t l, size_t r) {
    while (l <= r) {
      size_t mid = (l + r) >> 1;
      if (stones[mid] < pos) {
        l = mid + 1;
      } else if (stones[mid] > pos) {
        r = mid - 1;
      } else {
        return mid;
      }
    }
    return 0;
  }
};
