// Copyright 2016 Qi Wang
// Date: 2016-10-27
#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  constexpr int MAXN = 1e4 + 5;
  int nums[MAXN];
  for (int i = 1; i <= n; ++i)
    scanf("%d", &nums[i]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 0) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", *std::min_element(nums + l, nums + 1 + r));
    } else {
      int idx, weight;
      scanf("%d%d", &idx, &weight);
      nums[idx] = weight;
    }
  }
}
