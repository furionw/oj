// Copyright 2017 Qi Wang
// Date: 2017-09-07
class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    int len = 0;
    for (char& c : S) {
      len += Alphanumerical(&c);
    }
    int cnt = len % K;
    string result;
    for (char c : S) {
      if (cnt == 0) {
        result += '-';
        cnt = K;
      }
      if (c != '-') {
        result += c;
        --cnt;
      }
    }
    // When len % K == 0
    if (result.front() == '-') {
      result = result.substr(1);
    }
    if (result.back() == '-') {
      result.pop_back();
    }
    return result;
  }

 private:
  bool Alphanumerical(char *c) const {
    if ('a' <= *c && *c <= 'z') {
      *c = *c - 'a' + 'A';
    }
    return *c != '-';
  }
};
