// Copyright 2016 Qi Wang
// Date: 2016-12-31
// Inspired by http://bookshadow.com/weblog/2016/11/13/leetcode-repeated-substring-pattern/
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    if (str.empty()) return false;  // ill input
    vector<int> prefix(str.size(), 0);
    for (size_t i = 1, q; i < str.size(); ++i) {
      for (q = prefix[i - 1]; q > 0 && str[q] != str[i]; q = prefix[q - 1]) {}
      prefix[i] = str[i] == str[q] ? q + 1 : 0;
    }
    int p = prefix.back();
    // Now I could prove that this condition iff(equal to) the return value
    // 2016-12-31
    return p > 0 && str.size() % (str.size() - p) == 0;
  }
};

// Date: 2016-11-13
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    if (str.size() <= 1) return false;
    for (size_t len = 1; len <= str.size() / 2; ++len)
      if (pred(str, str.substr(0, len)))
        return true;
    return false;
  }
 
 private:
  bool pred(const string& str, const string& p) {
    for (size_t i = p.size(); i < str.size(); i += p.size())
      if (str.substr(i, p.size()) != p)
        return false;
    return true;
  }
};
