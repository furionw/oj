// Copyright 2016 Qi Wang
// Date: 2016-12-05
class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    string cToStr[26];
    map<string, char> strToC;
    size_t pIdx = 0, sIdx = 0;
    for (; pIdx < pattern.size() && sIdx < str.size(); ++pIdx) {
      char c = pattern[pIdx];
      size_t begin = sIdx;
      for (; sIdx < str.size() && str[sIdx] != ' '; ++sIdx) {}
      string cur = str.substr(begin, sIdx - begin);
      sIdx += sIdx < str.size();
      if (cToStr[c - 'a'].empty()) {
        cToStr[c - 'a'] = cur;
      } else if (cToStr[c - 'a'] != cur) {
        return false;
      }
      auto it = strToC.find(cur);
      if (it == strToC.end()) {
        strToC[cur] = c;
      } else if (it->second != c) {
        return false;
      }
    }
    return pIdx == pattern.size() && sIdx == str.size();
  }
};
