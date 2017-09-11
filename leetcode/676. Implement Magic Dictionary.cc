// Copyright 2017 Qi Wang
// Date: 2017-09-09
class MagicDictionary {
 public:
  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    dict_.clear();
    for (const auto& str : dict) {
      dict_.insert(str);
    }
  }
  
  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    for (const string& dict_word : dict_) {
      if (word.size() != dict_word.size()) continue;
      int diff = 0;
      for (int i = 0; i < word.size() && diff < 2; ++i) {
        diff += (word[i] != dict_word[i]);
      }
      if (diff == 1) return true;
    }
    return false;
  }

 private:
  unordered_set<string> dict_;
};
