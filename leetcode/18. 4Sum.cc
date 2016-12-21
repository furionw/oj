// Copyright 2016 Qi Wang
// Date: 2016-12-20
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    // trivial case
    if (nums.size() < 4) return res;
    // non-trivial case
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 3;) {
      for (size_t j = i + 1; j < nums.size() - 2;) {
        size_t l = j + 1, r = nums.size() - 1;
        // Boost up by introducing twoSum instead of calculating nums[i, j, k, l]
        int twoSum = target - nums[i] - nums[j];
        while (l < r) {
          if (twoSum > nums[l] + nums[r]) {
            ++l;
          } else if (twoSum < nums[l] + nums[r]) {
            --r;
          } else {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l <= r && nums[l] == nums[l + 1]) ++l;
            ++l;
            while (l <= r && nums[r - 1] == nums[r]) --r;
            --r;
          }
        }
        advance(j, nums);
      }
      advance(i, nums);
    }
    return res;
  }

 private:
  void advance(size_t& idx, const vector<int>& nums) const {
    for (++idx; idx < nums.size() && nums[idx] == nums[idx - 1]; ++idx) {}
  }
};

// Date: 2016-11-13
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    // trivial case
    if (nums.size() < 4) return res;
    // non-trivial case
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 3; ++i) {
      // We have considered before nums[i], thus we just continue
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      for (size_t j = i + 1; j < nums.size() - 2; ++j) {
        // We have considered before nums[j], thus we just continue
        if (j != i + 1 && nums[j] == nums[j - 1]) continue;
        size_t k = j + 1, l = nums.size() - 1;
        // Boost up by introducing twoSum instead of calculating nums[i, j, k, l]
        int twoSum = target - nums[i] - nums[j];
        while (k < l) {
          if (twoSum > nums[k] + nums[l]) {
            ++k;
          } else if (twoSum < nums[k] + nums[l]) {
            --l;
          } else {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
            while (k <= l && nums[k] == nums[k + 1]) ++k;
            ++k;
            while (k <= l && nums[l - 1] == nums[l]) --l;
            --l;
          }
        }
      }
    }
    return res;
  }
};

// Date: 2014-05
class Solution 
{
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) 
  {
    vector<vector<int> > ret;

    sort(num.begin(), num.end());
    for (size_t a = 0; a<num.size(); ++ a)
    {
      if (a!=0 && num[a]==num[a-1])
      {
        continue;
      }
      for (size_t b=a+1; b<num.size(); ++ b)
      {
        if (b!=a+1 && num[b]==num[b-1])
        {
          continue;
        }
        size_t c = b+1, d = num.size()-1;
        while (c < d)
        {
          if (target > num[a]+num[b]+num[c]+num[d])
          {
            ++ c;
          } else if (target < num[a]+num[b]+num[c]+num[d])
          {
            -- d;
          } else if (c!=b+1 && num[c]==num[c-1])
          {
            ++ c;
          } else if (d!=num.size()-1 && num[d]==num[d+1])
          {
            -- d;
          } else
          {
            vector<int> item;
            item.push_back(num[a]);
            item.push_back(num[b]);
            item.push_back(num[c]);
            item.push_back(num[d]);
            ret.push_back(item);
            ++ c;
            -- d;
          }
        }
      }
    }

    return ret; 
  }
};