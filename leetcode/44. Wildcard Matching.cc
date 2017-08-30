// Copyright 2017 Qi Wang
// Date: 2017-08-29
class Solution {
 public:
  bool isMatch(string s, string p) {
    int last_s = -1, last_p = -1;
    int i = 0, j = 0;
    while (i < s.size()) {
      if (p[j] == '*') {
        last_s = i;
        last_p = j++;
      } else if (IsMatch(s[i], p[j])) {
        ++i;
        ++j;
      } else if (last_p == -1) {
        return false;
      } else {
        j = last_p;
        i = ++last_s;
      }
    }
    return all_of(p.begin() + j, p.end(), [](char c) {
      return c == '*';
    });
  }
 
 private:
  bool IsMatch(char s, char p) const {
    return p == '?' || s == p;
  }
};

// Date: 2017-07-29
// Refer to the solution on 2016-09-22
class Solution {
 public:
  bool isMatch(string s, string p) {
    int last_i = -1, last_j = - 1;
    int i = 0, j = 0;
    while (i < s.size()) {
      if (j < p.size() && p[j] == '*') {
        last_i = i;
        last_j = j++;
      } else if (j < p.size() && (p[j] == '?' || s[i] == p[j])) {
        ++i;
        ++j;
      } else if (last_j != -1) {
        i = ++last_i;
        j = last_j + 1;  // differ from the solution on 2016-09-22
      } else {
        return false;
      }
    }
    return all_of(p.begin() + j, p.end(), [](char c) { return c == '*'; });
  }
};

// Method 1
// TLE
// Date: 2017-07-27
class Solution {
 public:
  bool isMatch(string s, string p) {
    return IsMatch(s.data(), p.data());
  }

 private:
  bool IsMatch(const char* s, const char* p) const {
    if (*p == 0) {
      return *s == 0;
    } else if (*s == 0) {
      while (*p != 0) {
        if (*(p++) != '*') {
          return false;
        }
      }
      return true;
    } if (*p == '*') {
      return IsMatch(s + 1, p) || IsMatch(s, p + 1);
    } else if (*p == '?') {
      return IsMatch(s + 1, p + 1);
    } else {
      return s[0] == p[0] && IsMatch(s + 1, p + 1);
    }
  }
};

// Recursion => TLE
// Greedy
//   - cannot be verified yet
//   - time complexity cannot be analyzed yet
// Date: 2016-09-22
class Solution {
 public:
  bool isMatch(string s, string p) {
    size_t m = s.size(), n = p.size();
    int last_s = -1, last_p = -1;
    int i = 0, j = 0;
    while (i < m) {
      if (j < n && (s[i] == p[j] || p[j] == '?')) {
        ++i, ++j;
      } else if (j < n && p[j] == '*') {
        last_s = i;
        last_p = j++;
      } else if (last_p != -1) {
        i = ++last_s;
        j = last_p;
      } else {
        return false;
      }
    }
    return all_of(p.begin() + j, p.end(), [](char c) { return c == '*'; });
  }
};
