// Copyright 2017 Qi Wang
// Date: 2017-06-09
class Solution {
 public:
  TreeNode* str2tree(string s) {
    size_t pos = 0;
    return str2tree(s, pos);
  }
 
 private:
  TreeNode* str2tree(const string& s, size_t& pos) const {
    if (pos == s.size()) return nullptr;
    size_t len = s.find_first_of("()", pos);
    auto result = new TreeNode(stoi(s.substr(pos, len - pos)));
    if (string::npos == len) return result;
    pos = len;
    if ('(' == s[pos]) {
      result->left = str2tree(s, ++pos);
      if ('(' == s[pos]) result->right = str2tree(s, ++pos);
    }
    ++pos;
    return result;
  }
};
 
