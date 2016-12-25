// Copyright 2016 Qi Wang
// Date: 2016-12-25
class Solution {
 public:
  bool validWordAbbreviation(string word, string abbr) {
    size_t wIdx = 0, aIdx = 0;
    while (wIdx < word.size() && aIdx < abbr.size()) {
      if (isDigit(abbr[aIdx])) {
        if (abbr[aIdx] == '0') return false;
        size_t next = aIdx + 1;
        for (; next < abbr.size() && isDigit(abbr[next]); ++next) {}
        wIdx += stoi(abbr.substr(aIdx, next - aIdx));
        aIdx = next;
      } else {
        if (word[wIdx++] != abbr[aIdx++]) return false;
      }
    }
    return wIdx == word.size() && aIdx == abbr.size();
  }

 private:
  bool isDigit(char c) const { return '0' <= c && c <= '9'; }
};
