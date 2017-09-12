// Copyright 2017 Qi Wang
// Date: 2017-09-11
// Refer to the previous solution
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double l = *min_element(nums.begin(), nums.end());
    double r = *max_element(nums.begin(), nums.end());
    vector<double> sums(nums.size() + 1, 0);
    while (r - l >= 1e-6) {
      double mid = (l + r) / 2;
      bool found_avg_larger_than_mid = false;
      double pre_min = 0;
      for (int i = 1; i <= nums.size(); ++i) {
        sums[i] = sums[i - 1] + nums[i - 1] - mid;
        if (i >= k)
          pre_min = min(pre_min, sums[i - k]);
        if (i >= k && sums[i] - pre_min >= 0) {
          found_avg_larger_than_mid = true;
          break;
        }
      }
      if (found_avg_larger_than_mid) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

// Date: 2017-07-16
// Refer to other's solution
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double l = *min_element(nums.begin(), nums.end());
    double r = *max_element(nums.begin(), nums.end());
    vector<double> sum(nums.size() + 1, 0);
    while (r - l >= 1e-6) {
      double mid = (l + r) / 2.0;
      double min_pre = 0;
      bool check = false;
      for (int i = 1; i <= nums.size(); ++i) {
        sum[i] = sum[i - 1] + nums[i - 1] - mid;
        if (i >= k && sum[i] - min_pre >= 0) {
          check = true;
          break;
        }
        if (i >= k)
          min_pre = min(min_pre, sum[i - k + 1]);
      }
      if (check) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};