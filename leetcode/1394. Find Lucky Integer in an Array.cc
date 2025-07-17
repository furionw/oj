// 2025-07-16
class Solution {
 public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> cnts;
    for (int num : arr) {
      ++cnts[num];
    }
    int result = -1;
    for (auto [k, v] : cnts) {
      if (k == v) {
        result = max(result, k);
      }
    }
    return result;
  }
};
