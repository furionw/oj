// Copyright [2016] <Stephen Wong>

// Recursion => TLE
// Greedy
//   - cannot be verified yet
//   - time complexity cannot be analyzed yet
// Date: 2016-09-22
class Solution {
 public:
  bool isMatch(string s, string p) {
    size_t m = s.size(), n = p.size();
    int last_s = -1, last_p = -1;
    int i = 0, j = 0;
    while (i < m) {
      if (j < n && (s[i] == p[j] || p[j] == '?')) {
        ++i, ++j;
      } else if (j < n && p[j] == '*') {
        last_s = i;
        last_p = j++;
      } else if (last_p != -1) {
        i = ++last_s;
        j = last_p;
      } else {
        return false;
      }
    }
    return all_of(p.begin() + j, p.end(), [](char c) { return c == '*'; });
  }
};
