// 2025-06-24
class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    unordered_map<int, int> cnts;
    cnts[0] = 1;
    int maxK = 0;
    for (int num : nums) {
      unordered_map<int, int> newCnts;
      for (auto [k, v] : cnts) {
        newCnts[k | num] += v;
      }
      for (auto [k, v] : cnts) {
        newCnts[k] += v;
      }
      cnts = move(newCnts);
    }
    for (auto [k, _] : cnts) {
      maxK = max(maxK, k);
    }
    return cnts[maxK];
  }
};
