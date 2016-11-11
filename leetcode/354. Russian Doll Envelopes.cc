// Copyright 2016 Qi Wang
// Date: 2016-11-11
class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if (envelopes.empty()) return 0;
    sort(envelopes.begin(), envelopes.end());
    int dp[envelopes.size()];
    fill(dp, dp + envelopes.size(), 1);
    for (size_t i = 1; i < envelopes.size(); ++i)
      for (size_t j = 0; j < i; ++j)
        if (envelopes[i].first > envelopes[j].first
            && envelopes[i].second > envelopes[j].second)
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp, dp + envelopes.size());
  }
};
