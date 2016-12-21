// Copyright 2016 Qi Wang
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
