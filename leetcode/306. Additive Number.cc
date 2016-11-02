// Copyright 2016 Qi Wang
// Date: 2016-11-01
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    for (int len1 = 1; len1 <= num.size() / 2; ++len1) {
      // no leading zero
      if (num[0] == '0' && len1 > 1) break;
      // len2 : int, make sure minus OP is valid
      for (int len2 = 1; static_cast<int>(num.size()) - len1 - len2
          >= max(len1, len2); ++len2) {
        // no leading zero
        if (num[len1] == '0' && len2 > 1) break;
        if (isAdditiveNumber(num.substr(0, len1), num.substr(len1, len2),
            num.substr(len1 + len2))) return true;
      }
    }
    return false;
  }

 private:
  bool isAdditiveNumber(const string& pre, const string& cur,
      const string& str) const {
    if (str.empty()) return true;
    auto sum = addStrings(pre, cur);
    return sum == str.substr(0, sum.size())
        ? isAdditiveNumber(cur, sum, str.substr(sum.size()))
        : false;
  }

  // Refer to LeetCode 415. Add Strings
  string addStrings(string num1, string num2) {
    // error
    if (num1.empty() || num2.empty()) return "";
    // begin
    int carry = 0;
    string res;
    int len1 = num1.size(), len2 = num2.size();
    while (len1 || len2) {
      int sum = carry;
      if (len1) sum += num1[--len1] - '0';
      if (len2) sum += num2[--len2] - '0';
      res += (sum % 10 + '0');
      // Boost up via not using divide operation
      carry = sum >= 10;
    }
    if (carry) res += "1";
    reverse(res.begin(), res.end());
    return res;
  }
};
