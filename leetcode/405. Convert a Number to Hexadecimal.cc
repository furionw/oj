// Copyright 2016 Qi Wang
// Date: 2016-11-17
class Solution {
 public:
  string toHex(int num) {
    int chars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f'};
    string res;
    for (uint32_t i = num; i; i >>= 4)
      res.insert(res.begin(), chars[i & 15]);
    return !res.empty() ? res : "0";
  }
};
