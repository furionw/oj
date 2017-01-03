// Copyright 2017 Qi Wang
// Date: 2016-11-07
// Last modified: 2017-01-03
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> bits(words.size(), 0);
    for (size_t i = 0; i < words.size(); ++i)
      for (char c : words[i])
        bits[i] |= 1 << (c - 'a');
    int res = 0;
    for (size_t i = 0; i < words.size(); ++i)
      for (size_t j = 0; j < words.size(); ++j)
        // Note that &'s precedence is lower than ==, so the parentheses are
        // necessary here !!!
        if ((bits[i] & bits[j]) == 0)
          res = max(res, static_cast<int>(words[i].size() * words[j].size()));
    return res;
  }
};
