// Copyright 2017 Qi Wang
// Date: 2017-11-09
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    do {
      result.push_back(nums);
    } while (NextPermutation(&nums));
    return result;
  }

 private:
  bool NextPermutation(vector<int>* nums) {
    if (nums->size() <= 1) return false;
    for (int i = nums->size() - 2; i >= 0; --i) {
      for (int j = nums->size() - 1; j > i; --j) {
        if ((*nums)[j] > (*nums)[i]) {
          swap((*nums)[i], (*nums)[j]);
          reverse(nums->begin() + i + 1, nums->end());
          return true;
        }
      }
    }
    reverse(nums->begin(), nums->end());
    return false;
  }
};

// Date: 2016-12-27
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.push_back(nums);
    } while (nextPermutation(nums));
    return res;
  }

 private:
  bool nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return false;
    int n = static_cast<int>(nums.size());
    for (int i = n - 2; i >= 0; --i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] > nums[i]) {
          swap(nums[j], nums[i]);
          reverse(nums.begin() + i + 1, nums.end());
          return true;
        }
      }
    }
    return false;
  }
};

// Date: 
class Solution 
{
public:
    vector<vector<int> > permute(vector<int> &num) 
    {
    vector<vector<int> > ret;  
    sort(num.begin(), num.end());

    do 
    {
      ret.push_back( num );
    } while( has_next_permutation(num) );

    return ret;
  }

private:
  bool has_next_permutation(vector<int>& num)
  {
    // Bug report on 2016-12-27
    // num.size() - 2 could result in overflow, 'cause num.size() could be
    // smaller than 2
    for (int i = num.size()-2; i >= 0; -- i)
    {
      for (int j = num.size()-1; j > i; -- j)
      {
        if (num[j] > num[i])
        {
          swap(num[i], num[j]);
          sort(num.begin()+i+1, num.end());
          return true;
        }
      }
    }
    return false;
  }
};