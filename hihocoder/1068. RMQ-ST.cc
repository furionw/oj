// Copyright 2016 Qi Wang
// Date: 2016-10-26
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAXN = 1e6 + 5;
int dp[MAXN][20];

int main() {
  int n;
  scanf("%d", &n);
  // preprocess via dynamic programming
  // init
  for (int i = 1; i <= n; ++i)
    scanf("%d", &dp[i][0]);
  // dynamic equation
  // method 1
  // for (int j = 1; 1 << j <= n; ++j)
  //   for (int i = 1; i <= n; ++i)
  //     dp[i][j] = min(dp[i][j - 1], dp[min(n, i + (1 << (j - 1)))][j - 1]);
  // method 2
  for (int j = 1; 1 << j <= n; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      // make sure dp[i][j] is meaningful
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int exp = floor(log(r - l + 1) / log(2));
    printf("%d\n", min(dp[l][exp], dp[r - (1 << exp) + 1][exp]));
  }
}
