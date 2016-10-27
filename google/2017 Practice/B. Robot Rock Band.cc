// Copyright 2016 Qi Wang
// Date: 2016-10-26
#include <map>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> nums(4, vector<int>(n));
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < n; ++j)
        cin >> nums[i][j];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ++cnt[nums[0][i] ^ nums[1][j]];
    long long res = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        res += cnt[nums[2][i] ^ nums[3][j] ^ k];
    cout << "case #" << tt << ": " << res << endl;
  }
}
