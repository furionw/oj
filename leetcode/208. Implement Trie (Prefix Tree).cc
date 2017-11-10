// Copyright 2017 Qi Wang
// Date: 2017-11-09
// Please handle the empty string carefully.
class Trie {
 public:
  Trie() {}
 
  void insert(string word) {
    root_.Insert(word, 0);
  }
  
  bool search(string word) {
    return root_.Search(word, 0);
  }
    
  bool startsWith(string prefix) {
    return root_.StartsWith(prefix, 0);
  }
 
 private:
  class TrieNode {
   public:
    TrieNode() {
      memset(children_, 0, sizeof children_);
    }
 
    void Insert(const string& word, int idx) {
      if (idx == word.size()) {
        is_word_ = true;
      } else {
        int offset = word[idx] - 'a';
        if (children_[offset] == nullptr) {
          children_[offset] = new TrieNode();
        }
        children_[offset]->Insert(word, idx + 1);
      }
    }
 
    bool Search(const string& word, int idx) const {
      if (idx == word.size()) {
        return is_word_;
      } else {
        int offset = word[idx] - 'a';
        return children_[offset] != nullptr &&
               children_[offset]->Search(word, idx + 1);
      }
    }
 
    bool StartsWith(const string& prefix, int idx) const {
      if (idx == prefix.size()) {
        return true;
      } else {
        int offset = prefix[idx] - 'a';
        return children_[offset] != nullptr &&
               children_[offset]->StartsWith(prefix, idx + 1);
      }
    }
    
   private:
    TrieNode* children_[26];
    bool is_word_ = false;
  };
 
  TrieNode root_;
};

// Date: 2017-07-25
class Trie {
 public:
  Trie() {
    memset(children_, 0, sizeof children_);
  }

  void insert(string word) {
    if (word.empty()) {
      is_word_ = true;
      return;
    }
    int idx = word[0] - 'a';
    if (children_[idx] == nullptr) {
      children_[idx] = new Trie();
    }
    children_[idx]->insert(word.substr(1));
  }

  bool search(string word) {
    if (word.empty()) {
      return is_word_;
    } else {
      int idx = word[0] - 'a';
      return children_[idx] != nullptr &&
          children_[idx]->search(word.substr(1));
    }
  }

  bool startsWith(string prefix) {
    if (prefix.empty()) {
      return true;
    } else {
      int idx = prefix[0] - 'a';
      return children_[idx] != nullptr &&
          children_[idx]->startsWith(prefix.substr(1));
    }
  }

 private:
  Trie* children_[26];
  bool is_word_ = false;
};

// Date: 2016-12-31
// Last modified: 2017-01-03
// Method 2: without shared_ptr and memory re-allocation
// 45 ms, beats 89% cpp solutions
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

  bool search(string word) {
    auto node = find(word);
    return node != nullptr && node->word_;
  }

  bool startsWith(string prefix) { return find(prefix) != nullptr; }

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

// Date: 2016-12-31
// Method 1: with shared_ptr
// 200+ms, beats 1.5% cpp solutions. Kind of slow
class TrieNode {
 public:
  // Initialize your data structure here.
  unordered_map<char, shared_ptr<TrieNode>> children_;
  bool word_ = false;
};

class Trie {
 public:
  // Inserts a word into the trie.
  void insert(string word) {
    auto cur = root;
    for (char c : word) {
      if (cur->children_.count(c)) {
        cur = cur->children_[c];
      } else {
        cur = cur->children_[c] = make_shared<TrieNode>();
      }
    }
    cur->word_ = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    auto node = find(word);
    return node != nullptr && node->word_;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    return find(prefix) != nullptr;
  }

 private:
  shared_ptr<TrieNode> find(const string& str) const {
    auto cur = root;
    for (char c : str) {
      if (cur->children_.count(c)) {
        cur = cur->children_[c];
      } else {
        return nullptr;
      }
    }
    return cur;
  }

  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};


// Date: 2015-07
struct TrieNode
{
	map<char, shared_ptr<TrieNode>> children;
	bool is_word = false;
};

class Trie
{
public:
	Trie(): root(shared_ptr<TrieNode>(new TrieNode)) {}

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
