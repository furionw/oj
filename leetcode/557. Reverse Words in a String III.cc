// Copyright 2017 Qi Wang
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
