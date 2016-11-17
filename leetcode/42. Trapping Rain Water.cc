// Copyright 2016 Qi Wang
// Date: 2016-11-02
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int leftmost[height.size()], rightmost[height.size()];
    for (int i = 0, max = 0; i < height.size(); ++i) {
      leftmost[i] = max;
      max = ::max(max, height[i]);
    }
    for (int i = height.size() - 1, max = 0; i >= 0; --i) {
      rightmost[i] = max;
      max = ::max(max, height[i]);
    }
    int res = 0;
    for (size_t i = 1; i < height.size() - 1; ++i)
      if (min(leftmost[i], rightmost[i]) > height[i])
        res += min(leftmost[i], rightmost[i]) - height[i];
    return res;
  }
};

// Date: 2014-07
class Solution 
{
public:
    int trap(int A[], int n) 
    {
    	int sum = 0;
		vector<int> leftmost(n, 0), rightmost(n, 0);

		for (int i = 0, maxx = 0; i < n; ++ i)
		{
			leftmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = n-1, maxx = 0; i >= 0; -- i)
		{
			rightmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = 1; i < n-1; ++ i)
		{
			if (min(leftmost[i], rightmost[i]) > A[i])
			{
				sum += min(leftmost[i], rightmost[i]) - A[i];
			}
		}

		return sum;
    }
};