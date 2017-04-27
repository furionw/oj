// Copyright 2017 Qi Wang
// Date: 2017-04-27
class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs) {
      return lhs.size() > rhs.size();
    });
    for (size_t i = 0; i < strs.size(); ++i) {
      bool uncommon = true;
      for (size_t j = 0; j < strs.size() && uncommon; ++j)
        if (i != j && SubSeq(strs[i], strs[j]))
          uncommon = false;
      if (uncommon) return strs[i].size();
    }
    return -1;
  }

 private:
  bool SubSeq(const string& cur, const string& other) const {
    size_t i = 0;
    for (size_t j = 0; i < cur.size() && j < other.size();) {
      while (j < other.size() && cur[i] != other[j]) ++j;
      if (j++ < other.size()) ++i;
    }
    return i == cur.size();
  }
};
