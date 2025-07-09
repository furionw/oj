// 2025-07-08
// Identical to 1235. `Maximum Profit in Job Scheduling
class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());

    n = rides.size();
    vector<long long> dp(n, 0);
    long long profit = rides.back()[1] - rides.back()[0] + rides.back()[2];
    dp.back() = profit;
    for (int i = n - 2; i >= 0; --i) {
      profit = rides[i][1] - rides[i][0] + rides[i][2];
      dp[i] = max(profit, dp[i + 1]);
      auto it = lower_bound(rides.begin() + i + 1, rides.end(), rides[i][1],
          [](const auto& ride, int end) {
            return ride[0] < end;
          });
      dp[i] = it == rides.end()
          ? dp[i]
          : max(dp[i], profit + dp[it - rides.begin()]);
    }

    return dp[0];
  }
};

// 2025-07-07
// TLE
class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    long long result = 0;
    sort(rides.begin(), rides.end());
    map<int, long long> endToTip;
    for (const auto& r : rides) {
      long long tip = r[1] - r[0] + r[2];
      auto it = endToTip.upper_bound(r[0]);
      if (it == endToTip.begin()) {
        endToTip[r[1]] = max(endToTip[r[1]], tip);
      } else {
        do {
          --it;
          endToTip[r[1]] = max(endToTip[r[1]], tip + it->second);
        } while (it != endToTip.begin());
      }
      result = max(result, endToTip[r[1]]);
    }
    return result;
  }
};
