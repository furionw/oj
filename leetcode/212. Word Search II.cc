// 2025-06-06
class Trie {
 public:
  void insert(const string& str, size_t idx) {
    if (str.size() == idx) {
      isWord = true;
      return;
    }
    children_[str[idx]].insert(str, idx + 1);
  }

  void erase(char c) {
    children_.erase(c);
  }

  bool hasChild(char c) const {
    return children_.find(c) != children_.end();
  }

  Trie& child(char c) {
    auto it = children_.find(c);
    assert(it != children_.end());
    return it->second;
  }

  bool empty() const {
    return !isWord && children_.empty();
  }

  bool isWord = false;

 private:
  unordered_map<char, Trie> children_;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    m_ = board.size();
    n_ = board[0].size();
    Trie trie;
    for (const auto& w : words) {
      trie.insert(w, 0 /*idx*/);
    }
    string str;
    for (int i = 0; i < m_ && !trie.empty(); ++i) {
      for (int j = 0; j < n_ && !trie.empty(); ++j) {
        if (trie.hasChild(board[i][j])) {
          findWords(board, trie.child(board[i][j]), i, j, str);
        }
      }
    }
    return result_;
  }

 private:
  // Assumptions
  //   - x, y are valid
  //   - board[x][y] is not visited before
  void findWords(vector<vector<char>>& board, Trie& trie,
      int x, int y, string& str) {
    char c = board[x][y];
    board[x][y] = -1;
    str += c;
    if (trie.isWord) {
      result_.push_back(str);
      trie.isWord = false;
    }
    vector<int> d {0, 1, 0, -1, 0};
    for (int k = 0; k < 4 && !trie.empty(); ++k) {
      int i = x + d[k];
      int j = y + d[k + 1];
      if (i < 0 || i >= m_ || j < 0 || j >= n_ || board[i][j] == -1
          || !trie.hasChild(board[i][j])) {
        continue;
      }
      auto& child = trie.child(board[i][j]);
      findWords(board, child, i, j, str);
      if (child.empty()) {
        trie.erase(board[i][j]);
      }
    }
    str.pop_back();
    board[x][y] = c;
  }

  int m_;
  int n_;
  vector<string> result_;
};

// Copyright 2017 Qi Wang
// Date: 2017-01-03
// Thie trie is implemented on LC 208. Implement Trie (Prefix Tree)
class Trie {
 private:
  // Define nested class
  struct TrieNode {
    TrieNode() {
      memset(children_, 0, sizeof children_);
    }
    TrieNode* children_[26];
    bool word_ = false;
  };

 public:
  void insert(string word) {
    auto cur = root;
    for (char c : word) {
      if (cur->children_[c - 'a']) {
        cur = cur->children_[c - 'a'];
      } else {
        cur = cur->children_[c - 'a'] = new TrieNode;
      }
    }
    cur->word_ = true;
  }

  bool search(string word) const {
    auto node = find(word);
    return node != nullptr && node->word_;
  }

  bool startsWith(string prefix) const { return find(prefix) != nullptr; }

 private:
  TrieNode* find(const string& str) const {
    auto cur = root;
    for (char c : str) {
      if (cur->children_[c - 'a']) {
        cur = cur->children_[c - 'a'];
      } else {
        return nullptr;
      }
    }
    return cur;
  }

  TrieNode* root = new TrieNode;
};

class Solution {
 public: 
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || board[0].empty()) return vector<string>();
    Trie trie;
    for (auto& word : words)
      trie.insert(word);
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> vi(m, vector<bool>(n, false));
    unordered_set<string> res;
    string word;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (trie.startsWith(string(1, board[i][j])))
          findWords(board, i, j, word, vi, trie, res);
    return vector<string>(res.begin(), res.end());
  }

 private:
  void findWords(vector<vector<char>>& board, int i, int j, string& word,
      vector<vector<bool>>& vi, const Trie& trie, unordered_set<string>& res)
      const {
    word += board[i][j];
    vi[i][j] = true;
    if (trie.search(word)) res.insert(word);
    static constexpr int DELTA[] = {0, 1, 0, -1, 0};
    for (int d = 0; d < 4; ++d) {
      int x = i + DELTA[d], y = j + DELTA[d + 1];
      if (0 <= x && x < board.size() && 0 <= y && y < board[0].size()
          && !vi[x][y] && trie.startsWith(word + board[x][y])) {
        findWords(board, x, y, word, vi, trie, res);
      }
    }
    vi[i][j] = false;
    word.pop_back();
  }
};

// Date: 2015-08
struct TrieNode
{
  map<char, shared_ptr<TrieNode>> children;
  bool is_word = false;
};

class Trie
{
public:
  Trie(vector<string>& words): root(shared_ptr<TrieNode>(new TrieNode))
  {
    for (auto word: words)
    {
      insert(word);
    }
  }

  // Inserts a word into the trie.
  void insert(string word) const
  {
    if (word.empty())
    {
      return ;
    }
    auto node = root;
    for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
    {
      if (node->children.find((word[i])) == node->children.end())
      {
        node->children[word[i]] = shared_ptr<TrieNode>(new TrieNode);
      }
    }
    node->is_word = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) const
  {
    auto node = searchNode(word);
    return node!=nullptr && node->is_word;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) const
  {
    return searchNode(prefix) != nullptr;
  }

private:
  shared_ptr<TrieNode> searchNode(string word) const
  {
    auto node = root;
    for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
    {
      if (node->children.find(word[i]) == node->children.end())
      {
        return nullptr;
      }
    }
    return node;
  }

  shared_ptr<TrieNode> root;
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
      if (board.empty())
      {
        return ret;
      }

        Trie trie(words);
        vi = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++ i)
        {
          // use board[0] instead of board[i] to get the better performance
          for (int j = 0; j < board[0].size(); ++ j)
          {
            dfs(string(), board, i, j, trie);
          }
        }

        return ret;
    }

private:
  void dfs(string cur, const vector<vector<char>>& board, int i, int j, Trie& trie)
  {
    if (vi[i][j] == true)
    {
      return ;
    }

    vi[i][j] = true;
    cur += board[i][j];
    if (trie.search(cur))
    {
      ret.push_back(cur);
    }
    if (trie.startsWith(cur) == true)
    {
      for (auto dir: dirs)
      {
        if (i+dir[0]>=0 && i+dir[0]<board.size()
          && j+dir[1]>=0 && j+dir[1]<board[0].size())
        {
          dfs(cur, board, i+dir[0], j+dir[1], trie);
        }
      }
    }
    vi[i][j] = false;
  }

  vector<string> ret;
  vector<vector<bool>> vi;
  int dirs[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
