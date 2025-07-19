// 2025-07-18
// Method 1
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (abs(m - n) > 1) {
      return false;
    }
    bool edited = false;
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      } else if (edited) {
        return false;
      } else {
        edited = true;
        if (m < n) {
          ++j;
        } else if (m > n) {
          ++i;
        } else {
          ++i;
          ++j;
        }
      }
    }
    // readed end (false) ^ edited (true) = true
    // not reached (true) ^ unedited (false) = true
    return (i != m || j != n) ^ edited;
  }
};


// 2025-07-18
// Method 2: refer to the previous method
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() > t.size()) {
      swap(s, t);
    }
    // s.size() < t.size()
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != t[i]) {
        return s.size() == t.size()
            // change and move on
            ? s.substr(i + 1) == t.substr(i + 1)
            // delete `t[i]` (aka insert into s)
            : s.substr(i) == t.substr(i + 1);
      }
    }
    return t.size() - s.size() == 1;
  }
};



// Date: 2017-11-06
// Case 1: "ab", "ab" -> false
// Case 2: "abc", "bbc" -> true
// Case 3: "abb", "ab" -> true
// Please note that the solution on 2017-07-18 is more concise.
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() == t.size()) {
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
          return s.substr(i + 1) == t.substr(i + 1);
        }
      }
      return false;
    } else {
      if (s.size() > t.size()) swap(s, t);
      if (s.size() + 1 != t.size()) return false;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
          return s.substr(i) == t.substr(i + 1);
        }
      }
      return true;
    }
  }
};

// Date: 2017-07-18
// Method 2
// Refer to one of the leetcode solution.
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() < t.size()) s.swap(t);
    if (s.size() - t.size() > 1) return 0;
    for (int i = 0; i < t.size(); i++) {
      // The reference use "!s.compare(_1, _2, _3, _4, _5)" in the tenary op,
      // but I think I can use s.substr() for the better readability.
      if (s[i] != t[i])
        return s.size() == t.size()
            ? s.substr(i + 1) == t.substr(i + 1)
            : s.substr(i + 1) == t.substr(i);
    }
    return s.size() == t.size() + 1;
  }
};

// Date: 2017-07-18
// Method 1
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() > t.size()) swap(s, t);
    if (t.size() - s.size() > 1) return false;
    int diff_cnt = 0;
    if (s.size() == t.size()) {
      for (size_t i = 0; i < s.size(); ++i) {
        diff_cnt += s[i] != t[i];
      }
      return 1 == diff_cnt;
    } else {
      for (size_t i = 0; i < s.size();) {
        if (s[i] != t[i + diff_cnt]) {
          if (diff_cnt) {
            return false;
          } else {
            ++diff_cnt;
          }
        } else {
          ++i;
        }
      }
      return diff_cnt <= 1;
    }
  }
};
