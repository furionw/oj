// 2025-05-01
class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    size_t n = nums.size();
    vector<int> d(n + 1, 0); // deltas
    for (const auto& q: queries) {
      ++d[q[0]];
      --d[q[1] + 1];
    }
    int delta = 0;
    for (size_t i = 0; i < n; ++i) {
      delta += d[i];
      if (nums[i] - delta > 0) {
        return false;
      }
    }
    return true;
  }
};
