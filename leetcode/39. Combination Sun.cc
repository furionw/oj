// Copyright 2016 Qi Wang
// Date: 2016-12-10
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    // trivial case
    if (!candidates.empty()) {
      vector<int> cur;
      sort(candidates.begin(), candidates.end());
      combinationSum(candidates, 0, target, cur, res);
    }
    return res;
  }
 
 private:
  // DFS
  void combinationSum(vector<int>& candidates, int idx, int target,
      vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) {
      res.push_back(cur);
      return;
    }
    if (idx >= candidates.size() || candidates[idx] > target) return;
    combinationSum(candidates, idx + 1, target, cur, res);
    for (int i = 1; i * candidates[idx] <= target; ++i) {
      cur.push_back(candidates[idx]);
      combinationSum(candidates, idx + 1, target - i * candidates[idx], cur,
          res);
    }
    int cnt = target / candidates[idx];
    for (int i = 0; i < cnt; ++i) cur.pop_back();
  }
};

// Date: 2016-12-10
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) return vector<vector<int>>();
    sort(candidates.begin(), candidates.end());
    return combinationSum(candidates, candidates.size() - 1, target);
  }

 private:
  vector<vector<int>> combinationSum(vector<int>& candidates, int idx,
      int target) {
    if (target == 0) return vector<vector<int>>(1, vector<int>());
    if (idx < 0) return vector<vector<int>>();
    vector<vector<int>> res;
    for (int i = 0; i * candidates[idx] <= target; ++i) {
      auto temp = combinationSum(candidates, idx - 1,
          target - i * candidates[idx]);
      for (auto& elem : temp) {
        for (int j = 0; j < i; ++j)
          elem.push_back(candidates[idx]);
        res.push_back(elem);
      }
    }
    return res;
  }
};

// Date: 2014-07
class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
      sort(candidates.begin(), candidates.end());
      for (size_t i = 0; i < candidates.size(); ++ i)
      {
        if (i==0 || candidates[i]!=candidates[i-1])
        {
          m_candidates.push_back( candidates[i] );
        }
      }
      vector<int> now;
      dfs(now, target, 0);
      return ret;
    }
private:
  vector<int> m_candidates;
  vector<vector<int> > ret;
  
  void dfs(vector<int>& now, int remain, int index)
  {
    for (int i = index; i<m_candidates.size(); ++ i)
    {
      if (m_candidates[i] > remain)
      {
        break;
      } else 
      {
        int cur = remain;
        while (m_candidates[i] <= cur)
        {
          now.push_back( m_candidates[i] );
          dfs(now, cur-m_candidates[i], i+1);
          cur -= m_candidates[i];
        }
        if (cur == 0)
        {
          ret.push_back( now );
        }
        while (cur < remain)
        {
          now.pop_back();
          cur += m_candidates[i];
        }        
      }
    }
  }
};