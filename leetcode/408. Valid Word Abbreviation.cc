// 2025-05-27
class Solution {
 public:
  bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    int m = word.size(), n = abbr.size();
    while (i < m && j < n) {
      if (isLetter(abbr[j])) {
        if (word[i] != abbr[j]) {
          return false;
        }
        ++i;
        ++j;
        continue;
      }
      if (abbr[j] == '0') {
        return false;
      }
      int len = abbr[j] - '0';
      for (++j; j < n && !isLetter(abbr[j]); ++j) {
        len = 10 * len + abbr[j] - '0';
      }
      if (len == 0) {
        return false;
      }
      i += len;
    }
    return i == m && j == n;
  }

 private:
  bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
  }
};

// 2016-12-25
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
