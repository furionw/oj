// 2025-05-01
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> cnts;
    for (int num : arr) {
      ++cnts[num];
    }
    unordered_set<int> occurrences;
    for (auto [_, cnt]: cnts) {
      if (occurrences.contains(cnt)) {
        return false;
      }
      occurrences.insert(cnt);
    }
    return true;
  }
};
