// Copyright 2016 Qi Wang
// Date: 2016-11-10
class Solution {
 public:
  string originalDigits(string s) {
    auto sCnts = stat(s);
    pair<string, int> digits[] = {
      {"six", '6'}, {"zero", '0'}, {"seven", '7'}, {"eight", '8'},
      {"five", '5'}, {"nine", '9'}, {"four", '4'}, {"three", '3'},
      {"two", '2'}, {"one", '1'}
    };
    string res;
    for (char i = 0; i < 10; ++i) {
      auto dCnts = stat(digits[i].first);
      while (all_of(dCnts.begin(), dCnts.end(), [&sCnts]
          (const pair<char, int>& p) { return p.second <= sCnts[p.first]; })) {
        for (const auto& p : dCnts)
          sCnts[p.first] -= p.second;
        res += digits[i].second;
      }
    }
    sort(res.begin(), res.end());
    return res;
  }

 private:
  unordered_map<char, int> stat(const string& str) {
    unordered_map<char, int> res;
    for (char c : str)
      ++res[c];
    return res;
  }
};
