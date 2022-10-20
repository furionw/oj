// Date: 2022-10-19
// Refer to: https://leetcode.com/problems/minimize-maximum-of-array/discuss/2706521/JavaC%2B%2BPython-Prefix-Sum-Average-O(n)
class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    int res = 0;
    size_t sum = 0;
    int cnt = 0;
    for (int num : nums) {
      sum += num;
      res = max(res, int(ceil(1. * sum / ++cnt)));
    }
    return res;
  }
};
