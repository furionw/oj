// Copyright 2016 Qi Wang
// Date: 2016-12-30
// Method 2: without set
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int max = 0, sz = 0, cs[2], csIdx = 0;  // cs : character set
    pair<char, int> last;  // (char, idx)
    for (char c : s) {
      // exists
      if (any_of(cs, cs + csIdx, [c](char inSet) { return inSet == c; })) {
        last = last.first == c ? last : make_pair(c, sz);
        ++sz;
      // non exists, with cs.size() < 2
      } else if (csIdx < 2) {
        last = {c, sz++};
        cs[csIdx++] = c;
      // non exists, with cs.size() == 2
      } else {
        for (int i = 0; i < 2; ++i)
          if (cs[i] != last.first)
            cs[i] = c;
        sz = sz - last.second + 1;
        last = {c, sz - 1};
      }
      max = std::max(max, sz);
    }
    return max;
  }
};

// Date: 2016-12-30
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int max = 0, sz = 0;
    pair<char, int> last;  // (char, idx)
    set<char> cs;  // character set
    for (char c : s) {
      // exists
      if (cs.count(c) > 0) {
        last = last.first == c ? last : make_pair(c, sz);
        ++sz;
      // non exists, with cs.size() < 2
      } else if (cs.size() < 2) {
        last = {c, sz++};
        cs.insert(c);
      // non exists, with cs.size() == 2
      } else {
        for (char inSet : cs)
          if (inSet != last.first) {
            cs.erase(inSet);
            break;
          }
        sz = sz - last.second + 1;
        last = {c, sz - 1};
        cs.insert(c);
      }
      max = std::max(max, sz);
    }
    return max;
  }
};
