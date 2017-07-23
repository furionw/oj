// Copyright 2017 Qi Wang
// Date: 2017-07-22
class Trie {
 public:
  Trie() {
    memset(children_, 0, sizeof children_);
  }

  void Insert(const string& str, size_t idx) {
    if (idx == str.size()) {
      is_root_ =  true;
    } else {
      size_t offset = str[idx] - 'a';
      if (children_[offset] == nullptr)
        children_[offset] = new Trie();
      children_[offset]->Insert(str, idx + 1);
    }
  }

  bool FindRoot(const string& str, size_t idx, string* result) const {
    if (is_root_) return true;
    if (idx == str.size()) return false;
    size_t offset = str[idx] - 'a';
    if (children_[offset] == nullptr) {
      return false;
    } else {
      result->push_back(str[idx]);
      return children_[offset]->FindRoot(str, idx + 1, result);
    }
  }

  Trie* children_[26];
  bool is_root_ = false;
};

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    Trie trie;
    // ctor tree
    for (const string& root : dict) {
      trie.Insert(root, 0);
      if (root == "") return "";
    }
    // map
    map<string, string> word_map;
    for (size_t i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ') continue;
      size_t pos = sentence.find(' ', i);
      string word = sentence.substr(i, pos - i);
      if (word_map.find(word) != word_map.end()) continue;
      string result;
      if (trie.FindRoot(word, 0, &result)) {
        word_map[word] = result;
      } else {
        word_map[word] = word;
      }
      if (pos == string::npos) break;
      i = pos;
    }
    string result;
    for (size_t i = 0; i < sentence.size(); ++i) {
      if (sentence[i] == ' ') continue;
      size_t pos = sentence.find(' ', i);
      string word = sentence.substr(i, pos - i);
      i = pos;
      if (!result.empty()) result += " ";
      result += word_map[word];
      if (pos == string::npos) break;
    }
    return result;
  }
};
