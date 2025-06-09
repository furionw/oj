// 2025-06-08
class Solution {
 public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<unordered_set<int>> jumps(n, unordered_set<int>{});
    jumps[0].insert(1);
    for (int i = 0; i < n; ++i) {
      for (int k : jumps[i]) {
        int next = stones[i] + k;
        auto it = lower_bound(stones.begin() + i + 1, stones.end(), next);
        if (it == stones.end() || *it != next) {
          continue;
        }
        int idx = it - stones.begin();
        if (idx == n - 1) {
          return true;
        }
        jumps[idx].insert(max(1, k - 1));
        jumps[idx].insert(k);
        jumps[idx].insert(k + 1);
      }
    }
    return false;
  }
};

// Date: 2016-11-07
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
