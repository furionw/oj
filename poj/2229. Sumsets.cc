// Copyright 2017 Qi Wang
// Date: 2017-05-10
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<uint64_t> dp(n + 1, 0);
  dp[0] = dp[1] = 1;
  // method 2
  // refer to: http://blog.csdn.net/scorpiocj/article/details/5940456
  for (int i = 2; i <= n; ++i)
    dp[i] = (dp[i - 2] + dp[i >> 1]) % 1000000000;
  cout << dp.back() << endl;

  // method 1: complete knapsack
  // TLE
  fill(dp.begin(), dp.end(), 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i <<= 1)
    for (int j = i; j <= n; ++j)
      dp[j] = (dp[j] + dp[j - i]) % 1000000000;
  cout << dp.back() % 1000000000 << endl;
}
