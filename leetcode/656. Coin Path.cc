// Copyright 2017 Qi Wang
// Date: 2017-08-08
class Solution {
 public:
  vector<int> cheapestJump(vector<int>& A, int B) {
    if (A.empty()) return {};
    vector<pair<int, vector<int>>> dp(A.size(),
                                      make_pair(INT_MAX, vector<int>()));
    if (A[0] != -1) dp[0] = make_pair(A[0], vector<int>{0});
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] == -1 || dp[i].first == INT_MAX) continue;
      for (int j = 1; j <= B && i + j < A.size(); ++j) {
        if (A[i + j] == -1) continue;
        if (dp[i].first +  A[i + j] < dp[i + j].first) {
          dp[i + j].first = dp[i].first + A[i + j];
          dp[i + j].second = dp[i].second;
          dp[i + j].second.push_back(i + j);
        } else if (dp[i].first + A[i + j] == dp[i + j].first) {
          auto vt = dp[i].second;
          vt.push_back(i + j);
          if (less(vt, dp[i + j].second)) dp[i + j].second = move(vt);
        }
      }
    }
    for (int& idx : dp.back().second) ++idx;
    return dp.back().second;
  }
 
 private:
  bool less(const vector<int>& lhs, const vector<int>& rhs) const {
    for (int i = 0; i < lhs.size() && i < rhs.size(); ++i) {
      if (lhs[i] != rhs[i]) {
        return lhs[i] < rhs[i];
      }
    }
    return lhs.size() < rhs.size();
  }
};
