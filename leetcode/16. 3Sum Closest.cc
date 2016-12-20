// Copyright 2016 Qi Wang
// Date: 2016-12-20
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    // illegal input
    if (nums.size() < 3) return 1;
    sort(nums.begin(), nums.end());
    int res = accumulate(nums.begin(), nums.begin() + 3, 0);
    for (int i = 0; i < nums.size() && res != target;) {
      for (int j = i + 1; j < nums.size() && res != target;) {
        binary_search(nums, j + 1, nums.size() - 1,
            nums[i] + nums[j], target, res);
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

  void binary_search(const vector<int>& nums, int l, int r,
      int twoSum, int target, int& res) const {
    while (l <= r) {
      int mid = (l + r) >> 1;
      res = abs(target - res) < abs(target - twoSum - nums[mid])
          ? res : twoSum + nums[mid];
      if (nums[mid] == target - twoSum) {
        return;
      } else if (nums[mid] < target - twoSum) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
};


class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
      int closest = INT_MAX, ret;

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
          int ans = binary_search(num, target-num[i]-num[j], j+1) ;
          if (closest > abs(target-num[i]-num[j]-ans))
                {
                    closest = abs(target-num[i]-num[j]-ans);
                    ret = num[i] + num[j] + ans;
                }
        }
      }   

      return ret; 
    }
private:
  int binary_search(vector<int>& num, int target, int l)
  {
    int r = num.size()-1, mid;
    while (l <= r)
    {
      mid = (l+r)/2;
      if (num[mid] < target)
      {
                if (abs(target-num[mid]) >= abs(target-num[mid+1]))
                {
            l = mid + 1;
                } else
                {
                    break;
                }
      } else if (num[mid] > target)
      {
                if (abs(target-num[mid]) >= abs(target-num[mid-1]))
                {
            r = mid - 1;
                } else
                {
                    break;
                }
      } else
      {
        break;
      }
    }
        return num[mid];
  }
};
