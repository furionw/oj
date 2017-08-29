// Copyright 2017 Qi Wang
// Date: 2017-08-27
class Solution {
 public:
  string reverseWords(string s) {
    if (s.empty()) return "";
    int begin = 0;
    for (int end = 0; end < s.size(); ++end) {
      if (s[end] == ' ') {
        Reverse(&s, begin, end - 1);
        begin = end + 1;
      }
    }
    Reverse(&s, begin, s.size() - 1);
    return s;
  }
 
 private:
  void Reverse(string* s, int begin, int end) const {
    while (begin < end) {
      swap((*s)[begin++], (*s)[end--]);
    }
  }
};

// Date: 2017-04-20
class Solution {
 public:
  string reverseWords(string s) {
    size_t i = 0;
    for (size_t i = 0; i < s.size(); ) {
      size_t end = s.find_first_of(' ', i);
      if (string::npos != end) {
        reverse(s.begin() + i, s.begin() + end);
        i = end + 1;
      } else {
        reverse(s.begin() + i, s.end());
        break;
      }
    }
    return s;
  }
};
