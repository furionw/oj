// Date: 2022-11-18
class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> s;
    long long res = 0;
    for (long long i = 0, sum = 0, prev = 0; i < nums.size(); ++i) {
      if (i - prev > k - 1) {
        sum -= nums[prev];
        s.erase(nums[prev]);
        ++prev;
      }
      if (s.count(nums[i])) {
        do {
          sum -= nums[prev];
          s.erase(nums[prev]);
          ++prev;
        } while (nums[prev - 1] != nums[i]);
      }
      sum += nums[i];
      s.insert(nums[i]);
      if (i - prev == k - 1) {
        res = max(res, sum);
      }
    }
    return res;
  }
};
