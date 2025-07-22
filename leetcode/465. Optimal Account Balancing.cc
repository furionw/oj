// 2025-07-19
// Refer to the Editorial
class Solution {
 public:
  int minTransfers(vector<vector<int>>& transactions) {
    unordered_map<int, int> balance1;
    for (const auto& t : transactions) {
      balance1[t[0]] -= t[2];
      balance1[t[1]] += t[2];
    }

    // non-zero
    vector<int> balance2;
    for (auto [_, v] : balance1) {
      if (v != 0) {
        balance2.push_back(v);
      }
    }
    int n = balance2.size();

    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    return n - f(dp, (1 << n) - 1, balance2);
  }

 private:
  int f(vector<int>& dp, int idx, const vector<int>& balance) const {
    // visited
    if (dp[idx] != -1) {
      return dp[idx];
    }

    int acc = 0;
    int answer = 0;
    for (int i = 0; i < balance.size(); ++i) {
      if (idx & (1 << i)) {
        answer = max(answer, f(dp, idx - (1 << i), balance));
        acc += balance[i];
      }
    }

    return dp[idx] = answer + (acc == 0 ? 1 : 0);
  }
};
