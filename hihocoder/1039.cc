// Copyright 2016 Qi Wang
// Date: 2016-10-13
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::cin; using std::cout; using std::endl;
using std::max;

string recursive(const string& str) {
  vector<int> same(str.size(), false);
  for (size_t i = 0; i < str.size(); ++i) {
    if (i + 1 < str.size() && str[i] == str[i + 1]) {
      same[i] = same[i + 1] = true;
    }
  }
  string res;
  for (size_t i = 0; i < same.size(); ++i) {
    res += !same[i] ? str[i] : "";
  }
  return res.size() == str.size() ? res : recursive(res);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int res = 0;
    for (size_t i = 0; i < str.size(); ++i)
      for (char c = 'A'; c <= 'C'; ++c)
        res = max(res, str.size()
            - recursive(str.substr(0, i) + c + str.substr(i)).size());
    cout << res << endl;
  }
}
