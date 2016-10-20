// Copyright 2016 Qi Wang
// Date: 2016-10-03
class Solution {
 public:
  int longestPalindrome(string s) {
    vector<int> cnts(52, 0);
    for (char c : s) {
      if (c >= 'A' && c <= 'Z') {
        ++cnts[c - 'A'];
      } else {
        ++cnts[c - 'a' + 26];
      }
    }
    bool findOdd = false;
    int res = 0;
    for (int cnt : cnts) {
      res += ((cnt >> 1) << 1);
      findOdd = findOdd || (cnt % 2 == 1);  // There is no ||= in C++
    }
    return findOdd? res + 1: res;
  }
};
