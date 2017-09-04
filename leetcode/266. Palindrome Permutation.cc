// Copyright 2017 Qi Wang
// Date: 2017-09-02
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    int cnts[256];
    memset(cnts, 0, sizeof cnts);
    for (char c : s) ++cnts[c];
    int cnt = 0;
    for (int i = 0; i < 256; ++i) {
      cnt += (cnts[i] & 1);
      if (cnt > 1) return false;
    }
    return true;
  }
};

// Difficulty: Easy
// Date: 2016-12-21
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> cnts;
    for (char c : s) ++cnts[c];
    int oddCnt = 0;
    for (auto it = cnts.begin(); it != cnts.end() && oddCnt < 2; ++it)
      oddCnt += it->second & 1;
    return oddCnt < 2;
  }
};
