// 2025-06-19
class Solution {
 public:
  int minSteps(string s, string t) {
    int cnts1[26] = {0};
    int cnts2[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      ++cnts1[s[i] - 'a'];
      ++cnts2[t[i] - 'a'];
    }
    int result = 0;
    for (int i = 0; i < 26; ++i) {
      result += max(0, cnts2[i] - cnts1[i]);
    }
    return result;
  }
};
