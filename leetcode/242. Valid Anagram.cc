// Copyright 2017 Qi Wang
// Date: 2017-07-24
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (char c : t) {
      --cnt[c - 'a'];
    }
    return count(cnt, cnt + 26, 0) == 26;
  }
};
