// Copyright 2017 Qi Wang
// Date: 2017-08-26
// Case 1: "abc def" -> "fed cba"
class Solution {
 public:
  void reverseWords(string &s) {
    if (s.empty()) return;
    reverse(s.begin(), s.end());
    int begin = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if (begin == i) {
          ++begin;
        } else {
          Reverse(s, begin, i - 1);
          begin = i + 1;
        }
      }
    }
    // Don't forget this
    if (begin != s.size()) Reverse(s, begin, s.size() - 1);
  }
 
 private:
  void Reverse(string& str, int begin, int end) const {
    while (begin < end) {
      swap(str[begin++], str[end--]);
    }
  }
};
