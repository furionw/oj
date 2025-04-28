// Date: 2022-10-16
class Solution {
 public:
  string longestWord(vector<string>& words) {
    string res;
    
    unordered_set<string> s;
    for (const auto& word : words) {
      s.insert(word);
    }
    
    for (const auto& word : words) {
      string cur;
      for (char c : word) {
        cur += c;
        if (s.count(cur) == 0) {
          cur.clear();
          break;
        }
      }
      if (cur == word) {
        if (word.size() > res.size()) {
          res = word;
        } else if (word.size() == res.size()) {
          res = min(res, word);
        }
      }
    }
    
    return res;
  }
};