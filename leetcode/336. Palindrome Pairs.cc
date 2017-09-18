// Copyright 2017 Qi Wang
// Date: 2017-09-17
// Refer to: https://discuss.leetcode.com/topic/40657/150-ms-45-lines-java-solution
class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> word_to_idx_map;
    for (int i = 0; i < words.size(); ++i) {
      word_to_idx_map[words[i]] = i;
    }
    vector<vector<int>> result;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j <= words[i].size(); ++j) {
        string s1 = words[i].substr(0, j);
        string s2 = words[i].substr(j);
        if (Palindrome(s1)) {
          string temp = s2;
          reverse(temp.begin(), temp.end());
          if (word_to_idx_map.find(temp) != word_to_idx_map.end()
              && word_to_idx_map[temp] != i) {
            result.push_back({word_to_idx_map[temp], i});
          }
        }
        if (Palindrome(s2) && !s2.empty()) {
          string temp = s1;
          reverse(temp.begin(), temp.end());
          if (word_to_idx_map.find(temp) != word_to_idx_map.end()
              && word_to_idx_map[temp] != i) {
            result.push_back({i, word_to_idx_map[temp]});
          }
        }
      }
    }
    return result;
  }

 private:
  bool Palindrome(const string& str) const {
    if (str.empty()) return true;
    for (int l = 0, r = str.size() - 1; l < r; ++l, --r) {
      if (str[l] != str[r]) {
        return false;
      }
    }
    return true;
  }
};
