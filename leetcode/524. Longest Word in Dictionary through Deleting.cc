// Copyright 2017 Qi Wang
// Date: 2017-05-03
class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    string result;
    for (const auto& word : d)
      if (Subsequence(word, s) && (word.size() > result.size() ||
          (word.size() == result.size() && word < result)))
        result = word;
    return result;
  }

 private:
  bool Subsequence(const string& word, const string& s) const {
    size_t i = 0;
    for (size_t j = 0; i < word.size() && j < s.size(); ++j)
      if (word[i] == s[j]) ++i;
    return i == word.size();
  }
};
