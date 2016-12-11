// Copyright 2016 Qi Wang
// Date: 2016-12-10
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if (!candidates.empty()) {
      sort(candidates.begin(), candidates.end());
      vector<pair<int, int>> nums;
      for (size_t i = 0; i < candidates.size(); ++i) {
        if (i == 0 || candidates[i] != candidates[i - 1]) {
          nums.emplace_back(candidates[i], 1);
        } else {
          ++nums.back().second;
        }
      }
      vector<int> cur;
      combinationSum2(nums, 0, target, cur, res);
    }
    return res;
  }

 private:
  void combinationSum2(const vector<pair<int, int>>& nums, int idx, int target,
      vector<int>& cur, vector<vector<int>>& res) const {
    if (target == 0) {
      res.push_back(cur);
      return;
    }
    if (idx == nums.size() || nums[idx].first > target) return;
    combinationSum2(nums, idx + 1, target, cur, res);
    int cnt = min(target / nums[idx].first, nums[idx].second);
    for (int i = 0; i < cnt; ++i) {
      cur.push_back(nums[idx].first);
      combinationSum2(nums, idx + 1, target -= nums[idx].first, cur, res);
    }
    while (cnt--) cur.pop_back();
  }
};

// Date: 2014-07
class Solution 
{
public:
  vector<vector<int> > combinationSum2(vector<int> &candidates, int target) 
  {
    sort(candidates.begin(), candidates.end());
    for (size_t i = 0; i < candidates.size(); ++ i)
    {
      if (i==0 || candidates[i]!=candidates[i-1])
      {
        num.push_back( candidates[i] );
        cnt.push_back( 1 );
      } else
      {
        ++ cnt[cnt.size()-1];
      }
    }
    vector<int> now;
    dfs(now, 0, target);
    return ret;
  }
private:
  vector<int> num;
  vector<int> cnt;
  vector<vector<int> > ret;
  void dfs(vector<int>& now, size_t index, int remain)
  {
    for (size_t i = index; i < num.size(); ++ i)
    {
      if (num[i] > remain)
      {
        break;
      } else
      {
        int cur = remain;
        for (int j = 0; j<cnt[i] && num[i]<=cur; ++ j)
        {
          cur -= num[i];
          now.push_back( num[i] );
          dfs(now, i+1, cur);
        }
        if (cur == 0)
        {
          ret.push_back( now );
        }
        while (cur != remain)
        {
          now.pop_back();
          cur += num[i];
        }
      }
    }
  }
};
