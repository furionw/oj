// Copyright 2016 Qi Wang
// Date: 2016-12-26
class Solution {
 public:
  string decodeString(string s) {
    string res;
    for (size_t i = 0; i < s.size();) {
      if (digit(s[i])) {
        size_t end = i + 1;
        // 'cause the input is valid, we do not check end < s.size() here
        for (; digit(s[end]); ++end) {}
        int times = stoi(s.substr(i, end - i));
        i = ++end;
        for (int bracketCnt = 1; bracketCnt > 0; ++end)
          if (s[end] == '[') {
            ++bracketCnt;
          } else if (s[end] == ']') {
            --bracketCnt;
          }
        string sub = decodeString(s.substr(i, end - 1 - i));
        for (int k = 0; k < times; ++k) res += sub;
        i = end;
      } else {
        res += s[i++];
      }
    }
    return res;
  }

 private:
  bool digit(char c) const { return '0' <= c && c <= '9'; }
};

// Date: 2016-10-28
class Solution {
 public:
  string decodeString(string str) {
    size_t idx = 0;
    return decodeString(1, str, idx);
  }

 private:
  string decodeString(int times, const string& str, size_t& idx) const {
    string encodeStr;
    for (; str[idx] != ']' && idx < str.size(); ++idx) {
      if (isDigit(str[idx])) {
        size_t digitBegin = idx++;
        for (; isDigit(str[idx]); ++idx) {}
        int t = stoi(str.substr(digitBegin, idx - digitBegin));
        encodeStr += decodeString(t, str, ++idx);
      } else {
        // trivial character. We just append it to the end of the "encodeStr"
        encodeStr += str[idx];
      }
    }
    string res;
    while (times--) res += encodeStr;
    return res;
  }

  inline bool isDigit(char c) const { return '0' <= c && c <= '9'; }
};
