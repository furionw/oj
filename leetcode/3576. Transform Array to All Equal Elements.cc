// 2025-06-10
class Solution {
 public:
  bool canMakeEqual(vector<int>& nums, int k) {
    auto temp = nums;
    int times = 0;
    // convert to 1s
    for (int i = 0; i + 1 < temp.size(); ++i) {
      if (temp[i] == -1) {
        temp[i] = -temp[i];
        temp[i + 1] = -temp[i + 1];
        ++times;
      }
    }
    if (times <= k && temp.back() == 1) {
      return true;
    }

    times = 0;
    // convert to -1
    for (int i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] == 1) {
        nums[i] = -nums[i];
        nums[i + 1] = -nums[i + 1];
        ++times;
      }
    }
    return times <= k && nums.back() == -1;
  }
};
