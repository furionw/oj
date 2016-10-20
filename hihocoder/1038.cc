#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  // Input
  int n, m;
  cin >> n >> m;
  vector<int> needs, values;
  while (n -- != 0) {
    int need, value;
    cin >> need >> value;
    needs.push_back(need);
    values.push_back(value);
  }
  // DP
  // Initialization
  vector<int> dp(m + 1, 0);
  // Start
  for (size_t i = 0; i < needs.size(); ++ i)
    for (int j = m; j >= needs[i]; -- j)
      dp[j] = max(dp[j], dp[j - needs[i]] + values[i]);
  cout << dp[m] << endl;
}
