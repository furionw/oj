// Copyright 2017 Qi Wang
// Date: 2017-02-07
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    if (nums.empty()) return vector<string>();
    vector<pair<int, int>> ps(nums.size());
    for (int i = 0; i < nums.size(); ++i)
      ps[i] = {nums[i], i};
    sort(ps.begin(), ps.end(), greater<pair<int, int>>());
    vector<string> result(ps.size());
    result[ps[0].second] = "Gold Medal";
    if (ps.size() > 1) result[ps[1].second] = "Silver Medal";
    if (ps.size() > 2) result[ps[2].second] = "Bronze Medal";
    for (int i = 3; i < ps.size(); ++i)
      result[ps[i].second] = to_string(i + 1);
    return result;
  }
};
