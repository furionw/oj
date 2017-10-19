// Copyright 2017 Qi Wang
// Date: 2017-10-18
class Solution {
 public:
  bool validPalindrome(string s) {
    if (s.size() <= 2) return;
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] == s[r]) {
        ++l, --r;
      } else {
        return ValidPalindrome(s, l + 1, r) || ValidPalindrome(s, l, r - 1);
      }
    }
    return true;
  }

 private:
  bool ValidPalindrome(const string& s, int l, int r) const {
    for (; l < r; ++l, --r) {
      if (s[l] != s[r]) return false;
    }
    return true;
  }
};

// Date: 2017-09-16
class Solution {
 public:
  bool validPalindrome(string s) {
    if (s.size() <= 2) return true;
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
      if (s[l] != s[r]) {
        return P(s, l, r - 1) || P(s, l + 1, r);
      }
    }
    return true;
  }

  bool P(const string& s, int l, int r) const {
    if (l >= r) return true;
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
};
