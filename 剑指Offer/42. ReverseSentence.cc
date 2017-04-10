// Copyright 2017 Qi Wang
// Date: 2017-04-10
class Solution {
 public:
  string ReverseSentence(string str) {
    if (str.empty()) return "";
    Reverse(str, 0, str.size() - 1);
    for (size_t begin = str.find_first_not_of(' '); begin < str.size();) {
      size_t end = str.find_first_of(' ', begin);
      if (end == string::npos) end = str.size();
      Reverse(str, begin, end - 1);
      begin = str.find_first_not_of(' ', end);
    }
    return str;
  }

 private:
  void Reverse(string& str, size_t begin, size_t end) const {
    while (begin < end) swap(str[begin++], str[end--]);
  }
};

// Date: 2107-04-10
// Refer to the ReverseSentence solution on 2017-04-10
class Solution {
 public:
  string LeftRotateString(string str, int n) {
    if (str.empty() || n <= 0 || n % str.size() == 0) return str;
    n %= str.size();
    Reverse(str, 0, n - 1);
    Reverse(str, n, str.size() - 1);
    Reverse(str, 0, str.size() - 1);
    return str;
  }

 private:
  // Using the identical Reverse() presented on 2017-04-10 ReverseSentence
  void Reverse(string& str, size_t begin, size_t end) const {
    while (begin < end) swap(str[begin++], str[end--]);
  }
};

// Date: 2017-04-07
// Method 1
class Solution {
 public:
  string LeftRotateString(string str, int n) {
    if (str.empty() || n <= 0) return str;
    n %= str.size();
    return str.substr(n) + str.substr(0, n);
  }
};
