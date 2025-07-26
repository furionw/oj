// 2025-07-25
class Solution {
 public:
  string breakPalindrome(string p) {
    if (p.size() == 1) {
      return "";
    }
    // boundary:
    //   4 -> 2
    //   3 -> 2
    //   2 -> 1
    //   1 -> 0
    for (int i = 0; i < p.size() / 2; ++i) {
      p[i] = 'a';
      if (p[i] != p[p.size() - 1 - i]) {
        return p;
      }
    }
    // start:
    //   4 -> 1
    //   3 -> 1
    //   2 -> 0
    for (char c = 'b'; true; ++c) {
      p.back() = c;
      if (p.back() != p.front()) {
        return p;
      }
    }
    return "?";
  }
};
