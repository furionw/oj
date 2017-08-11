// Copyright 2017 Qi Wang
// Date: 2017-08-10
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<pair<int, int>> idx_and_cnt_pairs(26, make_pair(0, 0));
    for (int i = 0; i < s.size(); ++i) {
      int idx = s[i] - 'a';
      idx_and_cnt_pairs[idx].first = i;
      ++idx_and_cnt_pairs[idx].second;
    }
    int result = -1;
    for (const auto& p : idx_and_cnt_pairs) {
      if (p.second == 1) {
        result = result == -1 ? p.first : min(p.first, result);
      }
    }
    return result;
  }
};

// Date: 2016-10-06
class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> cnts(26, 0);
    for (char c : s) ++cnts[c - 'a'];
    for (size_t i = 0; i < s.size(); ++i)
      if (cnts[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
