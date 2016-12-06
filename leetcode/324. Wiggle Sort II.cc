// Copyright 2016 Qi Wang
// Method 2
// Refer to: http://blog.csdn.net/qq508618087/article/details/51337187
// It seems that there is a O(n) time and O(1) space solution, which I cannot
// understand now.
// Date: 2016-12-05
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    
  }
};

// Method 1
// Date: 2016-12-05
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> res;
    res.reserve(nums.size());
    size_t jBegin = (nums.size() >> 1) + (nums.size() & 1);
    for (int i = jBegin - 1, j = nums.size() - 1, flag = 0;
        i >= 0 || j >= jBegin; flag = !flag) {
      if (!flag) {
        res.push_back(nums[i--]);
      } else {
        res.push_back(nums[j--]);
      }
    }
    nums = res;
  }
};
