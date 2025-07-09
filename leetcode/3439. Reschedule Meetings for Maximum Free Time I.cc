// 2025-07-09
class Solution {
 public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    
    vector<int> nums(n + 1, 0);
    nums[0] = startTime.front();
    for (int i = 1; i < n; ++i) {
      nums[i] = startTime[i] - endTime[i - 1];
    }
    nums[n] = eventTime - endTime.back();

    // sliding window size of k
    ++k;
    int cur = accumulate(nums.begin(), nums.begin() + k, 0);
    int result = cur;
    for (int i = k; i < nums.size(); ++i) {
      cur = cur - nums[i - k] + nums[i];
      result = max(result, cur);
    }
    return result;
  }
};
