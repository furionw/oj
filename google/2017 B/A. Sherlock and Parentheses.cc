// Copyright 2016 Qi Wang
// Date: 2016-10-16
#include <iostream>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::min;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    long long l, r;
    cin >> l >> r;
    long long num = min(l, r);
    cout << "case #" << i << ": " << (num * num + num) / 2 << endl;
  }
}
