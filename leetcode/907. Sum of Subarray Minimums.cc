// Date: 2022-11-08
// Method 2
// Refer to the below post on 11-07 and solve this question alone on 11-08. Congrats, Qi!
// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170769/Java-O(n)-monotone-stack-with-DP 
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    vector<int> dp(arr.size(), 0);
    stack<int> s;
    for (size_t i = 0; i < arr.size(); ++i) {
      for (; !s.empty() && arr[s.top()] >= arr[i]; s.pop()) {}
      if (s.empty()) {
        dp[i] = arr[i] * (i + 1);
      } else {
        dp[i] = (dp[s.top()] + arr[i] * (i - s.top())) % int(1e9 + 7);
      }
      s.push(i);
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};

// Date: 2022-11-07
// Method 1
// TLE. O(n^2) time complexity.
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    vector<int> dp = arr;
    int res = accumulate(dp.begin(), dp.end(), 0);
    for (int i = 1; i < arr.size(); ++i) {
      for (int j = arr.size() - 1; j - i >= 0; --j) {
        dp[j] = min(dp[j], arr[j - i]);
        res = (res + dp[j]) % int(1e9 + 7);
      }
    }
    return res;
  }
};
