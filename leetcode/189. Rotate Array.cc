// Copyright 2017 Qi Wang
// Date: 2017-08-27
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1) return;
    int n = nums.size();
    if ((k %= n) == 0) return;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};

// Date: 2017-08-26
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (k < 0 || nums.empty()) return;
    k %= nums.size();
    if (k == 0) return;
    vector<int> temp(nums.end() - k, nums.end());
    for (int i = nums.size() - 1; i - k >= 0; --i) {
      nums[i] = nums[i - k];
    }
    copy(temp.begin(), temp.end(), nums.begin());
  }
};

// O(n) space
class Solution 
{
public:
  void rotate(int nums[], int n, int k) 
  {
    int new_nums[n];
    for (int i = 0; i < n; ++ i)
    {
      new_nums[(i+k)%n] = nums[i];
    }
    for (int i = 0; i < n; ++ i)
    {
      nums[i] = new_nums[i];
    }
  }
};