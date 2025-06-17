// 2025-06-16
// Method 2: Trie
class Trie {
 public:
  void insert(const string& str, int idx) {
    if (idx == str.size()) {
      isWord_ = true;
      return;
    }
    auto& child = children_[str[idx] - 'a'];
    if (child == nullptr) {
      child = make_shared<Trie>();
    }
    child->insert(str, ++idx);
  }

  vector<string> top(string& prefix, int& k) {
    vector<string> result;
    top(result, prefix, k);
    return result;
  }

  std::shared_ptr<Trie> find(char c) {
    return children_[c - 'a'];
  }

 private:
  void top(vector<string>& result, string& prefix, int& k) {
    if (k == 0) {
      return;
    }
    if (isWord_) {
      --k;
      result.push_back(prefix);
    }
    for (int i = 0; i < 26 && k > 0; ++i) {
      if (children_[i] != nullptr) {
        prefix += 'a' + i;
        children_[i]->top(result, prefix, k);
        prefix.pop_back();
      }
    }
  }

  bool isWord_ = false;
  shared_ptr<Trie> children_[26];
};

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> result;
    shared_ptr<Trie> trie = make_shared<Trie>();
    for (const auto& p : products) {
      trie->insert(p, 0 /*idx*/);
    }
    string prefix = "";
    for (char c : searchWord) {
      prefix += c;
      if (trie != nullptr) {
        trie = trie->find(c);
      }
      int k = 3;
      result.push_back(trie != nullptr
          ? trie->top(prefix, k)
          : vector<string>{});
    }
    return result;
  }
};

// Method 1: std::set
class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> result;
    sort(products.begin(), products.end());
    string substr = "";
    for (char c : searchWord) {
      substr += c;
      auto it = lower_bound(products.begin(), products.end(), substr);
      vector<string> cur;
      for (; it != products.end()
          && it->substr(0, substr.size()) == substr
          && cur.size() < 3; ++it) {
        cur.push_back(*it);
      }
      result.push_back(std::move(cur));
    }
    return result;
  }
};
