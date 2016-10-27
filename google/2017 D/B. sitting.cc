// Copyright 2016 Qi Wang
// Date: 2016-10-16
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int res = -1;
    int r, c;
    cin >> r >> c;
    int p1 = r / 3 + (r % 3 >= 1);
    int p2 = r / 3 + (r % 3 >= 2);
    int q = c / 3 * 2 + c % 3;
    if (r <= 2) {
      res = r * q;
    } else if (c <= 2) {
      res = (p1 + p2) * c;
    } else if (c % 3 == 0) {
      res = r * q;
    } else if (c % 3 == 1) {
      // r - p1 - p2 == r / 3
      res = (p1 + p2) * q + (r - p1 - p2) * (q - 1);
    } else {
      // now c % 3 == 2
      res = p1 * q + (r - p1) * (q - 1);
    }
    cout << "case #" << i << ": " << res << endl;
  }
}
