// Copyright 2017 Qi Wang
// Date: 2017-11-02
// Case 1: "101", "1"
class Solution {
 public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string result;
    int i = 0, j = 0, carry = 0;
    for (; i < a.size() && j < b.size(); ++i, ++j) {
      int sum = a[i] + b[j] - '0' * 2 + carry;
      result += '0' + sum % 2;
      carry = sum / 2;
    }
    if (i != a.size()) result += AddBinary(a, i, &carry);
    if (j != b.size()) result += AddBinary(b, j, &carry);
    if (carry > 0) result += '1';
    reverse(result.begin(), result.end());
    return result;
  }

 private:
  string AddBinary(const string& num, int idx, int* carry) const {
    string result;
    for (; idx < num.size(); ++idx) {
      int sum = num[idx] - '0' + *carry;
      result += '0' + (sum == 1);
      *carry = sum / 2;
    }
    return result;
  }
};

// Date: 2017-08-28
class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.empty() || b.empty()) return a.empty() ? b : a;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool carry = false;
    int i = 0;
    string result;
    for (; i < a.size() && i < b.size(); ++i) {
      int sum = a[i] + b[i] - 2 * '0' + carry;
      result += (sum & 1) + '0';
      carry = sum >> 1;
    }
    if (i == a.size() && i == b.size()) {
      if (carry) result += '1';
    } else if (i < a.size()) {
      F(a, i, carry, &result);
    } else {
      F(b, i, carry, &result);
    }
    reverse(result.begin(), result.end());
    return result;
  }

 private:
  void F(const string& s, int idx, bool carry, string* result) const {
    for (; idx < s.size(); ++idx) {
      int sum = s[idx] - '0' + carry;
      (*result) += (sum & 1) + '0';
      carry = sum >> 1;
    }
    if (carry) (*result) += '1';
  }
};

// Date: 2017-07-04
class Solution {
 public:
  string addBinary(string a, string b) {
    return Reverse(AddBinary(Reverse(a), Reverse(b), 0));
  }
 
 private:
  string AddBinary(string a, string b, int carry) const {
    if (!a.empty() && !b.empty()) {
      int sum = a.front() + b.front() - '0' * 2 + carry;
      return string(1, sum % 2 + '0') +
          AddBinary(a.substr(1), b.substr(1), sum / 2);
    } else {
      return AddBinary(b.empty() ? a : b, carry);
    }
  }
 
  string AddBinary(string a, int carry) const {
    if (a.empty()) {
      return carry != 0 ? "1" : "";
    } else {
      int sum = a.front() - '0' + carry;
      return string(1, sum % 2 + '0') + AddBinary(a.substr(1), sum / 2);
    }
  }
 
  string Reverse(string s) const {
    reverse(s.begin(), s.end());
    return s;
  }
};

// Date: 2017-03-05
class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    for (; i >= 0 && j >= 0; --i, --j) {
      int sum = a[i] - '0' + b[j] - '0' + carry;
      result += (sum & 1) + '0';
      carry = sum >> 1;      
    }
    add(a, i, carry, result);
    add(b, j, carry, result);
    if (carry) result += '1';
    reverse(result.begin(), result.end());
    return result;
  }

 private:
  void add(const string& s, int idx, int& carry, string& result) const {
    for (; idx >= 0; --idx) {
      int sum = s[idx] - '0' + carry;
      result += (sum & 1) + '0';
      carry = sum >> 1;
    }
  }
};

// Date: 2017-03-03
class Solution {
 public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string result;
    size_t i = 0, j = 0;
    static constexpr int offset = '0' << 1;
    for (; i < a.size() && j < b.size(); ++i, ++j) {
      int sum = carry + a[i] + b[j] - offset;
      result += (sum & 1) + '0';
      carry = sum >> 1;
    }
    if (i < a.size()) f(a, i, carry, result);
    if (j < b.size()) f(b, j, carry, result);
    if (carry) result += '1';
    reverse(result.begin(), result.end());
    return result;
  }

 private:
  void f(const string& s, size_t i, int& carry, string& result) const {
    for (; i < s.size(); ++i) {
      int sum = carry + s[i] - '0';
      result += (sum & 1) + '0';
      carry = sum >> 1;
    }
    if (carry) {
      result += '1';
      carry = 0;
    }
  }
};

// Date: 2014-07
class Solution 
{
public:
    string addBinary(string a, string b) 
    {
      int i, j, carry=0;
      string ret;      
      
      for (i=a.size()-1, j=b.size()-1; i>=0 && j>=0; --i, --j)
      {
        ret.insert(ret.begin(), '0'+(a[i]+b[j]+carry-'0'-'0')%2);
        carry = (a[i]+b[j]+carry-'0'-'0') / 2;
      }
      for ( ; i >= 0; -- i)
      {
      ret.insert(ret.begin(), '0'+(a[i]+carry-'0')%2);
        carry = (a[i]+carry-'0') / 2;
      }
      for ( ; j >= 0; -- j)
      {
        ret.insert(ret.begin(), '0'+(b[j]+carry-'0')%2);
        carry = (b[j]+carry-'0') / 2;
      }
      ret.insert(0, carry!=0? "1": "");

      return ret;
    }
};
