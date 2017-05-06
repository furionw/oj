// Copyright 2017 Qi Wang
// Date: 2017-05-06
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s(n, 0);
  for (int i = 0; i < n; ++i) cin >> s[i];
  string result;
  while (!s.empty()) {
    string temp(s.rbegin(), s.rend());
    if (s < temp) {
      result += s[0];
      s.erase(s.begin());
    } else {
      result += s[s.size() - 1];
      s.erase(--s.end());
    }
  }
  size_t i = 0;
  for (; i + 80 < result.size(); i += 80)
    cout << result.substr(i, 80) << endl;
  cout << result.substr(i) << endl;
}
