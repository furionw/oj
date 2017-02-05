// Copyright 2017 Qi Wang
// Date: 2017-01-30
// Method 3: DP
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    static constexpr int OFFSET = 1000;
    static constexpr int LENGTH = (OFFSET << 1) + 1;
    if (nums.empty() || S > OFFSET) return 0;
    int dp[2][LENGTH];
    memset(dp, 0, sizeof dp);
    dp[0][nums.front() + OFFSET] = 1;
    // handle the case when the front == 0
    dp[0][-nums.front() + OFFSET] = dp[0][0 + OFFSET] + 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      memset(dp[1], 0, sizeof dp[1]);
      for (int j = 0; j < LENGTH; ++j)
        if (dp[0][j]) {
          dp[1][j + nums[i]] += dp[0][j];
          dp[1][j - nums[i]] += dp[0][j];
        }
      copy(dp[1], dp[1] + LENGTH, dp[0]);
    }
    return dp[0][S + OFFSET];
  }
};

// Method 2: unordered_map
// Date: 2017-01-30
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    if (nums.empty() || S > 1000) return 0;
    unordered_map<int, int> cnts;
    cnts[nums.front()] = 1;
    cnts[-nums.front()] = cnts[0] + 1;  // handle the case when the front == 0
    for (size_t i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      unordered_map<int, int> temp;
      for (const auto& p : cnts) {
        temp[p.first + num] += cnts[p.first];
        temp[p.first - num] += cnts[p.first];
      }
      cnts = move(temp);
    }
    return cnts[S];
  }
};

// Method 1
// Date: 2017-01-29
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int cnt = 0;
    f(nums, 0, 0, S, cnt);
    return cnt;
  }

 private:
  void f(const vector<int>& nums, int idx, int sum, int S, int& cnt) const {
    if (idx == nums.size()) {
      cnt += sum == S;
      return;
    }
    f(nums, idx + 1, sum + nums[idx], S, cnt);
    f(nums, ++idx, sum - nums[idx], S, cnt);
  }
};
