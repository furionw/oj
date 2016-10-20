// Copyright 2016 Stephen Wong
// KMP
// Date: 2016-09-24
// Correctness: CLRS 32.4, not read yet
// Complexity: O(n+m) time, proved in CLRS 32.4, not read yet
class Solution {
 public:
  int strStr(string s, string p) {
    if (p.empty()) return 0;
    auto pi = computePrefixFunction(p);
    for (size_t i = 0, q = 0; i < s.size(); ++i) {
      if (s[i] == p[q]) {
        if (++q == p.size()) return i - q + 1;
      } else {
        while (q != 0 && s[i] != p[q]) q = pi[q - 1];
        q = s[i] == p[q]? q + 1: 0;
      }
    }
    return -1;
  }

 private:
  vector<int> computePrefixFunction(const string& p) {
    vector<int> pi(p.size(), 0);
    for (size_t i = 1, q; i < p.size(); ++i) {
      for (q = pi[i - 1]; q > 0 && p[q] != p[i]; q = pi[q - 1]) {}
      pi[i] = p[q] == p[i]? q + 1: 0;
    }
    return pi;
  }
};
