// 2025-06-18
class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    bitset<26> visited;
    bool duplicates = false;
    if (s.size() != goal.size()) {
      return false;
    }
    vector<int> idxs;
    for (int i = 0; i < s.size(); ++i) {
      if (visited[s[i] - 'a']) {
        duplicates = true;
      } else {
        visited[s[i] - 'a'] = true;
      }
      if (s[i] != goal[i]) {
        idxs.push_back(i);
      }
    }
    if (idxs.empty() && duplicates) {
      return true;
    }

    if (idxs.size() != 2) {
      return false;
    }
    int idx1 = idxs[0];
    int idx2 = idxs[1];
    swap(s[idx1], s[idx2]);
    return s[idx1] == goal[idx1] && s[idx2] == goal[idx2];
  }
};
