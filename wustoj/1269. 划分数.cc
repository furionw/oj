// Copyright 2017 Qi Wang
// Date: 2017-05-07
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  int dp[201][7];
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= 200; ++i) dp[i][1] = 1;
  for (int i = 1; i <= 200; ++i)
    for (int j = 2; j <= i && j <= 6; ++j)
      dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
  // This stupid OJ "implicitly" require keep reading input until EOF
  for (int n, m; cin >> n >> m;)
    cout << dp[n][m] << endl;
}
