#include <cstdio>
#include <vector>

using namespace std;

int main() {
  for (int n; scanf("%d", &n) != EOF;) {
    long long num1 = 1, num2 = 1;
    for (int i = 2; i <= n; ++i) {
      long long num3 = num1 + num2;
      num1 = num2;
      num2 = num3;
    }
    printf("%lld\n", num2);
  }
}
