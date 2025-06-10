// 2025-06-09
class Solution {
 public:
  int maxDifference(string s) {
    unordered_map<char, int> cnts;
    for (char c : s) {
      ++cnts[c];
    }
    int oddCnt = 0;
    int evenCnt = s.size();
    for (const auto& [c, cnt] : cnts) {
      if (cnt & 1 == 1) {
        oddCnt = max(oddCnt, cnt);
      } else {
        evenCnt = min(evenCnt, cnt);
      }
    }
    return oddCnt - evenCnt;
  }
};
