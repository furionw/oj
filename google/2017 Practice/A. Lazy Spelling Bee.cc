// Copyright 2016 Qi Wang
// Date: 2016-10-25
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::cin; using std::cout; using std::endl;

constexpr long long DIVISOR = 1000000007;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    std::string str;
    cin >> str;
    std::vector<long long> vt(str.size(), 0);
    for (int i = 0; i < str.size(); ++i) {
      std::unordered_set<char> s;
      if (i - 1 >= 0) s.insert(str[i - 1]);
      s.insert(str[i]);
      if (i + 1 < str.size()) s.insert(str[i + 1]);
      vt[i] = s.size();
    }
    long long res = 1;
    for (long long num : vt) res = (res * num) % DIVISOR;
    cout << "case #" << tt << ": " << res << endl;
  }
}
