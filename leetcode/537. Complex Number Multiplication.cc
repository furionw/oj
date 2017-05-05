// Copyright 2017 Qi Wang
// Date: 2017-05-05
class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    auto p1 = Parse(a), p2 = Parse(b);
    return to_string(p1.first * p2.first - p1.second * p2.second) + "+" +
        to_string(p1.first * p2.second + p1.second * p2.first) + "i";
  }

 private:
  pair<int, int> Parse(const string& str) const {
    int i = 0;
    while (str[i] < '0' || str[i] > '9') ++i;
    while (str[i] != '+' && str[i] != '-') ++i;
    if (str[i] == '+') ++i;
    return {stoi(str.substr(0, i)), stoi(str.substr(i, str.size() - i - 1))};
  }
};
