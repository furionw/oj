#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);
  while (k--) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (; n != 0; n = n & (n - 1)) {
      ++cnt;
    }
    printf("%d\n", cnt);
  }
}
