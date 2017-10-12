// Copyright 2017 Qi Wang
// Date: 2017-10-11
class Solution {
 public:
  string addBinary(string &a, string &b) {
    if (a.empty() || b.empty()) return !a.empty() ? a : b;
    string result;
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    for (; i >= 0 && j >= 0; --i, --j) {
      int sum = a[i] + b[j] - '0' * 2 + carry;
      result += '0' + sum % 2;
      carry = sum / 2;
    }
    AddBinary(i != -1 ? a.substr(0, i + 1) : b.substr(0, j + 1), carry,
              &result);
    reverse(result.begin(), result.end());
    return result;
  }
 
 private:
  void AddBinary(const string& str, int carry, string* result) const {
    if (carry == 0) {
      result->resize(result->size() + str.size());
      copy(str.rbegin(), str.rend(),
           result->begin() + result->size() - str.size());
      return;
    }
    if (str.empty()) {
      result->push_back('1');
      return;
    }
    for (int i = str.size() - 1; i >= 0; --i) {
      int sum = str[i] - '0' + carry;
      result->push_back('0' + sum % 2);
      carry = sum / 2;
    }
    if (carry == 1) result->push_back('1');
  }
};
