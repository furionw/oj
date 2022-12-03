// Date: 2022-11-30
class Solution {
 public:
  bool halvesAreAlike(string s) {
    unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (vowels.count(s[i])) {
        if (i < s.size() / 2) {
          ++cnt1;
        } else {
          ++cnt2;
        }
      }
    }
    return cnt1 == cnt2;
  }
};
