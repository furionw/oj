// Copyright 2017 Qi Wang
// Date: 2017-04-24
class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1) return to_string(nums.front());
    vector<vector<pair<double, string>>> dp(nums.size());
    dp.back().push_back({nums.back(), to_string(nums.back())});
    for (int i = nums.size() - 2; i >= 0; --i) {
      double dividend = nums[i];
      string prefix = to_string(nums[i]);
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1) {
          dividend /= nums[j - 1];
          prefix += string("/") + to_string(nums[j - 1]);
        }
        for (const auto& p : dp[j]) {
          if (j + 1 == nums.size()) {
            dp[i].push_back({dividend / p.first, prefix + '/' + p.second});
          } else {
            dp[i].push_back({dividend / p.first,
                prefix + "/(" + p.second + ")"});
          }
        }
      }
    }
    return max_element(dp[0].begin(), dp[0].end())->second;
  }
};
