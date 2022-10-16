// Date: 2022-10-15
class Solution {
 public:
  int partitionString(string s) {
    unordered_set<char> chars;
    int res = 0;
    for (char c : s) {
      if (chars.count(c)) {
        ++res;
        chars.clear();
      }
      chars.insert(c);
    }
    ++res;
    return res;
  }
};
