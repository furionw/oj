// Copyright 2016 Qi Wang
// Date: 2016-11-06
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; ++t) {
    int n, d;
    int ans = 0;
    cin >> n >> d;
    for (int i = d; i <= n; i += d) {
      int num = n / i;
      int maxLen = num - 1, minLen = (n - i) / (i + 2);
      for(int j = minLen; j <= maxLen; ++j) {
        int left = n - (i + i * j);
        int two = left / 2, zero;
        if (left % 2 == 0) {
          if (two > j) continue;
          zero = j - two;
        } else if (left % 2 == 1) {
          if (two + 1 > j) continue;
          zero = j - two - 1;
        }
        ans += 1 + min(zero, two);
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
