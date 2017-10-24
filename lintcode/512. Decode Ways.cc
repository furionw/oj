// Copyright 2017 Qi Wang
// Date: 2017-10-23
class Solution {
 public:
  int numDecodings(string &s) {
    if (s.empty() || s[0] == '0') return 0;
    int a1 = 1, a2 = 1;
    for (int i = 1; i < s.size(); ++i) {
      int two_digits = stoi(s.substr(i - 1, 2));
      if (s[i] == '0') {
        if (s[i - 1] == '1' || s[i - 1] == '2') {
          swap(a1, a2);
        } else {
          return 0;
        }
      } else if (11 <= two_digits && two_digits <= 26) {
        int new_a2 = a1 + a2;
        a1 = a2;
        a2 = new_a2;
      } else {
        a1 = a2;
      }
    }
    return a2;
  }
};
