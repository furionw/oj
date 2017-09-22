// Copyright 2017 Qi Wang
// Date: 2017-09-21
// Refer to: LC 49
class Solution {
 public:
  vector<string> anagrams(vector<string> &strs) {
    unordered_map<string, list<string>> root_to_strs_map;
    for (const auto& str : strs) {
      auto root = str;
      sort(root.begin(), root.end());
      root_to_strs_map[root].push_back(str);
    }
    vector<string> result;
    for (auto& p : root_to_strs_map) {
      if (p.second.size() > 1) {
        for (string& str : p.second) {
          result.push_back(move(str));
        }
      }
    }
    return result;
  }
};
