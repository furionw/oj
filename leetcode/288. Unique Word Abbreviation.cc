// Copyright 2016 Qi Wang
// Difficulty: Easy
// Date: 2016-12-21
class ValidWordAbbr {
 public:
  ValidWordAbbr(vector<string> &dictionary)
      : dictionary_(dictionary.begin(), dictionary.end()) {
    for (string& word : dictionary)
      ++cnts_[abbr(word)];
  }

  bool isUnique(string word) {
    if (word.size() <= 2) return true;
    return dictionary_.count(word)
        ? cnts_[abbr(word)] == 1  // exists
        : cnts_[abbr(word)] == 0;  // non-exists word
  }
 
 private:
  string abbr(const string& str) const {
    return str.size() <= 2 ? str
          : str.substr(0, 1) + to_string(str.size() - 2) + str.back();
  }
  unordered_set<string> dictionary_;
  unordered_map<string, int> cnts_;
};
