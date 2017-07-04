// Copyright 2017 Qi Wang
// Date: 2017-07-02
class Solution {
 public:
  bool isMatch(string s, string p) {
    return IsMatch(s, 0, p, 0);
  }
 
 private:
  bool IsMatch(const string& s, size_t s_idx,
      const string& p, size_t p_idx) const {
    if (s.size() == s_idx) {
      return count(p.begin() + p_idx, p.end(), '*') * 2 == (p.size() - p_idx);
    } else if (p.size() == p_idx) {
      return false;
    } else if (p_idx + 1 < p.size() && '*' == p[p_idx + 1]) {
      return IsMatch(s, s_idx, p, p_idx + 2)
          || (Equal(s[s_idx], p[p_idx]) && IsMatch(s, s_idx + 1, p, p_idx));
    } else {
      return Equal(s[s_idx], p[p_idx]) && IsMatch(s, s_idx + 1, p, p_idx + 1);
    }
  }
 
  bool Equal(char s, char p) const {
    return '.' == p || s == p;
  }
};
 
// Date: 2016-12-19
class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) {
      return s.empty();
    } else if (s.empty()) {
      // we have to consume all p with an empty string s.
      if (p.size() & 1) return false;
      for (size_t i = 1; i < p.size(); i += 2)
        if (p[i] != '*') return false;
      return true;
    }

    if (p.size() > 1 && p[1] == '*') {
      return isMatch(s, p.substr(2))  // do not try to match
          || (isMatch(s[0], p[0]) && isMatch(s.substr(1), p));  // find match
    } else {
      return isMatch(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
    }
  }

 private:
  bool isMatch(char s, char p) const {
    return s == p || p == '.';
  }
};

// Date: 2016-09
class Solution {
 public:
  bool isMatch(string s, string p) {
    // Trivial case
    if (s.empty() && p.empty()) {
      return true;
    } else if (!s.empty() && p.empty()) {
      return false;
    } else if (s.empty() && !p.empty()) {
      // Return false when the # of elems is odd
      if (p.size() % 2 != 0) return false;
      for (size_t i = 0; i < p.size(); ++i)
        // The elements with even 'i' should be '*'
        if (i % 2 == 1 && p[i] != '*') return false;
      return true;
    }

    // Non-trivial case: both s and p are not empty
    if (p.size() == 1) {
      return s.size() == 1 && (p[0] == '.' || s[0] == p[0]);
    // Consider the case when p.size() > 1, where we 
    } else if (p[1] != '*') {
      if (p[0] == '.') {
        return isMatch(s.substr(1), p.substr(1));
      } else {
        return s[0] == p[0] && isMatch(s.substr(1), p.substr(1));
      }
    } else if (p[1] == '*') {
      // 0 element
      if (isMatch(s, p.substr(2))) return true;
      //
      if (p[0] == '.') {
        // 1 or more elements
        return isMatch(s.substr(1), p);
      } else {
        // 1 or more elements        
        return s[0] == p[0] && isMatch(s.substr(1), p);
      }
    }
    return false;  // soft the compiler
  }
};
