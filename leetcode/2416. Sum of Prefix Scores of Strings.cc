// Date: 2022-10-08
// Refer to: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/discuss/2590081/C%2B%2B-Java-Python3-Easy-Trie-Explained-with-diagram
struct Trie {
  int getScore(const string& prefix, int idx) {
    if (idx == prefix.size()) {
      return cnt;
    }
    char c = prefix[idx];
    return cnt + children[c - 'a']->getScore(prefix, idx + 1);
  }
  
  void insert(const string& word, int idx) {
    auto& child = children[word[idx] - 'a'];
    if (child == nullptr) {
      child = new Trie();
    }
    ++child->cnt;
    if (idx + 1 < word.size()) {
      child->insert(word, idx + 1);
    }
  }

  int cnt = 0;
  Trie* children[26] = {};
};

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> answers(words.size(), 0);
    
    Trie trie;
    for (const auto& word: words) {
      trie.insert(word, 0);
    }
    for (size_t i = 0; i < words.size(); ++i) {
      answers[i] = trie.getScore(words[i], 0 /*idx*/);
    }
  
    return answers;
  }
};

// TLE 2
struct Trie {
  int getScore(const string& prefix, int idx) {
    if (idx == prefix.size()) {
      return cnt;
    }
    char c = prefix[idx];
    return children[c - 'a']->getScore(prefix, idx + 1);
  }
  
  void insert(const string& word, int idx) {
    auto& child = children[word[idx] - 'a'];
    if (child == nullptr) {
      child = new Trie();
    }
    ++child->cnt;
    if (idx + 1 < word.size()) {
      child->insert(word, idx + 1);
    }
  }

  int cnt = 0;
  Trie* children[26] = {};
};

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> answers(words.size(), 0);
    
    Trie trie;
    for (const auto& word: words) {
      trie.insert(word, 0);
    }
    for (size_t i = 0; i < words.size(); ++i) {
      for (size_t len = 1; len <= words[i].size(); ++len) {
        int temp = trie.getScore(words[i].substr(0, len), 0 /*idx*/);
        answers[i] += temp;
      }
    }
  
    return answers;
  }
};

// TLE 1
class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> answers(words.size(), 0);
    
    unordered_map<string, vector<int>> indexByPrefix;
    for (size_t i = 0; i < words.size(); ++i) {
      indexByPrefix[""].push_back(i);
    }
    for (size_t i = 0; i < words.size(); ++i) {
      string prev;
      for (char c : words[i]) {
        string cur = prev + c;
        if (indexByPrefix.count(cur) == 0) {
          int charIdxToCheck = prev.size();
          for (int wordIdx : indexByPrefix[prev]) {
            const auto& other = words[wordIdx];
            if (other.size() > charIdxToCheck && other[charIdxToCheck] == c) {
              indexByPrefix[cur].push_back(wordIdx);
            }
          }
        }
        answers[i] += indexByPrefix[cur].size();
        prev = cur;
        if (indexByPrefix[cur].empty()) {
          break;
        }
      }
    }
  
    return answers;
  }
};