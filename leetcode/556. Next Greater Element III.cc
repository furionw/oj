// Copyright 2017 Qi Wang
// Date: 2017-04-21
class Solution {
 public:
  int nextGreaterElement(int n) {
    string str = to_string(n);
    if (next_permutation(str.begin(), str.end())) {
      try {
        return stoi(str);
      } catch(out_of_range e) {
        return -1;
      }
    } else {
      return -1;
    }
  }
};
