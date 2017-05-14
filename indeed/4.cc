// Copyright 2017 Qi Wang
// Date: 2017-05-13
#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>

using namespace std;

int main() {
  int64_t result = 0;
  int64_t l, n;
  cin >> l >> n;
  vector<int64_t> houses(n + 1), rs(n + 1), dist_acc(n + 1, 0), r_acc(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int64_t dist, r;
    cin >> dist >> r;
    houses[i + 1] = dist;
    rs[i + 1] = r;
    dist_acc[i + 1] = dist_acc[i] + dist;
    r_acc[i + 1] = r_acc[i] + r;
  }
  for (int i = 2; i <= n; ++i)
    result += (houses[i] - houses[1]) * rs[i];
  for (int i = 2; i <= n; ++i) {
    result = min<int64_t>(result, result + (houses[i] - houses[i - 1]) * (r_acc[i - 1] - (r_acc[n] - r_acc[i - 1])));
  }
  cout << result << endl;
}
