// Copyright 2017 Qi Wang
// Date: 2017-09-16
// Case 1: "()()" => true
// Case 2: "(*)" => true
// Case 3: "*)" => false
// Case 4: "(*" => true
// Case 5: ")()*" => false
// Case 6: "()*(" => false
class Solution {
 public:
  bool checkValidString(string s) {
    list<char> l;
    for (auto c : s) {
      if (c == '(' || c == '*') {
        l.push_back(c);
      } else {
        if (l.empty()) {
          return false;
        } else {
          auto itr = l.end();
          for (auto itr2 = l.begin(); itr2 != l.end(); ++itr2) {
            if (*itr2 == '(') {
              itr = itr2;
            }
          }
          if (itr == l.end()) {
            l.pop_back();
          } else {
            l.erase(itr);
          }
        }
      }
    }
    while (!l.empty() && l.front() == '*')
      l.pop_front();
    int acc = 0;
    for (auto c : l) {
      if (c == '(') {
        ++acc;
      } else if (c == '*' && acc > 0) {
        --acc;
      }
    }
    return acc == 0;
  }
};