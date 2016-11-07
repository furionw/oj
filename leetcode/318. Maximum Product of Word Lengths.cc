// Copyright 2016 Qi Wang
// Date: 2016-11-07
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int bits[words.size()];
    memset(bits, 0, sizeof bits);
    for (size_t i = 0; i < words.size(); ++i)
      for (char c : words[i])
        bits[i] |= 1 << (c - 'a');
    size_t res = 0;
    for (size_t i = 0; i < words.size(); ++i)
      for (size_t j = 0; j < words.size(); ++j)
        // Note that &'s precedence is lower than ==, so the parentheses are
        // necessary here !!!
        if ((bits[i] & bits[j]) == 0)
          res = max(res, words[i].size() * words[j].size());
    return static_cast<int>(res);
  }
};
