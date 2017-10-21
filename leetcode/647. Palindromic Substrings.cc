// Copyright 2017 Qi Wang
// Date: 2017-10-19
// Refer to: https://discuss.leetcode.com/topic/96819/java-solution-8-lines-extendpalindrome
class Solution {
 public:
  int countSubstrings(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      cnt += ExtendPalindrome(s, i, i);
      cnt += ExtendPalindrome(s, i, i + 1);
    }
    return cnt;
  }

 private:
  int ExtendPalindrome(const string& s, int l, int r) const {
    int cnt = 0;
    for (; 0 <= l && r < s.size() && s[l] == s[r]; --l, ++r) {
      ++cnt;
    }
    return cnt;
  }
};

// Date: 2017-07-22
class Solution {
 public:
  int countSubstrings(string s) {
    int result = 0;
    for (int len = 1; len <= s.size(); ++len) {
      for (int pos = 0; pos + len <= s.size(); ++pos) {
        result += IsP(s.substr(pos, len));
      }
    }
    return result;
  }

 private:
  // non empty str
  bool IsP(const string& str) {
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
      if (str[i] != str[j]) {
        return false;
      }
    }
    return true;
  }
};