// Copyright 2017 Qi Wang
// Date: 2017-04-06
class Solution {
 public:
  int FirstNotRepeatingChar(string str) {
    if (str.empty()) return -1;
    int cnt[256][2];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < str.size(); ++i) {
      ++cnt[str[i]][0];
      cnt[str[i]][1] = i;
    }
    int result = INT_MAX;
    for (int i = 0; i < 256; ++i)
      if (cnt[i][0] == 1)
        result = min(result, cnt[i][1]);
    return result != INT_MAX ? result : -1;
  }
};
