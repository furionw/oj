// Copyright 2017 Qi Wang
// Date: 2017-10-05
class Trie {
 public:
  void insert(string &word) {
    if (!word.empty()) root_.Insert(word, 0);
  }
 
  bool search(string &word) {
    return word.empty() ? true : root_.Search(word, 0);
  }
 
  bool startsWith(string &prefix) {
    return root_.StartsWith(prefix, 0);  
  }
 
 private:
  struct TrieNode {
    TrieNode() {
     memset(children, 0, sizeof children);
    }
 
    ~TrieNode() {
      for (int i = 0; i < 26; ++i) {
        delete children[i];
      }
    }
 
    bool Search(const string& word, size_t idx) const {
      int offset = word[idx] - 'a';
      return children[offset] != nullptr &&
             (idx == word.size() - 1 ? children[offset]->is_word
                                     : children[offset]->Search(word, idx + 1));
    }
 
    bool StartsWith(const string& prefix, size_t idx) const {
      if (idx == prefix.size()) return true;
      int offset = prefix[idx] - 'a';
      return children[offset] != nullptr &&
             children[offset]->StartsWith(prefix, idx + 1);
    }
 
    void Insert(const string& word, size_t idx) {
      int offset = word[idx] - 'a';
      if (children[offset] == nullptr) children[offset] = new TrieNode();
      if (idx == word.size() - 1) {
        children[offset]->is_word = true;
      } else {
        children[offset]->Insert(word, idx + 1);
      }
    }
 
    TrieNode* children[26];
    bool is_word = false;
  };
 
  TrieNode root_;
};
