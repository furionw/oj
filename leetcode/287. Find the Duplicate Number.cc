// Copyright 2017 Qi Wang
// Date: 2017-08-10
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    const int N = nums.size() - 1;
    int l = 1, r = N;
    while (l <= r) {
      int mid = l + r >> 1;
      int greater_cnt = 0, less_cnt = 0;
      for (int num : nums) {
        if (num > mid) {
          ++greater_cnt;
        } else if (num < mid) {
          ++less_cnt;
        }
      }
      if (greater_cnt > N - mid) {
        l = mid + 1;
      } else  if (less_cnt > mid - 1) {
        r = mid - 1;
      } else {
        return mid;
      }
    }
    return INT_MIN;
  }
};
