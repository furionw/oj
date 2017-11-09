// Copyright 2017 Qi Wang
// Date: 2017-11-08
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> root_to_strs_map;
    for (string& str : strs) {
      string root = str;
      sort(root.begin(), root.end());
      root_to_strs_map[root].push_back(move(str));
    }
    vector<vector<string>> result;
    for (auto& p : root_to_strs_map) {
      result.push_back(move(p.second));
    }
    return result;
  }
};
 
// Date: 2017-07-24
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> root_to_words_map;
    for (const string& word : strs) {
      string root = word;
      sort(root.begin(), root.end());
      root_to_words_map[root].push_back(word);
    }
    vector<vector<string>> result;
    for (auto& p : root_to_words_map) {
      result.push_back(move(p.second));
    }
    return result;
  }
};
