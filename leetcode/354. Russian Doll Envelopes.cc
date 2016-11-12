// Copyright 2016 Qi Wang
// Method 3
// Binary search with std::lower_bound, turning problem into LIS
// Refer to: http://www.cnblogs.com/grandyang/p/5568818.html
// Date: 2016-11-12
class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if (envelopes.empty()) return 0;
    sort(envelopes.begin(), envelopes.end(),
        [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.first != rhs.first
              ? lhs.first < rhs.first
              : lhs.second > rhs.second;
        });
    vector<int> dp {envelopes[0].second};
    for (size_t i = 1; i < envelopes.size(); ++i) {
      auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
      if (it == dp.end()) {
        dp.push_back(envelopes[i].second);
      } else {
        *it = envelopes[i].second;
      }
    }
    return static_cast<int>(dp.size());
  }
};

// Method 2
// Binary search, turning problem into LIS
// Refer to: http://www.cnblogs.com/grandyang/p/5568818.html
// Date: 2016-11-12
class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    if (envelopes.empty()) return 0;
    sort(envelopes.begin(), envelopes.end(),
        [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.first != rhs.first
              ? lhs.first < rhs.first
              : lhs.second > rhs.second;
        });
    vector<int> dp {envelopes[0].second};
    for (size_t i = 1; i < envelopes.size(); ++i) {
      int l = 0, r = dp.size();
      while (l < r) {
        int mid = (l + r) >> 1;
        if (dp[mid] < envelopes[i].second) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (r == dp.size()) {
        dp.push_back(envelopes[i].second);
      } else {
        dp[r] = envelopes[i].second;
      }
    }
    return static_cast<int>(dp.size());
  }
};

// Method 2
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
