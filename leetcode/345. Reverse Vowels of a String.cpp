// Copyright 2016 Qi Wang
// Date: 2016-10-08
class Solution {
 public:
  string reverseVowels(string s) {
    vector<size_t> idxs;
    for (size_t i = 0; i < s.size(); ++i)
      if (isVowel(s[i])) idxs.push_back(i);
    for (size_t i = 0; i < idxs.size() / 2; ++i)
      swap(s[idxs[i]], s[idxs[idxs.size() - 1 - i]]);
    return s;
  }

 private:
  inline bool isVowel(char c) const {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};
