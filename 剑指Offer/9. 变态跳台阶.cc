#include <cstdio>
#include <vector>

using namespace std;

int main() {
  vector<long long> dp(51, 0);
  dp[0] = 1;
  for (int i = 1; i <= 50; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i] += dp[j];
    }
  }
  for (int n; scanf("%d", &n) != EOF;) {
    printf("%lld\n", dp[n]);
  }
}
