// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> shift;
    for (auto& str : strings)
      shift[getBase(str)].push_back(move(str));
    vector<vector<string>> res;
    for (auto& p : shift)
      res.push_back(move(p.second));
    return res;
  }

 private:
  string getBase(const string& str) const {
    if (str.empty()) return "";
    string res = str;
    char offset = res.front() - 'a';
    for (char& c : res) {
      c -= offset;
      c += c < 'a' ? 26 : 0;
    }
    return res;
  }
};
