// Copyright 2016 Qi Wang
// Date: 2016-11-02
class Solution {
 public:
  inline string getHint(string secret, string guess) {
    int cnts[10];
    memset(cnts, 0, sizeof cnts);
    for (char c : secret) ++cnts[c - '0'];
    int bull = 0, cow = 0;
    for (size_t i = 0; i < secret.size(); ++i)
      if (secret[i] == guess[i]) {
        ++bull;
        --cnts[secret[i] - '0'];
      }
    for (size_t i = 0; i < secret.size(); ++i)
      if (cnts[guess[i] - '0'] && secret[i] != guess[i]) {
        ++cow;
        --cnts[guess[i] - '0'];
      }
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};
