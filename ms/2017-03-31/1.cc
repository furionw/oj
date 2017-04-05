// Copyright 2017 Qi Wang
// Date: 2017-04-03
// Refer to: http://blog.csdn.net/bahuia/article/details/68942663

#include <cstdio>
#include <cmath>

int main() {
  int p, q, n;
  scanf("%d%d%d", &p, &q, &n);
  double result = 0;
  for (int i = 1; i <= n; ++i) {
    double e = 0, acc_p = 1;
    int steps = 0, cur_p = p;
    while (true) {
      e += ++steps * acc_p * cur_p / 100;
      if (cur_p == 100) break;
      acc_p *= (100 - cur_p) / 100.;
      cur_p = fmin(100, cur_p + q);
    }
    p >>= 1;
    result += e;
  }
  printf("%.2lf\n", result);
}
