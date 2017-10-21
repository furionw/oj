// Copyright 2017 Qi Wang
// Date: 2017-10-19
// Case 1: [1, 2]
// i = 1
//   j = 0, update dp[1]
// Case 2: [1, 1, 2]
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<Seq> dp(nums.size());
    int max_len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j].len + 1 > dp[i].len) {
            dp[i].len = dp[j].len + 1;
            dp[i].freq = dp[j].freq;
          } else if (dp[j].len + 1 == dp[i].len) {
            dp[i].freq += dp[j].freq;
          }
        }
      }
      max_len = max(max_len, dp[i].len);
    }
    return accumulate(dp.begin(), dp.end(), 0, [max_len](int acc, const Seq& seq) {
      return acc + (seq.len == max_len ? seq.freq : 0);
    });
  }

 private:
  struct Seq {
    int len = 1;
    int freq = 1;
  };
};

// Date: 2017-09-09
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int longest = 1;
    vector<pair<int, int>> dp(nums.size(), {1, 1});
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j].first + 1 > dp[i].first) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = dp[j].second;
          } else if (dp[j].first + 1 == dp[i].first) {
            dp[i].second += dp[j].second;
          }
        }
      }
      longest = max(longest, dp[i].first);
    }
    int result = 0;
    for (const auto& p : dp) {
      if (p.first == longest) result += p.second;
    }
    return result;
  }
};