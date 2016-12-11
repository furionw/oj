// Copyright 2016 Qi Wang
// Date: 2016-12-11
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    combinationSum3(1, k, n, cur, res);
    return res;
  }

 private:
  void combinationSum3(int num, int k, int n, vector<int>& cur,
      vector<vector<int>>& res) const {
    if (n == 0 || k == 0) {
      if (n == 0 && k == 0) res.push_back(cur);
      return;
    }
    if (num == 10) return;
    combinationSum3(num + 1, k, n, cur, res);
    cur.push_back(num);
    combinationSum3(num + 1, --k, n -= num, cur, res);
    cur.pop_back();
  }
};

// Date: 2015-09
class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        for (int i = 1; i<=9 && k>0 && i<=n; ++ i)
        {
          vector<int> cur(1, i);
          gao(i+1, k-1, n-i, cur);
        }
        return ret;
    }

private:
  void gao(int begin, int k, int n, vector<int>& cur)
  {
    if (k==0 && n==0)
    {
      ret.push_back(cur);
      return;
    }
    for (int i = begin; i<=9 && k>0 && i<=n; ++ i)
    {
      cur.push_back(i);
      gao(i+1, k-1, n-i, tmp);
      cur.pop_back();
    }
  }

  vector<vector<int>> ret;
};