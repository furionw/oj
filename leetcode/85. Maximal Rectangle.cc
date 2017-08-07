// Copyright 2017 Qi Wang
// Date: 2017-08-06
class Solution {
 public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i][j] = matrix[i][j] == '0' ? 0 : 1 + (i == 0 ? 0 : dp[i - 1][j]);
    int result = 0;
    for (int i = 0; i < m; ++i)
      result = max(result, MaxRect(dp[i]));
    return result;
  }
 
 private:
  int MaxRect(vector<int>& height) const {
    stack<int> idxs;
    // dummy element used to extract all element from idxs
    height.push_back(-1);
    int result = 0;
    for (int i = 0; i < height.size();) {
      if (idxs.empty() || height[idxs.top()] <= height[i]) {
        idxs.push(i++);
      // Note that all the preceeding elements of height is less than its last:
      // elem < height[height.back() - 1] == -1
      } else {
        int h = height[idxs.top()]; idxs.pop();
        result = max(result, h * (idxs.empty() ? i : i - idxs.top() - 1));
      }
    }
    return result;
  }
};

class Solution
{
 public:
  int maximalRectangle(vector<vector<char> > &matrix) 
  {
    if (matrix.empty() == true)
    {
      return 0;
    }

    size_t n=matrix.size(), m=matrix[0].size();
    vector<vector<int>> cnt(n, vector<int>(m));
    int maxx = 0;

    for (size_t j = 0; j < m; ++ j)
    {  
      for (size_t i = 0; i < n; ++ i)
      {
        if (i == 0)
        {
          cnt[i][j] = matrix[i][j] - '0';
        } else
        {
          cnt[i][j] = matrix[i][j]=='0'? 0: 1+cnt[i-1][j];
        }
      }
    }
    for (size_t i = 0; i < n; ++ i)
    {
      maxx = max(maxx, largestRectangleArea(cnt[i]));
    }

    return maxx;
  }

private:
  int largestRectangleArea(vector<int> &height)
  {
    height.push_back(-1); // dummy element
    stack<int> s;
    int maxx = 0;

    for (int i = 0; i < height.size(); )
    {
      if (s.empty()==true || height[s.top()]<=height[i])
      {
        s.push(i ++); // -1 will be pushed at last, and nothing will happen
      } else 
      {
        int top_index = s.top();
        s.pop();
        maxx = max(maxx, height[top_index]*(s.empty()? i: i-s.top()-1));
      }
    }

    return maxx;
  }
};