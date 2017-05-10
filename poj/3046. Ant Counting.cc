// Copyright 2017 Qi Wang
// Date: 2017-05-10
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int nums[1005], up[1005];

int main() {
  int t, a, s, b;
  scanf("%d%d%d%d", &t, &a, &s, &b);
  vector<int> dp(a + 1, 0), acc(a + 1, 0);
  memset(nums, 0, sizeof nums);
  for (int i = 0; i < a; ++i) {
    int type;
    scanf("%d", &type);
    ++nums[type];
  }
  // up: 上界
  memset(up, 0, sizeof up);
  for (int type = 1; type <= t; ++type)
    up[type] = up[type - 1] + nums[type];
  // 在此的 dp 为滚动数组，所代表的涵义实为 dp[type][j]
  dp[0] = acc[0] = 1;
  for (int type = 1; type <= t; ++type) {
    // 约束边界，减少迭代次数
    int max_i = min(up[type], b);
    // 上一次 dp 状态的累积和，使得计算 dp[i] 时可以省去一层嵌套 for 循环
    for (int i = 1; i <= max_i; ++i)
      acc[i] = (acc[i - 1] + dp[i]) % 1000000;
    for (int i = max_i; i >= 1; --i) {
      int maxx = max(0, i - nums[type]);
      dp[i] = (maxx == 0 ? acc[i] : acc[i] - acc[maxx - 1]) % 1000000;
    }
  }
  int result = 0;
  for (int i = s; i <= b; ++i)
    result = (result + dp[i]) % 1000000;
  printf("%d\n", result);
}
