// Copyright 2017 Qi Wang
// Date: 2017-05-20
#include <iostream>
#include <climits>

using namespace std;

int dp[305][305];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      dp[i][j] = i == j ? 0 : INT_MAX;
  while (m--) {
    int num;
    cin >> num;
    int cows[305];
    for (int i = 0; i < num; ++i)
      cin >> cows[i];
    for (int i = 0; i < num; ++i)
      for (int j = 0; j < num; ++j)
        if (i != j)
          dp[cows[i]][cows[j]] = dp[cows[j]][cows[i]] = 1;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX
            && dp[i][j] > dp[i][k] + dp[k][j])
          dp[i][j] = dp[i][k] + dp[k][j];
  int result = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    int acc = 0;
    for (int j = 1; j <= n; ++j)
      if (i != j) acc += dp[i][j];
    result = min(result, acc);
  }
  cout << result * 100 / (n - 1) << endl;
}
