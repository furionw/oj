// Copyright 2017 Qi Wang
// Date: 2017-02-21
// Refer to: https://discuss.leetcode.com/topic/79930/java-1-liner
// It's easy to code but runs pretty slow
class Solution {
 public:
  bool detectCapitalUse(string word) {
    return regex_match(word, regex("[a-z]+|[A-Z]+|[A-Z][a-z]+"));
  }
};

// Date: 2017-02-21
class Solution {
 public:
  bool detectCapitalUse(string word) {
    return
        all_of(word.begin(), word.end(), [this](char c) { return upper(c); }) ||
        all_of(word.begin(), word.end(), [this](char c) { return lower(c); }) ||
        (word.size() > 1 && upper(word[0]) && all_of(word.begin() + 1,
            word.end(), [this](char c) { return lower(c); }));
  }

 private:
  bool upper(char c) const { return 'A' <= c && c <= 'Z'; }
  bool lower(char c) const { return 'a' <= c && c <= 'z'; }
};
