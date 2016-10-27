// Copyright 2016 Qi Wang
// Date: 2016-10-17
#include <cstdio>

double tot[4001];

// combination
inline double com(double n, i) {
  return tot[n] / tot[n - i] / tot[i];
}

int main() {
  // preprocess
  tot[0] = 1;  
  for (int i = 1; i <= 4000; ++i) tot[i] = tot[i - 1] * i;
  // input
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    int m, n;
    scanf("%d%d", &m, &n);
    if (n >= m) {
      printf("Case #%d: %.8f\n", tt, 0.);
      continue;
    } if (m == 1) {
      printf("Case #%d: %.8f\n", tt, 1.);
      continue;      
    }
    double negativeCnt = n * tot[m + n - 1] + m * n * tot[m + n - 2];
    double pre = 1;
    for (int i = 2; i <= n; ++i) {
      pre *= (n - i + 1) * (m - i + 1) * (2 * i * i - 5 * i + 2);
      negativeCnt +=  pre * tot[m + n - 2 * i];
    }
    printf("Case #%d: %.8f\n", tt, (tot[m + n] - negativeCnt) / tot[m + n]);
    // printf("negative: %.8f, tot: %.8f\n", negativeCnt, tot[m + n]);
  }
}
