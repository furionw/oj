// Copyright 2017 Qi Wang
// Date: 2017-01-01
// Refer to: https://discuss.leetcode.com/topic/41711/8-lines-c-o-n-8ms
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int cnts[256], begin = -1, distinct = 0, maxLen = 0;
    memset(cnts, 0, sizeof cnts);
    for (int i = 0; i < s.size(); ++i) {
      distinct += cnts[s[i]]++ == 0;
      while (distinct > k)
        distinct -= --cnts[s[++begin]] == 0;
      maxLen = max(maxLen, i - begin);
    }
    return maxLen;
  }
};
