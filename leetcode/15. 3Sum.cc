// Copyright 2017 Qi Wang
// Date: 2017-08-30
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size();) {
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        if (nums[j] + nums[k] < -nums[i]) {
          Advance(nums, &j);
        } else if (nums[j] + nums[k] == -nums[i]) {
          result.push_back({nums[i], nums[j], nums[k]});
          Advance(nums, &j);
        } else {
          --k;
        }
      }
      Advance(nums, &i);
    }
    return result;
  }

 private:
  void Advance(const vector<int>& nums, int* idx) const {
    for (++(*idx); (*idx) < nums.size() &&
           nums[(*idx)] == nums[(*idx) - 1]; ++(*idx)) {}
  }
};

// Date: 2017-08-16
// This is the best solution ever! Only in O((N^2)
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size();) {
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          Advance(nums, &j);
        } else if (sum < 0) {
          Advance(nums, &j);
        } else {
          // We can implement a Stepback function here or just use --k
          --k;
        }
      }
      Advance(nums, &i);
    }
    return result;
  }

 private:
  void Advance(const vector<int>& nums, int* idx) const {
    ++*idx;
    while (*idx < nums.size() && nums[*idx] == nums[*idx - 1]) {
      ++*idx;
    }
  }
};

// Date: 2017-08-16
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size();) {
      for (int j = i + 1; j < nums.size();) {
        int target = -nums[i] - nums[j];
        if (binary_search(nums.begin() + j + 1, nums.end(), target)) {
          result.push_back({nums[i], nums[j], target});
        }
        Advance(nums, &j);
      }
      Advance(nums, &i);
    }
    return result;
  }

 private:
  void Advance(const vector<int>& nums, int* idx) const {
    ++*idx;
    while (*idx < nums.size() && nums[*idx] == nums[*idx - 1]) {
      ++*idx;
    }
  }
};

// Date: 2017-07-02
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (size_t i = 0; i < nums.size();) {
      for (size_t j = i + 1; j < nums.size();) {
        if (binary_search(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j]))
          result.push_back({nums[i], nums[j], -nums[i] - nums[j]});
        for (++j; j < nums.size() && nums[j - 1] == nums[j]; ++j) {}
      }
      for (++i; i < nums.size() && nums[i - 1] == nums[i]; ++i) {}
    }
    return result;
  }
};
 
// Date: 2016-12-19
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size();) {
      for (int j = i + 1; j < nums.size();) {
        if (binary_search(nums, j + 1, static_cast<int>(nums.size()) - 1,
            -nums[i] - nums[j]))
          res.push_back({nums[i], nums[j], -nums[i] - nums[j]});
        advance(j, nums);
      }
      advance(i, nums);
    }
    return res;
  }

 private:
  void advance(int& idx, const vector<int>& nums) const {
    for (++idx; idx < nums.size() && nums[idx] == nums[idx - 1]; ++idx) {}
  }

  bool binary_search(const vector<int>& nums, int l, int r, int target) {
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};

// Date: 2014-06
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > ret;

        sort (num.begin(), num.end());
        for (size_t a = 0; a < num.size(); ++ a)
        {
            if (a!=0 && num[a] == num[a-1])
            { 
                continue;
            }
            size_t b=a+1, c=num.size()-1;
            while (b < c)
            {
                if (0 > num[a]+num[b]+num[c])
                {
                    ++ b;
                } else if (0 < num[a]+num[b]+num[c])
                {
                    -- c;
                } else if (b!=a+1 && num[b]==num[b-1])
                {
                    ++ b;
                } else if (c!=num.size()-1 && num[c]==num[c+1])
                {
                    -- c;
                } else 
                {
                    vector<int> item;
                    item.push_back(num[a]);
                    item.push_back(num[b]);
                    item.push_back(num[c]);
                    ret.push_back(item);
                    ++ b;
                    -- c;
                }
            }
        }

        return ret;
    }
};

// old 
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        if (num.empty() == true)
        {
            return vector<vector<int> >();
        }
        
      vector<vector<int> > ret;

      sort(num.begin(), num.end());
      for (int i = 0; i < int(num.size())-2; ++ i)
      {
      if (i!=0 && num[i]==num[i-1])
      {
        continue;
      }
        for (int j = i+1; j < int(num.size())-1; ++ j)
        {
          if (j!=i+1 && num[j]==num[j-1])
          {
            continue;
          }
          if ( binary_search(num, 0-num[i]-num[j], j+1) )
          {
            vector<int> item;
            item.push_back(num[i]);
            item.push_back(num[j]);
            item.push_back(0-num[i]-num[j]);
            ret.push_back(item);
          }
        }
      }   

      return ret; 
    }
private:
  bool binary_search(vector<int>& num, int target, int l)
  {
    int r = num.size()-1;
    while (l <= r)
    {
      int mid = (l+r)/2;
      if (num[mid] < target)
      {
        l = mid + 1;
      } else if (num[mid] > target)
      {
        r = mid - 1;
      } else
      {
        return true;
      }
    }
    return false;
  }
};