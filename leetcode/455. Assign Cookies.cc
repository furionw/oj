// Copyright 2016 Qi Wang
// Date: 2016-11-13
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    for (size_t i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
      if (s[j] >= g[i]) {
        ++i;
        ++res;
      }
    }
    return res;
  }
};
