// Copyright 2017 Qi Wang
// Date: 2017-05-09
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > dp(n, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= i + 1; ++j)
      cin >> dp[i][j];
  for (int i = 1; i < n; ++i)
    for (int j = 1; j <= i + 1; ++j)
      dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
  cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}
