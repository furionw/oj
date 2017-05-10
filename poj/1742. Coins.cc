// Copyright 2017 Qi Wang
// Date: 2017-05-10
// Refer to: 背包九讲
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coins[105], nums[105];
int dp[100005];

int main() {
  for (int n, m; cin >> n >> m, 0 != n && 0 != m;) {
    int num_sz = 0;
    for (int i = 0; i < n; ++i) cin >> coins[i];
    for (int i = 0; i < n; ++i) cin >> nums[i];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) {
      dp[0] = nums[i];
      for (int j = 1; j <= m; ++j)
        if (dp[j] > -1)
          dp[j] = nums[i];
      for (int j = 0; j + coins[i] <= m; ++j)
        if (dp[j] > 0)
          dp[j + coins[i]] = max(dp[j + coins[i]], dp[j] - 1);
    }
    int result = 0;
    for (int j = 1; j <= m; ++j)
      result += dp[j] >= 0;
    cout << result << endl;
  }
}
