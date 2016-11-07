// Copyright 2016 Qi Wang
// Date: 2016-11-01
// Method 2: refer to http://blog.csdn.net/qq508618087/article/details/51359965
// Time: about 3ms
class Solution {
 public:
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

// Date: 2016-11-01
// Method 1
// I think the insert(method 1.1) is more time consuming than +=(method 1.2),
// the former took about 6~9ms, the latter took about 3~6ms
class Solution {
 public:
  string addStrings(string num1, string num2) {
    // error
    if (num1.empty() || num2.empty()) return "";
    // begin
    int carry = 0;
    string res;
    if (num1.size() < num2.size()) swap(num1, num2);
    int i = num1.size() - 1;
    for (int j = num2.size() - 1; j >= 0; --i, --j)
      cal(res, num1[i] + num2[j] - ('0' << 1) + carry, carry);
    for (; i >= 0; --i)
      cal(res, num1[i] - '0' + carry, carry);
    // method 1.1
    // if (carry) res.insert(res.begin(), '1');
    // method 1.2
    if (carry) res += "1";
    reverse(res.begin(), res.end());
    return res;
  }

 private:
  inline void cal(string& res, int sum, int& carry) const {
    // method 1.1
    // res.insert(res.begin(), sum % 10 + '0');
    // method 1.2
    res += (sum % 10 + '0');
    carry = sum >= 10;  // Boost up via not using divide operation
  }
};
