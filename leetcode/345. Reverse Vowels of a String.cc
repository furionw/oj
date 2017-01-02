// Copyright 2017 Qi Wang
// Date: 2017-01-02
class Solution {
 public:
  string reverseVowels(string s) {
    if (s.size() <= 1) return s;
    for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
      for (; i <= j && !count(VOWELS, VOWELS + 10, s[i]); ++i) {}
      for (; i <= j && !count(VOWELS, VOWELS + 10, s[j]); --j) {}
      if (i < j) swap(s[i], s[j]);
    }
    return s;
  }

 static constexpr char* VOWELS = "aeiouAEIOU";
};

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
