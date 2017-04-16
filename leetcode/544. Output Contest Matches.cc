// Copyright 2017 Qi Wang
// Date: 2017-03-22
class Solution {
 public:
  string findContestMatch(int n) {
    vector<string> init;
    for (int i = 1; i <= n; ++i) init.push_back(to_string(i));
    return f(init);
  }

 private:
  string f(const vector<string>& strs) const {
    vector<string> next;
    for (size_t i = 0; i < strs.size() / 2; ++i)
      next.push_back(pack(strs[i], strs[strs.size() - 1 - i]));
    return next.size() == 1 ? next.front() : f(next);
  }

  string pack(const string& strong, const string& weak) const {
    return string("(") + strong + "," + weak + ")";
  }
};
