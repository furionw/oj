// 2025-06-18
class Solution {
 public:
  bool areAlmostEqual(string s, string s2) {
    if (s.size() != s2.size()) {
      return false;
    }
    vector<int> idxs;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != s2[i]) {
        idxs.push_back(i);
      }
    }
    if (idxs.empty()) {
      return true;
    }
    if (idxs.size() != 2) {
      return false;
    }
    int idx1 = idxs[0];
    int idx2 = idxs[1];
    return s[idx1] == s2[idx2] && s[idx2] == s2[idx1];
  }
};
