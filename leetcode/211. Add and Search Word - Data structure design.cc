// Copyright 2017 Qi Wang
// Date: 2017-07-20
class WordDictionary {
 public: 
  WordDictionary() {
    memset(children_, 0, sizeof children_);
  }

  ~WordDictionary() {
    // Cannot delete here, or the OJ will throw an error
    // delete[] children_;
  }
  
  void addWord(string word) {
    if (word.empty()) {
      is_word_ = true;
      return;
    }
    int idx = word[0] - 'a';
    if (nullptr == children_[idx])
      children_[idx] = new WordDictionary();
    children_[idx]->addWord(word.substr(1));
  }
    
  bool search(string word) {
    if (word.empty()) return is_word_;
    auto found = [word](WordDictionary* child) {
      return nullptr != child && child->search(word.substr(1));
    };
    return '.' == word[0]
        ? any_of(children_, children_ + 26, found)
        : found(children_[word[0] - 'a']);
  }

 private:
  WordDictionary* children_[26];
  bool is_word_ = false;
};
