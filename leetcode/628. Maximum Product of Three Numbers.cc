// Copyright 2017 Qi Wang
// Date: 2017-06-25
// Refer to Jinhao's solution
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    size_t n = nums.size();
    int result = nums[n - 3] * nums[n - 2] * nums[n - 1];
    result = max(result, nums[0] * nums[1] * nums[n - 1]);
    return result;
  }
};

// Date: 2017-06-25
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    vector<int> pos, non_pos;
    for (int num : nums)
      if (num > 0) {
        pos.push_back(num);
      } else {
        non_pos.push_back(num);
      }
    sort(pos.begin(), pos.end());
    sort(non_pos.begin(), non_pos.end());
    if (pos.size() >= 3) {
      int result = pos.back() * pos[pos.size() - 2] * pos[pos.size() - 3];
      if (non_pos.size() >= 2)
        result = max(result, non_pos[0] * non_pos[1] * pos.back());
      return result;
    } else if (pos.size() == 2) {
      if (non_pos.size() >= 2) {
        return non_pos[0] * non_pos[1] * pos[1];
      } else {
        return non_pos[0] * pos[0] * pos[1];
      }
    } else if (pos.size() == 1) {
      return pos[0] * non_pos[0] * non_pos[1];
    } else {
      return non_pos.back() * non_pos[non_pos.size() - 2] *
          non_pos[non_pos.size() - 3];
    }
  }
};
