// 2025-06-11
// Method 2
// Refer to: https://leetcode.com/problems/last-stone-weight-ii/solutions/294888/java-c-python-easy-knapsacks-dp/
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    bitset<1501> dp;
    int sum = 0;
    dp[0] = true;
    for (int s : stones) {
      sum += s;
      for (int i = min(sum, 1500); i >= s; --i) {
        dp[i] = dp[i] + dp[i - s];
      }
    }
    for (int i = sum / 2; i >= 0; --i) {
      if (dp[i]) {
        return sum - i - i;
      }
    }
    return -1;
  }
};

// Method 1
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int offset = accumulate(stones.begin(), stones.end(), 0);
    int n = 2 * offset + 1;
    int flag = 0;
    vector<vector<bool>> dp(2, vector<bool>(n, 0));
    dp[1 - flag][offset] = true;
    for (int s : stones) {
      const auto& prevDp = dp[1 - flag];
      auto& curDp = dp[flag];
      for (int i = 0; i <= n ;++i) {
        curDp[i] = false;
        int i1 = i - s;
        if (i1 >= 0 && prevDp[i1]) {
          curDp[i] = true;
        }
        int i2 = i + s;
        if (i2 < n && prevDp[i2]) {
          curDp[i] = true;
        }
      }
      flag = 1 - flag;
    }
    const auto& curDp = dp[1 - flag];
    for (int i = offset; i <= n; ++i) {
      if (curDp[i]) {
        return i - offset;
      }
    }
    return -1;
  }
};