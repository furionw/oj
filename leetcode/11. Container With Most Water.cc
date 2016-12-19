// Copyright 2016 Qi Wang
// Date: 2016-12-19
class Solution {
 public:
  int maxArea(vector<int>& height) {
    if (height.size() < 2) return 0;
    int res = 0;
    for (int i = 0, j = height.size() - 1; i < j; ) {
      int minHeight = min(height[i], height[j]);
      res = max(res, minHeight * (j - i));
      while (i < j && height[i] <= minHeight) ++i;
      while (i < j && height[j] <= minHeight) --j;
    }
    return res;
  }
};

// Date: 2014-06
class Solution 
{
public:
    int maxArea(vector<int> &height) 
    {
      int maxx = 0, l = 0, r = height.size()-1;

      while (l < r)
      {
        maxx = maxx>(r-l)*min(height[l], height[r])? maxx: (r-l)*min(height[l], height[r]);
        if (height[l] < height[r])
        {
          ++ l;
        } else
        {
          -- r;
        }
      }

        return maxx;
    }
};
