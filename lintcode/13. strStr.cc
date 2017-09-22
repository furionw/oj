// Copyright 2017 Qi Wang
// Date: 2017-09-20
// Case 1: "abc", "bc"
class Solution {
 public:
  int strStr(const char *source, const char *target) {
    if (source == nullptr || target == nullptr) return -1;
    if (*target == 0) return 0;
    for (const char* begin = source; *begin != 0; ++begin) {
      auto* t = target;
      for (auto* s = begin; *s != 0 && *t != 0 && *t == *s; ++t, ++s) {}
      if (*t == 0) return begin - source;
    }
    return -1;
  }
};
