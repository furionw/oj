// 2025-06-08
// Refer to: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = needle.size();

    // longest proper suffix
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; ++i) {
      while (needle[i] != needle[len] && len > 0) {
        len = lps[len - 1];
      }
      if (needle[i] == needle[len]) {
        lps[i] = ++len;
      }
    }

    int i = 0, j = 0;
    int m = haystack.size();
    for (; i < m && j < n; ++i) {
      while (haystack[i] != needle[j] && j > 0) {
        j = lps[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
    }

    return j == n ? i - n : -1;
  }
};

// Date: 2017-11-09
class Solution {
 public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
      if (haystack.substr(i, needle.size()) == needle) return i;
    }
    return -1;
  }
};

  // Date: 2017-07-30
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> n(needle.size(), 0);
    for (int i = 1; i < needle.size(); ++i) {
      int len = n[i - 1];
      for (; len != 0 && needle[len] != needle[i]; len = n[len - 1]) {}
      n[i] = needle[len] == needle[i] ? len + 1 : 0;
    }
    for (int i = 0, len = 0; i < haystack.size(); ++i) {
      if (haystack[i] == needle[len]) {
        if (++len == needle.size()) {
          return i - len + 1;
        }
      } else {
        for (; len != 0 && needle[len] != haystack[i]; len = n[len - 1]) {}
        len = needle[len] == haystack[i] ? len + 1 : 0;
      }
    }
    return -1;
  }
};

// Date: 2016-12-31
class Solution {
 public:
  int strStr(string s, string pattern) {
    if (pattern.empty()) return 0;
    auto pi = prefixArray(pattern);
    for (size_t i = 0, q = 0; i < s.size(); ++i) {
      if (s[i] == pattern[q]) {
        if (++q == pattern.size()) return i + 1 - q;
      } else {
        // if (q > 0)
        //   for (q = pi[q - 1]; q > 0 && pattern[q] != s[i]; q = pi[q - 1]) {}
        // imitate the solution on 16-09-24
        while (q != 0 && s[i] != pattern[q]) q = pi[q - 1];
        q = pattern[q] == s[i] ? q + 1 : 0;
      }
    }
    return -1;
  }

 private:
  vector<int> prefixArray(const string& s) const {
    vector<int> pi(s.size(), 0);
    for (size_t i = 1, q; i < s.size(); ++i) {
      for (q = pi[i - 1]; q > 0 && s[q] != s[i]; q = pi[q - 1]) {}
      pi[i] = s[i] == s[q] ? q + 1 : 0;
    }
    return pi;
  }
};

// Date: 2016-12-21
class Solution {
 public:
  int strStr(string s, string p) {
    return s.find(p);
  }
};

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
