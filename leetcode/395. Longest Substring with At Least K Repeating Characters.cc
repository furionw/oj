// Copyright 2016 Qi Wang
// Date: 2016-12-17
// Here we present a brute force algorithm in order to find the length of the
// longest substring T of a given string s.
// Firstly, a two dimensional array was constructed.
//   - cnts[i + 1] contains 26 counters and each counter represents the number
//     of a specific character in a specific substring.
// Take the cnts[i + 1][0] as an example:
//   - cnts[i +1] contains 26 counters specifying the number of the
//     corresponding 26 lowercase letters in the first i characters of the given string s
//   - cnts[i + 1][0] records the number of character ‘a’ in the substring,
//     which consists of s0, s1, …, si-1
class Solution {
 public:
  int longestSubstring(string s, int k) {
    int cnts[s.size() + 1][26];
    memset(cnts, 0, sizeof cnts);
    int res = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      copy(cnts[i], cnts[i] + 26, cnts[i + 1]);
      // contain lowercase letters only
      ++cnts[i + 1][s[i] - 'a'];
      for (int j = 0; j + k <= i + 1 && (i + 1) - j > res; ++j) {
        bool valid = true;
        // DO NOT use k to iterate from 0 to 25, 'cause k is the parameter!!!
        for (int p = 0; p < 26 && valid; ++p) {
          int diff = cnts[i + 1][p] - cnts[j][p];
          valid = diff == 0 || diff >= k;
        }
        if (valid) res = (i + 1) - j;
      }
    }
    return res;
  }
};
