#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> need(N), value(N);  
  vector<int> dp(M + 1, 0);
  for (int i = 0; i < N; ++ i)
    cin >> need[i] >> value[i];
  for (int i = 0; i < N; ++ i)
    for (int j = need[i]; j <= M; ++ j)
      dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
  cout << dp[M] << endl;
}