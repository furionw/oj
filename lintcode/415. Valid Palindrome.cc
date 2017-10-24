// Copyright 2017 Qi Wang
// Date: 2017-10-12
// Case 1: ""
// Case 2: "abA"
class Solution {
 public:
  bool isPalindrome(string &s) {
    if (s.empty()) return true;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      FindAlphanumeric(&s, &i, 1);
      FindAlphanumeric(&s, &j, -1);
      if (i < j && s[i] != s[j]) return false;
    }
    return true;
  }
 
 private:
  void FindAlphanumeric(string* s, int* idx, int delta) const {
    for (; 0 <= *idx && *idx < s->size(); *idx += delta) {
      if (('0' <= (*s)[*idx] && (*s)[*idx] <= '9') ||
          ('a' <= (*s)[*idx] && (*s)[*idx] <= 'z')) {
        return;
      } else if ('A' <= (*s)[*idx] && (*s)[*idx] <= 'Z') {
        (*s)[*idx] += 'a' - 'A';
        return;
      }
    }
  }
};
